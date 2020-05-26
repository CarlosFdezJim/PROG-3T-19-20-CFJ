//
//	Vista.cpp
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
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
#include <string.h>

#include "TablaUsuarios.h"
#include "Vista.h"

using namespace std;


///////////////////////////////				VISTA					////////////////////////////////

Vista::Vista(){

	setDEBUG(true);

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO VISTA    **** " << DEFAULT << endl;
	}

	//Inicializamos los miembros de vista.
	this->TotalTuplas = 10;

	//Filtro para que las tuplas del vector no sea negativo, en caso de serlo abortará la ejecución.
	if(this->TotalTuplas >= 0){
		//Creamos un vector de punteros de Usuarios.
		punteroapuntero = new Usuario**[TotalTuplas+1];	//Reservo el valor de TotalTuplas+1.

		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->TablaUsuarios == 0){
			cerr << "Error. No hay memoria suficiente. Se abortará la ejecución " << endl;
			cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
			exit(-1);
		}

		//Rellenamos el vector de coeficientes a 0
		/*for(int i=0; i <= TotalTuplas; i++){
			coef[i]= 0.0;
		}*/

	}else if (this->TotalTuplas < 0){
		cerr << "¡¡ERROR!! una TablaUsuarios no puede tener una dimensión negativo." << endl;
		cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
		exit(-1);
	}

	if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}




}
Vista::~Vista(){






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
	cout << PURPLE <<  "\nAquí le mostramos las opciones disponibles para realizar en la clase Vista : " << DEFAULT;
	cout << PURPLE <<  "\n[  1 ] " << DEFAULT << " Modo DEBUG. ";
	cout << PURPLE <<  "\n[  2 ] " << DEFAULT << " Testing Automático. ";
	cout << PURPLE <<  "\n[  3 ] " << DEFAULT << " Crear Tabla Usuarios. ";
	cout << PURPLE <<  "\n[  4 ] " << DEFAULT << " Eliminar Tabla Usuarios. ";
	cout << PURPLE <<  "\n[  5 ] " << DEFAULT << " Imprimir Tabla Usuarios. ";
	cout << PURPLE <<  "\n[  6 ] " << DEFAULT << " Insertar Usuario en Tabla Usuarios. ";
	cout << PURPLE <<  "\n[  7 ] " << DEFAULT << " Eliminar Usuario en Tabla Usuarios. ";
	cout << PURPLE <<  "\n[  8 ] " << DEFAULT << " Buscar Usuario por Login en Tabla Usuarios. ";
	cout << PURPLE <<  "\n[  9 ] " << DEFAULT << " Ordenar Tabla Usuarios. ";
	cout << PURPLE <<  "\n[ 10 ] " << DEFAULT << " Añadir Fotografía a Usuario. ";
	cout << PURPLE <<  "\n[ 11 ] " << DEFAULT << " Eliminar Fotografía de un Usuario. ";
	cout << PURPLE <<  "\n[ 12 ] " << DEFAULT << " Imprimir Fotografía de un Usuario. ";
	cout << PURPLE <<  "\n[ 13 ] " << DEFAULT << " EXTRA. ";
	cout << PURPLE <<  "\n[ 14 ] " << DEFAULT << " Salir. " << endl;

}
void Vista::menuVista(){

	//Declaración de variables.
	int opcion=0;
	bool creado = false;
	
	//Filtro para que el usuario no se salga de las opciones.
	while(opcion!=14){
		//Mostramos menú anteriormente realizado.
		printMenu();
		
		//Pedimos al usuario que escoga una opción de las mostradas previamente.
		cout << "\nEliga usted el programa que desea ejecutar: " << endl;
		cin >> opcion;

			switch (opcion){

				case 1:	
					//Activar/ Desactivar MODO DEBUG
						//setDebug(true);
				break;

				case 2:
					// Ejecutar Testing Automático.
					// TestingAutomático();
				break;
				
				case 3:
					//Crear tabla Usuario
					if(creado==false){
						creado=true;
						//TablaUsuario();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 4:
					//Eliminar TablaUsuarios
					if(creado==true){
						//~TablaUsuarios();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 5:
					//Imprimir TablaUsuarios
					if(creado==true){
						//printTablaUsuarios();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 6:
					//Insertar Usuarios en TablaUsuario.
					if(creado==true){
						//InsertUsuariosTablaUsuarios();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 7:
					//Eliminar Usuario en TablaUsuario.
					if(creado==true){
						//eliminarUsuarioTablaUsuarios();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 8:
					//Buscar Usuario por login (búsqueda secuencial)
					if(creado==true){
						//buscarUsuario();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 9:
					//Ordenar TablaUsuario:
						//1) totalFotosUsuarios
						//2) Login
					if(creado==true){
						//ordenarTablaUsuarios();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 10:
					//Añadir Fotografía en Usuario.
					if(creado==true){
						//InsertarFotoUsuario();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 11:
					//Eliminar Fotografía de un Usuario.
					if(creado==true){
						//eliminarFotoUsuario();
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 12:
					//Imprimir Fotografía de un Usuario.
					if(creado==true){
						
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 13:
					//Busqueda fotografía en todos los usuarios(Sólo Admin).
					if(creado==true){
						
					}else{
						cout << ERROR << "Recuerde que si no CREA una TablaUsuarios no puede eliminarla. " << DEFAULT << endl;
						}
				break;
				
				case 14:
					//Salir
					cout << PURPLE << "----------SALIENDO----------\n" ;
					cout << "\nGracias por usar el modo Vista del POLINOMIO " << endl;
					cout << "\n © Carlos Fdez " << DEFAULT << endl;
				break;
				
				default:
					cout << PURPLE << "Lo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
					cout << PURPLE << "Por favor seleccione otra o pulse 14 para salir. \n" << DEFAULT << endl;
			}
	}
}

///////////////////////////////				DEBUG					////////////////////////////////

void Vista::setDEBUG(bool DEBUG){
	this->DEBUG = DEBUG;
}
bool Vista::getDEBUG(){
	return this->DEBUG;
}
