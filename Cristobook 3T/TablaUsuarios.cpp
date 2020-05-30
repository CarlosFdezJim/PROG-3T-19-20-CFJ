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

///////////////////////////////				TABLA USUARIOS					////////////////////////////////

TablaUsuarios::TablaUsuarios(){
	
	//if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO TABLAUSUARIOS    **** " << DEFAULT << endl;
	//}
		//Inicializamos el contenido de la TablaUsuarios.
		this->TotalTuplas = 0;
		
		//Reservamos un nuevo espacio para el vector de punteros que tiene dentro la variable estructurada TablaUsuario
		this->punteroapuntero = new Usuario*[this->TotalTuplas];
	
		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->punteroapuntero == 0){
			cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
			exit(-1);
		}
		
	//if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	//}
}
TablaUsuarios::~TablaUsuarios(){

	//if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    ELIMANDO TABLAUSUARIOS    **** " << DEFAULT << endl;
	//}	
		if (getTotalTuplas() > 0){
			//Eliminamos el vector de punteros a Usuarios.
			for(int i=0; i <= this->getTotalTuplas(); i++){
				delete punteroapuntero[i];
				this->getTotalTuplas()-1;
			}
		
			//Ponemos los datos del usuario a 0 antes de eliminar el usuario.
			this->setTotalTuplas(0);

			//Borramos el vector dinámico de coeficientes.
			delete [] punteroapuntero;
			punteroapuntero = 0;
		}else if (getTotalTuplas() < 0){
			cerr << RED << "No existe ninguna TablaUsuarios. " << endl;
	
		}
	//if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha eliminado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	//}
}
void TablaUsuarios::setTotalTuplas(int TotalTuplas){
	this->TotalTuplas=TotalTuplas;
}
int TablaUsuarios::getTotalTuplas(){
	return this->TotalTuplas;
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

///////////////////////////////				 OTHER					////////////////////////////////

void TablaUsuarios::insertarUsuarioTablaUsuarios(Usuario *u){
	
	//Aumentamos la dimensión en una posición.
	this->resize(getTotalTuplas()+1);
	//Insertamos el usuario en la nueva posición-
	this->punteroapuntero[this->getTotalTuplas()] = u;
	//Actualizamos las TotalTuplas.
	this->setTotalTuplas(this->getTotalTuplas()+1);
}

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
	Usuario *u;
	
	//Imprimimos la tabla de Usuarios
	for(int i = 0; i < this->getTotalTuplas(); i++){
		this->punteroapuntero[i]->printUsuario();
	}
	//Pedimos al usuario el login (que es único en el sistema) para eliminarlo.
	cout << "Selecione el usuario que desea eliminar, recuerde que tiene que introducir el login" << endl;
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
	cout << "\n[1] Ordenar por Login ";
	cout << "\n[2] Ordenar por el total fotos. ";
	cout << "\n******************************" << DEFAULT << endl;
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

void TablaUsuarios::usuariosPredefinidos(){
		
	/***************************************
	**************	CARLOS	****************
	****************************************/
	Usuario *Carlos = new Usuario;
	Carlos->setLogin("@Carlos");
	Carlos->setNombre("Carlos");
	Carlos->setApellido("Fernández");
	Carlos->setPerfilUsuario("Admin");
	this->insertarUsuarioTablaUsuarios(Carlos);
	//Foto1
	Foto *f= new Foto;
	f->setRuta("/home/Carlos/Escritorio/Imagenes/Españita");
	f->setTipo("jpeg");
	f->setTamanio(49350);
	//Carlos->insertarFotoUsuario(f);
/*	//Foto2
	f->setRuta("/home/Carlos/Escritorio/Imagenes/esto_es_ESPANIAAAAAA");
	f->setTipo("gif");
	f->setTamanio(6050);
	Normal::insertarFotoUsuario(f);

	
	/***************************************
	**************	JAIME	****************
	****************************************/
	Usuario *Jaime = new Usuario;
	Jaime->setLogin("@Jaime");
	Jaime->setNombre("Jaime");
	Jaime->setApellido("Cabezas");
	Jaime->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Jaime);
/*	//Foto1
	Jaime->setRuta("/home/Jaime/Escritorio/Imagenes/Skone");
	Jaime->setTipo("jpeg");
	Jaime->setTamanio(49350);
	this->insertarFotoUsuario(Jaime);
	//Foto2
	Jaime->setRuta("/home/Jaime/Escritorio/Imagenes/Force");
	Jaime->setTipo("jpeg");
	Jaime->setTamanio(49350);
	this->insertarFotoUsuario(Jaime);	

	
	/***************************************
	********	CRISTIAN	********
	****************************************/
	Usuario *Cristian = new Usuario;
	Cristian->setLogin("@Cristian");
	Cristian->setNombre("Cristian");
	Cristian->setApellido("Campos");
	Cristian->setPerfilUsuario("Administrador");
	this->insertarUsuarioTablaUsuarios(Cristian);
/*	//Foto1
	Cristian->setRuta(f, "/home/Cristian/Escritorio/Imagenes/fackposlisia");
	Cristian->setTipo(f,"jpeg");
	Cristian->setTamanio(f,49350);
	this->insertarFotoUsuario(Cristian, f);
	//Foto2
	Cristian->setRuta(f, "/home/Cristian/Escritorio/Imagenes/LoKo_ReShUlOn");
	Cristian->setTipo("jpeg");
	Cristian->setTamanio(49350);
	this->insertarFotoUsuario(Cristian);

	
	/***************************************
	**************	ADRIAN	****************
	****************************************/
	Usuario *Adrian =  new Usuario;
	Adrian->setLogin("@Adrian");
	Adrian->setNombre("Adrián");
	Adrian->setApellido("Castillo");
	Adrian->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Adrian);
/*	//Foto1
	Adrian->setRuta("/home/Adrian/Escritorio/Imagenes/polvora");
	Adrian->setTipo("gif");
	Adrian->setTamanio(6050);
	this->insertarFotoUsuario(Adrian);
	//Foto2
	Adrian->setRuta("/home/Adrian/Escritorio/Imagenes/Calamar");
	Adrian->setTipo("bmp");
	Adrian->setTamanio(125910);
	this->insertarFotoUsuario(Adrian);

	
	/***************************************
	**************	JESUS	****************
	****************************************/
	Usuario *David = new Usuario;
	David->setLogin("@David");
	David->setNombre("Antonio David");
	David->setApellido("López");
	David->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(David);
/*	//Foto1
	David->setRuta("/home/David/Escritorio/Imagenes/Semana-Santa-19");
	David->setTipo("gif");
	David->setTamanio(6050);
	this->insertarFotoUsuario(David);
	//Foto2
	David->setRuta("/home/Jesus/Escritorio/Imagenes/Wallpaper_Camarón_4K");
	David->setTipo("jpeg");
	David->setTamanio(6050);
	this->insertarFotoUsuario(David);

	
	/***************************************
	**************	PABLO	****************
	****************************************/
	Usuario *Pablo = new Usuario;
	Pablo->setLogin("@Pablo");
	Pablo->setNombre("Pablo");
	Pablo->setApellido("García");
	Pablo->setPerfilUsuario("Administrador");
	this->insertarUsuarioTablaUsuarios(Pablo);
/*	//Foto1
	Pablo->setRuta("/home/Pablo/Escritorio/Imagenes/gente_seria");
	Pablo->setTipo("jpeg");
	Pablo->setTamanio(6050);
	insertarFotoUsuario(Pablo);
	//Foto2
	Pablo->setRuta("/home/Pablo/Escritorio/Imagenes/mas_gente_seria_4k");
	Pablo->setTipo("jpeg");
	Pablo->setTamanio(6050);
	this->insertarFotoUsuario(Pablo);

	
	/***************************************
	**************	  ANA	****************
	****************************************/
	Usuario *Ana = new Usuario;
	Ana->setLogin("@Ana");
	Ana->setNombre("Ana");
	Ana->setApellido("Tallón");
	Ana->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Ana);
/*	//Foto1
	Ana->setRuta("/home/Ana/Escritorio/Imagenes/Amorsito");
	Ana->setTipo("jpeg");
	Ana->setTamanio(6050);
	Ana->insertarFotoUsuario(Ana);
	//Foto2
	Ana->setRuta("/home/Ana/Escritorio/Imagenes/Aguacatinhos");
	Ana->setTipo("png");
	Ana->setTamanio(8710);
	insertarFotoUsuario(Ana);
*/	
}
/*void TablaUsuarios::Salir(){
	
}*/
