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
	
		string login;		//Debe ser único, se usará para inicia sesión.
		string nombre;		//Nombre del usuario.
		string apellido;	//Apellido del usuario.
		string perfil_usuario;	//Perfil del Usuario. Administrador o Usuario Normal.
		bool DEBUG;

	
	public:
		/**
		* @brief Método que cambia el valor de la variable booleana DEBUG.
		* @param bool DEBUG
		* @post Introduciremos en la variable booleana DEBUG un valor true/false para activar y desactivar el modo DEBUG.
		* @author Carlos Fdez.
		* @version 1.0
		*/
		void setDEBUG(bool DEBUG);
		/**
		* @brief Método que devuelve el valor de la variable booleana DEBUG.
		* @post Devolveremos el valor que tenga introducido la variable booleana DEBUG.
		* @author Carlos Fdez
		* @version 1.0
		*/
		bool getDEBUG();
		/**
		* @brief Método que cambia el estado de la variable booleana DEBUG para activar o desactivar el DEBUG.
		* @pre Tendremos que tener bien hecho los set y get de la variable booleana DEBUG.
		* @post Cambiamos el valor de la variable boolenana DEBUG.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void modoDEBUG(bool DEBUG);
		
		
		
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
		* @brief Constructor por copia(parámetros). Este contructor introduce automáticamente los parámetros en los datos del Usuario.
		* @post Se reservará un espacio de memoria para la Usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		Usuario(Usuario &u);
		/**
		* @brief Constructor por copia (puntero). Este contructor introduce automáticamente los parámetros en los datos del Usuario.
		* @post Se reservará un espacio de memoria para la Usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		Usuario(Usuario *u);
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
		 * @param string login.
		 * @post Se almacenará en la variable estructurada Usuario el login del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setLogin(string login);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada nombre.
		 * @param string nombre.
		 * @post Se almacenará en la variable estructurada Usuario el nombre del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setNombre(string nombre);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada apellido.
		 * @param string apellido.
		 * @post Se almacenará en la variable estructurada Usuario el apellido del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setApellido(string apellido);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable string llamada perfil_usuario que almacenará el 			 * 	tipo de usuario, ADMIN o NORMAL.
		 * @param string perfil_usuario
		 * @post Se almacenará el tipo de dato del usuario que vamos a utilizar.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setPerfilUsuario(string perfil_usuario);
		
		
		
		/**
		 * @brief Devuelve el valor Login de un de tipo Usuario.
		 * @post Devolveremos el valor del Login de ese Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getLogin();
		/**
		 * @brief Devuelve el valor Nombre de un de tipo Usuario.
		 * @post Devolveremos el valor del Nombre de ese Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		string getNombre();
		/**
		 * @brief Devuelve el valor Apellido de un de tipo Usuario.
		 * @post Devolveremos el valor del Apellido de ese Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		string getApellido();
		/**
		 * @brief Devuelve el valor Perfil_Usuario de un de tipo Usuario.
		 * @post Devolveremos el valor del Perfil de usuario de ese Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getPerfilUsuario();
		
		
		
		/**
		 * @brief Imprime por pantalla el contenido de un tipo Usuario.
		 * @post Imprimir un Usuario seleccionado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		virtual void printUsuario();
		/**
		 * @brief Módulo que me muestra las fotos de un vector de fotos.
		 * @pre El vector de fotos tiene que estar creado y tener por lo menos una foto.
		 * @post Se mostrará el vector de fotos de un Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void printVectorFotos();
		
		
		
		/**
		 * @brief Sobrecarga del operador << 
		 * @post Se utiliza para poder imprimir un usuario de tipo Usuario utilizando simplemente este operador.
		 * Ejemplo --> cout << Carlos.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Usuario *u);
		/**
		 * @brief Sobrecarga del operador <<  por referencia.
		 * @post Se utiliza para poder imprimir un usuario de tipo Usuario utilizando simplemente este operador.
		 * Ejemplo --> cout << Carlos.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Usuario &u);
		/**
		* @brief Sobrecarga del operador = por referencia.
		* @post Se utiliza para copiar los miembros de un Usuario en otro.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void operator=(Usuario &u);
		/**
		* @brief Sobrecarga del operador =.
		* @post Se utiliza para copiar los miembros de un Usuario en otro.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void operator=(Usuario *u);
		
		
		
};
class Admin: public Usuario{

	protected:
	
		int consultas;		//Número de consultas que realiza el Administrador.
		
	public:
		/**
		* @brief Constructor de la clase Admin, constructor que utiliza el constructor de Usuario y luego crea sus miembros propios
		* @author Carlos Fdez
		* @version 1.0
		*/
		Admin();
		/**
		* @brief Constructor por parámetros, este contructor hereda los miembros de la clase padre y los incluye en su mismo contructor.
		* @post Construiremos los parámetros en una misma línea.
		* @author Carlos Fdez
		* @version 1.0
		*/
		//Admin(int consultas):Usuario(string login, string nombre,string apellido, string perfil_usuario);
		/**
		* @brief Destructor de la clase Admin, es virtual porque al eliminar un Usuario Admin elimina los miembos de la clase Usuario.
		* @pre Debemos de tener al menos un Usuario Administrador.
		* @author Carlos Fdez
		* @version 1.0
		*/
		virtual ~Admin();
		
		
		/**
		* @brief Método que se utiliza para insertar en el miembro consultas de la clase Admin un número de consultas.
		* @pre No puede ser negativo.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void setConsultas(int consultas);
		/**
		* @brief Método que devuelves cuantas consultas se han realizado.
		* @author Carlos Fdez
		* @version 1.0
		*/
		int getConsultas();
		
		
		
		/**
		* @brief Imprime los atributos propios de la clase Normal.
		* @post Imprimiermos los atributos propios y los de Usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		virtual void printUsuario();
		
		
		
		/**
		 * @brief Sobrecarga del operador << 
		 * @post Se utiliza para poder imprimir un usuario de tipo Admin utilizando simplemente este operador.
		 * Ejemplo --> cout << Carlos.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Admin *a);
		/**
		 * @brief Sobrecarga del operador <<
		 * @post Se utiliza para poder imprimir un usuario de tipo Admin utilizando simplemente este operador.
		 * Ejemplo --> cout << Carlos.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Admin &a);
		/**
		* @brief Sobrecarga del operador =.
		* @post Se utiliza para copiar los miembros de un usuario Admin en otro.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void operator=(Admin &a);
		/**
		* @brief Sobrecarga del operador =.
		* @post Se utiliza para copiar los miembros de un usuario Admin en otro.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void operator=(Admin *a);
		
		

};
class Normal: public Usuario{

	protected:
		
		Foto* v_fotos;		//Vector Dinámico de Burbujas.
		int DIM_vfotos;				//Dimensión del vector.
		int totalFotosUsuario;			//Útiles del vector
		
	public:
	
		/**
		* @brief Constructor de la clase Normal.
		* @pre Debemos de tener creada la clase Usuario perfectamente.
		* @post Crearemos una clase que hereda los atributos desde la clase padre(Usuario).
		* @author Carlos Fdez
		* @version 1.0
		*/
		Normal();
		/**
		* @brief Constructor por parámetros, este contructor hereda los miembros de la clase padre y los incluye en su mismo contructor.
		* @post Construiremos los parámetros en una misma línea.
		* @author Carlos Fdez
		* @version 1.0
		*/
		//Normal(int DIM_vfotos, int totalFotosUsuario):Usuario(login, nombre,apellido,perfil_usuario);
		/**
		* @brief Destructor de la clase Normal.
		* @pre Debemos de tener al menos un Usuario Normal.
		* @post Crearemos una clase que hereda los atributos desde la clase padre(class Usuario).
		* @author Carlos Fdez
		* @version 2.0
		*/
		~Normal();
		
		
		
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada totalFotosUsuario.
		 * @param int totalFotosUsuario
		 * @post Se almacenará en la variable estructurada Usuario el total de fotos que tiene actualmente el usuario del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		void setTotalFotosUsuario(int totalFotosUsuario);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada v_fotos.
		 * @param int i			//Variable que apunta a una foto dentro del vector de fotos.
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
		* @post Imprimiermos los atributos propios y los de Usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		virtual void printUsuario();
		
		
		
		/**
		 * @brief Este módulo se usa para introducir las fotos del usuario predefinido.
		 * @param Foto *f
		 * @pre El resize debe de funcionar correctamente.
		 * @post El usuario tendrá las fotos insertadas en su perfil.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void insertarFotoUsuario(Foto *f);
		/**
		* @brief Redimensiona el vector de fotos.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void resizeFoto(int DIM);
		
		
		
		/**
		 * @brief Sobrecarga del operador << 
		 * @post Se utiliza para poder imprimir un Usuario de tipo Normal utilizando simplemente este operador.
		 * Ejemplo --> cout << Carlos.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Normal *n);
		 /**
		 * @brief Sobrecarga del operador << por referencia.
		 * @post Se utiliza para poder imprimir un Usuario de tipo Normal utilizando simplemente este operador.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Normal &n);
		/**
		* @brief Sobrecarga del operador =.
		* @post Se utiliza para copiar los miembros de un Usuario Normal en otro.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void operator=(Normal &n);
		/**
		* @brief Sobrecarga del operador =.
		* @post Se utiliza para copiar los miembros de un Usuario Normal en otro.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void operator=(Normal *n);


};
