//
//	POLINOMIO.cpp
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//

//*********	COLOR		*********//

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
		/**
		 * @brief Se crea un polinomio estático y reservamos memoria para el vector de coeficientes.
		 * @post Tendrémos creado un polinomio y se reservará memoria para el vector de coeficientes y los iniciaremos a 0.
		 */
		Polinomio();				//Constructor del polinomio (CrearPolinomio).
		/**
		 * @brief Se crea un polinomio estático y asignaremos el valor del max_grado del polinomio.
		 * @post Tendrémos creado un polinomio y se reservará memoria para el vector de coeficientes y los iniciaremos a 0.
		 */
		Polinomio( int max);
		/**
		 * @brief Se elimina la memoria dinámica reservada del Polinomio y ponemos los miembros a 0.
		 * @pre Se debe de tener creado el polinomo.
		 * @post Borraremos la memoria del Polinomio creado anteriormente.
		 */
		~Polinomio();
		/**
		 * @brief Insertamos el valor del coeficiente en la posición del iterador i que el pasamos en el método.
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
		 * @post Insertaremos el coeficiente en la posición que deseamos.
		 */
		void setCoeficientev1(int i, float c);
		/**
		 * @brief 
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 */
		void setCoeficientev2(int i, float c);
		/**
		 * @brief Introducimos el grado del polinomio en base al valor de [i]
		 * @param int i		
		 * @pre Debemos de haber introducido algún monomio.
		 * @post El grado se guardará en el miembro correspondiente.
		 */
		void setGrado(int i);
		/**
		 * @brief Introducimos el máximo grado del polinomio en base al valor introducido por el usuario.
		 * @param int i		//Valor que le pedimos al usuario.
		 * @pre Debemos de haber introducido algún monimio.
		 * @post El grado se guardará en el miembro correspondiente.
		 */
		void setMax_Grado(int i);
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro Coeficiente en la posición determinada por el indicador [i].
		 * @pre El coeficiente debe de tener un valor introducido.
		 */
		float getCoeficiente(int i) const;
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro grado.
		 */
		int getGrado() const;
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro max_grado.
		 */
		int getMax_Grado() const;
		/**
		 * @brief Imprimimos el Polinomio.
		 */
		void printPolinomio() const;
		/**
		 * @brief Método que se encarga de pedir los datos de el polinomio deseado.
		 */
		void DatosPolinomio();
		void resizeAumentarPolinomio(int DIM);
		void Testing_0();
		void Testing_1();
		void Testing_2();
		void Testing_3();
		void Testing_4();
		void Testing_5();
		void Testing_5_1();
};
Polinomio::Polinomio(){

	cout  << PURPLE << "\n ****    CREANDO POLINOMIO    **** " << DEFAULT << endl;

	//Inicializamos los miembros del polinomio.
	max_grado = 10;
	grado = 0;

	//Creamos un vector dinámico de coeficientes.
	coef = new float[max_grado+1];	

	//Rellenamos el vector de coeficientes 0
	for(int i=0; i <= max_grado; i++){
		coef[i]= 0.0;
	}

	//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
	if (coef == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
		}

	cout << GREEN << "El polinomio se ha creado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;

}
Polinomio::Polinomio(int max){

	cout  << PURPLE << "\n ****    CREANDO POLINOMIO    **** " << DEFAULT << endl;

	//Inicializamos los miembros del polinomio.
	max_grado = max;
	grado = 0;

	if( max_grado >= 0){
		//Creamos un vector dinámico de coeficientes.
		coef = new float[max_grado+1];	//Reservo el valor de max_grado+1.

		//Rellenamos el vector de coeficientes a 0
		for(int i=0; i <= max_grado; i++){
			coef[i]= 0.0;
		}

		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (coef == 0){
			cerr << "Error. No hay memoria suficiente. Se abortará la ejecución " << endl;
			cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
			exit(-1);
		}
	}else if (max_grado < 0){
		cerr << "¡¡ERROR!! un polinomo no puede tener un grado negativo." << endl;
		cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
		exit(-1);
	}

	cout << GREEN << "El polinomio se ha creado correctamente.\n" << DEFAULT ;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;

}
Polinomio::~Polinomio(){

	cout  << PURPLE << "\n ****    BORRANDO POLINOMIO    **** " << DEFAULT << endl;

	//Rellenamos el vector de coeficientes 0
	for(int i=0; i <= grado; i++){
		coef[i]=0;
	}

	//Borramos los datos de los miembros del polinomio.
	max_grado = 0;
	grado = 0;

	//Borramos el vector dinámico de coeficientes.
	delete [] coef;

	//Borramos el valor del puntero.
	coef = 0;

	cout << GREEN << "El polinomio se ha borrado correctamente." << DEFAULT << endl;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;

}
void Polinomio::resizeAumentarPolinomio(int DIM){
	
	float *aux = new float[DIM+1];

	if (aux == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}

	for(int i = 0;i <= getMax_Grado();i++){
		aux[i]=coef[i];
	}
	
	delete [] coef;
	coef = aux;
	max_grado = DIM;
	
}
///////////////////////////////				SET				///////////////////////////////

void Polinomio::setCoeficientev1(int i, float c){

	//Añadimos en la posicion [i] el coeficiente (c) y actualizamos el grado con el setGrado.
	coef[i]=c;
	setGrado(i);
}
void Polinomio::setCoeficientev2(int i, float c){

	if( i >= getMax_Grado()){
		resizeAumentarPolinomio(i+1);
		coef[i]=c;
		setGrado(i);
	}else if (i < getMax_Grado()){
		coef[i]=c;
		setGrado(i);
	}

}
void Polinomio::setGrado(int i){

	if(i >= 0){
		grado = i;
	}else if (i < 0){
		cerr << "Error un polinomo no puede tener un grado negativo" << endl;
		exit(-1);
	}
}
void Polinomio::setMax_Grado(int i){

	if(i > 1){
		setMax_Grado(i);
	}else if( i == 0){
		cout << "Recuerda que un polinomio es un conjunto de monomios" << endl;
		setMax_Grado(i);
	}else if (i <= 0){
		cerr << "Error un polinomo no puede tener un grado negativo" << endl;
		exit(-1);
	}
}
///////////////////////////////				GET				///////////////////////////////

float Polinomio::getCoeficiente(int i) const{

	return coef[i];
}
int Polinomio::getGrado() const{

	return grado;
}
int Polinomio::getMax_Grado() const{

	return max_grado;
}
///////////////////////////////				PRINT				///////////////////////////////

void Polinomio::printPolinomio() const{

	cout << GREY << "****************************************" << DEFAULT << endl;

        cout <<"P(x) = ";	
        for(int i = 0; i<= getMax_Grado(); i++){
            cout << coef[i] << "x^" << i;
            if(i != getMax_Grado()){
                cout << " + ";
            }
        }
        cout << endl;

	cout << GREY << "****************************************" << DEFAULT << endl; 
	cout << CYAN << "Máximo grado del polinomio: " << DEFAULT << getMax_Grado() << endl;
}

void Polinomio::DatosPolinomio(){

	//Declaración de variables
	float va = 0.0;

	cout << "Introduzca los valores de menor grado a mayor. " << endl;
	cout << BLUE << "Recuerde que el máximo grado de este polinomio es " << getMax_Grado() << DEFAULT << endl;
	for(int i = 0; i < getMax_Grado();i++){
		cin >> va;
		setCoeficientev2(i,va);
		setGrado(i);
		cout << YELLOW << "***" << DEFAULT << endl;
	}
}
void Polinomio::Testing_0(){

	cout  << YELLOW << "\n ****   TESTING 0    **** " << DEFAULT << endl;
	cout << BLUE << "Imprimiendo por pantalla el contenido por defecto tras la creación de un polinomio: " << DEFAULT << endl;
    
    	printPolinomio();

    	cout  << YELLOW << "\n ****   TESTING 0 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_1(){

	cout  << YELLOW << "\n ****   TESTING 1    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado menos al actual. " << DEFAULT << endl;
   	
	cout << BLUE << "El grado actual es: " << getGrado() << endl;
    	setCoeficientev2(8,4);
	setCoeficientev2(4,8);
    	printPolinomio();
	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;

    	cout  << YELLOW << "\n ****   TESTING 1 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_2(){

	cout  << YELLOW << "\n ****   TESTING 2    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado negativo. " << DEFAULT << endl;
   	
    	setCoeficientev2(-1,4);

    	printPolinomio();

    	cout  << YELLOW << "\n ****   TESTING 2 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_3(){

	cout  << YELLOW << "\n ****   TESTING 3    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado mayor al actual, pero que sea menor que max_grado. " << DEFAULT << endl;
   	
    	setCoeficientev2(1,4);
    	setCoeficientev2(8,87);

    	printPolinomio();

    	cout  << YELLOW << "\n ****   TESTING 3 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_4(){

	cout  << YELLOW << "\n ****   TESTING 4    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado mayor al actual, y que sea mayor que max_grado. " << DEFAULT << endl;
   	
    	setCoeficientev2(3,4);
    	setCoeficientev2(18,87);

    	printPolinomio();

    	cout  << YELLOW << "\n ****   TESTING 4 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_5(){

	cout  << YELLOW << "\n ****   TESTING 5    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado igual al actual y cuyo coeficiente sea 0. " << DEFAULT << endl;
   	
    	setCoeficientev2(3,4);
    	setCoeficientev2(3,0);

    	printPolinomio();

    	cout  << YELLOW << "\n ****   TESTING 5 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_5_1(){

	cout  << YELLOW << "\n ****   TESTING 5.1    **** " << DEFAULT << endl;
	cout << BLUE << "Si todos los coeficientes anteriores también son 0. " << DEFAULT << endl;
   	
    	setCoeficientev2(3,0);
    	setCoeficientev2(3,0);

    	printPolinomio();

    	cout  << YELLOW << "\n ****   TESTING 5.1 TERMINADO    **** " << DEFAULT << endl;
}

int main(){

	//Declaración de variable auxiliar.
	int max = 0;

	cout  << PURPLE << "\n ****   POLINOMIO    **** " << DEFAULT << endl;
	cout << BLUE << "Introduzca el máximo grado del polinomio: " << DEFAULT << endl;
	//cin >> max;

	Polinomio p1(10);	// 1) Creamos Polinomio.

	//TESTING
	//p1.Testing_0();
	//p1.Testing_1();
	//p1.Testing_2();
	//p1.Testing_3();
	//p1.Testing_4();	
	p1.Testing_5();
	p1.Testing_5_1();	

	/*p1.setCoeficientev2(4,5);
	p1.setCoeficientev2(8,4);
	p1.setCoeficientev2(0,2);
	p1.setCoeficientev2(1,87);*/



	//p1.DatosPolinomio();	// 2) Pedimos Datos al usuario

	//p1.printPolinomio();	// 3) Imprimimios polinomio.


}
