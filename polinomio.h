//
//	librería polinomio.h
//
//  Created by Carlos Fdez
//  https://github.com/CarlosFdezJim/PROG-3T-19-20-CFJ
//
//

//**************************************//
#include <iostream>
#include <stdlib.h>
using namespace std;

/*****************************************
** Definición de la clase Polinomio 	**
*****************************************/

class Polinomio{

	private:
		float *coef;			//Vector con los coeficientes
		int grado;			//Grado actual del polinomio. El grado de un polinomio no puede ser negativo.
		int max_grado;			//Máximo grado permitido a este polinomio. El grado de un polinomio no puede ser negativo.
		bool DEBUG;			//Miembro de la clase polinomio de tipo booleano que se usa para ver determinados mensajes de error que nos interesen.

		/**
		 * @brief Cambia la dimensión del vector aumentando o disminuyendo si fuera necesario.
		 * 	|0 |1 |2 |3 |4 |5 |6 |  --> resize(9);
		 * 	|0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |
		 * 	|0 |1 |2 |3 |4 |5 |6 |  --> resize(3);
		 * 	|0 |1 |2 |3 |
		 * @post Se abrá aumentado la dimensión del vector DIM veces.
		 * @author Carlos Fdez
		 * @version 2.0
		 */
		void resize(int DIM);
		/**
		 * @brief Aumenta la posición del vector "DIM" veces (número pasado por referencia), copiandolo en un vector auxiliar de mayor dimensión.
		 * 	|0 |1 |2 |3 |4 |5 |6 |  --> resize(3);
		 * 	|0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |
		 * @post Se abrá aumentado la dimensión del vector DIM veces.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void resizeAumentarPolinomio(int DIM);
		/**
		 * @brief Aumenta la posición del vector "DIM" veces (número pasado por referencia), copiandolo en un vector auxiliar de menor dimensión.
		 * 	|0 |1 |2 |3 |4 |5 |6 |  --> resize(3);
		 * 	|0 |1 |2 |3 |
		 * @post Se abrá aumentado la dimensión del vector DIM veces.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void resizeDisminuirPolinomio(int DIM);
	public:
		/**
		 * @brief Método que activa el debug para realizar el testing. ¡ OJO ! Sólo lo puede usar el BACK END ya que es un método privado.
		 * @pre 
		 * @post Cambia el valor de la variable DEBUG que activa o desactiva el modo DEBUG.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void setDEBUG(bool DEBUG);
		/**
		 * @brief Método que devuelve un booleano, y activa o desactuva el método DEBUG
		 * @pre 
		 * @post Devuelve un booleano que usaremos para activar o desactivar el modo DEBUG.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		bool getDEBUG();
		/**
		 * @brief Se crea un polinomio estático y reservamos memoria para el vector de coeficientes.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Tendremos creado un polinomio y se reservará memoria para el vector de coeficientes y los iniciaremos a 0.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		Polinomio();				//Constructor del polinomio (CrearPolinomio).
		/**
		 * @brief Se crea un polinomio estático y asignaremos el valor pasado por parámetros al max_grado.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Tendrémos creado un polinomio y se reservará memoria para el vector de coeficientes y los iniciaremos a 0.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		Polinomio( int max);
		/**
		 * @brief Crea una copia exacta del polinomio que le pasamos por referencia.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Tendrémos creado un polinomio identico reservandose memoria para el vector de coeficientes y los inicializando a 0.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		Polinomio(const Polinomio &p1);
		/**
		 * @brief Se libera la memoria estática reservada del Polinomio, eliminamos el vector de coeficientes y ponemos los miembros a 0.
		 * @pre Se debe de tener creado el polinomo.
		 * @post Borraremos la memoria estática del Polinomio creado anteriormente.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		~Polinomio();
		/**
		 * @brief Insertamos el valor del coeficiente (c) y lo introducimos en la posición del iterador (i) que le pasamos en el método.
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
		 * @post Insertaremos el coeficiente en la posición que deseamos.
		 * @author Carlos Fdez
		 * @version 1.0
		 * 	· Esta versión tiene un filtrado para que no permita introducir un coeficiente negativo.
		 * 	· Esta versión introduce los datos en el polinomio.
		 */
		void setCoeficientev1(int i, float c);
		/**
		 * @brief Insertamos el valor del coeficiente (c) y lo introducimos en la posición del iterador (i) que le pasamos en el método. Si es necesario 			 * usa el método resize para ampliar la dimensión del vector automáticamente.
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
		 * @post Insertaremos el coeficiente en la posición que deseamos.
		 * @author Carlos Fdez
		 * @version 2.0
		 * 	· Esta versión tiene un filtrado para que no permita introducir un coeficiente negativo.
		 * 	· Esta versión incluye el método resize aumentar  en el caso de que el grado que se quiere incluir es mayor al max_grado actual.
		 */
		void setCoeficientev2(int i, float c);
		/**
		 * @brief Insertamos el valor del coeficiente (c) y lo introducimos en la posición del iterador (i) que le pasamos en el método. Si es necesario 			 * usa el método resize para ampliar la dimensión del vector automáticamente.
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
		 * @post Insertaremos el coeficiente en la posición que deseamos.
		 * @author Carlos Fdez
		 * @version 3.0
		 * 	· Esta versión tiene un filtrado para que no permita introducir un coeficiente negativo.
		 * 	· Esta versión incluye el método resize aumentar y disminuir.
		 * 	· Esta versión tiene memoria exacta Es decir el grado y el max_grado tienen el mismo valor.
		 */
		void setCoeficientev3(int i, float c);
		/**
		 * @brief Introducimos el grado del polinomio en base al valor de [i].
		 * @param int i
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @pre Debemos de haber creado al menos un monomio.
		 * @post El grado se guardará en el miembro correspondiente (grado).
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void setGrado(int i);
		/**
		 * @brief Introducimos el máximo grado del polinomio en base al valor de [i].
		 * @param int i		//Valor que le pedimos al usuario.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @pre Debemos de haber creado al menos un monomio.
		 * @post El grado se guardará en el miembro correspondiente ( max_grado).
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void setMax_Grado(int i);
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro vector coef[] en la posición determinada por el indicador [i]. Lo definimos const para 			 * evitar que accidentalmente alguna sentencia modifique algún dato miembro de la clase.
		 * @pre El coeficiente debe de tener al menos un valor introducido.
		 * @post Devolveremos el valor del coeficiente indicado por el indicador [i].
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		float getCoeficiente(int i) const;
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro grado. Lo definimos const para evitar que accidentalmente alguna sentencia modifique 			 * algún dato miembro de la clase.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Devolveremos el valor del miembro grado.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		int getGrado() const;
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro max_grado. Lo definimos const para evitar que accidentalmente alguna sentencia 			 * modifique algún dato miembro de la clase.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Devolveremos el valor del miembro max_grado.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		int getMax_Grado() const;
		/**
		 * @brief Imprimimos por pantalla el polinomio hasta el valor de max_grado.
		 * @post Imprimimos por pantalla el Polinomio.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void printPolinomio();
		/**
		 * @brief Método que se encarga de pedir los coeficientes al usuario para introducirlos en el vector automáticamente.
		 * @post Se insertarán los datos del usuario en el vector.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void DatosPolinomio();
		/**
		 * @brief Método que se encarga de pedir el grado y los coeficientes al usuario para introducirlos en el vector.
		 * @post Se insertarán los datos del usuario en el vector.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void DatosPolinomio2();
		/**
		 * @brief Método de testing nº0: 
		 * Imprime por pantalla el contenido por defecto tras la creación de un polinomio
		 * @post Mostrarmos el vector por pantalla.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void Testing_0();
		/**
		 * @brief Método de testing nº1: 
		 * Inserta un monomio de grado menor al actual.
		 * @post Mostrarmos el vector por pantalla con un monomio menor al actual.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void Testing_1();
		/**
		 * @brief Método de testing nº2: 
		 * Inserta un monomio de grado negativo.
		 * @post Provocará un error por el filtro y se abortará la ejecución porque el grado no puede ser negativo.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void Testing_2();
		/**
		 * @brief Método de testing nº3: 
		 * Inserta un monomio de grado mayor al actual, pero que sea menor que max_grado.
		 * @post Se insertará correctamente el valor introducido y se muestra por pantalla.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void Testing_3();
		/**
		 * @brief Método de testing nº4: 
		 * Inserta un monomio de grado mayor al actual, y que sea mayor que max_grado.
		 * @post Se insertará correctamente el valor introducido usando el  método resize automáticamente y se muestra por pantalla.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void Testing_4();
		/**
		 * @brief Método de testing nº5: 
		 * Inserta un monomio de grado igual al actual y cuyo coeficiente sea 0.
		 * @author Carlos Fdez
		 * @version 1.0
		 * @post 
		 */
		void Testing_5();
		/**
		 * @brief Método de testing nº5.1: 
		 * Si todos los coeficientes anteriores también son 0.
		 * @author Carlos Fdez
		 * @version 1.0
		 * @post 
		 */
		void Testing_5_1();
		/**
		 * @brief Método de testing automatizado. 
		 * Realiza todos los test automáticamente.
		 * @post Se mostrarán los testing desde el 0 hasta el 5.1.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void TestingAutom();
		/**
		 * @brief Método que te dejará seleccionar que tipo de testing quieres utilizar. 
		 * Muestra un menú para saleccionar si quieres usar cualquier caso de testing ya programado.
		 * @post Se mostrará un menú donde el FRONT END puede elegir los testing que desee desde el 0 hasta el 5.1 y el testing automático.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void MenuTesting();
		/**
		 * @brief Método que suma dos polinomio. Pasando uno por referencia. El resultado se almacena en el polinomio llamante.(en este caso p1)
		 * @pre Debe te tener creado los dos polinomios.
		 * @post Sumará el resultado de los dos polinomios y los alamacenará en el polinomio llamante (en este caso p1).
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void sumPolinomio(Polinomio &p2);
		/**
		 * @brief Método que suma dos polinomio. Pasando los dos por referencia. El resultado se almacena en el polinomio llamante.(en este caso p1)
		 * @pre Debe te tener creado los dos polinomios.
		 * @post Sumará el resultado de los dos polinomios y los alamacenará en el polinomio llamante (en este caso p1).
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		void sumPolinomiov2(Polinomio &p2,Polinomio &p3);
		/**
		 * @brief Método que suma dos polinomio. Pasando uno por referencia. El resultado se almacena en el polinomio auxiliar (creado en el mismo método) 			 * que devolveremos con un return.
		 * @pre Debe te tener creado los dos polinomios.
		 * @post Sumará el resultado de los dos polinomios y los alamacenará en el polinomio llamante (en este caso p1).
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		Polinomio sumPolinomiov3(const Polinomio &p2);
		/**
		 * @brief Método que suma dos polinomios.Pasando el puntero de uno por parámetros. El resultado del polinomio se devuelve como puntero.		  
		 * @pre Debemos de tener creado los polinomio con memória dinámica.
		 * @post Devolverá el resultado de la suma de los polinomios de memória dinámica.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		Polinomio* sumPolinomiov4(const Polinomio *p2);
		/**
		 * @brief Sobrecarga del operador +.
		 * @post Se utiliza para sumar datos de un polinomio a otro utilizando simplemente este operador.
		 * Ejemplo --> res = p1 + p2.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		Polinomio operator+(const Polinomio &p2);
		/**
		 * @brief Sobrecarga del operador =. 
		 * @post Se utiliza para asignar datos de un polinomio a otro utilizando simplemente este operador.
		 * Ejemplo -->  p1 = p2.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		 void operator=(const Polinomio &p);
		 /**
		 * @brief Sobrecarga del operador <<. 
		 * @post Se utiliza para poder imprimir un polinomio utilizando simplemente este operador.
		 * Ejemplo --> cout << p1.
		 * @author Carlos Fdez
		 * @version 1.0
		 */
		friend ostream& operator<<(ostream &flujo, const Polinomio &p);
		/**
		 * @brief Sobrecarga del operador << por punteros. 
		 * @post Se utiliza para poder imprimir un polinomio utilizando simplemente este operador.
		 * Ejemplo --> cout << p1.
		 * @author Carlos Fdez
		 * @version 2.0
		 */
		friend ostream& operator<<(ostream &flujo, Polinomio* p);
		/**
		 * @brief Sobrecarga del operador >>. 
		 * @post Se utiliza para introducir datos en un polinomio utilizando simplemente este operador.
		 * Ejemplo --> cin >> p1.
		 */
		friend istream& operator>>(std::istream &flujo, Polinomio &p);
		
};
