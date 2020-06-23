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

#include "TablaUsuarios.h"
using namespace std;

///////////////////////////////				DEBUG					////////////////////////////////

void TablaUsuarios::setDEBUG(bool DEBUG){
	
	this->DEBUG = DEBUG;
}
bool TablaUsuarios::getDEBUG(){
	return this->DEBUG;
}
void TablaUsuarios::modoDEBUG(bool DEBUG){

	for(int i = 0; i < this->getTotalTuplas(); i++){
		this->punteroapuntero[i]->setDEBUG(DEBUG);
	}

}

///////////////////////////////				TABLA USUARIOS					////////////////////////////////

TablaUsuarios::TablaUsuarios(){
	
	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO TABLAUSUARIOS    **** " << DEFAULT << endl;
	}
		
		//Inicializamos TotalTuplas a 0.
		this->setTotalTuplas(0);

		//Filtro para que las tuplas del vector no sea negativo, en caso de serlo abortará la ejecución.
		if (this->getTotalTuplas() < 0){
			cerr << "¡¡ERROR!! las tuplas no pueden ser negativas." << endl;
			cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
			exit(-1);
		}

		//Reservamos un nuevo espacio para el vector de punteros que tiene dentro la variable estructurada TablaUsuario
		this->punteroapuntero = new Usuario*[this->getTotalTuplas()];
	
		//Insertamos los Usuarios predefinidos.
		this->dataBase();
	
		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->punteroapuntero == 0){
			cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
			exit(-1);
		}
		
	if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha creado correctamente.\n" << DEFAULT ;
		cout << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
TablaUsuarios::TablaUsuarios(int TotalTuplas){
	
	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO TABLAUSUARIOS POR PARÁMETROS    **** " << DEFAULT << endl;
	}
		
		//Inicializamos TotalTuplas al valor pasado por parámetros.
		this->setTotalTuplas(TotalTuplas);

		//Filtro para que las tuplas del vector no sea negativo, en caso de serlo abortará la ejecución.
		if (this->getTotalTuplas() < 0){
			cerr << "¡¡ERROR!! las tuplas no pueden ser negativas." << endl;
			cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
			exit(-1);
		}

		//Reservamos un nuevo espacio para el vector de punteros que tiene dentro la variable estructurada TablaUsuario
		this->punteroapuntero = new Usuario*[this->getTotalTuplas()];
	
		//Insertamos los Usuarios predefinidos.
		this->dataBase();
	
		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->punteroapuntero == 0){
			cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
			exit(-1);
		}
		
	if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha creado correctamente.\n" << DEFAULT ;
		cout << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
TablaUsuarios::~TablaUsuarios(){

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    ELIMANDO TABLAUSUARIOS    **** " << DEFAULT << endl;
	}	
		if (this->getTotalTuplas() > 0){
			//Eliminamos el contenido del vector de punteros a Usuarios.
			for(int i=0; i <= this->getTotalTuplas(); i++){
				delete this->punteroapuntero[i];
			}
		
			//Ponemos los datos del usuario a 0 antes de eliminar el usuario.
			this->setTotalTuplas(0);

			//Borramos el vector dinámico de punteros a usuarios.
			delete [] this->punteroapuntero;
			
			//Eliminamos la dirección del punteroapuntero.
			this->punteroapuntero = 0;
			
		}else if (this->getTotalTuplas() < 0){
			cerr << RED << "No existe ninguna TablaUsuarios. " << endl;
	
		}
	if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha eliminado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
///////////////////////////////				 SET/GET					////////////////////////////////

void TablaUsuarios::setTotalTuplas(int TotalTuplas){
	this->TotalTuplas=TotalTuplas;
}
int TablaUsuarios::getTotalTuplas(){
	return this->TotalTuplas;
}

///////////////////////////////				PASS					////////////////////////////////

void TablaUsuarios::credentials(string pass, string contrasena, bool &usado){
	
	//Declaración de variables.
	int cont = 0;
	
	for(int i = 0; i < this->getTotalTuplas(); i++){
		if(Admin *a = dynamic_cast <Admin*>(this->punteroapuntero[i])){
			if(pass == a->getLogin() && cont != 1){
				usado = true;
				cont++;
				cout << GREEN << "Acceso concedido" << DEFAULT << endl;
			}
		}
		/*if(Normal *n = dynamic_cast <Normal*>(this->punteroapuntero[i])){
			if(pass == n->getLogin() && cont != 1){
				cout << "DEBUG 2 " << endl;
				usado = false;
				cout << RED << "Este usuario se encuentra en nuestra base de datos";
				cout <<" pero no puede usar esta funcionalidad porque no es Administrador. " << DEFAULT << endl;
			}else{
				cout << ERROR << "El Login introducido no se encuentra en nuestra base de datos. " << DEFAULT << endl;
			}
		}*/
		
	}
}
void TablaUsuarios::comprobacionLoginTU(string &Login, bool &usado, int &posicion){
	
	//Comprobamos si el login existe o no.
	for(int i = 0; i < this->getTotalTuplas();i++){
		if(Login == this->punteroapuntero[i]->getLogin()){
			usado = true;
			posicion = i;
		}
	}
}

///////////////////////////////				 PRINT					////////////////////////////////

void TablaUsuarios::printTablaUsuarios(){

	if(this->getTotalTuplas() >= 0){
		for(int i = 0; i < this->getTotalTuplas(); i++){
			this->punteroapuntero[i]->printUsuario();
		}
	}else{
			cout << ERROR << "No hay ningún usuario insertado para eliminarlo. " << DEFAULT << endl;
		}
}
void TablaUsuarios::printUser(int posicion){

	this->punteroapuntero[posicion]->printUsuario();

}

///////////////////////////////				 DATABASE					////////////////////////////////

void TablaUsuarios::dataBase(){
	
	Foto *f = new Foto;
	
	/***************************************
	**************	CARLOS	****************
	****************************************/
	Admin *Carlos = new Admin;
	Carlos->setLogin("@Carlos");
	Carlos->setNombre("Carlos");
	Carlos->setApellido("Fernández");
	Carlos->setPerfilUsuario("Admin");
	this->insertarUsuarioTablaUsuarios(Carlos);
	Carlos->setConsultas(99);

	/***************************************
	**************	JAIME	****************
	****************************************/
	Normal *Jaime = new Normal;
	Jaime->setLogin("@Jaime");
	Jaime->setNombre("Jaime");
	Jaime->setApellido("Cabezas");
	Jaime->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Jaime);
	//Foto1
	f->setRuta("/home/Jaime1988/Escritorio/Imagenes/Skone");
	f->setTipo("jpeg");
	f->setTamanio(49350);
	Jaime->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/Jaime1988/Escritorio/Imagenes/Force");
	f->setTipo("jpeg");
	f->setTamanio(49350);
	Jaime->insertarFotoUsuario(f);
	
	/***************************************
	********	CRISTIAN	********
	****************************************/
	Admin *Cristian = new Admin;
	Cristian->setLogin("@Cristian");
	Cristian->setNombre("Cristian");
	Cristian->setApellido("Campos");
	Cristian->setPerfilUsuario("Admin");
	this->insertarUsuarioTablaUsuarios(Cristian);
	Cristian->setConsultas(9);
	
	/***************************************
	**************	ADRIAN	****************
	****************************************/
	Normal *Adrian =  new Normal;
	Adrian->setLogin("@Adrian");
	Adrian->setNombre("Adrián");
	Adrian->setApellido("Castillo");
	Adrian->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Adrian);
	//Foto1
	f->setRuta("/home/Adrian/Escritorio/Imagenes/polvora");
	f->setTipo("gif");
	f->setTamanio(6050);
	Adrian->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/Adrian/Escritorio/Imagenes/Calamar");
	f->setTipo("bmp");
	f->setTamanio(125910);
	Adrian->insertarFotoUsuario(f);
	//Foto3
	f->setRuta("/home/Adrian/Escritorio/Imagenes/Panojito");
	f->setTipo("bmp");
	f->setTamanio(125910);
	Adrian->insertarFotoUsuario(f);
	
	/***************************************
	**************	PABLO	****************
	****************************************/
	Admin *Pablo = new Admin;
	Pablo->setLogin("@Pablo");
	Pablo->setNombre("Pablo");
	Pablo->setApellido("García");
	Pablo->setPerfilUsuario("Admin");
	this->insertarUsuarioTablaUsuarios(Pablo);
	Cristian->setConsultas(19);
	
	/***************************************
	**************	DAVID	****************
	****************************************/
	Normal *David = new Normal;
	David->setLogin("@David");
	David->setNombre("Antonio David");
	David->setApellido("López");
	David->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(David);
	//Foto1
	f->setRuta("/home/David/Escritorio/Imagenes/Semana-Santa-19");
	f->setTipo("gif");
	f->setTamanio(6050);
	David->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/David/Escritorio/Imagenes/Wallpaper_Camarón_4K");
	f->setTipo("jpeg");
	f->setTamanio(6050);
	David->insertarFotoUsuario(f);
	
	/***************************************
	**************	  ANA	****************
	****************************************/
	Normal *Ana = new Normal;
	Ana->setLogin("@Ana");
	Ana->setNombre("Ana");
	Ana->setApellido("Tallón");
	Ana->setPerfilUsuario("Normal");
	this->insertarUsuarioTablaUsuarios(Ana);
	//Foto1
	f->setRuta("/home/Ana/Escritorio/Imagenes/Amorsito");
	f->setTipo("jpeg");
	f->setTamanio(6050);
	Ana->insertarFotoUsuario(f);
	//Foto2
	f->setRuta("/home/Ana/Escritorio/Imagenes/Aguacatinhos");
	f->setTipo("png");
	f->setTamanio(8710);
	Ana->insertarFotoUsuario(f);
	//Foto3
	f->setRuta("/home/Ana/Escritorio/Imagenes/Golfeo");
	f->setTipo("png");
	f->setTamanio(8710);
	Ana->insertarFotoUsuario(f);
	
}

///////////////////////////////				 RESIZE					////////////////////////////////

void TablaUsuarios::resize(int DIM){

	//Reservo memoria para el vector auxiliar con una DIM +1.
	Usuario** aux = new Usuario*[DIM+1];
	
	//Compruebo que hay memoria suficiente.
	if (aux == 0){
		cerr << "Error. No hay memoria suficiente para crear un nuevo usuario en el resize. Se abortará la ejecución" << endl;
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
	
	//Eliminamos la memoria del vector de usuario.
	delete [] punteroapuntero;

	//Reasignamos el puntero de punteroapuntero y ponemos a 0 el puntero que hemos creado.
	punteroapuntero = aux;
	aux = 0;

}

///////////////////////////////				 INSERT					////////////////////////////////

void TablaUsuarios::crearUsuario(string Login, int posicion, bool usado, int opcion){

	if (opcion == 1){
		//Reservamos el espacio de memmoria al nuevo Usuario.
		Normal *n = new Normal;
		n->setLogin(Login);
		pedirDatosUsuario(n);
		n->setPerfilUsuario("Normal");
		this->insertarUsuarioTablaUsuarios(n);
	}else if(opcion == 2){
		Admin *a = new Admin;
		a->setLogin(Login);
		pedirDatosUsuario(a);
		a->setPerfilUsuario("Admin");
		this->insertarUsuarioTablaUsuarios(a);
	}else{
		 cout << RED << " La opción escogida no es válida, lo siento " << DEFAULT << endl;
	 }

}
void TablaUsuarios::insertarUsuarioTablaUsuarios(Usuario *u){
	
	//Aumentamos la dimensión en una posición.
	this->resize(getTotalTuplas()+1);
	
	//Insertamos el usuario en la nueva posición.
	this->punteroapuntero[this->getTotalTuplas()] = u;
	
	//Actualizamos las TotalTuplas.
	this->setTotalTuplas(this->getTotalTuplas()+1);
	
}

///////////////////////////////				 DELETE					////////////////////////////////

void TablaUsuarios::eliminarUsuario(int posicion){

	//Elimino el usuario en la posición indicada
	delete this->punteroapuntero[posicion];
	
	//Copio el último usuario en la posición que acabamos de borrar
	this->punteroapuntero[posicion] = this->punteroapuntero[this->getTotalTuplas()-1];

	//Disminuimos el tamaño del vector.
	this->resize(this->getTotalTuplas()-1);

	//Actualizamos las TotalTuplas.
	this->setTotalTuplas(this->getTotalTuplas()-1);
	
}
void TablaUsuarios::eliminarUsuarioTablaUsuarios(int posicion, bool usado){
	
	if (this->getTotalTuplas() >= 0){
		//Si usado==true, el usuario existe y podemos eliminarlo.
		if(usado == true){
			//Eliminamos el Usuario
			this->eliminarUsuario(posicion);
		}else{
			cout << ERROR << "El Login que usted ha elegido no se encuentra en nuestra tabla de usuarios. " << DEFAULT << endl;
			}
	}else{
		cout << ERROR << "No hay ningún usuario insertado para eliminarlo. " << DEFAULT << endl;
	}
}
///////////////////////////////				 BUSCAR					////////////////////////////////

void TablaUsuarios::BuscarLogin(bool usado, int posicion){

	//Si existe el usuario entramos en el if e imprimimos el Usuario, si no existe mostramos un mensaje por pantalla.
	if(usado == true){
		//Mostramos la posición dónde está el usuario.
		cout << BLUE << "El usuario se encuentra en la posición: " << DEFAULT << posicion << endl;
		this->punteroapuntero[posicion]->printUsuario();
	}
}

///////////////////////////////				 ORDENAR					////////////////////////////////

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
		
	int cont = 0;
		
	if(this->getTotalTuplas() > 0){
		for(int i = 0; i < this->getTotalTuplas();i++){
			if(Normal *n = dynamic_cast<Normal*>(this->punteroapuntero[i])){
				if(Normal *N = dynamic_cast<Normal*>(this->punteroapuntero[i+1])){	
						if(n->getTotalFotosUsuario() < N->getTotalFotosUsuario()){
							Normal *aux = 0;
							
							//Ordenamos las fotos con un Usuario Normal aux.
							aux = n;
							n = N;
							N = aux;
							
							//Eliminamos la dirección de memoria de los punteros.
							aux = 0;
							n = 0;
							N = 0;
						}
				}
				/*if (Admin *a = dynamic_cast<Admin*>(this->punteroapuntero[i+1])){
					Usuario *aux = 0;
					
					//Ordenamos las fotos con un Usuario Normal aux.
					aux = N;
					N = a;
					a = aux;
					
					//Eliminamos la dirección de memoria de los punteros.
					aux = 0;
					a = 0;
				}*/
			}
			if (Admin *a = dynamic_cast<Admin*>(this->punteroapuntero[i])){
				a = 0;
				cout << "El usuario no puede tener fotos porque es un administrador, no un usuario" << endl;
			}
		}
	}else{
		cout << RED << "Lo sentimos, todavía no podemos ordenar porque no hay los usuarios suficientes " << DEFAULT << endl;
		}
		
}

///////////////////////////////				 INSERTAR					////////////////////////////////

void TablaUsuarios::insertarFoto(int posicion, bool usado){

	//Si existe el login --> usado == true y reservamos memória dinámica para la foto y el usuario y creamos sus puntero inicializandolo a 0;
	if(usado == true){
		if(Normal *n = dynamic_cast<Normal*>(this->punteroapuntero[posicion])){
			Foto *f = new Foto;
			
			this->ValoresFoto(f);
			n->insertarFotoUsuario(f);
			n = 0;
		}else if (Admin *a = dynamic_cast<Admin*>(this->punteroapuntero[posicion])){
			a = 0;
			cout << "El usuario no puede tener fotos porque es un administrador , no un usuario." << endl;
		}
	}else{
		cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
		}
}

///////////////////////////////				 ELIMINAR					////////////////////////////////

void TablaUsuarios::eliminarFotoUsuario(int posicion, bool usado, int elim){

	//Declaración de variables locales.
	string Login = "";

	if (this->getTotalTuplas() > 0){
		//Si existe el usuario realizamos el intercambio de posiciones y eliminamos la última posición del vector.
		if(usado == true){
			if(Normal *n = dynamic_cast<Normal*>(this->punteroapuntero[posicion])){
				if(elim <= n->getTotalFotosUsuario()){
					//Realizamos el intercambio de posiciones
					n->getv_fotos(elim) = n->getv_fotos(n->getTotalFotosUsuario()-1);
					n->setTotalFotosUsuario(n->getTotalFotosUsuario()-1);
					n = 0;
				
				}else{
					cerr << RED << "Lo sentimos, este Usuario no dispone de ese número de fotos." << DEFAULT << endl;
				}
			}else{
				cout << RED << "Lo siento, los usuario Adim no tienen fotos ingresadas." << DEFAULT << endl;
			}
		}else{
			cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
		}
	}else{
		cout << ERROR << "No hay ningún usuario insertado para eliminarlo. " << DEFAULT << endl;
	}
}

///////////////////////////////				 IMPRIMIR FOTO USUARIO					////////////////////////////////

void TablaUsuarios::printFotosUsuario(bool usado, int posicion){

			
	//Si existe el usuario entramos en el if e imprimimos el Usuario, si no existe mostramos un mensaje por pantalla.
	if(usado == true){
		if(Normal *n = dynamic_cast<Normal*>(this->punteroapuntero[posicion])){
				n->printUsuario();
				cout << PURPLE << "----------------" << DEFAULT << endl;
				n = 0;
		}
		if(Admin *a = dynamic_cast<Admin*>(this->punteroapuntero[posicion])){
			cout << RED << " Este usuario es Administrador, por lo que no tiene foto insertadas. " << DEFAULT << endl;
			a = 0;
		}
	}else{
		cerr << RED << "Lo sentimos, el Login introducido no está en nuestra base de datos." << DEFAULT << endl;
	}
}

///////////////////////////////				 ELIMINAR USUARIO FOTOS MIN					////////////////////////////////

void TablaUsuarios::eliminarUsuariosFotosMin(int min){

	//Buscamos los usuarios que tengan al menos esas fotos.
	for (int i = 0; i < this->getTotalTuplas(); i++){
		if(Normal *n = dynamic_cast<Normal*>(this->punteroapuntero[i])){
			if(n->getTotalFotosUsuario() <= min){
				this->eliminarUsuario(i);
				n = 0;
				i = 0;
			}
		}
		if(Admin *a = dynamic_cast<Admin*>(this->punteroapuntero[i])){
			a = 0;
		}
	}
}













///////////////////////////////				 ------					////////////////////////////////

void TablaUsuarios::ValoresFoto(Foto *f){

	string r = "";;
	string t = "";;

	cout << BLUE << "* * * * * * * * * * * * * * * * * * * " << DEFAULT << endl;
	cout << YELLOW << "Por favor ingresa la ruta de la foto. " << DEFAULT << endl;
	cin >> r;
	f->setRuta(r);
	
	cout << YELLOW << "Por favor ingresa el formato de la foto. " << DEFAULT << endl;
	cout << YELLOW << "Le indico los tipos compatibles [bmp] [jpeg] [png] [gif] " << DEFAULT << endl ;
	cin >> t;
	f->setTipo(t);
	cout << BLUE << "* * * * * * * * * * * * * * * * * * * " << DEFAULT << endl;
	
	//Dependiendo del tipo de foto se le asigna un tamaño predeterminado.
	if(f->getTipo() == "bmp"){
		f->setTamanio(125910);
	}else if(f->getTipo() == "jpeg"){
		f->setTamanio(49350);
	}else if(f->getTipo() == "png"){
		f->setTamanio(8710);
	}else if(f->getTipo() == "gif"){
		f->setTamanio(6050);
	}else {
		f->setTamanio(405000);
	}
}
void TablaUsuarios::pedirDatosUsuario(Usuario *u){
	
	string nombre = "";
	string apellido = "";
	int x = 0;

	cout << YELLOW << "Nombre: " << DEFAULT << endl;
	cin >> nombre;
	cout << YELLOW << "Apellido: " << DEFAULT << endl;
	cin >> apellido;
	
	u->setNombre(nombre);
	u->setApellido(apellido);
	
}

///////////////////////////////				 TESTING					////////////////////////////////
/*
void TablaUsuarios::TestingAutomatico2(){

	cout  << CYAN << " ****    CREANDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	//TablaUsuarios *tu;
	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	this->printTablaUsuarios();
	cout  << CYAN << " ****    ELIMINANDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	this->~TablaUsuarios();
	cout  << CYAN << " ****    CREANDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	//TablaUsuarios *tu;
	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;	
	this->printTablaUsuarios();
	cout  << CYAN << " ****    CREAR TRES USUARIOS    **** " << DEFAULT << endl;
		for(int j=0; j < 3; j++){
			//this->crearUsuario();
		}
	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	this->printTablaUsuarios();
	cout  << CYAN << " ****    ELIMINANDO CINCO USUARIOS    **** " << DEFAULT << endl;
		for(int k=0; k < 5; k++){
			//this->eliminarUsuarioTablaUsuarios();	
		}
	cout  << CYAN << " ****    ORDENANDO TABLA DE USUARIOS POR LOGIN    **** " << DEFAULT << endl;	
	this->ordenamosLogin();
	cout  << CYAN << " ****    ELIMINANDO UN USUARIOS    **** " << DEFAULT << endl;	
	//this->eliminarUsuarioTablaUsuarios();
	cout  << CYAN << " ****    INSERTANDO FOTO EN UN USUARIOS    **** " << DEFAULT << endl;
	this->insertarFoto();

}
void TablaUsuarios::TestingAutomatico3(){

	cout  << CYAN << " ****    CREANDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	//TablaUsuarios *tu;
	cout  << CYAN << " ****    ELIMINANDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	this->~TablaUsuarios();	
	cout  << CYAN << " ****    CREANDO TABLA DE USUARIOS    **** " << DEFAULT << endl;
	//TablaUsuarios *tu;
	cout  << CYAN << " ****    IMPRIMIENDO TABLA DE USUARIOS    **** " << DEFAULT << endl;	
	this->printTablaUsuarios();
	cout  << CYAN << " ****    CREAR DOS USUARIOS    **** " << DEFAULT << endl;
		for(int i = 0; i < 2; i++){
			//this->crearUsuario();
		}
	cout  << CYAN << " ****    ELIMINANDO UN USUARIO    **** " << DEFAULT << endl;	
		for(int i = 0; i < 1; i++){
		//	this->eliminarUsuarioTablaUsuarios();
		}
	cout  << CYAN << " ****    BUSCAMOS USUARIOS POR LOGIN    **** " << DEFAULT << endl;	
	this->BuscarLogin();
	cout  << CYAN << " ****    ORDENANDO TABLA DE USUARIOS POR LOGIN    **** " << DEFAULT << endl;	
	this->ordenamosLogin();
	cout  << CYAN << " ****    INSERTANDO FOTO EN UN USUARIOS X2    **** " << DEFAULT << endl;
	this->insertarFoto();
	cout  << CYAN << " ****    ELIMINANDO FOTO A UN USUARIO    **** " << DEFAULT << endl;	
	this->eliminarFotoUsuario();
	cout  << CYAN << " ****    IMPRIMIENDO FOTOS DE USUARIO    **** " << DEFAULT << endl;	
	this->printFotosUsuario();
	cout  << CYAN << " ****    ELIMINANDO USUARIOS FOTOS MIN    **** " << DEFAULT << endl;	
	this->eliminarUsuariosFotosMin();



}*/

