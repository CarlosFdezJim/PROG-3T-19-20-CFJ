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
//#include "Vista.h"
//#include "TablaUsuarios.h"
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
		Foto* crearFoto();
		/**
		 * @brief Módulo que borrará el espacio de memoria reservado a Foto, borrando primero los miembros y después borramos el punteros.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @pre Se deberá de tener al menos una foto insertada.
		 * @post Se eliminará un espacio de memoria de Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void borrarFoto(Foto *f);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto en una variable string llamada ruta.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @param string ruta		//Nombre de la ruta donde se va a almacenar la foto.
		 * @post Se almacenará en la variable estructurada Foto la ruta de dónde está almacenada.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setRuta(Foto *f, string ruta);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto una variable string llamada tipo.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @param string tipo		//Formato de la foto.
		 * @post Se almacenará en la variable estructurada Foto el formato de la foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTipo(Foto *f, string tipo);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Foto una variable de tipo long int llamada tamanio.
		 * @param Foto *f		//Puntero de tipo foto.
		 * @param unsigned long int tamanio.	//Tamaño de la foto, esto dependerá de el tipo del formato que tenga la foto.
		 * @pre El tamanio no puede ser números negativos, por eso usamos "unsigned".
		 * @post Nos devuelve la variable tamanio de un tipo estructurado de Foto.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setTamanio (Foto *f, unsigned long int tamanio);
		/**
		 * @brief Este módulo se encarga de almacenar en el puntero de tipo Usuario una variable int llamada v_fotos.
		 * @param Usuario *u		//Puntero de tipo Usuario.
		 * @param Foto *f		//Puntero de tipo Foto.
		 * @post Se almacenará en la variable estructurada Usuario la cantidad de fotos que puede almacenar del usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void setV_Fotos(Usuario *u, Foto *f);
		//-----------------------------//
		string getRuta(Foto *f);
		string getTipo(Foto *f);
		int long unsigned getTamanio (Foto *f);
};
