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

	cout  << PURPLE << "\n  ****    CREANDO USUARIOS    **** " << DEFAULT << endl;

	//Reservamos un nuevo espacio de memoria para el usuario y lo inicializamos.
	Usuario *u = 0;
	u = new Usuario;
	
	//Inicializamos el contenido del Usuario.
	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";
	//u->v_fotos=0;
	u->DIM_vfotos=0;
	u->totalFotosUsuario=0;
	
	//Reservamos un nuevo espacio de memoria para el vector de fotos que lleva dentro el usuario.
	//u->v_fotos = new Foto[u->DIM_vfotos];

	//Si no hay memoria suficiente para crear el Usuario se aborta la ejecución y se sale del programa.
	if (u == 0){
		cerr << "Error. No hay memoria suficiente para crear un nuevo Usuario. Se abortará la ejecución" << endl;
		exit(-1);
	}
	
	/*Si no hay memoria suficiente para crear el vector de fotos se aborta la ejecución y se sale del programa.
	if (u->v_fotos == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}*/

	cout << GREEN << "El Usuario se ha creado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
	
	//Devuelvo la dirección que referenciaba al fragmento de memoria(puntero).
	//return u;

}
Usuario::~Usuario(){

	cout  << PURPLE << "\n  ****    BORRAR USUARIOS    **** " << DEFAULT << endl;

	//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
	this->login = "";
	this->nombre = "";
	this->apellido = "";
	this->perfil_usuario = "";	
	this->DIM_vfotos = 0;
	this->totalFotosUsuario = 0;

	//borro el fragmento de memoria
	//delete [] u->v_fotos;
	//delete u;
	
	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	//u = 0;
	
	cout << GREEN << "El Usuario se ha borrado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
	
}

///////////////////////////////				 SET					////////////////////////////////
/*
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
void Usuario::setTotalFotosUsuario(int totalFotosUsuario){
	this->totalFotosUsuario = totalFotosUsuario;   
}
/*void Usuario::setV_Fotos(Usuario *u, Foto *f){
	this->v_fotos = f;
}
void Usuario::setDIM_vfotos(Usuario *u, int DIM_vfotos){
    u->DIM_vfotos = DIM_vfotos;   
}
*/
///////////////////////////////				 GET					////////////////////////////////
/*
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
Foto Usuario::getv_fotos(){
	return this->v_fotos[u->totalFotosUsuario];
}
int Usuario::getDIM_vfotos(){
	return this->DIM_vfotos;
}
int Usuario::getTotalFotosUsuario(){
    return this->totalFotosUsuario;
}
*/
///////////////////////////////				 OTHER					////////////////////////////////
/**
 * @brief Módulo que se encarga de almacenar en la Tabla de Usuarios algunos usuarios predefinidos.
 * @param TablaUsuarios tu (E/S)
 * @pre Deberemos tener bien hechos los Set para que no fallen al insertar los usuarios predefinidos.
 * @post Los usuarios serán introducidos en la Tabla de Usuarios.
 * @version 2.2
 * @author Carlos Fdez.
 */
/*
void UsuariosPredefinidos(TablaUsuarios &tu){

	Foto *f = 0;
	f=crearFoto();
	
	Usuario *u = 0;
	u=crearUsuario();
	
	//Usuarios predefinidos.
	Usuario *Carlos=0;
	Usuario *Jaime=0;
	Usuario *Cristian=0;
	Usuario *Adrian=0;
	Usuario *Jesus=0;
	Usuario *Pablo=0;
	Usuario *Ana=0;
		
	/***************************************
	**************	CARLOS	****************
	****************************************/
/*	Carlos = new Usuario();
	setLogin("@CarlosCristoRey");
	setNombre("Carlos");
	setApellido("Fernández");
	setPerfilUsuario("FIFA");
	insertarUsuarioTablaUsuarios(tu);
	//Foto1
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
	setLogin("@JaimeCristoRey");
	setNombre("Jaime");
	setApellido("Cabezas");
	setPerfilUsuario(Jaime, "Minecraft");
	insertarUsuarioTablaUsuarios(tu);
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
	
}*/
///////////////////////////////				 PRINT					////////////////////////////////
/*
void Usuario::printUsuario(Usuario *u){

	//Imprimimos el usuario con todos sus miembros.
	cout << YELLOW << "****************************************" << endl;
	cout << YELLOW <<  "Login: " << DEFAULT << getLogin() << endl;
	cout << YELLOW << "Nombre: " << DEFAULT <<  getNombre() << endl;
	cout << YELLOW << "Apellido: " << DEFAULT <<  getApellido() << endl;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT <<  getPerfilUsuario() << endl;
	//cout << YELLOW << "--------------------------" << DEFAULT << endl;
	
	//Imprimimos el vector de fotos 
	if(getTotalFotosUsuario(u) != 0){
		cout << PURPLE << "----------------" << DEFAULT << endl;
		for(int i= 0; i < getTotalFotosUsuario(u);i++){
			cout << BLUE << "Foto número : " << DEFAULT << i << endl;
			printFoto(&u->v_fotos[i]);
		}
	}else
		cout << YELLOW << "Este usuario no tiene fotos. " << DEFAULT << endl;

}
*/

/**
 * @brief Módulo que se encarga de borrar la foto del usuario y ordenar el vector de fotos
 * @param TablaUsuarios tu (E/S)
 * @pre El usuario debe de tener al menos una foto introducida.
 * @post Al usuario seleccionado se le eliminará la foto de su vector de fotos.
 * @version 1.0
 * @author Carlos Fdez.
 */
/*void eliminarFotoUsuario(TablaUsuarios &tu){

	//Declaración de variables locales.
	string login = "";
	bool usado = false;
	unsigned int posicion=0;
	int cont=0;
	int elim=0;
	
	//Pedimos al usuario el Login para eliminar la fotografía.
	cout << "Introduce el Login del usuario al que quieres eliminar una fotografía : " << endl;
	cin >> login;
	
	//Comprobamos si el login existe o no.
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;	
		}
	}
	
	//Pedimos al usuario el número de fotografía que queremos eliminar.
	cout << "Introduce la posición que quieres eliminar : " << endl;
	cin >> elim;
	
	//Si existe el usuario realizamos el intercambio de posiciones y eliminamos la última posición del vector.
	if(usado == true){
		//Realizamos el intercambio de posiciones
		tu.punteroapuntero[posicion]->v_fotos[elim] = tu.punteroapuntero[posicion]->v_fotos[tu.punteroapuntero[posicion]->totalFotosUsuario-1];
		setTotalFotosUsuario(tu.punteroapuntero[posicion],tu.punteroapuntero[posicion]->totalFotosUsuario-1);
	}else{
		cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
	}
}
void Usuario::eliminarUsuarioTablaUsuarios(TablaUsuarios &tu){

	//Declaración de variables locales.
	string login = "";
	bool usado = false;
	unsigned int posicion = 0;
	int cont = 0;	
		
	//Pedimos al usuario el login (que es único en el sistema) para eliminarlo.
	cout << "Selecione el usuario que desea eliminar, recuerde que tiene que introducir el login" << endl;
	cin >> login;
	
	//Comprobar que el usuario existe.
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;	
		}
	}
	
	//Si usado==true, el usuario existe y podemos eliminarlo.
	if(usado == true){
	
		//Creamos un Usuario aux para hacer el intercambio.
		Usuario* aux=0;
		aux=crearUsuario();
		
		//Realizamos el intercambio de posiciones.
		aux = tu.punteroapuntero[posicion];
		tu.punteroapuntero[posicion]=tu.punteroapuntero[tu.TotalTuplas-1];
		tu.punteroapuntero[tu.TotalTuplas-1]= aux;
		
		//Borramos usuario en la última posición
		borrarUsuario(tu.punteroapuntero[tu.TotalTuplas-1]);
		
		//Disminuimos el tamaño del vector.
		tu.punteroapuntero = resizeDisminuirPorPunteros(tu,tu.punteroapuntero);
		
		//Imprimimos el vector de usuario para que el administrador vea que se ha borrado correctamente.
		printTablaUsuarios(tu);
	}else{
		cout << ERROR << "El Login que usted ha elegido no se encuentra en nuestra tabla de usuarios. " << DEFAULT << endl;
		}
}
void Usuario::insertarUsuarioNuevo(TablaUsuarios &tu){

	string login = "";
	bool usado = false;	
	
	//Pedimos al usuario los datos.
	cout << "Por favor ingrese los siguientes datos: " << endl;
	cout << YELLOW << "Login : " << DEFAULT << endl;
	cin >> login;
	
	//Comprobamos si el login existe o no.
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);	
	}
	
	//Si el usuario no existe entramos en este if y creamos Usuario y lo insertamos en la TablaUsuarios.
	if(usado != true){
		
		//Reservamos el espacio de memmoria al nuevo Usuario.
		Usuario *u = 0;	
		u = crearUsuario();
		pedirDatosUsuario(u);
		setLogin(u,login);
		insertarUsuarioTablaUsuarios(u,tu);
	}else{
		cout << RED << "El Login introducido ya está en uso." << DEFAULT << endl;
		}
}
void Usuario::insertarUsuarioTablaUsuarios(Usuario *u, TablaUsuarios &tu){

	//Resize decrease.
	resizeAumentarPorPunteros(tu,tu.punteroapuntero);
	
	//Insert user in vector
	tu.punteroapuntero[tu.TotalTuplas-1] = u;
}
void Usuario::resizeAumentarPorPunteros(TablaUsuarios &tu, Usuario **v){
	
	int DIM = tu.TotalTuplas+1;

	Usuario **vectorNuevo = 0;
	
	vectorNuevo = new Usuario*[DIM]; 

	if (vectorNuevo == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}
	for(int i = 0;i < tu.TotalTuplas;i++){
		vectorNuevo[i]=v[i];
	}
	
	delete [] v;
	tu.punteroapuntero = vectorNuevo;
	tu.TotalTuplas = DIM;
	//cout << "DEBUG: La DIM valen: " << DIM << endl;
	
}
Usuario** Usuario::resizeDisminuirPorPunteros(TablaUsuarios &tu, Usuario **u){
	
	int DIM = tu.TotalTuplas-1;
	Usuario **vectorNuevo = 0;
	
	vectorNuevo = new Usuario*[DIM]; //memoria dinámica: ME HE CREADO "tamanio" PERSONAS DINÁMICAS

	if (vectorNuevo == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
		}
	
	for(int i = 0;i < DIM;i++){
		vectorNuevo[i]=u[i];
		}
	
	delete [] u;
	
	tu.TotalTuplas = DIM;
	
	return vectorNuevo;
	
}
void Usuario::insertarFoto(TablaUsuarios &tu){

	string login = "";
	bool usado = false;
	int posicion=0;
	int cont = 0;
	
	
	cout << "Introduce su Login del usuario al que quieres introducir la fotografía : " << endl;
	cin >> login;
	
	//Comprobamos si el login existe o no.
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;	
		}
	}
	//Si existe el login --> usado == true y reservamos memória dinámica para la foto y el usuario y creamos sus puntero inicializandolo a 0;
	if(usado == true){
		Foto *f=0;
		f=crearFoto();
		Usuario *u = 0;
		
		u = tu.punteroapuntero[posicion];
		ValoresFoto(f);
		resizeAumentarFoto(tu.punteroapuntero[posicion],u->v_fotos);
		setTotalFotosUsuario(tu.punteroapuntero[posicion],getTotalFotosUsuario(u)+1);
		tu.punteroapuntero[posicion]->v_fotos[getTotalFotosUsuario(u)-1] = *f;
	}else{
		cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
		}
}*/
