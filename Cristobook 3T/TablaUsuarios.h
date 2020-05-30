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
		* @brief Método para crear la tabla de Usuarios.
		* @pre Debe de haber espacio para crearla.
		* @post Tendremos creado una vector Polimorfico de punteros a Usuarios
		* @author Carlos Fdez.
		* @version 1.0
		*/
		TablaUsuarios();
		/**
		 * @brief Este módulo se encarga de borrar la TablaUsuarios. Eliminando en el siguiente orden :
		 *		1º Borramos la estructura Foto y los datos introducidos y ponemos a 0 su puntero.
		 *		2º Borramos la estructura Usuario y los datos introducidos y ponemos a 0 su puntero.
		 *		3º Borramos la estructura TablaUsuarios y los datos introducidos y ponemos a 0 su puntero.
		 * @param TablaUsuarios tu (E/S)
		 * @pre Debemos de tener bien hecho el módulo borrarUsuario, sino se nos quedarán cosas en el limbo.
		 * @post Se librerará toda la memoria dinámica en el orden adecuado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		~TablaUsuarios();
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo TablaUsuario una variable int llamada TotalTuplas.
		 * @param TablaUsuarios tu (E/S)
		 * @param int TotalTuplas.
		 * @post Se alamacenará en la variable estructurada TablaUsuarios el tota de tuplas que tiene la tabla.(Las útiles del vector de usuarios llamado 			 * 	PunteroAPuntero).
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTotalTuplas(int TotalTuplas);
		/**
		 * @brief Devuelve el puntero totalFotosUsuario de una variable estructurada de tipo Usuario.
		 * @param TablaUsuarios tu (E/S)
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		int getTotalTuplas();
		/**
		 * @brief Módulo que se encarga de almacenar en la Tabla de Usuarios algunos usuarios predefinidos.
		 * @pre Deberemos tener bien hechos los Set para que no fallen al insertar los usuarios predefinidos.
		 * @post Los usuarios serán introducidos en la Tabla de Usuarios.
		 * @version 2.2
		 * @author Carlos Fdez.
		 */
		void usuariosPredefinidos();
		/**
		* @brief Imprimiremos la tabla Usuarios
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printTablaUsuarios();
		/**
		* @brief Método que se usa para insertar a los usuario en la TablaUsuarios.
		* @pre Debes tener creado los usuarios.¡OJO!Este método sólamente sirve para añadir los usuarios ya creados, para introducir un usuario nuevo, hay 			* 	otro método creado.
		* @post Se insertarán los usuarios ya creados previamente.
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
		 * @brief Módulo que se encarga de liberar toda la memoria dinñamica que hemos utilizado en nuestro programa.
		 * @param TablaUsuario tu (E/S)
		 * @post El programa no dejará ningún dato en el limbo, porque todo será borrado y puesto a 0/NULL
		 * @version 2.0
		 * @author Carlos Fdez.
		 */
		void Salir();
};
