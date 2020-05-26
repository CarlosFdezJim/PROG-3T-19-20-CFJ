//
//	librería Usuario.h
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Usuario{

	private:
	
	public:
		/**
		 * @brief Se reservará un espacio de memoria para crear un nuevo Usuario y sus miembros, siempre y cuando haya memoria suficiente.
		 * @post Se reservará un espacio de memoria para la Usuario.
		 * @pre Debe de teber memoria suficiente para crear un Usuario.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		Usuario* crearUsuario();
		/**
		 * @brief Módulo que borrará el espacio de memoria reservado a un Usuario, borrando primero los datos del usuario y después borramos los punteros.
		 * @param Usuario *u		//Puntero de tipo Usuario.
		 * @post Se liberará un espacio de memoria al borrar a un usuario.
		 * @pre Se deberá de tener al menos un usuario insertado.
		 * @version 1.0
		 * @author Carlos Fdez.
		 */
		void borrarUsuario(Usuario *u);
		
		string login;		//Debe ser único.
		string nombre;		//Nombre del usuario
		string apellido;	//Apellido del usuario
		string perfil_usuario;	// Nombre de videojuego
		Foto* v_fotos;		//Vector Dinámico de Burbujas.
		int DIM_vfotos;		//Dimensión del vector.
		int totalFotosUsuario;	//utiles del vector
};
//-----------------------------//
void setLogin(Usuario *u, string login);
void setNombre(Usuario *u, string nombre);
void setApellido(Usuario *u, string apellido);
void setPerfilUsuario(Usuario *u, string perfil_usuario);
void setV_Fotos(Usuario *u, Foto *f);
void setDIM_vfotos(Usuario *u, int DIM_vfotos);
void setTotalFotosUsuario(Usuario *u, int totalFotosUsuario);
//-----------------------------//
string getLogin(Usuario *u);
string getNombre(Usuario *u);
string getApellido(Usuario *u);
string getPerfilUsuario(Usuario *u);
Foto getv_fotos(Usuario *u);
int getDIM_vfotos(Usuario *u);
int getTotalFotosUsuario(Usuario *u);
