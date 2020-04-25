//
//	POLINOMIO.cpp
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-2T-CFJ
//
//

//**********COLOR**********//

#define DEFAULT "\033[1;0m"
#define GREY "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define ERROR "\033[1;41m"
//************************//

//********************************************************************************************************//
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/******************************************
** Definición del TIPO DE DATO Polinomio **
******************************************/

class Polinomio{

	private:
		float *coef;				//Vector con los coeficientes
		unsigned int grado;			//Grado actual del polinomio. El grado de un polinomio no puede ser negativo.
		unsigned int max_grado;			//Máximo grado permitido a este polinomio. El grado de un polinomio no puede ser negativo.
	public:
		Polinomio();				//Constructor del polinomio (CrearPolinomio).
		void setCoeficiente(int i, float c);
		float getCoeficiente(int i) const;
		int getGrado() const;
		void printPolinomio() const;
};
/**
 * @brief Se crea un polinomio estático y reservamos memoria para el vector de coeficientes.
 * @post Tendrémos creado un polinomio y se reservará memoria para el vector de coeficientes.
 * @version 1.5
 * @author Carlos Fdez.
 */
Polinomio::Polinomio(){

	max_grado=0;
	float *c;
	c = new float [max_grado];
	coef=c;

}
/**
 * @brief Insertamos el valor del coeficiente en la posición del iterador i que el pasamos en el método.
 * @param int i
 * @param float c
 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
 * @post Insertaremos el coeficiente en la posición que deseamos.
 * @version 1.0
 * @author Carlos Fdez.
 */
void Polinomio::setCoeficiente(int i, float c){

	coef[i]=c;
}
/**
 * @brief Devolvemos el valor que tenemos dentro del miembro Coeficiente en la posición determinada por el indicador [i]
 * @version 1.0
 * @author Carlos Fdez.
 */
float Polinomio::getCoeficiente(int i) const{

	return coef[i];
}
/**
 * @brief Devolvemos el valor que tenemos dentro del miembro grado.
 * @version 1.0
 * @author Carlos Fdez.
 */
int Polinomio::getGrado() const{

	return grado;
}
/**
 * @brief Imprimimos el Polinomio.
 * @param int i
 * @param 
 * @pre 
 * @post 
 * @version 1.0
 * @author Carlos Fdez.
 */
void printPolinomio(unsigned int max_grado) const{

	for(int i=0; i < max_grado;i++){
		cout << "Coeficiente: " << getCoeficiente(i) << endl;
	}

}


int main(){

	int x = 0;
	Polinomio p1;		//Invocación de constructor..

	p1.setCoeficiente(0,3);
	p1.getCoeficiente(0);
	

}
