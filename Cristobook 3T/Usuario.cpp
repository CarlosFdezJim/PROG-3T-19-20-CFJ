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

//**************************************//
#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Usuario.h"
using namespace std;

///////////////////////////////				 USUARIO					////////////////////////////////

Usuario::Usuario(){

	//if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO USUARIOS    **** " << DEFAULT << endl;
	//}
		//Inicializamos el contenido del Usuario.
		this->login = "NULL";
		this->nombre = "NULL";
		this->apellido = "NULL";
		this->perfil_usuario = "NULL";	
	
	//if(this->getDEBUG() == true){
		cout << GREEN << "El Usuario se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	//}

}
Usuario::Usuario(string login, string nombre, string apellido, string perfil_usuario){

	cout  << PURPLE << "\n  ****    CREANDO USUARIOS POR PARÁMETROS    **** " << DEFAULT << endl;

	//Inicializamos el contenido del Usuario.
	this->login = login;
	this->nombre = nombre;
	this->apellido = apellido;
	this->perfil_usuario = perfil_usuario;	

	cout << GREEN << "El Usuario se ha creado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;

}
Admin::Admin(){

	//Creo los miembro exclusivos del Administradorm el resto los hereda de Usuario.
	int consultas = 0;

}
Normal::Normal(){

	int DIM_vfotos = 0;
	int totalFotosUsuario = 0;
	
	//Rellenamos el vector de Fotos del Usuario.
	/*for( int i=0; i < this->getTotalFotosUsuario();i++){
		Foto* v_fotos[i] = new Foto;
	}*/

}
Usuario::~Usuario(){

	//if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    BORRAR USUARIOS    **** " << DEFAULT << endl;
	//}
	
		//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
		this->login = "";
		this->nombre = "";
		this->apellido = "";
		this->perfil_usuario = "";	
	
	cout << GREEN << "El Usuario se ha borrado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
	
}
Admin::~Admin(){

	//Creo los miembro exclusivos del Administradorm el resto los hereda de Usuario.
	int consultas = 0;

}
Normal::~Normal(){

	int DIM_vfotos = 0;
	int totalFotosUsuario = 0;
	
	//Borramos el vector de Fotos del Usuario.
		//for( int i=0; i < this->getTotalFotosUsuario();i++){
		//	this->v_fotos[i] = delete f;
		//}
		
	//borro el fragmento de memoria
	delete [] this->v_fotos;
	
	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	//this->u = 0;

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

///////////////////////////////				 PRINT					////////////////////////////////

void Usuario::printUsuario(){

	//Imprimimos el usuario con todos sus miembros.
	cout << YELLOW << "****************************************" << endl;
	cout << YELLOW <<  "Login: " << DEFAULT << this->getLogin() << endl;
	cout << YELLOW << "Nombre: " << DEFAULT <<  this->getNombre() << endl;
	cout << YELLOW << "Apellido: " << DEFAULT <<  this->getApellido() << endl;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT <<  this->getPerfilUsuario() << endl;
	cout << YELLOW << "--------------------------" << DEFAULT << endl;
	
	//Imprimimos el vector de fotos 
	/*if(getTotalFotosUsuario(u) != 0){
		cout << PURPLE << "----------------" << DEFAULT << endl;
		for(int i= 0; i < getTotalFotosUsuario(u);i++){
			cout << BLUE << "Foto número : " << DEFAULT << i << endl;
			printFoto(&u->v_fotos[i]);
		}
	}else
		cout << YELLOW << "Este usuario no tiene fotos. " << DEFAULT << endl;*/

}
void Admin::eliminarUsuarioTablaUsuarios(){

	//Declaración de variables locales.
	string Login = "";
	bool usado = false;
	unsigned int posicion = 0;
	
	//Imprimimos la tabla de Usuarios
	for(int i = 0; i < tu->getTotalTuplas(); i++){
		tu->punteroapuntero[i]->printUsuario();
	}
	//Pedimos al usuario el login (que es único en el sistema) para eliminarlo.
	cout << "Selecione el usuario que desea eliminar, recuerde que tiene que introducir el login" << endl;
	cin >> Login;
	
	//Comprobar que el usuario existe.
	for(int i = 0;i < tu->getTotalTuplas();i++){
		if(this->login == Login && usado=true){
			posicion=i;
		}
	}
	
	//Si usado==true, el usuario existe y podemos eliminarlo.
	if(usado == true){
	
		//Creamos un Usuario aux para hacer el intercambio.
		Usuario* aux = new Usuario;
		
		//Realizamos el intercambio de posiciones.
		aux = tu->punteroapuntero[posicion];
		tu->punteroapuntero[posicion] = tu->punteroapuntero[tu->getTotalTuplas()-1];
		tu->punteroapuntero[tu->getTotalTuplas()-1] = aux;
		
		//Borramos usuario en la última posición
		delete tu->punteroapuntero[tu->getTotalTuplas()-1];
		//borrarUsuario(tu.punteroapuntero[getTotalTuplas()-1]);
		
		//Disminuimos el tamaño del vector.
		tu->resize(tu->getTotalTuplas()-1);
		//this->punteroapuntero = resizeDisminuirPorPunteros(tu,t->punteroapuntero);
		
		//Imprimimos el vector de usuario para que el administrador vea que se ha borrado correctamente.
		tu->printTablaUsuarios();
	}else{
		cout << ERROR << "El Login que usted ha elegido no se encuentra en nuestra tabla de usuarios. " << DEFAULT << endl;
		}
}
/*void Admin::insertarUsuarioNuevo(){

	string Login = "";
	bool usado = false;	
	
	//Pedimos al usuario los datos.
	cout << "Por favor ingrese los siguientes datos: " << endl;
	cout << YELLOW << "Login : " << DEFAULT << endl;
	cin >> Login;
	
	//Comprobamos si el login existe o no.
	for(int i = 0;i < tu.TotalTuplas;i++){
		if(this->login == Login){
			posicion=i;
			usado=true;
		}	
	}
	
	//Si el usuario no existe entramos en este if y creamos Usuario y lo insertamos en la TablaUsuarios.
	if(usado != true){
		
		//Reservamos el espacio de memmoria al nuevo Usuario.
		Usuario *u = new Usuario();
		pedirDatosUsuario(u);
		setLogin(u,login);
		insertarUsuarioTablaUsuarios(u,tu);
	}else{
		cout << RED << "El Login introducido ya está en uso." << DEFAULT << endl;
		}
}*/
