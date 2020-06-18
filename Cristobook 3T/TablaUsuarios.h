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
	
		bool DEBUG;			//Varianle booleana que se utiliza para activar o no mensajes por pantalla.
		Usuario** punteroapuntero;	//Vector Dinámico de Punteros de Usuarios.
		int TotalTuplas;		//La reserva siempre es exacta y al tamaño, la dimensión, siempre coincide con las útiles.

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
		 * @brief Este módulo se encarga de crear la TablaUsuarios por parámetros. Creando en el siguiente orden :
		 *		1º Inicializamos los valores propios de la clase TablaUsuario al valor que le pasamos pro parámetros.
		 *		2º Creamos la el vector punteroapuntero que es de tipo Usuario.
		 * @pre Debemos de tener bien hecho los módulos setTotalTuplas y getTotalTuplas, porque lo utilizaremos en la creación de este método.
		 * @post Crearemos de manera correcta la TablaUsuario y el vector de punteros de Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		TablaUsuarios(int TotalTuplas);
		/**
		 * @brief Este módulo se encarga de borrar la TablaUsuarios. Eliminando en el siguiente orden :
		 *		1º Borramos el contenido del vector de punteros de Usuario y ponemos TotalTuplas a 0.
		 *		2º Borramos el vector dinámico de punteros y su dirección.
		 *		3º Borramos la clase TablaUsuarios y los datos introducidos y ponemos a 0 su puntero.
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
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		int getTotalTuplas();
		/**
		* @brief Comprueba que el Login introducido por el usuario está en nuestra base de datos.
		* @pre Debemos de tener instroducido al menos un usuario predefinido.
		* @post Devulveremos el valor de la variable booleana usado dependiendo si está en la base de datos o no.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void credentials(string pass, string contrasena, bool &usado);
		/**
		* @brief Comprobamos que el Login existe en nuestra base de datos.
		* @pre Deberemos de tener insertado algún usuario en nuestra TablaUsuarios, aunque sino está manda un mensaje de error.
		* @post Devolveremos un bool usado, si existe el login en nuestra TablaUsuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void comprobacionLoginTU(string &Login, bool &usado,int &posicion);
		/**
		* @brief Imprimiremos la tabla Usuarios por pantalla.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printTablaUsuarios();
		/**
		* @brief Imprime por pantalla un usuario si pasamos su posición en TablaUsuarios
		* @pre Debes de tener al menos un usuario en TablaUsuarios.
		* @post Imprimiremos el usuario que queramos de TablaUsuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printUser(int posicion);
		/**
		 * @brief Módulo que se encarga de insertar en la TablaUsuarios algunos usuarios predefinidos (dedicados a hacer pruebas).
		 * @pre Deberemos tener bien hecho el método para ingresar los usuarios.
		 * @post Los usuarios serán introducidos en la TablaUsuarios.
		 * @version 2.2
		 * @author Carlos Fdez.
		 */
		void dataBase();
		/**
		* @brief Método que se usa para hacer crecer o decrecer el vector de Usuarios.
		* @param DIM 
		* @post Tendremos un vector de mayor/menos dimensión.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void resize(int DIM);
		/**
		* @brief Crearemos un usuario en el vector de usuarios, dependiendo de la opción (Admin/Normal) indicada en por el usuario.
		* @param string Login
		* @param int posicion
		* @pram bool usado
		* @param int opcion
		* @pre Deberemos de tener creada una TablaUsuarios.
		* @post Insertaremos el Usuario en el vector de Usuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void crearUsuario(string Login, int posicion, bool usado, int opcion);
		/**
		* @brief Método que se usa para insertar a los usuario en la TablaUsuarios.
		*@param Usuario *u.
		* @pre Debes tener creado los usuarios. ¡OJO! Este método sólamente sirve para añadir los usuarios ya creados, para introducir un usuario nuevo, hay 			* 	otro método creado llamado insertarUsuarioNuevo().
		* @post Insertará los usuarios ya creados previamente.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void insertarUsuarioTablaUsuarios(Usuario *u);
		/**
		* @brief Eliminaremos el usuario en la posición indicada.
		* @param int posicion
		* @pre Deberemos de tener un usuario en esa posición.
		* @post El usuario de esa posición se eliminará
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarUsuario(int posicion);
		/**
		* @brief Eliminamos un usuario de la tablaUsuarios
		* @param int posicion
		* @param bool usado
		* @pre Deberemos de tener al menos un usuario introducido.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarUsuarioTablaUsuarios(int posicion, bool usado);
		/**
		 * @brief Método que se encarga de buscar usuario por Login en la TablaUsuarios.
		 * @param bool usado
		 * @param int posicion
		 * @pre Debemos de tener al menos un usuario introducido en la TablaUsuarios.
		 * @post Nos dirá en que posición se encuentra el usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void BuscarLogin(bool usado, int posicion);
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
		* @brief Insertaremos la foto en el vector de fotos del usuario.
		* @param int posicion
		* @param bool usado
		* @post Quedará la foto insertada en el vector de su usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void insertarFoto(int posicion, bool usado);
		/**
		* @brief Eliminaremos la foto del usuario indicado.
		* @pre Deberemos de tener al menos una foto insertada.
		* @post La foto será eliminada.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarFotoUsuario(int posicion, bool usado, int elim);
		/**
		* @brief Imprime por pantalla las fotos que tiene el usuario.
		* @pre Tenemos que tener alguna foto ingresada de caso contrario mostrará un mensaje advirtiendo.
		* @post Imprimimos todas las fotos del usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printFotosUsuario(bool usado, int posicion);
		/**
		* @brief Método que se encarga de eliminar todos los usuarios que tengan menos fotos que min, para ello pediremos al usuario introduzcan un 			* 	número que será las fotos mínimas que debe de tener el usuario para no ser eliminado.
		* @pre Debemos de tener al menos un usuario insertado, de lo contrario nos mandará un mensaje de error, y recuerda que los usuarios Admin no se 		* 	puede borrar.
		* @post Eliminaremos el usuario que tenga menos fotos de el número introducido "min".
		* @author Carlos Fdez
		* @version 1.0
		*/
		void eliminarUsuariosFotosMin(int min);
		/**
		* @brief Método que se encarga de pedir al usuario los valores de las fotos que quiere insertar, al usuario cuando ingrese el tipo foto se le dará 			* 	unos formatos predeterminados y se le asiganarán automáticamente el tamaño de la foto, si ingresa un tipo de foto diferente se le dará un 			*	valor por defecto.
		* @pre Deberemos de tener ya programados los set y get de Foto.
		* @post Se ingresará en la fotos los valores dados por el usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void ValoresFoto(Foto *f);
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
