//
//	TablaUsuarios.cpp
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

///////////////////////////////				TABLA USUARIOS					////////////////////////////////
TablaUsuarios::TablaUsuarios(){
	
	setDEBUG(true);

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO TABLAUSUARIOS    **** " << DEFAULT << endl;
	}

	//Reservamos un nuevo espacio de memoria para el usuario y lo inicializamos.
	TablaUsuarios *tu = 0;
	tu = new TablaUsuarios;
	
	//Inicializamos el contenido de la TablaUsuarios.
	tu->TotalTuplas=0;
	tu->punteroapuntero=0;
	
	//Reservamos un nuevo espacio para el vector de punteros que tiene dentro la variable estructurada TablaUsuario
	tu->punteroapuntero = new Usuario*[tu->TotalTuplas];

	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (tu->punteroapuntero == 0){
		cerr << "Error. No hay memoria suficiente para crear una nueva TablaUsuarios. Se abortará la ejecución" << endl;
		exit(-1);
	}

	if(this->getDEBUG() == true){
		cout << GREEN << "La TablaUsuarios se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}

}
TablaUsuarios::~TablaUsuarios(){

	//Eliminamos los datos del Usuario.(Dentro eliminamos el vector de fotos y los puntero).
	//cout << "DEBUG: Las útiles valen: " << tu.TotalTuplas << endl;
	for(int i=0; i < tu.TotalTuplas; i++){
		//cout << "DEBUG: Las útiles valen: " << tu.TotalTuplas << endl;
		borrarUsuario(tu.punteroapuntero[i]);
	}
	//borro el fragmento de memoria que pertenecía a punteroapuntero.
	delete [] tu.punteroapuntero;
	
	//Elimino el contenido de la TablaUsuarios.
	tu.TotalTuplas=0;
	tu.punteroapuntero=0;

}



/**
 * @brief Devuelve el puntero totalFotosUsuario de una variable estructurada de tipo Usuario.
 * @param TablaUsuarios tu (E/S)
 * @version 1.0
 * @author Carlos Fdez.
 */
int getTotalTuplas(TablaUsuarios &tu){
	return tu.TotalTuplas;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Éste módulo se encarga de imprimir la TablaUsuarios.
 * @param TablaUsuarios tu (E/S)
 * @pre La tabla de Usuarios debe de estar creada.
 * @post Mostrará todos los usuarios insertados en a tabla.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printTablaUsuarios(TablaUsuarios &tu){

	//Imprimimos TablaUsuarios pasando por todas la posiciones hasta llegar a TotalTuplas.
	for(int i = 0;i < getTotalTuplas(tu);i++)
		printUsuario(tu.punteroapuntero[i]);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Este módulo se encargade comprobar si el Login ya está introducido o no.
 * @param string login
 * @param Usuario *u
 * @param bool usado (E/S)
 * @pre El usuario debe de haber insertado el login.
 * @post Comprobaremos que el usuario está introducido o no.
 * @version 1.0
 * @author Carlos Fdez.
 */
void comprobacionLogin(string login,Usuario *u,bool &usado){

	//Comprobamos si el login está introducido o no. Si lo está devolveremos usado = true;(Lo hacemos aparte porque lo usaremos en varios sitios).
	if(login == u->login){
		usado = true;
	}
}
void TablaUsuarios::ordenarTablaUsuarios(){

	//Declaración de variables
	int opcion = 0;
	int buscar = 0;
	
	//Submenú ordenar.
	cout << BLUE << "\n******************************";
	cout << "\n[1] Ordenar por Login ";
	cout << "\n[2] Ordenar por el total fotos. ";
	cout << "\n******************************" << DEFAULT << endl;
	cout << "Seleccione el criterio por el que quiere ordenar: " << endl;
	cin >> opcion;
	
	//Dependiendo de la opción que desee el usuario entrará en la opcion 1 o 2, en caso contrario mostraremos un mensaje de error.
	if(opcion == 1){
		cout  << " ****    ORDENANDO TABLA DE USUARIOS POR LOGIN    **** " << endl;
		ordenamosLogin(tu);
		cout << GREEN << "La TablaUsuarios se ha ordenado correctamente." << DEFAULT << endl;
		cout << GREEN << "Para Imprimir la Tabla pulse [1] sino presione [0]." << DEFAULT << endl;
		cin >> buscar;
			if(buscar == 1){
				printTablaUsuarios(tu);
			}else if (buscar == 0){
				cout << GREEN << "Muchas gracias." << DEFAULT << endl;
			}
	}
	else if(opcion == 2){
		cout  << " ****    ORDENANDO TABLA DE USUARIOS POR TOTAL FOTOS USUARIO    **** " << endl;
		ordenamosTotalFotosUsuario(tu);
		cout << GREEN << "La TablaUsuarios se ha ordenado correctamente." << DEFAULT << endl;
		cout << GREEN << "Para Imprimir la Tabla pulse [1] sino presione [0]." << DEFAULT << endl;
		cin >> buscar;
			if(buscar == 1){
				printTablaUsuarios(tu);
			}else if (buscar == 0){
				cout << GREEN << "Muchas gracias." << DEFAULT << endl;
			}
	}else{
		cout << YELLOW << "\nLo siento, la opción seleccionada no ha sido añadida todavía. " << DEFAULT << endl;
	}
}
/**
 * @brief Módulo que se encarga de ordenar el vector por Login
 * @param TablaUsuarios tu
 * @pre El vector de usuarios debe de estar relleno  y tener al menos dos usuarios introducidos.
 * @post El vector quedará ordenado por Login
 * @version 1.0
 * @author Carlos Fdez.
 */
void ordenamosLogin(TablaUsuarios &tu){

	Usuario *aux = 0;
	
	if (tu.TotalTuplas > 1){
		for(int i = 0;i < tu.TotalTuplas;i++){
			for(int j= 0; j < tu.TotalTuplas;j++){
				if(tu.punteroapuntero[i]->login < tu.punteroapuntero[j]->login ){
					aux = tu.punteroapuntero[i];
					tu.punteroapuntero[i]=tu.punteroapuntero[j];
					tu.punteroapuntero[j]= aux;
				}
			}
		}
	}else{
		cout << RED << "Lo sentimos, todavía no podemos ordenar porque no hay los usuarios suficientes " << DEFAULT << endl;
		}
}

/**
 * @brief Módulo que se encarga de buscar usuario por Login
 * @param TablaUsuario tu
 * @pre Los usuarios deben de estar introducidos correctamente en el vector.
 * @post Nos dirá en que posición se encuentra el usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void BuscarLogin(TablaUsuarios &tu){

	bool usado=false;
	string login = "";
	unsigned int posicion=0;
	int cont=0;

	//Pedimos al administrador que indique el Login que quiere buscar.
	cout << "Por favor introduzca el login del usuario que quiere conocer su posición. " << endl;
	cin >> login;
	
	//Comprobamos si el login existe. Si existe devuelve usado=true.
	for(int i = 0;i < tu.TotalTuplas;i++){
		comprobacionLogin(login,tu.punteroapuntero[i],usado);
		if(usado == true && cont != 1){
			posicion=i;
			cont++;	
		}
	}
	
	//Si existe el usuario entramos en el if e imprimimos el Usuario, si no existe mostramos un mensaje por pantalla.
	if(usado == true){
		//Mostramos la posición dónde está el usuario.
		cout << BLUE << "El usuario se encuentra en la posición: " << DEFAULT << posicion << endl;
		printUsuario(tu.punteroapuntero[posicion]);
	}else{
		cout << ERROR << "El Login que usted ha elegido no se encuentra en nuestra tabla de usuarios. " << DEFAULT << endl;
	}
}
/**
 * @brief Módulo que se encarga de ordenar el vector por totalFotosUsuario.
 * @param TablaUsuarios tu
 * @pre El vector de usuarios debe de estar relleno  y tener al menos dos usuarios introducidos.
 * @post El vector quedará ordenado por totalFotosUsuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void ordenamosTotalFotosUsuario(TablaUsuarios &tu){

	Usuario *aux = 0;
	
	//Filtro desde uno porque al crear la tabla de usuarios se introducen 7 usuarios predefinidos por lo que TotalTuplas = 7.
	if (tu.TotalTuplas > 1){
		for(int i = 0;i < tu.TotalTuplas;i++){
			for(int j= 0; j < tu.TotalTuplas;j++){
				if(tu.punteroapuntero[i]->totalFotosUsuario < tu.punteroapuntero[j]->totalFotosUsuario ){
					aux = tu.punteroapuntero[i];
					tu.punteroapuntero[i]=tu.punteroapuntero[j];
					tu.punteroapuntero[j]= aux;
				}
			}
		}
	}else{
		cout << RED << "Lo sentimos, todavía no podemos ordenar porque no hay los usuarios suficientes " << DEFAULT << endl;
		}
}

/**
 * @brief Módulo que se encarga de pedir algunos datos al usuario. 
 * @param Usuario *u
 * @pre El módulo insertarUsuarioNuevo debe de estar introducido correctamente.
 * @version 1.0
 * @author Carlos Fdez.
 */
void pedirDatosUsuario(Usuario *u){
	
	string nombre = "";
	string apellido = "";
	string perfilUsuario = "";

	cout << YELLOW << "Nombre: " << DEFAULT << endl;
	cin >> nombre;
	cout << YELLOW << "Apellido: " << DEFAULT << endl;
	cin >> apellido;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT  << endl;
	cin >> perfilUsuario;
	
	setNombre(u,nombre);
	setApellido(u,apellido);
	setPerfilUsuario(u,perfilUsuario);

}
void TablaUsuarios::Salir(){

	//Creamos tabla de usuario para que el usuario no tenga que crear una tabla de usuarios si sólamente quiere salir.
	//tu=crearTablaUsuarios();
	borrarTablaUsuarios(tu);

}


