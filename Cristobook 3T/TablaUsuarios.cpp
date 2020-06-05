//
//	Vista.cpp
//
//	Created by Carlos Fdez
//	https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//

//*********	COLOR		*********//

#define DEFAULT "\033[1;0m"
#define GREY "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define ERROR "\033[1;41m"

//**************************************//
#include <iostream>
#include <stdlib.h>

#include "TablaUsuarios.h"
using namespace std;

///////////////////////////////				DEBUG					////////////////////////////////

void TablaUsuarios::setDEBUG(bool DEBUG){
	this->DEBUG = DEBUG;
}
bool TablaUsuarios::getDEBUG(){
	return this->DEBUG;
}

///////////////////////////////				TABLA USUARIOS					////////////////////////////////

TablaUsuarios::TablaUsuarios(){
	
	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO TABLAUSUARIOS    **** " << DEFAULT << endl;
	}
		// Inicializamos el contenido de la TablaUsuarios.
		
		//Inicializamos TotalTuplas a 0.
		this->setTotalTuplas(0);
		
		//Filtro para que las tuplas del vector no sea negativo, en caso de serlo abortará la ejecución.
		if (this->getTotalTuplas() < 0){
			cerr << "¡¡ERROR!! llas tuplas no pueden ser negativas." << endl;
			cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
			exit(-1);
		}
		
		//Reservamos un nuevo espacio para el vector de punteros que tiene dentro la variable estructurada TablaUsuario
		this->punteroapuntero = new Usuario*[this->TotalTuplas];
	
		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->punteroapuntero == 0){
			cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
			exit(-1);
		}
		
	if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha creado correctamente.\n" << DEFAULT ;
		cout << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
TablaUsuarios::~TablaUsuarios(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    ELIMANDO TABLAUSUARIOS    **** " << DEFAULT << endl;
	}	
		if (this->getTotalTuplas() >= 0){
			//Eliminamos el vector de punteros a Usuarios.
			for(int i=0; i <= this->getTotalTuplas(); i++){
				delete punteroapuntero[i];
				this->getTotalTuplas()-1;
			}
		
			//Ponemos los datos del usuario a 0 antes de eliminar el usuario.
			this->setTotalTuplas(0);

			//Borramos el vector dinámico de punteros a usuarios.
			delete [] punteroapuntero;
			
			//Eliminamos la dirección del punteroapuntero.
			punteroapuntero = 0;
			
		}else if (getTotalTuplas() < 0){
			cerr << RED << "No existe ninguna TablaUsuarios. " << endl;
	
		}
	if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha eliminado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
///////////////////////////////				 SET/GET					////////////////////////////////

void TablaUsuarios::setTotalTuplas(int TotalTuplas){
	this->TotalTuplas=TotalTuplas;
}
int TablaUsuarios::getTotalTuplas(){
	return this->TotalTuplas;
}

///////////////////////////////				 PREDEFINIDOS					////////////////////////////////

void TablaUsuarios::usuariosPredefinidos(){
	
	Foto *f = new Foto;
	
	/***************************************
	**************	CARLOS	****************
	****************************************/
	Admin *Carlos = new Admin;
	Carlos->setLogin("@Carlos");
	Carlos->setNombre("Carlos");
	Carlos->setApellido("Fernández");
	Carlos->setPerfilUsuario("Admin");
	this->insertarUsuarioTablaUsuarios(Carlos);

	/***************************************
	**************	JAIME	****************
	****************************************/
	Normal *Jaime = new Normal;
	Jaime->setLogin("@Jaime");
	Jaime->setNombre("Jaime");
	Jaime->setApellido("Cabezas");
	Jaime->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Jaime);
	//Foto1
	f->setRuta("/home/Jaime/Escritorio/Imagenes/Skone");
	f->setTipo("jpeg");
	f->setTamanio(49350);
	Jaime->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/Jaime/Escritorio/Imagenes/Force");
	f->setTipo("jpeg");
	f->setTamanio(49350);
	Jaime->insertarFotoUsuario(f);	
	
	/***************************************
	********	CRISTIAN	********
	****************************************/
	Admin *Cristian = new Admin;
	Cristian->setLogin("@Cristian");
	Cristian->setNombre("Cristian");
	Cristian->setApellido("Campos");
	Cristian->setPerfilUsuario("Admin");
	this->insertarUsuarioTablaUsuarios(Cristian);
	
	/***************************************
	**************	ADRIAN	****************
	****************************************/
	Normal *Adrian =  new Normal;
	Adrian->setLogin("@Adrian");
	Adrian->setNombre("Adrián");
	Adrian->setApellido("Castillo");
	Adrian->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Adrian);
	//Foto1
	f->setRuta("/home/Adrian/Escritorio/Imagenes/polvora");
	f->setTipo("gif");
	f->setTamanio(6050);
	Adrian->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/Adrian/Escritorio/Imagenes/Calamar");
	f->setTipo("bmp");
	f->setTamanio(125910);
	Adrian->insertarFotoUsuario(f);
	
	/***************************************
	**************	PABLO	****************
	****************************************/
	Admin *Pablo = new Admin;
	Pablo->setLogin("@Pablo");
	Pablo->setNombre("Pablo");
	Pablo->setApellido("García");
	Pablo->setPerfilUsuario("Admin");
	this->insertarUsuarioTablaUsuarios(Pablo);
	
	/***************************************
	**************	DAVID	****************
	****************************************/
	Normal *David = new Normal;
	David->setLogin("@David");
	David->setNombre("Antonio David");
	David->setApellido("López");
	David->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(David);
	//Foto1
	f->setRuta("/home/David/Escritorio/Imagenes/Semana-Santa-19");
	f->setTipo("gif");
	f->setTamanio(6050);
	David->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/David/Escritorio/Imagenes/Wallpaper_Camarón_4K");
	f->setTipo("jpeg");
	f->setTamanio(6050);
	David->insertarFotoUsuario(f);
	
	/***************************************
	**************	  ANA	****************
	****************************************/
	Normal *Ana = new Normal;
	Ana->setLogin("@Ana");
	Ana->setNombre("Ana");
	Ana->setApellido("Tallón");
	Ana->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Ana);
	//Foto1
	f->setRuta("/home/Ana/Escritorio/Imagenes/Amorsito");
	f->setTipo("jpeg");
	f->setTamanio(6050);
	Ana->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/Ana/Escritorio/Imagenes/Aguacatinhos");
	f->setTipo("png");
	f->setTamanio(8710);
	Ana->insertarFotoUsuario(f);
	
}
///////////////////////////////				 PRINT					////////////////////////////////

void TablaUsuarios::printTablaUsuarios(){

	for(int i = 0; i < this->getTotalTuplas(); i++){
		this->punteroapuntero[i]->printUsuario();
	}
}

///////////////////////////////				 RESIZE					////////////////////////////////

void TablaUsuarios::resize(int DIM){

	//Reservo memoria para el vector auxiliar con una DIM +1.
	Usuario** aux = new Usuario*[DIM+1];
	
	//Compruebo que hay memoria suficiente.
	if (aux == 0){
		cerr << "Error. No hay memoria suficiente para crear un nuevo vector. Se abortará la ejecución" << endl;
		exit(-1);
	}

	if( DIM > this->getTotalTuplas()){

		//Copio el contenido de punteroapuntero[i] en aux[i].
		for(int i = 0;i < this->getTotalTuplas();i++){
			aux[i] = this->punteroapuntero[i];
		}

	}else if (DIM < this->getTotalTuplas()){

		//Copio el contenido de punteroapuntero[i] en aux[i].
		for(int i = 0; i <= DIM; i++){
			aux[i] = this->punteroapuntero[i];
		}
	}
	
	//Eliminamos la memoria del vector coef.
	delete [] punteroapuntero;

	//Reasignamos el puntero de coeficientes.
	punteroapuntero = aux;

}

///////////////////////////////				 INSERT					////////////////////////////////

void TablaUsuarios::insertarUsuarioTablaUsuarios(Usuario *u){
	
	//Aumentamos la dimensión en una posición.
	this->resize(getTotalTuplas()+1);
	//Insertamos el usuario en la nueva posición-
	this->punteroapuntero[this->getTotalTuplas()] = u;
	//Actualizamos las TotalTuplas.
	this->setTotalTuplas(this->getTotalTuplas()+1);
}
/**
 * @brief Módulo que se encarga de comprobar el login de un usuario para saber si está usado o no.
 * @param string Login.
 * @param Usuario *u.
 * @param bool usado.
 * @pre La TablaUsuarios debberá de tener al menos un usuario ingresado
 * @post Sabremos si el login introducido está usado o no.
 * @version 1.0
 * @author Carlos Fdez.
 */
void comprobacionLogin(string Login,Usuario *u,bool &usado){

	//Comprobamos si el login está introducido o no. Si lo está devolveremos usado = true;(Lo hacemos aparte porque lo usaremos en varios sitios).
	if(Login == u->getLogin()){
		usado = true;
	}
}
void TablaUsuarios::eliminarUsuarioTablaUsuarios(){

	//Declaración de variables locales.
	string Login = "";
	bool usado = false;
	unsigned int posicion = 0;
	int cont = 0;
	//Usuario *u;
	
	//Imprimimos la tabla de Usuarios
	for(int i = 0; i < this->getTotalTuplas(); i++){
		this->punteroapuntero[i]->printUsuario();
	}
	
	//Pedimos al usuario el login (que es único en el sistema) para eliminarlo.
	cout << YELLOW << "Selecione el usuario que desea eliminar, recuerde que tiene que introducir el login" << DEFAULT << endl;
	cin >> Login;
	
	//Comprobar que el usuario existe.
	for(int i = 0; i < this->getTotalTuplas();i++){
		comprobacionLogin(Login,this->punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;	
		}
	}
	
	//Si usado==true, el usuario existe y podemos eliminarlo.
	if(usado == true){
		//Creamos un Usuario aux para hacer el intercambio.
		Usuario* aux = new Usuario;
		
		//Realizamos el intercambio de posiciones.
		aux = this->punteroapuntero[posicion];
		this->punteroapuntero[posicion] = this->punteroapuntero[this->getTotalTuplas()-1];
		this->punteroapuntero[this->getTotalTuplas()-1] = aux;
		
		//Borramos usuario en la última posición
		delete this->punteroapuntero[this->getTotalTuplas()-1];
		
		//Disminuimos el tamaño del vector.
		this->resize(this->getTotalTuplas()-1);
		//this->punteroapuntero = resizeDisminuirPorPunteros(tu,t->punteroapuntero);
		this->setTotalTuplas(this->getTotalTuplas()-1);
		
		//Imprimimos el vector de usuario para que el administrador vea que se ha borrado correctamente.
		this->printTablaUsuarios();
	}else{
		cout << ERROR << "El Login que usted ha elegido no se encuentra en nuestra tabla de usuarios. " << DEFAULT << endl;
		}
}
/**
 * @brief Módulo que se encarga de pedir algunos datos al usuario. 
 * @param Usuario *u
 * @pre El módulo insertarUsuarioNuevo debe de estar introducido correctamente.
 * @version 1.0
 * @author Carlos Fdez.
 */
void pedirDatosUsuario(Usuario *u){
	
	string nombre = "";
	string apellido = "";
	string perfilUsuario = "";

	cout << YELLOW << "Nombre: " << DEFAULT << endl;
	cin >> nombre;
	cout << YELLOW << "Apellido: " << DEFAULT << endl;
	cin >> apellido;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT  << endl;
	cin >> perfilUsuario;
	
	u->setNombre(nombre);
	u->setApellido(apellido);
	u->setPerfilUsuario(perfilUsuario);

}
void TablaUsuarios::insertarUsuarioNuevo(){

	string Login = "";
	bool usado = false;
		
	
	//Pedimos al usuario los datos.
	cout << "Por favor ingrese los siguientes datos: " << endl;
	cout << YELLOW << "Login : " << DEFAULT << endl;
	cin >> Login;
	
	//Comprobar que el usuario existe.
	for(int i = 0; i < this->getTotalTuplas();i++){
		comprobacionLogin(Login,this->punteroapuntero[i],usado);
		}
	
	//Si el usuario no existe entramos en este if y creamos Usuario y lo insertamos en la TablaUsuarios.
	if(usado != true){
		
		//Reservamos el espacio de memmoria al nuevo Usuario.
		Usuario *u = new Usuario;
		u->setLogin(Login);
		pedirDatosUsuario(u);
		this->insertarUsuarioTablaUsuarios(u);
	}else{
		cout << RED << "El Login introducido ya está en uso." << DEFAULT << endl;
		}
}
void TablaUsuarios::BuscarLogin(){

	bool usado=false;
	string Login = "";
	unsigned int posicion=0;
	int cont=0;

	//Pedimos al administrador que indique el Login que quiere buscar.
	cout << "Por favor introduzca el login del usuario que quiere conocer su posición. " << endl;
	cin >> Login;
	
	//Comprobar que el usuario existe.
	for(int i = 0; i < this->getTotalTuplas();i++){
		comprobacionLogin(Login,this->punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;	
		}
	}
	
	//Si existe el usuario entramos en el if e imprimimos el Usuario, si no existe mostramos un mensaje por pantalla.
	if(usado == true){
		//Mostramos la posición dónde está el usuario.
		cout << BLUE << "El usuario se encuentra en la posición: " << DEFAULT << posicion << endl;
		this->punteroapuntero[posicion]->printUsuario();
	}else{
		cout << ERROR << "El Login que usted ha elegido no se encuentra en nuestra tabla de usuarios. " << DEFAULT << endl;
	}
}
void TablaUsuarios::ordenamosLogin(){

	Usuario *aux = 0;
	
	if (this->getTotalTuplas() > 1){
		for(int i = 0;i < this->getTotalTuplas();i++){
			for(int j= 0; j < this->getTotalTuplas();j++){
				if(this->punteroapuntero[i]-> getLogin() < this->punteroapuntero[j]->getLogin() ){
					aux = this->punteroapuntero[i];
					this->punteroapuntero[i] = this->punteroapuntero[j];
					this->punteroapuntero[j]= aux;
				}
			}
		}
	}else{
		cout << RED << "Lo sentimos, todavía no podemos ordenar porque no hay los usuarios suficientes " << DEFAULT << endl;
		}
}
void TablaUsuarios::ordenamosTotalFotosUsuario(){

	Usuario *aux = 0;
	
	//Filtro desde uno porque al crear la tabla de usuarios se introducen 7 usuarios predefinidos por lo que TotalTuplas = 7.
	if (this->getTotalTuplas() > 1){
		for(int i = 0;i < this->getTotalTuplas();i++){
			for(int j= 0; j < this->getTotalTuplas();j++){
			//	if(this->punteroapuntero[i]-> getTotalFotosUsuario() < this->punteroapuntero[j]-> getTotalFotosUsuario() ){
					aux = this->punteroapuntero[i];
					this->punteroapuntero[i] = this->punteroapuntero[j];
					this->punteroapuntero[j]= aux;
				}
			//}
		}
	}else{
		cout << RED << "Lo sentimos, todavía no podemos ordenar porque no hay los usuarios suficientes " << DEFAULT << endl;
		}
}
void TablaUsuarios::ordenarTablaUsuarios(){

	//Declaración de variables
	int opcion = 0;
	int buscar = 0;
	
	//Submenú ordenar.
	cout << BLUE << "\n******************************";
	cout << BLUE << "\n[1] " << DEFAULT << "Ordenar por Login ";
	cout << BLUE << "\n[2] " << DEFAULT << "Ordenar por el total fotos. ";
	cout << BLUE << "\n******************************" << DEFAULT << endl;
	cout << "Seleccione el criterio por el que quiere ordenar: " << endl;
	cin >> opcion;
	
	//Dependiendo de la opción que desee el usuario entrará en la opcion 1 o 2, en caso contrario mostraremos un mensaje de error.
	if(opcion == 1){
		cout  << " ****    ORDENANDO TABLA DE USUARIOS POR LOGIN    **** " << endl;
		ordenamosLogin();
		cout << GREEN << "La TablaUsuarios se ha ordenado correctamente." << DEFAULT << endl;
		cout << GREEN << "Para Imprimir la Tabla pulse [1] sino presione [0]." << DEFAULT << endl;
		cin >> buscar;
			if(buscar == 1){
				printTablaUsuarios();
			}else if (buscar == 0){
				cout << GREEN << "Muchas gracias." << DEFAULT << endl;
			}
	}
	else if(opcion == 2){
		cout  << " ****    ORDENANDO TABLA DE USUARIOS POR TOTAL FOTOS USUARIO    **** " << endl;
		ordenamosTotalFotosUsuario();
		cout << GREEN << "La TablaUsuarios se ha ordenado correctamente." << DEFAULT << endl;
		cout << GREEN << "Para Imprimir la Tabla pulse [1] sino presione [0]." << DEFAULT << endl;
		cin >> buscar;
			if(buscar == 1){
				printTablaUsuarios();
			}else if (buscar == 0){
				cout << GREEN << "Muchas gracias." << DEFAULT << endl;
			}
	}else{
		cout << YELLOW << "\nLo siento, la opción seleccionada no ha sido añadida todavía. " << DEFAULT << endl;
	}
}
/*void TablaUsuarios::eliminarUsuariosFotosMin(){

	int posicion = 0;
	int min = 0;
	Normal *n = new Normal;

	//1) Imprimimos la TablaUsuarios.
	this->printTablaUsuarios();
	
	//2)Pedimos al usuario el número de fotos mínimas que desea eliminar.
	cout << BLUE << "\n Por favor indique el número de fotos mínimas que tiene que tener un usuario para eliminarlo: " << DEFAULT << endl;
	cin >> min;
	
	n->setFotosMin(min);
	
	//3)Buscamos los usuarios que tengan al menos esas fotos.
	for (int i = 0; i < this->getTotalTuplas(); i++){
		if (this->punteroapuntero[i]->getTotalFotosUsuario() < n->getFotosMin()){
			posicion=i;
			Usuario *aux = new Usuario;
		
			//Realizamos el intercambio de posiciones.
			aux = this->punteroapuntero[posicion];
			this->punteroapuntero[posicion] = this->punteroapuntero[this->getTotalTuplas()-1];
			this->punteroapuntero[this->getTotalTuplas()-1] = aux;
			
			//Borramos usuario en la última posición
			delete this->punteroapuntero[this->getTotalTuplas()-1];

			//Disminuimos el tamaño del vector.
			this->resize(this->getTotalTuplas()-1);
			this->setTotalTuplas(this->getTotalTuplas()-1);
		}
	}

		//Imprimimos el vector de usuario para que el administrador vea que se ha borrado correctamente.
			this->printTablaUsuarios();

}*/

///////////////////////////////				 TESTING					////////////////////////////////
void TablaUsuarios::TestingAutomatico(){

	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	this->printTablaUsuarios();
	cout  << CYAN << " ****    ORDENANDO TABLA DE USUARIOS POR LOGIN    **** " << DEFAULT << endl;
	this->ordenamosLogin();
	cout  << YELLOW << " Ordenando... " << DEFAULT << endl;
	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	this->printTablaUsuarios();
	/*cout  << CYAN << " ****    INSERTANDO FOTOS A CADA USUARIOS    **** " << DEFAULT << endl;
	for(int i=0; i < getTotalTuplas(tu); i++){
		this->insertarFoto();
	}*/
	cout  << PURPLE << " ****    ELIMINANDO USUARIOS    **** " << DEFAULT << endl;
	for(int j=0; j < 7; j++){
		this->eliminarUsuarioTablaUsuarios();
	}

}

void TablaUsuarios::Testing(){

	int opcion = 0;

	while(opcion!=5){
		cout << BLUE << " ****************************** "<< DEFAULT << endl;
		cout << BLUE << " *****    MENÚ TESTING    ***** " << DEFAULT << endl;
		cout << BLUE << " ****************************** "<< DEFAULT << endl;
		cout << BLUE << "[1] " << DEFAULT << " Insertar 3 Usuarios en TablaUsuarios. "<< DEFAULT << endl;
		cout << BLUE << "[2] " << DEFAULT << " Eliminar 5 Usuarios de TablaUsuarios. "<< DEFAULT << endl;
		cout << BLUE << "[3] " << DEFAULT << " Insertar 2 Usuarios en TablaUsuarios. "<< DEFAULT << endl;
		cout << BLUE << "[4] " << DEFAULT << " Testing automátizado. "<< DEFAULT << endl;
		cout << BLUE << "[5] " << DEFAULT << " Salir. "<< DEFAULT << endl;
		cout << BLUE << " ****************************** " << DEFAULT << endl;
		
		//Pedimos al usuario que escoga una opción de las mostradas previamente.
		cout << "\nEliga usted el Testing que desea ejecutar: " << endl;
		cin >> opcion;

		switch (opcion){

			case 1:	
				// 1º) Insetamos tres usuarios
				for(int j=0; j < 3; j++){
					this->insertarUsuarioNuevo();
				}
			break;
			
			case 2:	
				// 2º) Eliminamos cinco usuario
				for(int k=0; k < 5; k++){
					this->eliminarUsuarioTablaUsuarios();	
				}
			break;
			
			case 3:	
				// 3º) Insertamos dos usuarios
				for(int l=0; l < 2; l++){
					this->insertarUsuarioNuevo();
				}
			break;
			
			case 4:	
				// 4º)Testing automátizado
				 TestingAutomatico();
			break;
			
			case 5:	
				// 5º) Salir
				cout << " Saliendo del Testing " << endl;
			break;
	
			default:
				cout << BLUE << "Lo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
				cout << BLUE << "Por favor seleccione otra o pulse 14 para salir. \n" << DEFAULT << endl;
			}
	}
}

///////////////////////////////				 EXIT					////////////////////////////////

void TablaUsuarios::Salir(){

	//this->TablaUsuarios();
	//this->~TablaUsuarios();
	
}
