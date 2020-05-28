//
//	Librería Foto.h
//
//	Created by Carlos Fdez
//	https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//


#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Foto{

	private:
		string ruta;			//ruta del archivo en el SO.
		string tipo;			//Tipo de la foto(jpg, png).
		unsigned long int tamanio;	//Se va a guardar en bytes.
	public:
		
		/**
		 * @brief Se reservará un espacio de memoria para crear una estructura de tipo Foto, siempre y cuando haya memoria suficiente.
		 * @post Se reservará un espacio de memoria para la Foto.
		 * @pre Debe de teber memoria suficiente para crear la Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		Foto();
		/**
		 * @brief Módulo que borrará el espacio de memoria reservado a Foto, borrando primero los miembros y después borramos el punteros.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @pre Se deberá de tener al menos una foto insertada.
		 * @post Se eliminará un espacio de memoria de Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		~Foto();
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto en una variable string llamada ruta.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @param string ruta		//Nombre de la ruta donde se va a almacenar la foto.
		 * @post Se almacenará en la variable estructurada Foto la ruta de dónde está almacenada.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setRuta(string ruta);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto una variable string llamada tipo.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @param string tipo		//Formato de la foto.
		 * @post Se almacenará en la variable estructurada Foto el formato de la foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTipo(string tipo);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto una variable de tipo long int llamada tamanio.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @param unsigned long int tamanio.	//Tamaño de la foto, esto dependerá de el tipo del formato que tenga la foto.
		 * @pre El tamanio no puede ser números negativos, por eso usamos "unsigned".
		 * @post Nos devuelve la variable tamanio de un tipo estructurado de Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTamanio(unsigned long int tamanio);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada v_fotos.
		 * @param Usuario *u		//Puntero de tipo Usuario.
		 * @param Foto *f		//Puntero de tipo Foto.
		 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setV_Fotos();
		/**
		 * @brief Devuelve el puntero Ruta de una variable estructurada de tipo Foto.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getRuta();
		/**
		 * @brief Devuelve el puntero Tipo de una variable estructurada de tipo Foto.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getTipo();
		/**
		 * @brief Devuelve el Tamanio de una variable estructurada de tipo Foto.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @pre Está filtrada al usar unsigned int para no introducir números negativos.
		 * @post Nos devuelve la variable edad de un tipo estructurado de alumno.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		int long unsigned getTamanio();
		/**
		 * @brief Imprime por pantalla la ruta de la foto junto a su tipo y el tamaño que ocupa la foto.
		 * @param Foto *f
		 * @post Imprimiremos la ruta de la foto por pantalla.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void printFoto();
		/**
		 * @brief Módulo que se encarga de imprimir el vector de fotografías de un usuario.
		 * @param TablaUsuarios tu
		 * @pre El usuario debe de estar instertado.
		 * @post Se muestran por pantalla las fotografías de ese usuario
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		 void printFotosUsuario();
		 
		 
};
