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

#include "TablaUsuarios.h"
#include "Vista.h"
using namespace std;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Se reservará un espacio de memoria para crear un nuevo Usuario y sus miembros, siempre y cuando haya memoria suficiente.
 * @post Se reservará un espacio de memoria para la Usuario.
 * @pre Debe de teber memoria suficiente para crear un Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
Usuario* crearUsuario(){

	//Reservamos un nuevo espacio de memoria para el usuario y lo inicializamos.
	Usuario *u = 0;
	u = new Usuario;
	
	//Inicializamos el contenido del Usuario.
	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";
	u->v_fotos=0;
	u->DIM_vfotos=0;
	u->totalFotosUsuario=0;
	
	//Reservamos un nuevo espacio de memoria para el vector de fotos que lleva dentro el usuario.
	u->v_fotos = new Foto[u->DIM_vfotos];

	//Si no hay memoria suficiente para crear el Usuario se aborta la ejecución y se sale del programa.
	if (u == 0){
		cerr << "Error. No hay memoria suficiente para crear un nuevo Usuario. Se abortará la ejecución" << endl;
		exit(-1);
	}
	
	//Si no hay memoria suficiente para crear el vector de fotos se aborta la ejecución y se sale del programa.
	if (u->v_fotos == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}
	
	//Devuelvo la dirección que referenciaba al fragmento de memoria(puntero).
	return u;

}
/**
 * @brief Módulo que borrará el espacio de memoria reservado a un Usuario, borrando primero los datos del usuario y después borramos los punteros.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @post Se liberará un espacio de memoria al borrar a un usuario.
 * @pre Se deberá de tener al menos un usuario insertado.
 * @version 1.0
 * @author Carlos Fdez.
 */
void borrarUsuario(Usuario *u){

	//Ponemos los datos del usuario a Null/-1 antes de eliminar el usuario.
	u->login = "";
	u->nombre = "";
	u->apellido = "";
	u->perfil_usuario = "";	
	
	u->DIM_vfotos = 0;
	u->totalFotosUsuario = 0;

	//borro el fragmento de memoria
	delete [] u->v_fotos;
	delete u;
	
	//elimino la dirección que referenciaba al fragmento de memoria(puntero).
	u = 0;
	
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada login.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string login		//Login del usuario.
 * @post Se almacenará en la variable estructurada Usuario el login del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setLogin(Usuario *u, string login){
	u->login = login;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada nombre.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string nombre		//Nombre del usuario.
 * @post Se almacenará en la variable estructurada Usuario el nombre del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setNombre(Usuario *u, string nombre){
    u->nombre = nombre;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada apellido.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param string apellido	//Apellido del usuario.
 * @post Se almacenará en la variable estructurada Usuario el apellido del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setApellido(Usuario *u, string apellido){
    u->apellido = apellido;   
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada perfil_usuario que almacenará el nombre del juego al que el usuario quiere jugar.
 * @param Usuario *u			//Puntero de tipo Usuario.
 * @param string perfil_usuario		//Nombre del juego al que juega el usuario.
 * @post Se almacenará en la variable estructurada Usuario el juego favorito del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setPerfilUsuario(Usuario *u, string perfil_usuario){ 
    u->perfil_usuario = perfil_usuario;
}
/**
 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada totalFotosUsuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @param int totalFotosUsuario	//Total de fotos que almacena actualmente el usuario.
 * @post Se almacenará en la variable estructurada Usuario el total de fotos que tiene actualmente el usuario del usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
void setTotalFotosUsuario(Usuario *u, int totalFotosUsuario){
    u->totalFotosUsuario = totalFotosUsuario;   
}
/**
 * @brief Devuelve el puntero Login de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getLogin(Usuario *u){
    return u->login;
}
/**
 * @brief Devuelve el puntero Nombre de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getNombre(Usuario *u){
    return u->nombre;
}
/**
 * @brief Devuelve el puntero Apellido de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getApellido(Usuario *u){
    return u->apellido;
}
/**
 * @brief Devuelve el puntero Perfil_Usuario de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
string getPerfilUsuario(Usuario *u){
    return u->perfil_usuario;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Devuelve el puntero totalFotosUsuario de una variable estructurada de tipo Usuario.
 * @param Usuario *u		//Puntero de tipo Usuario.
 * @version 1.0
 * @author Carlos Fdez.
 */
int getTotalFotosUsuario(Usuario *u){
    return u->totalFotosUsuario;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Imprime por pantalla el contenido de una variable estructurada de tipo Usuario.
 * @param Usuario *u
 * @post Imprimir un Usuario seleccionado.
 * @version 1.0
 * @author Carlos Fdez.
 */
void printUsuario(Usuario *u){

	//Imprimimos el usuario con todos sus miembros.
	cout << YELLOW << "****************************************" << endl;
	cout << YELLOW <<  "Login: " << DEFAULT << getLogin(u) << endl;
	cout << YELLOW << "Nombre: " << DEFAULT <<  getNombre(u) << endl;
	cout << YELLOW << "Apellido: " << DEFAULT <<  getApellido(u) << endl;
	cout << YELLOW << "Perfil de usuarios: " << DEFAULT <<  getPerfilUsuario(u) << endl;
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


/**
 * @brief Módulo que se encarga de borrar la foto del usuario y ordenar el vector de fotos
 * @param TablaUsuarios tu (E/S)
 * @pre El usuario debe de tener al menos una foto introducida.
 * @post Al usuario seleccionado se le eliminará la foto de su vector de fotos.
 * @version 1.0
 * @author Carlos Fdez.
 */
void eliminarFotoUsuario(TablaUsuarios &tu){

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
/**
 * @brief Este módulo se va a encargar de borrar el usuario seleccionado de la tabla.
 * @param TablaUsuarios tu
 * @pre La tabla de usuarios deberá estar creada.
 * @post Se elimnará el usuario selecionado.
 * @version 1.0
 * @author Carlos Fdez.
 */
void eliminarUsuarioTablaUsuarios(TablaUsuarios &tu){

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

/**
 * @brief Este módulo ingresa un usuario en la TablaUsuarios
 * @param TablaUsuarios tu (E/S)
 * @pre La tabla ha tenido que ser creada previamente.
 * @post El usuario aparecerá en la TablaUsuarios.
 * @version 1.0
 * @author Carlos Fdez.
 */
void insertarUsuarioNuevo(TablaUsuarios &tu){

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
/**
 * @brief En éste módulo insertaremos los usuarios predefinidos en una TablaUsuarios que hemos creado previamente.
 * @param Usuario *u
 * @param TablaUsuarios &tu
 * @pre Deberemos haber creado la tabla de usuarios previamente.
 * @post Insertaremos en la tabla de usuarios los usuarios que querámos.
 * @version 1.0
 * @author Carlos Fdez.
 */
void insertarUsuarioTablaUsuarios(Usuario *u, TablaUsuarios &tu){

	//Resize decrease.
	resizeAumentarPorPunteros(tu,tu.punteroapuntero);
	
	//Insert user in vector
	tu.punteroapuntero[tu.TotalTuplas-1] = u;
}
/**
 * @brief Aumenta la dimensión del vector de uno en uno.
 * @param TablaUsuarios tu (E/S)
 * @param Usuario **v
 * @post Aumentaremos en uno la dimensión de nuestro vector.
 * @version 1.0
 * @author Carlos Fdez.
 */
void resizeAumentarPorPunteros(TablaUsuarios &tu, Usuario **v){
	
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
Usuario** resizeDisminuirPorPunteros(TablaUsuarios &tu, Usuario **u){
	
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

