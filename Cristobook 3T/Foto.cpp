//
//	Foto.cpp
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-2T-CFJ
//
//

//**********COLOR**********//

#define DEFAULT "\033[1;0m"
#define GREY "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define ERROR "\033[1;41m"
//************************//

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Foto.h"
using namespace std;


Foto* Foto::crearFoto(){

	//Reservamos un nuevo espacio de memoria para la Foto y lo inicializamos.
	Foto *f=0;
	f = new Foto;
	
	//Inicializamos el contenido del Usuario.	
	f->ruta = "";
	f->tipo = "";
	f->tamanio = 0;
	
	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (f == 0){
		cerr << "Error. No hay memoria suficiente para crear una foto nueva. Se abortará la ejecución" << endl;
		exit(-1);
	}
	
	//Devuelvo la dirección que referenciaba al fragmento de memoria(puntero).
	return f;
	
}
void Foto::borrarFoto(Foto *f){

	//Ponemos a cero/null todos los datos que tiene la Foto
	f->ruta = "";
	f->tipo = "";
	f->tamanio = 0;

	//borro el fragmento de memoria
	delete f;

	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	f = 0;
	
}
void Foto::setRuta(Foto *f, string ruta){
	f->ruta = ruta;
}
void Foto::setTipo(Foto *f, string tipo){
	f->tipo = tipo;
}
void Foto::setTamanio (Foto *f, unsigned long int tamanio){
    f->tamanio = tamanio;
}
string Foto::getRuta(Foto *f){
    return f->ruta;
}
string Foto::getTipo(Foto *f){
    return f->tipo;
}
int long unsigned Foto::getTamanio (Foto *f){
    return f->tamanio;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Foto::printVectorFotos(Foto *v_fotos, Usuario *u ){

		if(getTotalFotosUsuario(u) != 0){
			for(int i=0; i < getTotalFotosUsuario(u); i++){
				printFoto(&v_fotos[i]);
				cout << PURPLE << "----------------" << DEFAULT << endl;
			}
		}else
			cerr << RED << "Lo sentimos, no hay fotos insertadas." << DEFAULT << endl;
}
/**
 * @brief Módulo que se encarga de imprimir el vector de fotografías de un usuario.
 * @param TablaUsuarios tu
 * @pre El usuario debe de estar instertado.
 * @post Se muestran por pantalla las fotografías de ese usuario
 * @version 1.0
 * @author Carlos Fdez.
 */
void printFotosUsuario(TablaUsuarios &tu){

	string login = "";
	bool usado = true;
	int posicion=0;
	int cont = 0;
	Usuario *u = 0;
	
	cout << PURPLE << "Por favor introduzca el Login del usuario que quiere ver sus fotos: " << DEFAULT << endl;
	cin >> login;
	
	//Comprobamos si el login existe o no.
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;
			cout << "Posición: " << posicion << endl;	
		}
	}

	//Si existe el login
	if(usado == true){
		//cout << "DEBUG: Posición: " << posicion << endl;
		printVectorFotos(tu.punteroapuntero[posicion]->v_fotos, tu.punteroapuntero[posicion]);
		
	}else
		cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
}
/**
 * @brief Este módulo se encarga de pedir los valores predeterminados al usuario y distingirá entre varias opciones para asignarle un tamaño a la foto.
 * @param Foto *f
 * @pre Los módulos set tienen que estar hechos correctamente.
 * @post Almacenaremos en el usuario los valores de las fotos.
 * @version 1.0
 * @author Carlos Fdez.
 */
void Foto::ValoresFoto(Foto *f){

	cout << BLUE << "* * * * * * * * * * * * * * * * * * * " << DEFAULT << endl;
	cout << YELLOW << "Por favor ingresa la ruta de la foto. " << DEFAULT << endl;
	cin >> f->ruta;
	
	cout << YELLOW << "Por favor ingresa el formato de la foto. " << DEFAULT << endl;
	cout << YELLOW << "Le indico los tipos compatibles [bmp] [jpeg] [png] [gif] " << DEFAULT << endl ;
	cin >> f->tipo;
	cout << BLUE << "* * * * * * * * * * * * * * * * * * * " << DEFAULT << endl;
	
	//Dependiendo del tipo de foto se le asigna un tamaño predeterminado.
	if(f->tipo == "bmp"){
		setTamanio(f,125910);
	}else if(f->tipo == "jpeg"){
		setTamanio(f,49350);
	}else if(f->tipo == "png"){
		setTamanio(f,8710);
	}else if(f->tipo == "gif"){
		setTamanio(f,6050);
	}else 
		setTamanio(f,405000);
}
void Foto::printFoto(Foto *f){

	//Imprimimos toda la foto inluyendo Ruta,Tipo y Tamanio.
	cout << BLUE << "Ruta : " << DEFAULT << getRuta(f) << "." << getTipo(f) << endl;
	cout << BLUE << "Tipo : " << DEFAULT << getTipo(f)  << endl;
	cout << BLUE << "Tamaño : " << DEFAULT << getTamanio(f) << " bytes." << endl;
	cout << PURPLE << "----------------" << DEFAULT << endl;
	
}

/**
 * @brief Este módulo se usa para introducir las fotos del usuario predefinido.
 * @param Usuario *u
 * @param Foto *f
 * @pre El resize debe de funcionar correctamente.
 * @post El usuario tendrá las fotos insertadas en su perfil.
 * @version 1.0
 * @author Carlos Fdez.
 */
void insertarFotoUsuario(Usuario *u, Foto *f){
	
	//Aumentamos en uno nuestro vector.
	resizeAumentarFoto(u,u->v_fotos);
	
	//Insertamos en elvector nuestra foto
	u->v_fotos[getTotalFotosUsuario(u)] = *f;
	
	setTotalFotosUsuario(u,getTotalFotosUsuario(u)+1);
}
void Foto::resizeAumentarFoto(Usuario *u,Foto *v_fotos){
	
	int DIM = u->totalFotosUsuario+1;

	Foto *vectorNuevo = 0;
	
	vectorNuevo = new Foto[DIM];

	if (vectorNuevo == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}
	for(int i = 0;i < u->totalFotosUsuario;i++){
		vectorNuevo[i]=v_fotos[i];
	}
	u->v_fotos = vectorNuevo;
	delete [] v_fotos;
	
}
void Foto::resizeDisFoto(Usuario *u,Foto *v_fotos){
	
	int DIM = u->totalFotosUsuario-1;

	Foto *vectorNuevo = 0;
	
	vectorNuevo = new Foto[DIM];

	if (vectorNuevo == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}
	
	for(int i = 0;i < DIM;i++){
		vectorNuevo[i]=v_fotos[i];
	}
	
	u->v_fotos = vectorNuevo;
	
	delete [] v_fotos;
		
}
