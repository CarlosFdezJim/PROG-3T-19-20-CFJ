//
//	librería Usuario.h
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Foto.h"
using namespace std;

class Usuario{

	protected:
	
		string login;		//Debe ser único.
		string nombre;		//Nombre del usuario
		string apellido;	//Apellido del usuario
		string perfil_usuario;	//Perfil del Usuario. Administrador o Usuario Normal.
		
	
	public:
		/**
		 * @brief Se reservará un espacio de memoria para crear un nuevo Usuario y sus miembros, siempre y cuando haya memoria suficiente.
		 * @post Se reservará un espacio de memoria para la Usuario.
		 * @pre Debe de teber memoria suficiente para crear un Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		Usuario();
		/**
		* @brief Constructor por parámetros. Este contructor introduce automáticamente los parámetros en los datos del Usuario.
		* @post Se reservará un espacio de memoria para la Usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		Usuario(string login, string nombre, string apellido, string perfil_usuario);
		/**
		 * @brief Módulo que borrará el espacio de memoria reservado a un Usuario, borrando primero los datos del usuario y después borramos los punteros.
		 * @post Se liberará un espacio de memoria al borrar a un usuario.
		 * @pre Se deberá de tener al menos un usuario insertado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		virtual ~Usuario();
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada login.
		 * @param string login		//Login del usuario.
		 * @post Se almacenará en la variable estructurada Usuario el login del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setLogin(string login);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada nombre.
		 * @param string nombre		//Nombre del usuario.
		 * @post Se almacenará en la variable estructurada Usuario el nombre del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setNombre(string nombre);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada apellido.
		 * @param string apellido	//Apellido del usuario.
		 * @post Se almacenará en la variable estructurada Usuario el apellido del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setApellido(string apellido);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada perfil_usuario que almacenará el nombre del 			 * 	juego al que el usuario quiere jugar.
		 * @param Usuario *u			//Puntero de tipo Usuario.
		 * @param string perfil_usuario		//Nombre del juego al que juega el usuario.
		 * @post Se almacenará en la variable estructurada Usuario el juego favorito del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setPerfilUsuario(string perfil_usuario);
		/**
		 * @brief Devuelve el puntero Login de una variable estructurada de tipo Usuario.
		 * @param Usuario *u		//Puntero de tipo Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getLogin();
		/**
		 * @brief Devuelve el puntero Nombre de una variable estructurada de tipo Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		string getNombre();
		/**
		 * @brief Devuelve el puntero Apellido de una variable estructurada de tipo Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		string getApellido();
		/**
		 * @brief Devuelve el puntero Perfil_Usuario de una variable estructurada de tipo Usuario.
		 * @param Usuario *u		//Puntero de tipo Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getPerfilUsuario();
		/**
		 * @brief Imprime por pantalla el contenido de una variable estructurada de tipo Usuario.
		 * @post Imprimir un Usuario seleccionado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		virtual void printUsuario();
		/**
		 * @brief Módulo que me muestra las fotos tengo en el vector de fotos.
		 * @param Foto *v_fotos
		 * @pre El vector de fotos tiene que estar creado y tener por lo menos una foto.
		 * @post Se mostrará el vector de fotos al usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void printVectorFotos();
		/**
		 * @brief Módulo que inserta una foto en el vector de fotos de cada usuario.
		 * @param TablaUsuarios tu (E/S)
		 * @pre El usuario debe de estar insertado correctamente.
		 * @post Se insertará una foto al usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		 
		//void insertarFoto(TablaUsuarios &tu);
		/**
		 * @brief En éste módulo insertaremos los usuarios predefinidos en una TablaUsuarios que hemos creado previamente.
		 * @pre Deberemos haber creado la tabla de usuarios previamente.
		 * @post Insertaremos en la tabla de usuarios los usuarios que querámos.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		//void insertarUsuarioTablaUsuarios(TablaUsuarios *tu);
		/**
		 * @brief Este módulo ingresa un usuario en la TablaUsuarios
		 * @param TablaUsuarios tu (E/S)
		 * @pre La tabla ha tenido que ser creada previamente.
		 * @post El usuario aparecerá en la TablaUsuarios.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		//void insertarUsuarioNuevo(TablaUsuarios &tu);
		/**
		 * @brief Este módulo se va a encargar de borrar el usuario seleccionado de la tabla.
		 * @param TablaUsuarios tu
		 * @pre La tabla de usuarios deberá estar creada.
		 * @post Se elimnará el usuario selecionado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		//void eliminarUsuarioTablaUsuarios(TablaUsuarios &tu);
		/**
		 * @brief Módulo que se encarga de borrar la foto del usuario y ordenar el vector de fotos
		 * @param TablaUsuarios tu (E/S)
		 * @pre El usuario debe de tener al menos una foto introducida.
		 * @post Al usuario seleccionado se le eliminará la foto de su vector de fotos.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		//void eliminarFotoUsuario(TablaUsuarios &tu);
};
class Admin: public Usuario{

	protected:
		
		int consultas;
		
	public:
		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		Admin();
		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		Admin(string login, string nombre, string apellido, string perfil_usuario);
		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		virtual ~Admin();
		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarUsuarioTablaUsuarios();
		/**
		* @brief Imprime los atributos propios de la clase Normal.
		* @post Imprimiermos SÓLAMENTE los atributos propios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		//virtual void printUsuario();


};
class Normal: public Usuario{

	protected:
		
		Foto* v_fotos;	//Vector Dinámico de Burbujas.
		int DIM_vfotos;		//Dimensión del vector.
		int totalFotosUsuario;	//utiles del vector
	public:
	
		/**
		* @brief Constructor de la clase Normal.
		* @pre Debemos de tener creada la clase Usuario perfectamente.
		* @post Crearemos una clase que hereda los atributos desde la clase padre(class Usuario).
		* @author Carlos Fdez
		* @version 1.0
		*/
		Normal();
		/**
		* @brief Constructor de la clase Normal pasando los parámetros.
		* @pre Debemos de tener creada la clase Usuario perfectamente.
		* @post Crearemos una clase que hereda los atributos desde la clase padre(class Usuario).
		* @author Carlos Fdez
		* @version 1.0
		*/
		Normal(string login, string nombre, string apellido, string perfil_usuario);
		/**
		* @brief Destructor de la clase Normal.
		* @pre Debemos de tener creada la clase Usuario perfectamente.
		* @post Crearemos una clase que hereda los atributos desde la clase padre(class Usuario).
		* @author Carlos Fdez
		* @version 2.0
		*/
		~Normal();
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada totalFotosUsuario.
		 * @param Usuario *u		//Puntero de tipo Usuario.
		 * @param int totalFotosUsuario	//Total de fotos que almacena actualmente el usuario.
		 * @post Se almacenará en la variable estructurada Usuario el total de fotos que tiene actualmente el usuario del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setTotalFotosUsuario(int totalFotosUsuario);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada v_fotos.
		 * @param Usuario *u		//Puntero de tipo Usuario.
		 * @param Foto *f		//Puntero de tipo Foto.
		 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setV_Fotos(int i);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada DIM_vfotos.
		 * @param int DIM_vfotos	//Dimensión de fotos que puede almacenar el usuario.
		 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar el usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setDIM_vfotos(int DIM_vfotos);
		/**
		 * @brief Devuelve una posición del vector de fotos de un Usuario concreto.
		 * @param int i
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		Foto getv_fotos(int i);
		/**
		 * @brief Devuelve el puntero DIM_vfotos de una variable estructurada de tipo Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		int getDIM_vfotos();
		/**
		 * @brief Devuelve el puntero totalFotosUsuario de una variable estructurada de tipo Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		int getTotalFotosUsuario();
		/**
		* @brief Imprime los atributos propios de la clase Normal.
		* @post Imprimiermos SÓLAMENTE los atributos propios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		//virtual void printUsuario();

};
