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
		float *coef;				//Array con los ceficientes
		int grado;				//Grado actual del polinomio
		int max_grado;				//Máximo grado permitido a este polinomio.
	public:
		Polinomio();				//Constructor del polinomio (CrearPolinomio).
		void SetCoeficiente(int i, float c);
		float GetCoeficiente(int i) const;
		int getGrado() const;
		void printPolinomio() const;
};

/**************************************************************
 **  Implementación de los Métodos del Tipo de Polinomio  **
 *************************************************************/
Polinomio::Polinomio();

int main(){

	Polinomio p1;		//Invocación de constructor.
//	Poliminio p2;		//Invocación de segundo constructor.

	









}
