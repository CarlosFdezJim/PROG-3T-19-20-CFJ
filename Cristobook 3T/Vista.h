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
		* @brief Método para crear la vista del Usuario.
		* @post Crearemos los atributos de la clase vista, incluyendo la TablaUsuario.
		* @author Carlos Fdez.
		* @version 1.0
		*/
		Vista();
		/**
		* @brief Método para crear la vista del Usuario con parámetros.
		* @post Crearemos los atributos de la clase vista, pasándole parámetros.
		* @author Carlos Fdez.
		* @version 1.0
		*/
		Vista(int TotalTuplas);
		/**
		* @brief Destructor de la clase vista.
		* @pre Debemos de tener creado correctamente el método vista.
		* @post Liberaremos la memoria creada liberándola en el orden correcto.
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
		* @brief Método que recoge los datos para comprobar que el usuario que desea ingresar es un usuario Administrador.
		* @pre Deberemos de tener los usuarios creador una vez creamos la TablaUsuarios.
		* @post Sólamente accederá al menú los usuarios Administrador.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void credentials();
		/**
		* @brief Comprobamos que el Login existe en nuestra TablaUsuarios
		* @pre Deberemos de tener insertado algún Login en nuestra TablaUsuarios, aunque sino está manda un mensaje de error.
		* @post Devolveremos un bool usado, si existe el login en nuestra TablaUsuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void comprobacionLoginVista(bool &usado);
};
