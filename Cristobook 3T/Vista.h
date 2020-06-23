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
		* @post Crearemos los atributos de la clase TablaUsuarios, pasándole parámetros.
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
		* @brief Método que recoge los datos para comprobar que el usuario que desea ingresar es un usuario Administrador.
		* @pre Deberemos de tener los usuarios creador una vez creamos la TablaUsuarios.
		* @post Sólamente accederá al menú los usuarios Administrador.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void credentials();
		/**
		* @brief Comprobamos que el Login existe en nuestra TablaUsuarios
		* @param string Login
		* @param int posicion
		* @param bool usado
		* @pre Deberemos de tener insertado algún Login en nuestra TablaUsuarios, aunque sino está manda un mensaje de error.
		* @post Devolveremos un bool usado, si existe el login en nuestra TablaUsuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void comprobacionLogin(string &Login, int &posicion, bool &usado);
		/**
		* @brief Método que se encarga de realizar una comprobación por si quieres imprimir o no la tabla.
		* @pre Debemos de tener bien hecho el método para imprimir la Tabla.
		* @post Depende de la opción que nos de el Usuario, imprimiremos o no la TablaUsuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printcheck();
		
		/**
		* @brief
		* @pre
		* @post
		* @author Carlos Fdez
		* @version 1.0
		*/
		void dataPhoto(string ruta, string tipo);
		/**
		* @brief Método que se encarga de pedir un Login al usuario y comprobar si existe o no, si no existe da la opción al usuario para crear un nuevo 			*	usuario de dos tipos, Admin o Normal, insertandolo después en la TablaUsuarios.
		* @pre Debemos de tener creada la TablaUsuarios
		* @pre Debemos de tener bien hecho el insertar Usuario
		* @pre Debemos de tener bien configurado la opción para crear Usuarios Normal o Usuarios Admin
		* @post Método que ingresa un Usuario en la TablaUsuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void insertUser();
		/**
		* @brief Método que eliminará un usuario de la TablaUsuarios, este módulo pedirá un Login al usuario y comprobará si existe. Si existe lo eliminará.
		* @pre Debemos de tener al menos un usuario insertado en la TablaUsuarios.
		* @post Eliminaremos un usuario de la TablaUsuarios.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void deleteUser();
		/**
		* @brief Método que se encarga de buscar un usuario pidiendo el Login al usuario y a continuación mostraremos su perfil.
		* @pre Debemos de tener al menos un usuario insertado en la TablaUsuariosñ.
		* @post Mostraremos por pantalla toda la información de un Usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void searchUser();
		/**
		* @brief Método que muestra un menú por pantalla, dónde nos dará a elegir entre dos opciones:
		*	1) Ordenar TablaUsuarios por Login.
		*	2) Ordenar TablaUsuarios por TotalFotosUsuarios.
		* @pre Debemos de tener al menos dos usuarios insertados en TablaUsuario.
		* @post Mostraremos por pantalla la ordenación por la opción que nos ha indicado el usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void sortTable();
		/**
		* @brief Método que se encarga de pedir un Login al usuario para comprobar si existe o no, si existe muestra los datos para que ingresemos la imagen 			*	en el vector de fotos de determinado Usuario.
		* @post Insertaremos en el vector de fotos la nueva foto.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void insertPhoto();
		/**
		* @brief Método que se encarga de pedir un Login al usuario para comprobar si existe o no, si existe nos muestra el Usuario elegido y nos pide que 			*	indiquemos que imagen queremos borrar, a continuación borraremos la foto del usuario y volverá a mostrar el Usuario para comprobar que se ha 			*	eliminado correctamente.
		* @pre Debemos de indicar un número de foto  válida del usuario, de no ser así mandará un mensaje por pantalla.
		* @post Eliminaremos una foto del Usuario que deseemos, ¡OJO! recuerda que los Administradores no pueden tener fotos.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void deletePhoto();
		/**
		* @brief Imprimirá por pantalla todas las fotos de un usuario que le indiquemos.
		* @pre Deberemos de tener al menos un usuario en nuestra base de datos.
		* @post Imprimiremos por pantalla un usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void printPhotoUser();
		/**
		* @brief Método que pide al usuario el valor que como mínimo de fotos que tiene que tener un Usuario para no ser borrado.
		* @pre Deberemos de tener al menos un usuario ingresado en la TablaUsuarios.
		* @post Eliminaremos los usuarios que no cumplan con dichas fotos.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void deleteUserPhotoMin();
		/**
		* @brief Método que se encarga de mostrar un menú y llamar al testing indicado.
		* @post Realizaremos el testing que desee el usuario.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void MenuTesting();
		/**
		* @brief Módulo que realiza un testing automático:
		*	1º) Imprime TablaUsuario
		*	2º) Ordena por Login
		*	3º) Elimina dos usuarios
		*	4º) ImprimeTablaUsuario
		*	5º) Inserta una Foto en un usuario.
		* @pre Deberemos de tener bien hechos los módulos printTablaUsuario(), ordenamosLogin(), eliminarUsuario() e insertarFoto()
		* @post Tendrémos un testing abarcando muchas posibilidades de error.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void TestingAutomatico();
		/**
		* @brief Módulo que realiza un testing automático:
		*	2º) ImprimeTablaUsuario
		*	3º) Elimina TablaUsuario
		*	1º) Crea TablaUsuario
		*	5º) ImprimeTablaUsuario
		*	6º) Crea tres usuarios
		*	7º) ImprimeTablaUsuario
		*	8º) Elimina dos usuarios
		*	9º) Ordena por Login
		*	10º) Inserta una Foto en un usuario.
		* @pre Deberemos de tener bien hechos los módulos TablaUsuarios(), printTablaUsuario(), ~TablaUsuarios(), insertUser(), eliminarUsuario(), ordenamosLogin(),  e insertarFoto()
		* @post Tendrémos un testing abarcando muchas posibilidades de error.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void TestingAutomatico2();
		/**
		 * @brief Módulo que se encarga de liberar toda la memoria dinñamica que hemos utilizado en nuestro programa.
		 * @post El programa no dejará ningún dato en el limbo, porque todo será borrado y puesto a 0/NULL
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void exit();
		/**
		* @brief Muestra una vista del menú donde el usuario podrá elegir que opción seleccionar.
		* @pre Deberemos de tener bien creado un módulo printMenu dónde seleccionaremos tendremos las opciones dadas al usuario.
		* @post Mostraremos por pantalla una vista de todas las opciones disponibles en el menú.
		* @author Carlos Fdez
		* @version 1.0
		*/
		void menuVista();
		
};
