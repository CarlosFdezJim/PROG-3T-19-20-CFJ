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
		cout << ERROR << "MODO DEBUG ACTIVADO" << DEFAULT << endl;
	}else{
		this->setDEBUG(false);
		cout << ERROR << "MODO DEBUG DESACTIVADO" << DEFAULT << endl;
	}
}
///////////////////////////////				VISTA					////////////////////////////////

Vista::Vista(){

	if(this->getDEBUG() == false){
		cout  << PURPLE << "\n  ****    CREANDO VISTA    **** " << DEFAULT << endl;
	}
	
		//Crearemos la TablaUsuarios en el método Vista.
		this->tu = new TablaUsuarios;

	if(this->getDEBUG() == false){
		cout << GREEN << "El modo Vista se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}

}
Vista::~Vista(){

	if(this->getDEBUG() == false){
		cout  << PURPLE << "\n  ****    DESTRUYENDO VISTA    **** " << DEFAULT << endl;
	}
		//Borramos los datos de los miembros del polinomio.
		tu->setTotalTuplas(0);

	if(this->getDEBUG() == false){
		cout << GREEN << "El modo Vista se ha eliminado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}

}
///////////////////////////////				MENU					////////////////////////////////

/**
 * @brief Muestra en el menú las opciones creadas en este módulo.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printMenu(){

	cout << BLUE <<"/***************************************"<< endl;
		cout << "****	     CLASE VISTA	    ****" << endl;
		cout << "****************************************/" << DEFAULT;
	cout << BLUE <<  "\nAquí le mostramos las opciones disponibles para realizar en la clase Vista : " << DEFAULT;
	cout << BLUE <<  "\n[  1 ] " << DEFAULT << " Modo DEBUG. ";
	cout << BLUE <<  "\n[  2 ] " << DEFAULT << " Testing Automático. ";
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
	cout << BLUE <<  "\n[ 13 ] " << DEFAULT << " EXTRA. ";
	cout << BLUE <<  "\n[ 14 ] " << DEFAULT << " Eliminar usuarios fotos min. ";
	cout << BLUE <<  "\n[ 15 ] " << DEFAULT << " Salir. " << endl;

}
void Vista::menuVista(){

	//Declaración de variables.
	int opcion=0;
	bool creado = false;
	
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
					this->modoDEBUG(getDEBUG());
				break;

				case 2:
					// Ejecutar Testing Automático.
					if(creado==true){
						cout << GREEN << "Ejecutando Testing en TablaUsuario... " << DEFAULT << endl;					
						tu->Testing();
					}else{
						cout << ERROR << "Recuerde que NO puede realizar el TESTING si no ha creado una TablaUsuarios. " << DEFAULT << endl;
						}
				break;
				
				case 3:
					//Crear tabla Usuario
					if(creado==false){
						cout << GREEN << "Creando TablaUsuario... " << DEFAULT << endl;
						tu->usuariosPredefinidos();
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
						tu->insertarUsuarioNuevo();
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
						tu->eliminarUsuarioTablaUsuarios();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminar ningún usuario. " << DEFAULT << endl;
						}
				break;
				
				case 8:
					//Buscar Usuario por login (búsqueda secuencial)
					if(creado==true){
						tu->BuscarLogin();
						cout << GREEN << "Buscanso Usuario... " << DEFAULT << endl;
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede buscar ningún Usuario. " << DEFAULT << endl;
						}
				break;
				
				case 9:
					//Ordenar TablaUsuario:
						//1) totalFotosUsuarios
						//2) Login
					if(creado==true){
						cout << GREEN << "Ordenando tabla... " << DEFAULT << endl;
						tu->ordenarTablaUsuarios();
						
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 10:
					//Añadir Fotografía en Usuario.
					if(creado==true){
						tu->insertarFoto();
						cout << GREEN << "Insertando fotografía... " << DEFAULT << endl;
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 11:
					//Eliminar Fotografía de un Usuario.
					if(creado==true){
						cout << GREEN << "Eliminando fotografía... " << DEFAULT << endl;
						tu->eliminarFotoUsuario();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 12:
					//Imprimir Fotografía de un Usuario.
					if(creado==true){
						cout << GREEN << "Imprimiendo fotografía... " << DEFAULT << endl;
						tu->printFotosUsuario();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 13:
					//Busqueda fotografía en todos los usuarios(Sólo Admin).
					if(creado==true){
						cout << "Buscando Fotografía de Usuario en tabla... " << DEFAULT << endl;
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 14:
					//Eliminar Usuarios Fotos min.
					if(creado==true){
						cout << "Buscando Usuario con unas fotografías mínimas... " << DEFAULT << endl;
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no tiene Usuarios para eliminar. " << DEFAULT << endl;
						}
				break;
				
				case 15:
					//Salir
					cout << PURPLE << "\n ----------SALIENDO---------- " << endl ;
					cout << " Gracias por usar CRISTOBOOK " << endl;
					cout << "\n 	© Carlos Fdez " << DEFAULT << endl;
					//this->~Vista();
				break;
				
				default:
					cout << PURPLE << "Lo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
					cout << PURPLE << "Por favor seleccione otra o pulse 14 para salir. \n" << DEFAULT << endl;
			}
	}
}
