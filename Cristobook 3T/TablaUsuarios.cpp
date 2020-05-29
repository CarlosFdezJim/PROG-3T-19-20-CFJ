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
		cout << ERROR << "DEBUG 1: " << this->getTotalTuplas()<< DEFAULT << endl;
		//Eliminamos el vector de punteros a Usuarios.
		for(int i=0; i <= this->getTotalTuplas(); i++){
			delete punteroapuntero[i];
			this->getTotalTuplas()-1;
		}
		cout << ERROR << "DEBUG 2: " << this->getTotalTuplas()<< DEFAULT << endl;
		//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
		this->setTotalTuplas(-1);
		cout << ERROR << "DEBUG 3: " << this->getTotalTuplas()<< DEFAULT << endl;	
		//Borramos el vector dinámico de coeficientes.
		delete [] punteroapuntero;
		punteroapuntero = 0;
		cout << ERROR << "DEBUG 4: " << this->getTotalTuplas()<< DEFAULT << endl;
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

///////////////////////////////				 OTHER					////////////////////////////////

void TablaUsuarios::insertarUsuarioTablaUsuarios(Usuario *u){
	
		this->resize(getTotalTuplas()+1);
		this->punteroapuntero[this->getTotalTuplas()] = u;
		this->setTotalTuplas(this->getTotalTuplas()+1);
}
void TablaUsuarios::resize(int DIM){

cout << "Entra en resize" << endl;
	
	//Reservo memoria para el vector auxiliar con una DIM +1.
	Usuario** aux = new Usuario*[DIM+1];
	
	//Compruebo que hay memoria suficiente.
	if (aux == 0){
		cerr << "Error. No hay memoria suficiente para crear un nuevo vector. Se abortará la ejecución" << endl;
		exit(-1);
	}

	if( DIM > this->getTotalTuplas()){
cout << "Entra en resize aumenta" << endl;
		//Copio el contenido de punteroapuntero[i] en aux[i].
		for(int i = 0;i < this->getTotalTuplas();i++){
			aux[i] = this->punteroapuntero[i];
		}
cout << "Sale en resize aumenta" << endl;
	}else if (DIM < this->getTotalTuplas()){
cout << "Entra en resize y disminuye" << endl;
		//Copio el contenido de punteroapuntero[i] en aux[i].
		for(int i = 0; i <= DIM; i++){
			aux[i] = this->punteroapuntero[i];
		}
cout << "Sale en resize disminuye" << endl;
	}
	
	//Eliminamos la memoria del vector coef.
	delete [] punteroapuntero;

	//Reasignamos el puntero de coeficientes.
	punteroapuntero = aux;

	//Actualizo el máximo grado y el grado.
	//this->setTotalTuplas(DIM);
cout << "Sale en resize " << endl;
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
			cout  << RED << "************************************** " << DEFAULT << endl;
	//Foto1
/*	Carlos->setRuta("/home/Carlos/Escritorio/Imagenes/Españita");
	Carlos->setTipo("jpeg");
	Carlos->setTamanio(49350);
	this->insertarFotoUsuario(Carlos);
	//Foto2
	Carlos->setRuta("/home/Carlos/Escritorio/Imagenes/esto_es_ESPANIAAAAAA");
	Carlos->setTipo("gif");
	Carlos->setTamanio(6050);
	this->insertarFotoUsuario(Carlos);

	
	/***************************************
	**************	JAIME	****************
	****************************************/
	Usuario *Jaime = new Usuario;
	Jaime->setLogin("@Jaime");
	Jaime->setNombre("Jaime");
	Jaime->setApellido("Cabezas");
	Jaime->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Jaime);
			cout  << RED << "************************************** " << DEFAULT << endl;
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
			cout  << RED << "************************************** " << DEFAULT << endl;
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
			cout  << RED << "************************************** " << DEFAULT << endl;
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
			cout  << RED << "************************************** " << DEFAULT << endl;
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
			cout  << RED << "************************************** " << DEFAULT << endl;
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
			cout  << RED << "************************************** " << DEFAULT << endl;
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
	cout << RED << "DEBUG: Totaltuplas = " << this->getTotalTuplas() << DEFAULT << endl;
}
/*void TablaUsuarios::Salir(){
	
}*/
