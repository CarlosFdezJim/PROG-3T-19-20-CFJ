//
//	librería TablaUsuarios.h
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "Usuario.h"
using namespace std;

class TablaUsuarios{

	private:
	
		bool DEBUG;
		Usuario** punteroapuntero;	//Vector Dinámico de Punteros a Burbuja.
		int TotalTuplas;		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.

	public:
		/**
		* @brief Método que cambia el valor de la variable booleana DEBUG.
		* @param bool DEBUG 	//Por defecto será true al no poder darle valor.
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
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		void modoDEBUG(bool DEBUG);
		
		
		/**
		 * @brief Este módulo se encarga de crear la TablaUsuarios. Creando en el siguiente orden :
		 *		1º Inicializamos los valores propios de la clase TablaUsuario a 0.
		 *		2º Creamos la el vector punteroapuntero que es de tipo Usuario.
		 * @pre Debemos de tener bien hecho los módulos setTotalTuplas y getTotalTuplas, porque lo utilizaremos en la creación de este método.
		 * @post Crearemos de manera correcta la TablaUsuario y el vector de punteros de Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		TablaUsuarios();

		/**
		 * @brief Este módulo se encarga de borrar la TablaUsuarios. Eliminando en el siguiente orden :
		 *		1º Borramos el contenido del vector de punteros de Usuario y ponemos TotalTuplas a 0.
		 *		2º Borramos el vector dinámico de punteros y su dirección.
		 *		3º Borramos la estructura TablaUsuarios y los datos introducidos y ponemos a 0 su puntero.
		 * @param TablaUsuarios tu (E/S)
		 * @pre Debemos de tener bien hecho el módulo borrarUsuario, sino se nos quedarán cosas en el limbo.
		 * @post Se librerará toda la memoria dinámica en el orden adecuado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		~TablaUsuarios();
		
		
		/**
		 * @brief Este método se encarga de almacenar el valor de TotalTuplas con el valor pasado por referencia.
		 * @param int TotalTuplas.
		 * @post Se alamacenará en la variable estructurada TablaUsuarios el valor de TotalTuplas.(Las útiles del vector de usuarios llamado 			 * 	PunteroAPuntero).
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTotalTuplas(int TotalTuplas);
		/**
		 * @brief Devuelve el valor actual de el miembro TotalTuplas.
		 * @param TablaUsuarios tu (E/S)
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		int getTotalTuplas();
		
		
		/**
		* @brief Método que realiza un Testing: 
		* @pre Tener bien creados los módulos a testar.
		* @post Realizaremos un testing automatizado.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void Testing();
		/**
		* @brief Testing Automático
		* @pre Tener bien creados los módulos a testar.
		* @post Realizaremos un testing automatizado.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void TestingAutomatico();
		
		
		
		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		void credentials(string pass, string contrasena, bool &usado);

		
		
		/**
		 * @brief Módulo que se encarga de insertar en la Tabla de Usuarios algunos usuarios predefinidos (dedicados a hacer pruebas).
		 * @pre Deberemos tener bien hecho el método para ingresar los usuarios.
		 * @post Los usuarios serán introducidos en la Tabla de Usuarios.
		 * @version 2.2
		 * @author Carlos Fdez.
		 */
		void usuariosPredefinidos();
		
		
		
		/**
		* @brief Imprimiremos la tabla Usuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printTablaUsuarios();
		
		
		
		/**
		 * @brief Módulo que se encarga de comprobar el login de un usuario para saber si está usado o no, devuelve una posición y un booleano.
		 * @param int i
		 * @param bool usado.
		 * @pre La TablaUsuarios debberá de tener al menos un usuario ingresado
		 * @post Sabremos si el login introducido está usado o no y la posición en caso de estar usado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void comprobacionLogin2(bool &usado, unsigned int &posicion);
		
		
		
		/**
		* @brief Método que se usa para insertar a los usuario en la TablaUsuarios.
		* @pre Debes tener creado los usuarios.¡OJO!Este método sólamente sirve para añadir los usuarios ya creados, para introducir un usuario nuevo, hay 			* 	otro método creado llamado insertarUsuarioNuevo().
		* @post Se insertarán los usuarios con los valores ya creados previamente.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void insertarUsuarioTablaUsuarios(Usuario *u);
		
		
		
		/**
		* @brief Método que se usa para hacer crecer o decrecer el vector. 
		* @post Tendrémos un vector de mayor/menos dimensión.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void resize(int DIM);
		
		
		
		/**
		* @brief Insertaremos un usuario en el vector de usuarios
		* @pre Debemos de tener memoria suficiente para Insertarlo
		* @author Carlos Fdez
		* @version 1.0
		*/
		void insertarUsuarioNuevo();
		
		
		
		/**
		* @brief Eliminaremos el usuario en la posición indicada.
		* @pre Deberemos de tener un usuario en esa posición.
		* @post El usuario de esa posición se eliminará
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarUsuario(int posicion);
		/**
		* @brief Eliminamos un usuario de la tablaUsuarios
		* @pre Deberemos de tener al menos un usuario introducido
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarUsuarioTablaUsuarios();
		
		
		
		/**
		 * @brief Módulo que se encarga de buscar usuario por Login
		 * @pre Los usuarios deben de estar introducidos correctamente en el vector.
		 * @post Nos dirá en que posición se encuentra el usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void BuscarLogin();
		/**
		 * @brief Este módulo se encarga de dar dos opciones para ordenar el menú o por Login o por totalFotosUsuario.
		 * @param TablaUsuarios tu (E/S)
		 * @pre El vector de usuarios debe de estar relleno  y tener al menos dos usuarios introducidos.
		 * @post El vector quedará ordenado por según el criterio seleccionado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void ordenarTablaUsuarios();
		/**
		 * @brief Módulo que se encarga de ordenar el vector por Login
		 * @pre El vector de usuarios debe de estar relleno  y tener al menos dos usuarios introducidos.
		 * @post El vector quedará ordenado por Login
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void ordenamosLogin();
		/**
		 * @brief Módulo que se encarga de ordenar el vector por totalFotosUsuario.
		 * @param TablaUsuarios tu
		 * @pre El vector de usuarios debe de estar relleno  y tener al menos dos usuarios introducidos.
		 * @post El vector quedará ordenado por totalFotosUsuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void ordenamosTotalFotosUsuario();
		
		
		
		/**
		* @brief Método que se encarga de eliminar todos los usuarios que tengan menos fotos que fotos_min, para ello pediremos al usuario introduzcan un 			* 	número que será las fotos mínimas que debe de tener el usuario para no ser eliminado.
		* @pre Deberemos de tener al menos introducidos más de un usuario, y además tener más de una foto cada usuario.
		* @post Eliminaremos el usuario que tenga menos de "fotos_min"
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarUsuariosFotosMin();
		/**
		* @brief Eliminaremos la foto del usuario indicado.
		* @pre Deberemos de tener al menos una foto insertada.
		* @post La foto será eliminada.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarFotoUsuario();
		/**
		* @brief Insertaremos la foto en el vector de fotos del usuario.
		* @post Quedará la foto insertada en el vector de su usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void insertarFoto();
		
		
		
		/**
		* @brief Imprime por pantalla las fotos que tiene el usuario.
		* @pre Tenemos que tener alguna foto ingresada de caso contrario mostrará un mensaje advirtiendo.
		* @post Imprimimos todas las fotos del usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printFotosUsuario();
		/**
		 * @brief Módulo que se encarga de pedir algunos datos al usuario. 
		 * @param Usuario *u
		 * @pre El módulo insertarUsuarioNuevo debe de estar introducido correctamente.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		 
		 
		 
		void pedirDatosUsuario(Usuario *u);
		/**
		 * @brief Módulo que se encarga de liberar toda la memoria dinñamica que hemos utilizado en nuestro programa.
		 * @post El programa no dejará ningún dato en el limbo, porque todo será borrado y puesto a 0/NULL
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void Salir();
};
