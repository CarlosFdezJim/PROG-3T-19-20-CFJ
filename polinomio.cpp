//
//	POLINOMIO.cpp
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//


//******	COLOR		*********//

#define DEFAULT "\033[1;0m"
#define GREY "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define ERROR "\033[1;41m"

//**************************************//
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/*****************************************
** Definición de la clase Polinomio 	**
*****************************************/

class Polinomio{

	private:
		float *coef;				//Vector con los coeficientes
		int grado;			//Grado actual del polinomio. El grado de un polinomio no puede ser negativo.
		int max_grado;			//Máximo grado permitido a este polinomio. El grado de un polinomio no puede ser negativo.
	public:
		Polinomio();				//Constructor del polinomio (CrearPolinomio).
		Polinomio( int max_grado);
		void setCoeficiente(int i, float c);
		void setGrado(int i);
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

	//Inicializamos los miembros del polinomio.
	max_grado = 10;
	grado = 0;
	
	//Creamos un vector dinámico de coeficientes.
	coef = new float[max_grado+1];

	//Rellenamos el vector de coeficientes 0
	for(int i=0; i <= max_grado; i++){
		coef[i]=0;
	}

}
/**
 * @brief Insertamos el valor del coeficiente en la posición del iterador i que el pasamos en el método.
 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
 * @param float c		//Coeficiente del polinomio.
 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
 * @post Insertaremos el coeficiente en la posición que deseamos.
 * @version 1.0
 * @author Carlos Fdez.
 */
void Polinomio::setCoeficiente(int i, float c){

	//Añadimos en la posicion [i] el coeficiente (c).
	coef[i]=c;

	setGrado(i);

}
/**
 * @brief Introducimos el grado del polinomio en base al valor de [i]
 * @param int i		
 * @pre Debemos de haber introducido algún monimio.
 * @post El grado se guardará en el miembro correspondiente.
 * @version 1.0
 * @author Carlos Fdez.
 */
void Polinomio::setGrado(int i){

	if(i > grado){
		grado=i;
		cout << "Debug: " << endl;
	}else{
		cout << "Debug2: " << endl;
		grado=0.0;
	}
}
/**
 * @brief Devolvemos el valor que tenemos dentro del miembro Coeficiente en la posición determinada por el indicador [i].
 * @pre El coeficiente debe de tener un valor introducido.
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
 * @brief Imprimimos lod diferentes miembros del Polinomio.
 * @post Imprimiremos por pantalla el polinomio.
 * @version 1.0
 * @author Carlos Fdez.
 */
void Polinomio::printPolinomio() const{

	cout << YELLOW << "****************************************" << DEFAULT << endl;
	for(int i=max_grado-1; i <= max_grado && i != 0;i--){
		if(grado != 0.0){
			cout << getCoeficiente(i);
			cout << "x " ;
			cout <<  getGrado();
		}else{
		cout << "Debug3: el grado es igual a 0.0 " << endl;	
		}
		cout << RED << " + " << DEFAULT;
	}
	cout << endl;
	cout << YELLOW << "****************************************" << DEFAULT << endl; 

}
int main(){

	Polinomio p1;		//Invocación de constructor.

	p1.setCoeficiente(0,0);
	p1.setCoeficiente(1,1);
	p1.setCoeficiente(2,2);
	//p1.setCoeficiente(3,3);
	p1.setCoeficiente(4,4);
	p1.setCoeficiente(5,5);
	p1.setCoeficiente(6,6);
	p1.setCoeficiente(7,7);
	p1.setCoeficiente(8,8);
	p1.setCoeficiente(9,9);

	p1.printPolinomio();
	
	//Realizando prueba

}
