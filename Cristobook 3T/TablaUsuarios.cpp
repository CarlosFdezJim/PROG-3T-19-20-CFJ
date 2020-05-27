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
	
	cout  << PURPLE << "\n  ****    CREANDO TABLAUSUARIOS    **** " << DEFAULT << endl;

	//Inicializamos el contenido de la TablaUsuarios.
	int TotalTuplas = 10;
	
	//Reservamos un nuevo espacio de memoria para la TablaUsuarios e inicializamos su puntero.
	TablaUsuarios *tu = 0;
	tu = new TablaUsuarios[TotalTuplas];
		
	//Reservamos un nuevo espacio para el vector de punteros que tiene dentro la variable estructurada TablaUsuario
	this->punteroapuntero = new Usuario*[tu->TotalTuplas];

	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (this->punteroapuntero == 0){
		cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
		exit(-1);
	}

	cout << GREEN << "La TablaUsuarios se ha creado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;

}
TablaUsuarios::~TablaUsuarios(){

	cout  << PURPLE << "\n  ****    ELIMANDO TABLAUSUARIOS    **** " << DEFAULT << endl;




	cout << GREEN << "La TablaUsuarios se ha eliminado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
}
void TablaUsuarios::setTotalTuplas(int TotalTuplas){
	this->TotalTuplas=TotalTuplas;
}
int TablaUsuarios::getTotalTuplas(){
	return this->TotalTuplas;
}
void TablaUsuarios::Salir(){

}
