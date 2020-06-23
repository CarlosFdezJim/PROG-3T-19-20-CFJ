//
//	Usuarios.cpp
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
#define BLACK "\033[0;30m"

//**************************************//
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Usuario.h"
using namespace std;

///////////////////////////////				DEBUG					////////////////////////////////

void Usuario::setDEBUG(bool DEBUG){
	this->DEBUG = DEBUG;
}
bool Usuario::getDEBUG(){
	return this->DEBUG;
}

///////////////////////////////				 USUARIO					////////////////////////////////

Usuario::Usuario(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO USUARIOS    **** " << DEFAULT << endl;
	}
		//Inicializamos el contenido del Usuario.
		this->login = "NULL";
		this->nombre = "NULL";
		this->apellido = "NULL";
		this->perfil_usuario = "NULL";	
	
	if(this->getDEBUG() == true){
		cout << GREEN << "El Usuario se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}

}
Usuario::Usuario(string login, string nombre, string apellido, string perfil_usuario){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n ****    CREANDO USUARIOS POR PARÁMETROS    **** " << DEFAULT << endl;
	}
		//Inicializamos el contenido del Usuario introduciendo los parámetros.
		this->login = login;
		this->nombre = nombre;
		this->apellido = apellido;
		this->perfil_usuario = perfil_usuario;

	if(this->getDEBUG() == true){
		cout << GREEN << "El Usuario se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
Usuario::Usuario(Usuario &u){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n ****    CREANDO USUARIOS POR COPIA    **** " << DEFAULT << endl;
	}
		//Inicializamos el contenido del Usuario copiando los valores del Usuario pasado por referencia.
		this->login = u.login;
		this->nombre = u.nombre;
		this->apellido = u.apellido;
		this->perfil_usuario = u.perfil_usuario;

	if(this->getDEBUG() == true){
		cout << GREEN << "El Usuario se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
Usuario::Usuario(Usuario *u){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n ****    CREANDO USUARIOS POR COPIA    **** " << DEFAULT << endl;
	}
		//Inicializamos el contenido del Usuario copiando los datos del puntero de Usuario.
		this->login = u->login;
		this->nombre = u->nombre;
		this->apellido = u->apellido;
		this->perfil_usuario = u->perfil_usuario;

	if(this->getDEBUG() == true){
		cout << GREEN << "El Usuario se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
Admin::Admin():Usuario(){

	//Creamos el miembro exclusivo del Administrador, el resto los hereda de Usuario.
	int consultas = 0;
	
}
Normal::Normal():Usuario(){
	
	//Creamos los miembro exclusivos del Normal, el resto los hereda de Usuario.
	int DIM_vfotos = 0;
	int totalFotosUsuario = 0;
	//Foto *v_fotos = new Foto[DIM_vfotos];
	
}
Usuario::~Usuario(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    BORRAR USUARIOS    **** " << DEFAULT << endl;
	}
		//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
		this->login = "";
		this->nombre = "";
		this->apellido = "";
		this->perfil_usuario = "";	

	if(this->getDEBUG() == true){
		cout << GREEN << "El Usuario se ha borrado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
Admin::~Admin(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    BORRAR ADMINISTRADOR    **** " << DEFAULT << endl;
	}
		//Elimino los miembro exclusivos del Administrador, el resto los borra con el destructor de Usuario.
		int consultas = 0;

	if(this->getDEBUG() == true){
		cout << GREEN << "El Administrador se ha borrado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
Normal::~Normal(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    BORRAR USUARIO NORMAL    **** " << DEFAULT << endl;
	}	
		//Ponemos a 0 los valores de los miembros.
		int DIM_vfotos = 0;
		int totalFotosUsuario = 0;

		//Eliminamos el contenido del vector de punteros a Usuarios.
		for(int i=0; i <= this->getTotalFotosUsuario(); i++){
		//	delete this->v_fotos[i];
		}
		
		//borro el vector dinámico de fotos, liberando así su memoria.
		delete [] this->v_fotos;

		//elimino la dirección que referenciaba al vector dinámico de fotos.
		this->v_fotos = 0;
		
	if(this->getDEBUG() == true){
		cout << GREEN << "El Usuario Normal se ha borrado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
	
}

///////////////////////////////				 RESIZE					////////////////////////////////

void Normal::resizeFoto(int DIM){

	//Reservo memoria para el vector auxiliar con una DIM +1.
	Foto *aux = new Foto[DIM];
	
	//Compruebo que hay memoria suficiente.
	if (aux == 0){
		cerr << "Error. No hay memoria suficiente para crear un nuevo vector. Se abortará la ejecución" << endl;
		exit(-1);
	}
	if(DIM > this->getTotalFotosUsuario()){

		//Copio el contenido de punteroapuntero[i] en aux[i].
		for(int i = 0;i < this->getTotalFotosUsuario();i++){
			aux[i] = this->v_fotos[i];
		}
		
	}
	
	//Eliminamos la memoria del vector v_fotos.
	//delete [] v_fotos;

	//Reasignamos el puntero de v_fotos y ponemos a 0 la dirección del vector auxiliar.
	v_fotos = aux;
	aux = 0;

	//Actualizamos la dimension
	this->setDIM_vfotos(this->getTotalFotosUsuario()+1);

}
///////////////////////////////				 SET					////////////////////////////////

void Usuario::setLogin(string login){
	this->login = login;
}
void Usuario::setNombre(string nombre){
	this->nombre = nombre;
}
void Usuario::setApellido(string apellido){
	this->apellido = apellido;   
}
void Usuario::setPerfilUsuario(string perfil_usuario){ 
	this->perfil_usuario = perfil_usuario;
}
void Normal::setTotalFotosUsuario(int totalFotosUsuario){
	this->totalFotosUsuario = totalFotosUsuario;   
}
void Normal::setV_Fotos(int i){
	this->v_fotos[i];
}
void Normal::setDIM_vfotos(int DIM_vfotos){
	this->DIM_vfotos = DIM_vfotos;   
}
void Admin::setConsultas(int consultas){
	this->consultas = consultas;
}

///////////////////////////////				 GET					////////////////////////////////

string Usuario::getLogin(){
    return this->login;
}
string Usuario::getNombre(){
    return this->nombre;
}
string Usuario::getApellido(){
    return this->apellido;
}
string Usuario::getPerfilUsuario(){
    return this->perfil_usuario;
}
Foto Normal::getv_fotos(int i){
	return this->v_fotos[i];
}
int Normal::getDIM_vfotos(){
	return this->DIM_vfotos;
}
int Normal::getTotalFotosUsuario(){
	return this->totalFotosUsuario;
}
int Admin::getConsultas(){
	return this->consultas;
}

///////////////////////////////				 PRINT					////////////////////////////////

void Usuario::printUsuario(){

	//Imprimimos el usuario con todos sus miembros.
	cout << YELLOW << "****************************************" << endl;
	cout << YELLOW <<  "Login: " << DEFAULT << this->getLogin() << endl;
	cout << YELLOW << "Nombre: " << DEFAULT <<  this->getNombre() << endl;
	cout << YELLOW << "Apellido: " << DEFAULT <<  this->getApellido() << endl;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT <<  this->getPerfilUsuario() << endl;
	cout << YELLOW << "--------------------------" << DEFAULT << endl;
	
}
void Normal::printUsuario(){

	//Imprimimos la parte de Usuario.
	this->Usuario::printUsuario();
	
	//Imprimimos los datos únicos del Usuario Normal.
	if(this->getTotalFotosUsuario() != 0){
		cout << PURPLE << "----------------" << DEFAULT << endl;
		for(int i= 0; i < this->getTotalFotosUsuario();i++){
			cout << BLUE << "Foto número : " << DEFAULT << i << endl;
			this->v_fotos[i].printFoto();
		}
	}else
		cout << RED << "Este usuario no tiene fotos. " << DEFAULT << endl;

}
void Admin::printUsuario(){

	//Imprimimos la parte de Usuario.
	this->Usuario::printUsuario();
	
	//Imprimimos los datos únicos del Administrador.
	cout << PURPLE << "****************************************" << DEFAULT << endl;
	cout << PURPLE << "Consultas realizadas: " << DEFAULT <<  this->getConsultas() << endl;
	cout << PURPLE << "****************************************" << DEFAULT << endl;

}
///////////////////////////////				 INSERT					////////////////////////////////

void Normal::insertarFotoUsuario(Foto *f){

	//Aumentamos en uno nuestro vector.
	this->resizeFoto(this->getTotalFotosUsuario()+1);
	//Insertamos en el vector nuestra foto.
	this->v_fotos[this->getTotalFotosUsuario()] = *f;
	//Actualizamos las TotalFotosUsuario
	this->setTotalFotosUsuario(this->getTotalFotosUsuario()+1);
}

///////////////////////////////				 SOBRECARGAS					////////////////////////////////

ostream& operator<<(ostream &flujo, Usuario &u){
	
	//Imprimimos el usuario con todos sus miembros.
	flujo << YELLOW << "****************************************" << endl;
	flujo << YELLOW <<  "Login: " << DEFAULT << u.getLogin() << endl;
	flujo << YELLOW << "Nombre: " << DEFAULT << u.getNombre() << endl;
	flujo << YELLOW << "Apellido: " << DEFAULT << u.getApellido() << endl;
	flujo << YELLOW << "Perfil de usuarios: " << DEFAULT << u.getPerfilUsuario() << endl;
	flujo << YELLOW << "--------------------------" << DEFAULT << endl;
	
	return flujo;
}
ostream& operator<<(ostream &flujo, Usuario *u){
	
	//Imprimimos el usuario con todos sus miembros.
	flujo << YELLOW << "****************************************" << endl;
	flujo << YELLOW <<  "Login: " << DEFAULT << u->getLogin() << endl;
	flujo << YELLOW << "Nombre: " << DEFAULT << u->getNombre() << endl;
	flujo << YELLOW << "Apellido: " << DEFAULT << u->getApellido() << endl;
	flujo << YELLOW << "Perfil de usuarios: " << DEFAULT << u->getPerfilUsuario() << endl;
	flujo << YELLOW << "--------------------------" << DEFAULT << endl;
	
	return flujo;
}
ostream& operator<<(ostream &flujo, Normal *n){
	
	//Imprimimos el usuario con todos sus miembros.
	flujo << YELLOW << "****************************************" << endl;
	flujo << YELLOW <<  "Login: " << DEFAULT << n->getLogin() << endl;
	flujo << YELLOW << "Nombre: " << DEFAULT << n->getNombre() << endl;
	flujo << YELLOW << "Apellido: " << DEFAULT << n->getApellido() << endl;
	flujo << YELLOW << "Perfil de usuarios: " << DEFAULT << n->getPerfilUsuario() << endl;
	flujo << YELLOW << "--------------------------" << DEFAULT << endl;
	
	//Imprimimos los miembros exclusivos de Usuario Normal. 
	if(n->getTotalFotosUsuario() != 0){
		flujo << PURPLE << "----------------" << DEFAULT << endl;
		for(int i= 0; i < n->getTotalFotosUsuario();i++){
			flujo << BLUE << "Foto número : " << DEFAULT << i << endl;
			n->v_fotos[i].printFoto();
		}
	}else{
		flujo << RED << "Este usuario no tiene fotos. " << DEFAULT << endl;
	}
	
	return flujo;
}
ostream& operator<<(ostream &flujo, Normal &n){
	
	//Imprimimos el usuario con todos sus miembros.
	flujo << YELLOW << "****************************************" << endl;
	flujo << YELLOW <<  "Login: " << DEFAULT << n.getLogin() << endl;
	flujo << YELLOW << "Nombre: " << DEFAULT << n.getNombre() << endl;
	flujo << YELLOW << "Apellido: " << DEFAULT << n.getApellido() << endl;
	flujo << YELLOW << "Perfil de usuarios: " << DEFAULT << n.getPerfilUsuario() << endl;
	flujo << YELLOW << "--------------------------" << DEFAULT << endl;
	
	//Imprimimos los miembros exclusivos de Usuario Normal. 
	if(n.getTotalFotosUsuario() != 0){
		flujo << PURPLE << "----------------" << DEFAULT << endl;
		for(int i= 0; i < n.getTotalFotosUsuario();i++){
			cout << BLUE << "Foto número : " << DEFAULT << i << endl;
			n.v_fotos[i].printFoto();
		}
	}else{
		flujo << RED << "Este usuario no tiene fotos. " << DEFAULT << endl;
	}
	
	return flujo;
		
}
ostream& operator<<(ostream &flujo, Admin &a){
	
	//Imprimimos el usuario con todos sus miembros.
	flujo << YELLOW << "****************************************" << endl;
	flujo << YELLOW <<  "Login: " << DEFAULT << a.getLogin() << endl;
	flujo << YELLOW << "Nombre: " << DEFAULT << a.getNombre() << endl;
	flujo << YELLOW << "Apellido: " << DEFAULT << a.getApellido() << endl;
	flujo << YELLOW << "Perfil de usuarios: " << DEFAULT << a.getPerfilUsuario() << endl;
	flujo << YELLOW << "--------------------------" << DEFAULT << endl;
	
	//Imprimimos los miembros exclusivos de Usuario Administrador. 
	cout << PURPLE << "****************************************" << endl;
	cout << PURPLE << "Consultas realizadas: " << DEFAULT <<  a.getConsultas() << endl;
	cout << PURPLE << "****************************************" << endl;
		
}
ostream& operator<<(ostream &flujo, Admin *a){
	
	//Imprimimos el usuario con todos sus miembros.
	flujo << YELLOW << "****************************************" << endl;
	flujo << YELLOW <<  "Login: " << DEFAULT << a->getLogin() << endl;
	flujo << YELLOW << "Nombre: " << DEFAULT << a->getNombre() << endl;
	flujo << YELLOW << "Apellido: " << DEFAULT << a->getApellido() << endl;
	flujo << YELLOW << "Perfil de usuarios: " << DEFAULT << a->getPerfilUsuario() << endl;
	flujo << YELLOW << "--------------------------" << DEFAULT << endl;
	
	//Imprimimos los miembros exclusivos de Usuario Administrador.
	cout << PURPLE << "****************************************" << DEFAULT << endl;
	cout << PURPLE << "Consultas realizadas: " << DEFAULT <<  a->getConsultas() << endl;
	cout << PURPLE << "****************************************" << DEFAULT << endl;
		
}
void Usuario::operator=(Usuario &u){

	//Copiamos el contenido del Usuario.
	this->login = u.login;
	this->nombre = u.nombre;
	this->apellido = u.apellido;
	this->perfil_usuario = u.perfil_usuario;

}
void Usuario::operator=(Usuario *u){

	//Copiamos el contenido del Usuario.
	this->login = u->login;
	this->nombre = u->nombre;
	this->apellido = u->apellido;
	this->perfil_usuario = u->perfil_usuario;

}
void Normal::operator=(Normal &n){

	//Copiamos el contenido del Usuario.
	this->login = n.login;
	this->nombre = n.nombre;
	this->apellido = n.apellido;
	this->perfil_usuario = n.perfil_usuario;	
	
	//Inicializamos los miembros del Usuario Normal.
	this->DIM_vfotos = n.DIM_vfotos;
	this->totalFotosUsuario = n.totalFotosUsuario;

}
void Normal::operator=(Normal *n){

	//Copiamos el contenido del Usuario.
	this->login = n->login;
	this->nombre = n->nombre;
	this->apellido = n->apellido;
	this->perfil_usuario = n->perfil_usuario;	
	
	//Inicializamos los miembros del Usuario Normal.
	this->DIM_vfotos = n->DIM_vfotos;
	this->totalFotosUsuario = n->totalFotosUsuario;

}
void Admin::operator=(Admin &a){

	//Copiamos el contenido del Usuario.
	this->login = a.login;
	this->nombre = a.nombre;
	this->apellido = a.apellido;
	this->perfil_usuario = a.perfil_usuario;	
	
	//Copiamos los miembros del Usuario Admin.
	this->consultas = a.consultas;

}
void Admin::operator=(Admin *a){

	//Copiamos el contenido del Usuario.
	this->login = a->login;
	this->nombre = a->nombre;
	this->apellido = a->apellido;
	this->perfil_usuario = a->perfil_usuario;	
	
	//Copiamos los miembros del Usuario Admin.
	this->consultas = a->consultas;

}
