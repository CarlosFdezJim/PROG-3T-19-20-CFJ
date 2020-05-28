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

///////////////////////////////				 USUARIO					////////////////////////////////

Foto::Foto(){

	cout  << PURPLE << "\n  ****    CREANDO FOTO    **** " << DEFAULT << endl;
	//Reservamos un nuevo espacio de memoria para la Foto y lo inicializamos.
	Foto *f= new Foto;
	
	//Inicializamos el contenido del Usuario.	
	this->ruta = "";
	this->tipo = "";
	this->tamanio = 0;
	
	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (f == 0){
		cerr << "Error. No hay memoria suficiente para crear una foto nueva. Se abortará la ejecución" << endl;
		exit(-1);
	}
	
	cout << GREEN << "La Foto se ha creado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
}
Foto::~Foto(){

	cout  << PURPLE << "\n  ****    BORRANDO FOTO    **** " << DEFAULT << endl;

	//Ponemos a cero/null todos los datos que tiene la Foto
	this->ruta = "NULL";
	this->tipo = "NULL";
	this->tamanio = -1;

	//borro el fragmento de memoria
	//delete f;

	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	//f = 0;
		
	cout << GREEN << "La foto se ha borrado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
}

///////////////////////////////				 SET					////////////////////////////////

void Foto::setRuta(string ruta){
	this->ruta = ruta;
}
void Foto::setTipo(string tipo){
	this->tipo = tipo;
}
void Foto::setTamanio(unsigned long int tamanio){
	this->tamanio = tamanio;
}

///////////////////////////////				 GET					////////////////////////////////

string Foto::getRuta(){
	return this->ruta;
}
string Foto::getTipo(){
	return this->tipo;
}
int long unsigned Foto::getTamanio (){
	return this->tamanio;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Foto::printFoto(){

	//Imprimimos toda la foto inluyendo Ruta,Tipo y Tamanio.
	cout << BLUE << "Ruta : " << DEFAULT << this->getRuta() << "." << this->getTipo() << endl;
	cout << BLUE << "Tipo : " << DEFAULT << this->getTipo()  << endl;
	cout << BLUE << "Tamaño : " << DEFAULT << this->getTamanio() << " bytes." << endl;
	cout << PURPLE << "----------------" << DEFAULT << endl;
	
}
/*void Foto::printFotosUsuario(){

	string login = "";
	bool usado = true;
	int posicion=0;
	int cont = 0;
	Usuario *u = 0;
	
	cout << PURPLE << "Por favor introduzca el Login del usuario que quiere ver sus fotos: " << DEFAULT << endl;
	cin >> login;
	
	//Comprobamos si el login existe o no.
	for(int i = 0;i < tu->TotalTuplas;i++){
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
		this->printVectorFotos(tu->punteroapuntero[posicion]->v_fotos, tu->punteroapuntero[posicion]);
		
	}else
		cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
}*/
/**
 * @brief Este módulo se encarga de pedir los valores predeterminados al usuario y distingirá entre varias opciones para asignarle un tamaño a la foto.
 * @param Foto *f
 * @pre Los módulos set tienen que estar hechos correctamente.
 * @post Almacenaremos en el usuario los valores de las fotos.
 * @version 1.0
 * @author Carlos Fdez.
 */
/*void Foto::ValoresFoto(Foto *f){

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
}*/


/**
 * @brief Este módulo se usa para introducir las fotos del usuario predefinido.
 * @param Usuario *u
 * @param Foto *f
 * @pre El resize debe de funcionar correctamente.
 * @post El usuario tendrá las fotos insertadas en su perfil.
 * @version 1.0
 * @author Carlos Fdez.
 */
/*void insertarFotoUsuario(Usuario *u, Foto *f){
	
	//Aumentamos en uno nuestro vector.
	resizeAumentarFoto(u,u->v_fotos);
	
	//Insertamos en elvector nuestra foto
	u->v_fotos[getTotalFotosUsuario(u)] = *f;
	
	setTotalFotosUsuario(u,getTotalFotosUsuario(u)+1);
}*/
