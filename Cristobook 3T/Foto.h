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
		string tipo;			//Tipo de la foto ( bmp, jpeg, png, gif).
		unsigned long int tamanio;	//Se va a guardar en bytes.
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
		 * @brief Se reservará un espacio de memoria para crear una clase de tipo Foto, siempre y cuando haya memoria suficiente.
		 * @post Se reservará un espacio de memoria para la Foto.
		 * @pre Debe de teber memoria suficiente para crear la Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		Foto();
		/**
		 * @brief Módulo que borrará el espacio de memoria reservado a Foto, borrando primero los miembros y después borramos el punteros.
		 * @pre Se deberá de tener al menos una foto insertada.
		 * @post Se eliminará un espacio de memoria de Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		~Foto();
		
		
		
		/**
		 * @brief Este módulo se encarga de almacenar en el valor de tipo Foto en una variable string llamada ruta.
		 * @param string ruta		//Nombre de la ruta donde se va a almacenar la foto.
		 * @post Se almacenará en la variable estructurada Foto la ruta de dónde está almacenada.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setRuta(string ruta);
		/**
		 * @brief Este módulo se encarga de almacenar en el valor de tipo Foto una variable string llamada tipo.
		 * @param string tipo		//Formato de la foto.
		 * @post Se almacenará en la variable estructurada Foto el formato de la foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTipo(string tipo);
		/**
		 * @brief Este módulo se encarga de almacenar en el valor de tipo Foto una variable de tipo unsigned long int llamada tamanio.
		 * @param unsigned long int tamanio.	//Tamaño de la foto, esto dependerá de el tipo del formato que tenga la foto.
		 * @pre El tamanio no puede ser números negativos, por eso usamos "unsigned".
		 * @post Nos devuelve la variable tamanio de un tipo estructurado de Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTamanio(unsigned long int tamanio);
		
		
		
		/**
		 * @brief Devuelve el valor Ruta de una variable estructurada de tipo Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getRuta();
		/**
		 * @brief Devuelve el valor Tipo de una variable estructurada de tipo Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		string getTipo();
		/**
		 * @brief Devuelve el valor Tamanio de una variable estructurada de tipo Foto.
		 * @pre Está filtrada al usar unsigned int para no introducir números negativos.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */		
		int long unsigned getTamanio();
		
		
		
		/**
		 * @brief Imprime por pantalla la ruta de la foto junto a su tipo y el tamaño que ocupa la foto.
		 * @post Imprimiremos la ruta de la foto por pantalla.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void printFoto();
		
		
		
		/**
		 * @brief Sobrecarga del operador << 
		 * @post Se utiliza para poder imprimir una foto utilizando simplemente este operador.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Foto *f);
		/**
		 * @brief Sobrecarga del operador << 
		 * @post Se utiliza para poder imprimir una foto utilizando simplemente este operador.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, Foto &f);
		 
		 
};
