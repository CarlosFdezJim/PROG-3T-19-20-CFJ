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
		 * @brief Este módulo se encarga de dar dos opciones para ordenar el menú o por Login o por totalFotosUsuario.
		 * @param TablaUsuarios tu (E/S)
		 * @pre El vector de usuarios debe de estar relleno  y tener al menos dos usuarios introducidos.
		 * @post El vector quedará ordenado por según el criterio seleccionado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void ordenarTablaUsuarios();

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
		void UsuariosPredefinidos();
		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printTablaUsuarios();
		/**
		 * @brief Módulo que se encarga de liberar toda la memoria dinñamica que hemos utilizado en nuestro programa.
		 * @param TablaUsuario tu (E/S)
		 * @post El programa no dejará ningún dato en el limbo, porque todo será borrado y puesto a 0/NULL
		 * @version 2.0
		 * @author Carlos Fdez.
		 */
		void Salir();
};
