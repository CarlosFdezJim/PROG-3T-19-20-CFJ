//
//	Librería Vista.h
//
//	Created by Carlos Fdez
//	https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "TablaUsuarios.h"
using namespace std;

class Vista{

	private:
		bool DEBUG;
		TablaUsuarios *tu;
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
		* @brief Método que cambia el estado de la variable booleana DEBUG para activar o desactivar el DEBUG.
		* @pre Tendremos que tener bien hecho los set y get de la variable booleana DEBUG.
		* @post Cambiamos el valor de la variable boolenana DEBUG.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void modoDEBUG(bool DEBUG);
		
		
		/**
		* @brief Método para crear la vista del Usuario.
		* @post Crearemos los atributos de la clase vista, incluyendo la TablaUsuario.
		* @author Carlos Fdez.
		* @version 1.0
		*/
		Vista();
		/**
		* @brief Destructor de la clase vista.
		* @pre Debemos de tener creado correctamente el método vista.
		* @post Liberaremos la memoria creada al crear TablaUsuarios.
		* @author Carlos Fdez.
		* @version 1.0
		*/
		~Vista();
		
		
		
		/**
		* @brief Muestra una vista del menú donde el usuario podrá elegir que opción seleccionar.
		* @pre Deberemos de tener bien creado un módulo printMenu dónde seleccionaremos tendremos las opciones dadas al usuario.
		* @post Mostraremos por pantalla una vista de todas las opciones disponibles en el menú.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void menuVista();

		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		void credentials();
};
