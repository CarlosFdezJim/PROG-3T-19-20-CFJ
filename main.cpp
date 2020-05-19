//
//	main.cpp
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
#include "polinomio.h"
using namespace std;

/*****************************************
** Definición de la clase Vista 	**
*****************************************/
class vista{
	private:
		Polinomio* vector;
		int util_v;
		void insertarPolinomio();
	public:
		void crearPolinomioUsuario();
		void borrarPolinomioUsuario();
		void printMenu();
		void MenuTesting();

};

///////////////////////////////				MODO VISTA				///////////////////////////////

void vista::printMenu(){

	cout << BLUE <<"/***************************************"<< endl;
		cout << "****	     CLASE VISTA	    ****" << endl;
		cout << "****************************************/" << DEFAULT;
	cout << PURPLE <<  "\nAquí le mostramos las opciones disponibles para realizar en la clase vista : " << DEFAULT;
	cout << PURPLE <<  "\n[1] " << DEFAULT << " Crear Polinomio. ";
	cout << PURPLE <<  "\n[2] " << DEFAULT << " Borrar Polinomio. ";
	cout << PURPLE <<  "\n[3] " << DEFAULT << " Salir. " << endl;

}
void vista::crearPolinomioUsuario(){

	Polinomio p1();
	
	/*cout  << PURPLE << "\n  ****    CREANDO POLINOMIO    **** " << DEFAULT << endl;
		
	//Inicializamos los miembros del polinomio.
	this->max_grado = 0;
	this->grado = 0;
	
	Polinomio* pol = 0;
	pol = new Polinomio();
	//Filtro para que al crear un polinomio no sea de grado negativo, en caso de serlo abortará la ejecución.
	if(this->max_grado >= 0){
		//Creamos un vector dinámico de coeficientes.
		this->coef = new float[max_grado+1];	//Reservo el valor de max_grado+1.

		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->coef == 0){
			cerr << "Error. No hay memoria suficiente. Se abortará la ejecución " << endl;
			cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
			exit(-1);
		}

		//Rellenamos el vector de coeficientes a 0
		for(int i=0; i <= max_grado; i++){
			coef[i]= 0.0;
		}

	}else if (this->max_grado < 0){
		cerr << "¡¡ERROR!! un polinomo no puede tener un grado negativo." << endl;
		cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
		exit(-1);
	}

	if(this->getDEBUG() == true){
		cout << GREEN << "El polinomio se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}*/
	
}
void vista::borrarPolinomioUsuario(){

	
}
void vista::MenuTesting(){

	//Declaración de variables.
	int opcion=0;
	bool creado = false;
	
	//Filtro para que el usuario no se salga de las opciones.
	while(opcion!=3){
		//Mostramos menú anteriormente realizado.
		printMenu();
		
		//Pedimos al usuario que escoga una opción de las mostradas previamente.
		cout << "\nEliga usted el programa que desea ejecutar: " << endl;
		cin >> opcion;

			switch (opcion){

				case 1:
					if(creado==false){
						crearPolinomioUsuario();
						creado=true;
					}else{
						cout << RED << "No existe todavía ningún Polinomio, por favor elige otra opción." << DEFAULT << endl;
						}
				break;

				case 2:
					if(creado==true){
						//eliminarPolinomio();
					}else{
						cout << ERROR << "Recuerde que si no CREA un Polinomio no puede eliminarlo. " << DEFAULT << endl;
						}
				break;
				
				case 3:
					cout << PURPLE << "----------SALIENDO----------\n" ;
					cout << "\nGracias por usar el modo vista del POLINOMIO " << endl;
					cout << "\n © Carlos Fdez " << DEFAULT << endl;
				break;
				
				default:
					cout << PURPLE << "Lo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
					cout << PURPLE << "Por favor seleccione otra o pulse 3 para salir. \n" << DEFAULT << endl;
			}
	}
}
int main(){

	//Declaración de variable que asignaremos para crear el polinomio de un tamaño inicial.
	/*int max = 0;
	max = GradoPolinomio(max);	// Módulo que se encarga de pedir al usuario el grado máximo del polinomio que desea crear.
	bool TESTING = false;		// Variable booleana que activa y desactiva el modo Testing.
	
	/****		Creación de Polinomios		****/
	/*Polinomio p1;		// Creación de un Polinomio.
	Polinomio p1 (max);	// Creación de un Polinomio de max_grado = max (variable introducida por el usuario).
	Polinomio p2 (p1);	// Creamos una copia del polinomio
	Polinomio p3 (p1);	// Creamos una copia del polinomio
	Polinomio res;

	/****		Modo DEBUG		****/
	/*setDEBUG(false);

	/****		Datos introducidos por el usuario	****/
	/*p1.DatosPolinomio();	// Pedimos Datos al usuario rellenando de menor grado a mayor todo el Polinomio.(sólo pedimos el valor)
	p1.DatosPolinomio2();	// Pedimos Datos al usuario. (coeficiente y valor)

	/****		Datos introducidos por el programador FrontEnd en p1	****/
	/*p1.setCoeficientev3(7,35);
	p1.setCoeficientev3(0,6);
	p1.setCoeficientev3(1,16);
	p1.setCoeficientev3(10,25);

	/****		Imprimir Polinomio p1		****/
	//p1.printPolinomio();

	/****		Datos introducidos por el programador FrontEnd en p2	****/
	/*p2.setCoeficientev3(9,7);
	p2.setCoeficientev3(4,20);
	p2.setCoeficientev3(6,30);
	p2.setCoeficientev3(10,50);
	
	/*Testing*/
	/*p1.setCoeficientev3(1,5);
	p2.setCoeficientev3(4,35);
	
		/****		MENÚ TESTING Polinomio p1		****/		
	/*if(TESTING == true){
		p1.MenuTesting();	// Menú donde puedes seleccionar el testing que desees tanto unitario como automático.
	}*/


	/****		SUMAR V1		****/
	/*Polinomio p2;	// Creamos una copia del polinomio
	
	p1.setCoeficientev3(4,5);
	p2.setCoeficientev3(1,35);
	
	p1.sumPolinomio(p2);
	
	/****		SUMAR V2		****/
	/*Polinomio p2 (p1);	// Creamos una copia del polinomio
	Polinomio p3;
	
	p2.setCoeficientev3(10,5);
	p3.setCoeficientev3(4,35);
	
	p1.sumPolinomiov2(p2,p3);
	
	/****		SUMAR V3		****/
	/*Polinomio p2 (p1);	// Creamos una copia del polinomio
	
	p1.setCoeficientev3(1,5);
	p2.setCoeficientev3(4,35);
	
	Polinomio res = p1.sumPolinomiov3(p2);
	res.printPolinomio();
	
	/****		SUMAR V4		****/
	/*Polinomio *p2;
	Polinomio *res = new Polinomio();
	

	res = p1.sumPolinomiov4(p2);
	res->printPolinomio();	
	
	delete res;
	res = 0;
	
	/****		SOBRECARGA OPERADOR +		****/
	/*Polinomio p2 (p1);	// Creamos una copia del polinomio
	
	p1.setCoeficientev3(10,5);
	p2.setCoeficientev3(4,35);
	
	Polinomio res = p2 + p1;
	res.printPolinomio();
	
	/****		SOBRECARGA OPERADOR =		****/
	/*Polinomio p2 (p1);	// Creamos una copia del polinomio
	
	p1.setCoeficientev3(10,5);
	p1.printPolinomio();
	p2.setCoeficientev3(4,35);
	p2.printPolinomio();
	p1=p2;
	
	p1.printPolinomio();
	
	/****		SOBRECARGA OPERADOR <<		****/
	/*p1.setCoeficientev3(1,5);
	p1.setCoeficientev3(5,25);
	p1.setCoeficientev3(3,15);
	
	cout << p1;

	/****		SOBRECARGA OPERADOR <<		****/
	/*p1.setCoeficientev3(1,5);
	p1.setCoeficientev3(5,25);
	p1.setCoeficientev3(3,15);*/
	
	//cin >> p1;
	
	//cout << p1;
	
	/****		SOBRECARGA OPERADOR << por punteros		****/
	//cout << 
	
	
	/****		SOBRECARGA OPERADOR << por punteros		****/
	vista v1;	
	v1.MenuTesting();

    //MANEJO DE POLINOMIOS ESTÁTICOS (tanto variables como vectores)
    Polinomio p1; //esto es estático, está desde el principio hasta el final de la ejecuación del programa. LA GESTIÓN DEL MOMENTO EN EL QUE SE CREA y SE DESTRUYE LA REALIZA EL SO.
    
    Polinomio vector[10]; //esto es estático, está desde el principio hasta el final de la ejecuación del programa. LA GESTIÓN DEL MOMENTO EN EL QUE SE CREA y SE DESTRUYE LA REALIZA EL SO.
    
    for(int i=0; i < 10; i++){
        vector[i].setCoeficientev3(2,3);
        cout << vector[i];
    }
    
    //MANEJO DE POLINOMIOS ESTÁTICOS (tanto variables como vectores)
    //CREACIÓN DE UN POLINOMIO DINÁMICO
   Polinomio* pol_ptr = 0;
    pol_ptr = new Polinomio(); //consturimos un polinomio dinámico, guardamos el puntero, y la memoria se crea a partir de este justo momento. LA GESTIÓN DEL MOMENTO EN EL QUE SE CREA y SE DESTRUYE LA REALIZA EL PROGRAMADOR;
    if (pol_ptr == 0){
        cerr << "Error. Se aborta..." << endl;
        exit(-1);
    }
    
    delete pol_ptr;
    pol_ptr = 0;
    
    //CREAR UN VECTOR DINÁMICO DE POLINOMIOS
    Polinomio* vector_din = 0;
    vector_din = new Polinomio[10]; //aquí se invoca al constructor automáticamente
    if (vector_din == 0){
         cout << vector_din << "Error. Se aborta no hay memoria para el vector..." << endl;
     }
    //uso del vector dinámico
    for(int i=0; i < 10; i++){
        vector_din[i].setCoeficientev3(2,5);
        cout << vector_din[i];
    }
    //Borramos el vector de objetos
    delete [] vector_din;
    
    
    //CREAR UN VECTOR DINÁMICO DE PUNTEROS A POLINOMIOS
    Polinomio** vector_din_punt = 0;
    vector_din_punt = new Polinomio* [10]; //crea un vector de 10 punteros a polinomio... OJO AQUÍ TODAVÍA NO SE HA CONSTRUIDO NINGÚN POLINOMIO (burbuja/panojito).
    //Por lo tanto, tenemos que invocar manualmente el CONSTRUCTOR
    for(int i=0; i < 10; i++){
        vector_din_punt[i] = new Polinomio(); //creación de una burbuja y almacenaje en la posición i del vector.
    }
    //uso del vector dinámico de punteros
      for(int i=0; i < 10; i++){
          vector_din_punt[i]->setCoeficientev3(2,7);
          cout << *(vector_din_punt[i]); //accedo mediante burbuja (sobrecarga 1)
          cout << vector_din_punt[i]; //accedo a mediante puntero (sobrecarga 2)
      }
    //Borrado tendré que hacerlo burbujita a burbujita y después el vector...
    for(int i=0; i < 10; i++){
        delete vector_din_punt[i]; //aquí borro la burbujita
    }
    delete [] vector_din_punt; //aquí borro el vector
    vector_din_punt = 0;
    
}
