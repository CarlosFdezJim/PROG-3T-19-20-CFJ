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
class Vista{
	private:
		Polinomio* vector[];
		int DIM;
		
	public:
		/**
		 * @brief Se crea un modo Vista y reservamos memoria para el vector punteros a Polinomios.
		 * @pre 
		 * @post 
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		Vista();
		/**
		 * @brief 
		 * @pre 
		 * @post 
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		~Vista();
		/**
		 * @brief 
		 * @pre 
		 * @post 
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void setDIM(int i);
		/**
		 * @brief 
		 * @pre 
		 * @post 
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		int getDIM();
		/**
		 * @brief 
		 * @pre 
		 * @post 
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void InsertarPolinomio();
		/**
		 * @brief 
		 * @pre 
		 * @post 
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void printMenu();
		/**
		 * @brief 
		 * @pre 
		 * @post 
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void menuVista();
		
		void crearPolinomioUsuario();
		void borrarPolinomioUsuario();
		/*void insertarPolinomioVector();*/

};

///////////////////////////////				MODO VISTA				///////////////////////////////
Vista::Vista(){

	cout  << YELLOW << "\n  ****    CREANDO VISTA USUARIO    **** " << DEFAULT << endl;

	//Inicializamos los miembros de modo Vista.
	int DIM = 0;
	
	//Creamos el vector de dinámico de polinomios.
	Polinomio** vector = 0;
	vector = new Polinomio* [DIM+1];
	
	//Por lo tanto, tenemos que invocar manualmente el CONSTRUCTOR
	for(int i=0; i < DIM; i++){
		vector[i] = new Polinomio(); //creación de una burbuja y almacenaje en la posición i del vector.
	}
	
	cout << GREEN << "La Vista de usuario se ha creado correctamente." << DEFAULT << endl;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
}
Vista::~Vista(){

	cout  << YELLOW << "\n  ****    ELIMINANDO VISTA USUARIO    **** " << DEFAULT << endl;

	//Borrado tendré que hacerlo burbujita a burbujita y después el vector...
	for(int i=0; i <= DIM; i++){
		delete vector[i]; //aquí borro la burbujita
	}
	
	//Borramos los miembros de modo Vista.
	int DIM = 0;
	
	//Borramos el vector dinámico de polinomios.
	//delete [] vector; //aquí borro el vector
	//*vector= 0;
	
	cout << GREEN << "La Vista de usuario se ha borrado correctamente." << DEFAULT << endl;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
	
}
///////////////////////////////				SET				///////////////////////////////
void Vista::setDIM(int i){
	
	//Filtro para evitar que grado sea negativo. Si es menor que 0 muestra un mensaje y no inserta nada.
	if(i >= 0){
		if( i >= DIM){
			this->DIM = i;
		}
	}else if (i < 0){
		cerr << RED << "Error un vector de polinomos no puede tener una dimensión negativa." << DEFAULT << endl;
		cerr << ERROR << "No se insertará ese monomio" << DEFAULT << endl;
	}
}
int Vista::getDIM(){
	return DIM;
	
}
void Vista::crearPolinomioUsuario(){

	Polinomio* p = 0;
	p = new Polinomio();
	
	if (p == 0){
		cerr << RED << "Error. No hay memoria suficiente. " << DEFAULT;
		cerr << ERROR << "Se abortará la ejecución." << DEFAULT << endl;
		exit(-1);
	}
	
}


void Vista::InsertarPolinomio(){



}
void Vista::borrarPolinomioUsuario(){
	
	cout  << YELLOW << "\n  ****    ELIMINANDO POLINOMIO USUARIO    **** " << DEFAULT << endl;
	
	cout << "Indique en que posición dónde se encuentra el polinomio que desea eliminar." << endl;
	
	//delete [] vector; //aquí borro el vector
	//vector= 0;

	cout << GREEN << "La Vista de usuario se ha borrado correctamente." << DEFAULT << endl;
	cout  << PURPLE << "************************************** " << DEFAULT << endl;
}
/*void Vista::crearVectorPolinomioUsuario(){

	Polinomio** vector = 0;
	vector = new Polinomio* [10]; //crea un vector de 10 punteros a polinomio... OJO AQUÍ TODAVÍA NO SE HA CONSTRUIDO NINGÚN POLINOMIO.
	
	//Por lo tanto, tenemos que invocar manualmente el CONSTRUCTOR
	for(int i=0; i < 10; i++){
		vector[i] = new Polinomio(); //creación de una burbuja y almacenaje en la posición i del vector.
	}

}
void Vista::insertarPolinomioVector(){

	//uso del vector dinámico de punteros
	for(int i=0; i < 10; i++){
		vector[i].setCoeficientev3(2,7);
		cout << vector[i];
	}
}
void Vista::eliminarVectorPolinomioUsuario(){

	//Borrado tendré que hacerlo burbujita a burbujita y después el vector...
	for(int i=0; i < 10; i++){
		delete vector[i]; //aquí borro la burbujita
	}

	delete [] vector; //aquí borro el vector
	vector= 0;
	

}*/
void Vista::printMenu(){

	cout << BLUE <<"/***************************************"<< endl;
		cout << "****	     CLASE VISTA	    ****" << endl;
		cout << "****************************************/" << DEFAULT;
	cout << PURPLE <<  "\nAquí le mostramos las opciones disponibles para realizar en la clase Vista : " << DEFAULT;
	cout << PURPLE <<  "\n[1] " << DEFAULT << " Crear Polinomio. ";
	cout << PURPLE <<  "\n[2] " << DEFAULT << " Borrar Polinomio. ";
	cout << PURPLE <<  "\n[3] " << DEFAULT << " Insertar Polinomio. ";
	cout << PURPLE <<  "\n[4] " << DEFAULT << " Salir. " << endl;

}
void Vista::menuVista(){

	//Declaración de variables.
	int opcion=0;
	bool creado = true;
	
	//Filtro para que el usuario no se salga de las opciones.
	while(opcion!=4){
		//Mostramos menú anteriormente realizado.
		printMenu();
		
		//Pedimos al usuario que escoga una opción de las mostradas previamente.
		cout << "\nEliga usted el programa que desea ejecutar: " << endl;
		cin >> opcion;

			switch (opcion){

				case 1:
					if(creado==true){
						crearPolinomioUsuario();
						//creado=true;
					}else{
						cout << RED << "No existe todavía ningún Polinomio, por favor elige otra opción." << DEFAULT << endl;
						}
				break;

				case 2:
					if(creado==true){
						borrarPolinomioUsuario();
					}else{
						cout << ERROR << "Recuerde que si no CREA un Polinomio no puede eliminarlo. " << DEFAULT << endl;
						}
				break;
				
				case 3:
					if(creado==true){
						//eliminarPolinomio();
					}else{
						cout << ERROR << "Recuerde que si no CREA un Polinomio no puede eliminarlo. " << DEFAULT << endl;
						}
				break;
				
				case 4:
					cout << PURPLE << "----------SALIENDO----------\n" ;
					cout << "\nGracias por usar el modo Vista del POLINOMIO " << endl;
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
	
	
	/************		MENU VISTA		************/
	Vista v1;
	v1.menuVista();

    //MANEJO DE POLINOMIOS ESTÁTICOS (tanto variables como vectores)
/*    Polinomio p1; //esto es estático, está desde el principio hasta el final de la ejecuación del programa. LA GESTIÓN DEL MOMENTO EN EL QUE SE CREA y SE DESTRUYE LA REALIZA EL SO.
    
    Polinomio vector[10]; //esto es estático, está desde el principio hasta el final de la ejecuación del programa. LA GESTIÓN DEL MOMENTO EN EL QUE SE CREA y SE DESTRUYE LA REALIZA EL SO.
    
    for(int i=0; i < 10; i++){
        vector[i].setCoeficientev3(2,3);
        cout << vector[i];
    }
*/    
    //MANEJO DE POLINOMIOS ESTÁTICOS (tanto variables como vectores)
    
    
    
    
    //CREACIÓN DE UN POLINOMIO DINÁMICO
  /* Polinomio* pol_ptr = 0;
    pol_ptr = new Polinomio(); //consturimos un polinomio dinámico, guardamos el puntero, y la memoria se crea a partir de este justo momento. LA GESTIÓN DEL MOMENTO EN EL QUE SE CREA y SE DESTRUYE LA REALIZA EL PROGRAMADOR;
    if (pol_ptr == 0){
        cerr << "Error. Se aborta..." << endl;
        exit(-1);
    }
    
    delete pol_ptr;
    pol_ptr = 0;*/
    
    //CREAR UN VECTOR DINÁMICO DE POLINOMIOS
 /*   Polinomio* vector_din = 0;
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
    delete [] vector_din;*/
    
    
    //CREAR UN VECTOR DINÁMICO DE PUNTEROS A POLINOMIOS
/*   Polinomio** vector_din_punt = 0;
    vector_din_punt = new Polinomio* [10]; //crea un vector de 10 punteros a polinomio... OJO AQUÍ TODAVÍA NO SE HA CONSTRUIDO NINGÚN POLINOMIO (burbuja/panojito).
    //Por lo tanto, tenemos que invocar manualmente el CONSTRUCTOR
    for(int i=0; i < 10; i++){
        vector_din_punt[i] = new Polinomio(); //creación de una burbuja y almacenaje en la posición i del vector.
    }*/
    //uso del vector dinámico de punteros
    /*  for(int i=0; i < 10; i++){
          vector_din_punt[i]->setCoeficientev3(2,7);
          cout << *(vector_din_punt[i]); //accedo mediante burbuja (sobrecarga 1)
          cout << vector_din_punt[i]; //accedo a mediante puntero (sobrecarga 2)
      }*/
    //Borrado tendré que hacerlo burbujita a burbujita y después el vector...
  /*  for(int i=0; i < 10; i++){
        delete vector_din_punt[i]; //aquí borro la burbujita
    }
    delete [] vector_din_punt; //aquí borro el vector
    vector_din_punt = 0;*/
    
}
