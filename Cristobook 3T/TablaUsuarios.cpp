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
		this->TotalTuplas = 4;
		
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
		
		//Eliminamos el vector de punteros a Usuarios.
		/*for(int i=0; i <= this->getTotalTuplas(); i++){
			delete punteroapuntero[i];
		}*/

	
		//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
		/*this->setTotalTuplas(-1);
	
		//Borramos el vector dinámico de coeficientes.
		/*delete [] punteroapuntero;
		punteroapuntero = 0;*/

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

///////////////////////////////				 OTHER					////////////////////////////////

void TablaUsuarios::UsuariosPredefinidos(){

	//Foto *f = new Foto();

//	Usuario *u = new Usuario();
	
	//Usuarios predefinidos.
/*	Usuario *Jaime=0;
	Usuario *Cristian=0;
	Usuario *Adrian=0;
	Usuario *Jesus=0;
	Usuario *Pablo=0;
	Usuario *Ana=0;
		
	/***************************************
	**************	CARLOS	****************
	****************************************/
	Usuario *u = new Usuario();
	u->setLogin("@Carlos");
	u->setNombre("Carlos");
	u->setApellido("Fernández");
	u->setPerfilUsuario("Admin");
	this->punteroapuntero[0] = u;
	
/*	//Foto1
	setRuta(f, "/home/Carlos/Escritorio/Imagenes/Españita");
	setTipo(f,"jpeg");
	setTamanio(f,49350);
	insertarFotoUsuario(Carlos, f);
	//Foto2
	setRuta(f, "/home/Carlos/Escritorio/Imagenes/esto_es_ESPANIAAAAAA");
	setTipo(f,"gif");
	setTamanio(f,6050);
	insertarFotoUsuario(Carlos, f);

	
	/***************************************
	**************	JAIME	****************
	****************************************/
/*	Jaime = new Usuario();
	Jaime->setLogin("@Jaime");
	Jaime->setNombre("Jaime");
	Jaime->setApellido("Cabezas");
	Jaime->setPerfilUsuario("Normal");
	Jaime->insertarUsuarioTablaUsuarios("Normal");
	//Foto1
	setRuta(f, "/home/Jaime/Escritorio/Imagenes/Skone");
	setTipo(f,"jpeg");
	setTamanio(f,49350);
	insertarFotoUsuario(Jaime, f);
	//Foto2
	setRuta(f, "/home/Jaime/Escritorio/Imagenes/Force");
	setTipo(f,"jpeg");
	setTamanio(f,49350);
	insertarFotoUsuario(f);		

	
	/***************************************
	********	CRISTIAN	********
	****************************************/
/*	Cristian = new Usuario();
	setLogin("@CristianCristoRey");
	setNombre("Cristian");
	setApellido("Campos");
	setPerfilUsuario("Footbal Manager");
	insertarUsuarioTablaUsuarios(tu);
	//Foto1
	setRuta(f, "/home/Cristian/Escritorio/Imagenes/fackposlisia");
	setTipo(f,"jpeg");
	setTamanio(f,49350);
	insertarFotoUsuario(Cristian, f);
	//Foto2
	setRuta(f, "/home/Cristian/Escritorio/Imagenes/LoKo_ReShUlOn");
	setTipo("jpeg");
	setTamanio(49350);
	insertarFotoUsuario(f);

	
	/***************************************
	**************	ADRIAN	****************
	****************************************/
/*	Adrian =  new Usuario();
	setLogin("@AdrianCristoRey");
	setNombre("Adrián");
	setApellido("Castillo");
	setPerfilUsuario("Counter Strike");
	insertarUsuarioTablaUsuarios(tu);
	//Foto1
	/*setRuta(f, "/home/Adrian/Escritorio/Imagenes/polvora");
	setTipo(f,"gif");
	setTamanio(f,6050);
	insertarFotoUsuario(Adrian, f);
	//Foto2
	setRuta(f, "/home/Adrian/Escritorio/Imagenes/Calamar");
	setTipo(f,"bmp");
	setTamanio(f,125910);
	insertarFotoUsuario(Adrian, f);

	
	/***************************************
	**************	JESUS	****************
	****************************************/
/*	Jesus = new Usuario();
	setLogin("@JesusCristoRey");
	setNombre("Jesús");
	setApellido("Rey");
	setPerfilUsuario("GTA V");
	insertarUsuarioTablaUsuarios(tu);
	//Foto1
	/*setRuta(f, "/home/Jesus/Escritorio/Imagenes/Escaleras");
	setTipo(f,"gif");
	setTamanio(f,6050);
	insertarFotoUsuario(Jesus, f);
	//Foto2
	setRuta(f, "/home/Jesus/Escritorio/Imagenes/Motosytoeso/susuki_compae");
	setTipo(f,"jpeg");
	setTamanio(f,6050);
	insertarFotoUsuario(Jesus, f);

	
	/***************************************
	**************	PABLO	****************
	****************************************/
/*	Pablo = new Usuario();
	setLogin("@PabloCristoRey");
	setNombre("Pablo");
	setApellido("García");
	setPerfilUsuario("Counter Strike");
	insertarUsuarioTablaUsuarios(Pablo,tu);
	//Foto1
	/*setRuta(f, "/home/Pablo/Escritorio/Imagenes/gente_seria");
	setTipo(f,"jpeg");
	setTamanio(f,6050);
	insertarFotoUsuario(Pablo, f);
	//Foto2
	setRuta(f, "/home/Pablo/Escritorio/Imagenes/mas_gente_seria_4k");
	setTipo(f,"jpeg");
	setTamanio(f,6050);
	insertarFotoUsuario(Pablo, f);

	
	/***************************************
	**************	  ANA	****************
	****************************************/
/*	Ana = new Usuario();
	setLogin("@AnaCristoRey");
	setNombre("Ana");
	setApellido("Tallón");
	setPerfilUsuario("Animal Crossing");
	insertarUsuarioTablaUsuarios(Ana,tu);
	//Foto1
	/*setRuta(f, "/home/Ana/Escritorio/Imagenes/Amorsito");
	setTipo(f,"jpeg");
	setTamanio(f,6050);
	insertarFotoUsuario(Ana, f);
	//Foto2
	setRuta(f, "/home/Ana/Escritorio/Imagenes/Aguacates");
	setTipo(f,"png");
	setTamanio(f,8710);
	insertarFotoUsuario(Ana, f);
*/	
}
void TablaUsuarios::printTablaUsuarios(){

	for(int i = 0; i < this->getTotalTuplas(); i++){
		this->punteroapuntero[i]->printUsuario();
	}
}
void TablaUsuarios::insertarUsuarioTablaUsuarios(){

	if(this->getTotalUsuario() >= 0 ){
	
	}else if(this->getTotalUsuario() >= 0){
	
	}

	//this->resize();
	//this->punteroapuntero[getTotalTuplas()]
}
void TablaUsuarios::resize(){





}
/*void TablaUsuarios::Salir(){

}*/
