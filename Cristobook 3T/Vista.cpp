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
#define BLACK "\033[0;30m"

//**************************************//
#include <iostream>
#include <stdlib.h>

#include "Vista.h"
using namespace std;


///////////////////////////////				DEBUG					////////////////////////////////

void Vista::setDEBUG(bool DEBUG){
	this->DEBUG = DEBUG;
}
bool Vista::getDEBUG(){
	return this->DEBUG;
}
void Vista::modoDEBUG(bool DEBUG){

	if(this->getDEBUG()==false){
		this->setDEBUG(true);
		tu->setDEBUG(DEBUG);
		cout << ERROR << "MODO DEBUG ACTIVADO" << DEFAULT << endl;
	}else{
		this->setDEBUG(false);
		tu->setDEBUG(DEBUG);
		cout << ERROR << "MODO DEBUG DESACTIVADO" << DEFAULT << endl;
	}
	
	tu->modoDEBUG(DEBUG);

}
///////////////////////////////				VISTA					////////////////////////////////

Vista::Vista(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO VISTA    **** " << DEFAULT << endl;
	}
	
		//Crearemos la TablaUsuarios en el método Vista.
		this->tu = new TablaUsuarios();

	if(this->getDEBUG() == true){
		cout << GREEN << "El modo Vista se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}

}
Vista::Vista(int TotalTuplas){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO VISTA CON PARÁMETROS    **** " << DEFAULT << endl;
	}
	
		//Crearemos la TablaUsuarios en el método Vista.
		this->tu = new TablaUsuarios(TotalTuplas);
		
	if(this->getDEBUG() == true){
		cout << GREEN << "El modo Vista se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}

}
Vista::~Vista(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    DESTRUYENDO VISTA    **** " << DEFAULT << endl;
	}
	
		//Ponemos a 0 las TotalTuplas de TablaUsuarios.
		tu->setTotalTuplas(0);

		//Llamamos al destructor de TablaUsuarios.
		tu->~TablaUsuarios();
		
	if(this->getDEBUG() == true){
		cout << GREEN << "El modo Vista se ha eliminado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}

}

///////////////////////////////				PASS					////////////////////////////////

void Vista::credentials(){

	string pass = "";
	string contrasena = "";
	bool usado = false;

	//Pedimos al usuario el login y lo comprobamos.
	cout << endl;
	cout << PURPLE << "Login : " << DEFAULT << endl;
	cin >> pass;

	//Comprobamos que el Login y contraseña existe en nuestra base de datos.
	tu->credentials(pass, contrasena, usado);
	
	//Entra aquí si el Login coincide con lo que tenemos en nuestra base de datos.
	if(usado == true){
		//Si el usuario existe le pedimos la contraseña.
		cout << PURPLE << "Password : " << BLACK << endl;
		cin >> contrasena;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
		menuVista();
	}else{
		cout << RED << "Este usuario no se encuentra en nuestra base de datos o no es de tipo Administrador. " << DEFAULT << endl;
	}

}

///////////////////////////////				----					////////////////////////////////

void Vista::comprobacionLogin(string &Login, int &posicion, bool &usado){

	//Pedimos al usuario el login (que es único en el sistema).
	cout << BLUE << "Selecione el Login del Usuario: " << DEFAULT << endl;
	cin >> Login;
	
	//Comprobamos que el Login existe en nuestra base de datos.
	tu->comprobacionLoginTU(Login, usado, posicion);
		
	if (usado == true){ 
		cout << GREEN << "El Login está en nuestra base de datos" << DEFAULT << endl;
	}else if(usado == false){
		cout << RED << "El login no se encuentra en nuestra base de datos" << DEFAULT << endl;
	}

}
void Vista::printcheck(){

	int opcion = 0;
	
	cout << GREEN << "Para Imprimir la Tabla pulse [1] sino presione [0]." << DEFAULT << endl;
	cin >> opcion;
	
	if(opcion == 1){
		tu->printTablaUsuarios();
	}else if (opcion == 0){
		cout << GREEN << "Muchas gracias." << DEFAULT << endl;
	}else{
		cout << YELLOW << "\nLo siento, la opción seleccionada no ha sido añadida todavía. " << DEFAULT << endl;
	}

}
void Vista::insertUser(){

	//Declaración de variables.
	string Login = "";
	bool usado = false;
	int posicion = 0;
	int opcion = 0;
		
	//Comprobamos que el usuario existe y devolvemos la posición dónde se encuentra.
	this->comprobacionLogin(Login, posicion, usado);
	
	//Si el usuario no existe entramos en este if y creamos Usuario (Normal/Admin) y lo insertamos en la TablaUsuarios.
	if(usado != true){
		//Elegimos que tipo de usuario queremos crear.
		cout << GREEN << "¿Que tipo de Usuario desea insertar? " << DEFAULT << endl;
		cout << "[1] Normal " << endl;
		cout << "[2] Admin " << endl;
		cin >> opcion;
		cout << " *********************************** " << endl;
		
		//Creamos el usuario y lo introducimos en la TablaUsuarios
		tu->crearUsuario(Login, usado, posicion, opcion);
	}else{
		cout << RED << "Lo sentimos, el Login introducido ya está en uso." << DEFAULT << endl;
	}
	
	//Preguntamos al usuario si quiere o no imprimir la TablaUsuarios.
	this->printcheck();
}
void Vista::deleteUser(){

	//Declaración de variables.
	string Login = "";
	bool usado = false;
	int posicion = 0;
	int opcion = 0;

	//Comprobamos que el usuario existe y devolvemos la posición dónde se encuentra.
	this->comprobacionLogin(Login, posicion, usado);
	
	if (tu->getTotalTuplas() >= 0){
		//Eliminamos el usuario indicado de la TablaUsuarios
		tu->eliminarUsuarioTablaUsuarios(posicion,usado);
	}else cout << "DEBUG" ;
	//Preguntamos al usuario si quiere o no imprimir la TablaUsuarios.
	this->printcheck();

}
void Vista::searchUser(){

	//Declaración de variables.
	string Login = "";
	bool usado = false;
	int posicion = 0;
	int opcion = 0;
	
	//Comprobamos que el usuario existe y devolvemos la posición dónde se encuentra.
	this->comprobacionLogin(Login, posicion, usado);

	//Buscaremos el usuario y lo imprimimos por pantalla.
	tu->BuscarLogin(usado, posicion);

}
void Vista::sortTable(){

	//Declaración de variables
	int opcion = 0;

	cout << BLUE << "\n******************************";
	cout << BLUE << "\n[1] " << DEFAULT << "Ordenar por Login ";
	cout << BLUE << "\n[2] " << DEFAULT << "Ordenar por el TotalFotos. ";
	cout << BLUE << "\n******************************" << DEFAULT << endl;

	cout << "Seleccione el criterio por el que quiere ordenar: " << endl;
	cin >> opcion;
	
	//Dependiendo de la opción que desee el usuario entrará en la opcion 1 o 2, en caso contrario mostraremos un mensaje de error.
	if(opcion == 1){
		cout  << GREEN << " ****    ORDENANDO TABLA DE USUARIOS POR LOGIN    **** " << DEFAULT << endl;
		tu->ordenamosLogin();
	}
	else if(opcion == 2){
		cout  << GREEN << " ****    ORDENANDO TABLA DE USUARIOS POR TOTAL FOTOS USUARIO    **** " << DEFAULT << endl;
		tu->ordenamosTotalFotosUsuario();
	}else{
		cout << YELLOW << "\nLo siento, la opción seleccionada no ha sido añadida todavía. " << DEFAULT << endl;
	}

	//Preguntamos al usuario si quiere o no imprimir la TablaUsuarios.
	this->printcheck();

}
/*void Vista::dataPhoto(string ruta, string tipo){

	string ruta = "";
	string tipo = "";

	cout << BLUE << "* * * * * * * * * * * * * * * * * * * " << DEFAULT << endl;
	cout << YELLOW << "Por favor ingresa la ruta de la foto. " << DEFAULT << endl;
	cin >> ruta;
	
	cout << YELLOW << "Por favor ingresa el formato de la foto. " << DEFAULT << endl;
	cout << YELLOW << "Le indico los tipos compatibles [bmp] [jpeg] [png] [gif] " << DEFAULT << endl ;
	cin >> tipo;
	
	tu->ValoresFoto(ruta, tipo)
	cout << BLUE << "* * * * * * * * * * * * * * * * * * * " << DEFAULT << endl;
	
}*/
void Vista::insertPhoto(){

	//Declaración de variables.
	string Login = "";
	bool usado = false;
	int posicion = 0;
	int opcion = 0;
	
	tu->printTablaUsuarios();
	this->comprobacionLogin(Login, posicion, usado);
	tu->insertarFoto(posicion, usado);
}
void Vista::deletePhoto(){

	//Declaración de variables.
	string Login = "";
	bool usado = false;
	int posicion = 0;
	int elim = 0;
	
	tu->printTablaUsuarios();
	cout << BLUE << "\n*****************************************" << DEFAULT << endl;
	//Comprobamos que el usuario existe y devolvemos la posición dónde se encuentra.
	this->comprobacionLogin(Login, posicion, usado);
	
	//Imprimimos el Usuario para saber la cantidad de fotos que tiene.
	tu->printUser(posicion);
	
	if(usado == true){
		//Pedimos al usuario el número de fotografía que queremos eliminar.
		cout << "Introduce la posición que quieres eliminar : " << endl;
		cin >> elim;
		tu->eliminarFotoUsuario(posicion, usado, elim);
		tu->printFotosUsuario(usado,posicion);
	}else{
		cout << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
	}
}
void Vista::printPhotoUser(){

	//Declaración de variables
	string Login = "";
	bool usado = false;
	int posicion = 0;
	
	//Comprobamos que el usuario existe y devolvemos la posición dónde se encuentra.
	this->comprobacionLogin(Login, posicion, usado);
	
	//Imprimos el usuario que le indiquemos.
	tu->printFotosUsuario(usado, posicion);

}
void Vista::deleteUserPhotoMin(){

	//Declaración de variables
	string Login = "";
	bool usado = false;
	int posicion = 0;
	int min = 0;

	//Pedimos al usuario el número de fotos mínimas necesario para eliminar el resto de usuarios.
	cout << BLUE << "Por favor indique el número de fotos mínimas que tiene que tener un usuario para eliminarlo: " << DEFAULT << endl;
	cin >> min;

	//Eliminamos los usuario que tengan menos de "min" fotos.
	tu->eliminarUsuariosFotosMin(min);
	
	//Imprimimos la TablaUsuarios.
	tu->printTablaUsuarios();

}

///////////////////////////////				 TESTING					////////////////////////////////

void Vista::TestingAutomatico(){

	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	tu->printTablaUsuarios();
	cout  << CYAN << " ****    ORDENANDO TABLA DE USUARIOS POR LOGIN    **** " << DEFAULT << endl;
	tu->ordenamosLogin();
	cout  << PURPLE << " ****    ELIMINANDO DOS USUARIOS    **** " << DEFAULT << endl;
	for(int i = 0; i < 2; i++){
		tu->eliminarUsuario(i);
	}
	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	tu->printTablaUsuarios();
	cout  << CYAN << " ****    INSERTANDO FOTOS A CADA USUARIOS    **** " << DEFAULT << endl;
	this->insertPhoto();

}
void Vista::TestingAutomatico2(){

	cout  << CYAN << " ****    ELIMINAR TABLA DE USUARIOS    **** " << DEFAULT << endl;	
	tu->~TablaUsuarios();
	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;	
	tu->printTablaUsuarios();
	cout  << CYAN << " ****    CREAR TRES USUARIO    **** " << DEFAULT << endl;
	for(int i = 0; i < 2; i++){
		this->insertUser();
	}
	cout  << CYAN << " ****    ELIMINO USUARIO    **** " << DEFAULT << endl;
	this->deleteUser();
	cout  << CYAN << " ****    BUSCAR USUARIO POR LOGIN    **** " << DEFAULT << endl;
	this->searchUser();
	cout << CYAN << " ****    ORDENANDO TABLA    **** " << DEFAULT << endl;	
	tu->ordenamosLogin();
	cout  << CYAN << " ****    INSERTANDO FOTO DE UN USUARIOS    **** " << DEFAULT << endl;
	this->insertPhoto();
	cout  << CYAN << " ****    ELIMINAR FOTO DE UN USUARIOS    **** " << DEFAULT << endl;
	this->deletePhoto();
	cout  << CYAN << " ****    IMPRIMIR FOTO DE UN USUARIOS    **** " << DEFAULT << endl;
	this->printPhotoUser();
}
void Vista::MenuTesting(){

	int opcion = 0;

	while(opcion!=4){
		cout << BLUE << " ****************************** "<< DEFAULT << endl;
		cout << BLUE << " *****    MENÚ TESTING    ***** " << DEFAULT << endl;
		cout << BLUE << "[1] " << DEFAULT << " Testing automatizado. "<< DEFAULT << endl;
		cout << BLUE << "[2] " << DEFAULT << " Testing automatizado 2. "<< DEFAULT << endl;
		cout << BLUE << "[3] " << DEFAULT << " Salir. "<< DEFAULT << endl;
		cout << BLUE << " ****************************** " << DEFAULT << endl;
		
		//Pedimos al usuario que escoga una opción de las mostradas previamente.
		cout << BLUE "\nIndica el Testing que desea ejecutar: " << DEFAULT << endl;
		cin >> opcion;

		switch (opcion){

			case 1:	
				// 1º) Testing automátizado
				 this->TestingAutomatico();
			break;
			
			case 2:	
				// 2º) Testing automátizado 2
				this->TestingAutomatico2();
			break;
			
			case 3:	
				// 3º) Salir
				cout << "Saliendo del Menú de Testing... " << endl;
				cout << "Continuaremos en el menú principal. " << endl;
			break;
	
			default:
				cout << BLUE << "Lo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
				cout << BLUE << "Por favor seleccione otra o pulse 6 para salir. \n" << DEFAULT << endl;
			}
	}
}
///////////////////////////////				 EXIT					////////////////////////////////

void Vista::exit(){

	
}

///////////////////////////////				MENU					////////////////////////////////

/**
 * @brief Muestra en el menú las opciones creadas en este módulo.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printMenu(){

	cout << BLUE <<"/***************************************"<< endl;
		cout << "****	     CRISTOBOOK	    ****" << endl;
		cout << "****************************************/" << DEFAULT;
	cout << BLUE <<  "\nAquí le mostramos las opciones disponibles para realizar en la clase Vista : " << DEFAULT;
	cout << BLUE <<  "\n[  1 ] " << DEFAULT << " Modo DEBUG. ";
	cout << BLUE <<  "\n[  2 ] " << DEFAULT << " Testing. ";
	cout << BLUE <<  "\n[  3 ] " << DEFAULT << " Crear Tabla Usuarios. ";
	cout << BLUE <<  "\n[  4 ] " << DEFAULT << " Eliminar Tabla Usuarios. ";
	cout << BLUE <<  "\n[  5 ] " << DEFAULT << " Imprimir Tabla Usuarios. ";
	cout << BLUE <<  "\n[  6 ] " << DEFAULT << " Insertar Usuario en Tabla Usuarios. ";
	cout << BLUE <<  "\n[  7 ] " << DEFAULT << " Eliminar Usuario en Tabla Usuarios. ";
	cout << BLUE <<  "\n[  8 ] " << DEFAULT << " Buscar Usuario por Login en Tabla Usuarios. ";
	cout << BLUE <<  "\n[  9 ] " << DEFAULT << " Ordenar Tabla Usuarios. ";
	cout << BLUE <<  "\n[ 10 ] " << DEFAULT << " Añadir Fotografía a Usuario. ";
	cout << BLUE <<  "\n[ 11 ] " << DEFAULT << " Eliminar Fotografía de un Usuario. ";
	cout << BLUE <<  "\n[ 12 ] " << DEFAULT << " Imprimir Fotografía de un Usuario. ";
	cout << BLUE <<  "\n[ 13 ] " << DEFAULT << " Busca Fotografías de Usuario en TablaUsuarios. ";
	cout << BLUE <<  "\n[ 14 ] " << DEFAULT << " Eliminar usuarios fotos min. ";
	cout << BLUE <<  "\n[ 15 ] " << DEFAULT << " Salir. " << endl;

}
void Vista::menuVista(){

	//Declaración de variables.
	int opcion = 0;
	int posicion = 0;
	bool creado = false;
	bool usado=false;
	string Login = "";
	
	//Filtro para que el usuario no se salga de las opciones.
	while(opcion!=15){
		//Mostramos menú anteriormente realizado.
		printMenu();
		
		//Pedimos al usuario que escoga una opción de las mostradas previamente.
		cout << "\nEliga usted el programa que desea ejecutar: " << endl;
		cin >> opcion;

			switch (opcion){

				case 1:	
					//Activar/ Desactivar MODO DEBUG
					cout << GREEN << "Modo DEBUG... " << DEFAULT << endl;	
					this->modoDEBUG(getDEBUG());
				break;

				case 2:
					// Ejecutar Testing Automático.
					if(creado==true){
						cout << GREEN << "Ejecutando Testing en TablaUsuario... " << DEFAULT << endl;					
						this->MenuTesting();
					}else{
						cout << ERROR << "Recuerde que NO puede realizar el TESTING si no ha creado una TablaUsuarios. " << DEFAULT << endl;
						}
				break;
				
				case 3:
					//Crear tabla Usuario
					if(creado==false){
						cout << GREEN << "Creando TablaUsuario... " << DEFAULT << endl;
						TablaUsuarios *tu;
						creado=true;
					}else{
						cout << ERROR << "Recuerde que ya hay CREADA una TablaUsuarios. " << DEFAULT << endl;
						}
				break;
				
				case 4:
					//Eliminar TablaUsuarios
					if(creado==true){
						cout << GREEN << "Eliminando TablaUsuario... " << DEFAULT << endl;
						tu->~TablaUsuarios();
						creado=false;
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 5:
					//Imprimir TablaUsuarios
					if(creado==true){
						cout << GREEN << "Imprimiendo tabla... " << DEFAULT << endl;
						tu->printTablaUsuarios();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede imprimirla. " << DEFAULT << endl;
						}
				break;
				
				case 6:
					//Insertar Usuarios en TablaUsuario.
					if(creado==true){
						this->insertUser();
						cout << GREEN << "Insertando Usuario de tabla... " << DEFAULT << endl;
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede insertar ningún Usuario. " << DEFAULT << endl;
						}
				break;
				
				case 7:
					//Eliminar Usuario en TablaUsuario.
					if(creado==true){
						//eliminarUsuarioTablaUsuarios();
						cout << GREEN << "Eliminando Usuario de tabla... " << DEFAULT << endl;
						this->deleteUser();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminar ningún usuario. " << DEFAULT << endl;
						}
				break;
				
				case 8:
					//Buscar Usuario por login (búsqueda secuencial)
					if(creado==true){
						cout << GREEN << "Buscando Usuario... " << DEFAULT << endl;
						this->searchUser();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede buscar ningún Usuario. " << DEFAULT << endl;
						}
				break;
				
				case 9:
					//Ordenar TablaUsuario:
					if(creado==true){
						cout << GREEN << "Ordenando tabla... " << DEFAULT << endl;
						this->sortTable();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 10:
					//Añadir Fotografía en Usuario.
					if(creado==true){
						cout << GREEN << "Insertando fotografía... " << DEFAULT << endl;
						this->insertPhoto();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 11:
					//Eliminar Fotografía de un Usuario.
					if(creado==true){
						cout << GREEN << "Eliminando fotografía... " << DEFAULT << endl;
						this->deletePhoto();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 12:
					//Imprimir Fotografía de un Usuario.
					if(creado==true){
						cout << GREEN << "Imprimiendo fotografía... " << DEFAULT << endl;
						this->printPhotoUser();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 13:
					//Busqueda fotografía en todos los usuarios(Sólo Admin).
					if(creado==true){
						cout << GREEN << "Buscando Fotografía de Usuario en tabla... " << DEFAULT << endl;
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 14:
					//Eliminar Usuarios Fotos min.
					if(creado==true){
						cout << GREEN << "Buscando Usuario con unas fotografías mínimas... " << DEFAULT << endl;
						this->deleteUserPhotoMin();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no tiene Usuarios para eliminar. " << DEFAULT << endl;
						}
				break;
				
				case 15:
					//Salir
					cout << PURPLE << "\n ----------SALIENDO---------- " << endl ;
					cout << " Gracias por usar CRISTOBOOK " << endl;
					cout << "\n 	© Carlos Fdez " << DEFAULT << endl;
					this->exit();
				break;
				
				default:
					cout << PURPLE << "Lo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
					cout << PURPLE << "Por favor seleccione otra o pulse 15 para salir. \n" << DEFAULT << endl;
			}
	}
}
