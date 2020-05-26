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
using namespace std;


Foto* crearFoto(){

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
void borrarFoto(Foto *f){

	//Ponemos a cero/null todos los datos que tiene la Foto
	f->ruta = "";
	f->tipo = "";
	f->tamanio = 0;

	//borro el fragmento de memoria
	delete f;

	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	f = 0;
	
}
void setRuta(Foto *f, string ruta){
	f->ruta = ruta;
}
void setTipo(Foto *f, string tipo){
	f->tipo = tipo;
}
void setTamanio (Foto *f, unsigned long int tamanio){
    f->tamanio = tamanio;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada v_fotos.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param Foto *f		//Puntero de tipo Foto.
 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setV_Fotos(Usuario *u, Foto *f){
	    u->v_fotos = f;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada DIM_vfotos.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param int DIM_vfotos	//Dimensión de fotos que puede almacenar el usuario.
 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar el usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setDIM_vfotos(Usuario *u, int DIM_vfotos){
    u->DIM_vfotos = DIM_vfotos;   
}
/**
 * @brief Devuelve el puntero Ruta de una variable estructurada de tipo Foto.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getRuta(Foto *f){
    return f->ruta;
}
/**
 * @brief Devuelve el puntero Tipo de una variable estructurada de tipo Foto.
 * @param Foto *f		//Puntero de tipo foto.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getTipo(Foto *f){
    return f->tipo;
}
/**
 * @brief Devuelve el Tamanio de una variable estructurada de tipo Foto.
 * @param Foto *f		//Puntero de tipo foto.
 * @pre Está filtrada al usar unsigned int para no introducir números negativos.
 * @post Nos devuelve la variable edad de un tipo estructurado de alumno.
 * @version 1.0
 * @author Carlos Fdez.
 */
int long unsigned getTamanio (Foto *f){
    return f->tamanio;
}
/**
 * @brief Devuelve una posición del vector de fotos de un Usuario concreto.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
Foto getv_fotos(Usuario *u){
	return u->v_fotos[u->totalFotosUsuario];
}
/**
 * @brief Devuelve el puntero DIM_vfotos de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
int getDIM_vfotos(Usuario *u){
	return u->DIM_vfotos;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Módulo que me muestra las fotos tengo en el vector de fotos.
 * @param Foto *v_fotos
 * @pre El vector de fotos tiene que estar creado y tener por lo menos una foto.
 * @post Se mostrará el vector de fotos al usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printVectorFotos(Foto *v_fotos, Usuario *u ){

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
void ValoresFoto(Foto *f){

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
/**
 * @brief Imprime por pantalla la ruta de la foto junto a su tipo y el tamaño que ocupa la foto.
 * @param Foto *f
 * @post Imprimiremos la ruta de la foto por pantalla.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printFoto(Foto *f){

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

/**
 * @brief Módulo que inserta una foto en el vector de fotos de cada usuario.
 * @param TablaUsuarios tu (E/S)
 * @pre El usuario debe de estar insertado correctamente.
 * @post Se insertará una foto al usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void insertarFoto(TablaUsuarios &tu){

	string login = "";
	bool usado = false;
	int posicion=0;
	int cont = 0;
	
	
	cout << "Introduce su Login del usuario al que quieres introducir la fotografía : " << endl;
	cin >> login;
	
	//Comprobamos si el login existe o no.
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;	
		}
	}
	//Si existe el login --> usado == true y reservamos memória dinámica para la foto y el usuario y creamos sus puntero inicializandolo a 0;
	if(usado == true){
		Foto *f=0;
		f=crearFoto();
		Usuario *u = 0;
		
		u = tu.punteroapuntero[posicion];
		ValoresFoto(f);
		resizeAumentarFoto(tu.punteroapuntero[posicion],u->v_fotos);
		setTotalFotosUsuario(tu.punteroapuntero[posicion],getTotalFotosUsuario(u)+1);
		tu.punteroapuntero[posicion]->v_fotos[getTotalFotosUsuario(u)-1] = *f;
	}else{
		cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
		}
}
void resizeAumentarFoto(Usuario *u,Foto *v_fotos){
	
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
/**
 * @brief Este módulo se encarga de disminuir en uno la dimensión y las útiles de nuestro vector cuando lo llamemos.
 * @param Usuario *u
 * @param Foto *v_fotos
 * @post La dimensión del vector decrecerá en una posición.
 * @version 1.0
 * @author Carlos Fdez.
 */
void resizeDisFoto(Usuario *u,Foto *v_fotos){
	
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
