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
		 */
		void resize(int DIM);
		/**
		 * @brief Aumenta la posición del vector "DIM" veces (número pasado por referencia), copiandolo en un vector auxiliar de mayor dimensión.
		 * 	|0 |1 |2 |3 |4 |5 |6 |  --> resize(3);
		 * 	|0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |
		 * @post Se abrá aumentado la dimensión del vector DIM veces.
		 */
		void resizeAumentarPolinomio(int DIM);
		/**
		 * @brief Aumenta la posición del vector "DIM" veces (número pasado por referencia), copiandolo en un vector auxiliar de menor dimensión.
		 * 	|0 |1 |2 |3 |4 |5 |6 |  --> resize(3);
		 * 	|0 |1 |2 |3 |
		 * @post Se abrá aumentado la dimensión del vector DIM veces.
		 */
		void resizeDisminuirPolinomio(int DIM);
	public:
		/**
		 * @brief Método que activa el debug para realizar el testing. ¡ OJO ! Sólo lo puede usar el BACK END ya que es un método privado.
		 * @pre 
		 * @post Cambia el valor de la variable DEBUG que activa o desactiva el modo DEBUG.
		 */
		void setDEBUG(bool DEBUG);
		/**
		 * @brief Método que devuelve un booleano, y activa o desactuva el método DEBUG
		 * @pre 
		 * @post Devuelve un booleano que usaremos para activar o desactivar el modo DEBUG.
		 */
		bool getDEBUG();
		/**
		 * @brief Se crea un polinomio estático y reservamos memoria para el vector de coeficientes.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Tendremos creado un polinomio y se reservará memoria para el vector de coeficientes y los iniciaremos a 0.
		 */
		Polinomio();				//Constructor del polinomio (CrearPolinomio).
		/**
		 * @brief Se crea un polinomio estático y asignaremos el valor pasado por parámetros al max_grado.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Tendrémos creado un polinomio y se reservará memoria para el vector de coeficientes y los iniciaremos a 0.
		 */
		Polinomio( int max);
		/**
		 * @brief Crea una copia exacta del polinomio que le pasamos por referencia.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Tendrémos creado un polinomio identico reservandose memoria para el vector de coeficientes y los inicializando a 0.
		 */
		Polinomio(const Polinomio &p1);
		/**
		 * @brief Se libera la memoria estática reservada del Polinomio, eliminamos el vector de coeficientes y ponemos los miembros a 0.
		 * @pre Se debe de tener creado el polinomo.
		 * @post Borraremos la memoria estática del Polinomio creado anteriormente.
		 */
		~Polinomio();
		/**
		 * @brief Insertamos el valor del coeficiente (c) y lo introducimos en la posición del iterador (i) que le pasamos en el método.
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
		 * @post Insertaremos el coeficiente en la posición que deseamos.
		 */
		void setCoeficientev1(int i, float c);
		/**
		 * @brief Insertamos el valor del coeficiente (c) y lo introducimos en la posición del iterador (i) que le pasamos en el método. Si es necesario 			 * usa el método resize para ampliar la dimensión del vector automáticamente.
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
		 * @post Insertaremos el coeficiente en la posición que deseamos.
		 */
		void setCoeficientev2(int i, float c);
		/**
		 * @brief Insertamos el valor del coeficiente (c) y lo introducimos en la posición del iterador (i) que le pasamos en el método. Si es necesario 			 * usa el método resize para ampliar la dimensión del vector automáticamente.
		 * @param int i			//Grado actual del polinomio donde vamos a insertar el coeficiente.
		 * @param float c		//Coeficiente del polinomio.
		 * @pre Debemos de haber creado el Polimio correctamente y debe de haber tenido memoria suficiente para crearse.
		 * @post Insertaremos el coeficiente en la posición que deseamos.
		 */
		void setCoeficientev3(int i, float c);
		/**
		 * @brief Introducimos el grado del polinomio en base al valor de [i].
		 * @param int i
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @pre Debemos de haber creado al menos un monomio.
		 * @post El grado se guardará en el miembro correspondiente (grado).
		 */
		void setGrado(int i);
		/**
		 * @brief Introducimos el máximo grado del polinomio en base al valor de [i].
		 * @param int i		//Valor que le pedimos al usuario.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @pre Debemos de haber creado al menos un monomio.
		 * @post El grado se guardará en el miembro correspondiente ( max_grado).
		 */
		void setMax_Grado(int i);
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro vector coef[] en la posición determinada por el indicador [i]. Lo definimos const para 			 * evitar que accidentalmente alguna sentencia modifique algún dato miembro de la clase.
		 * @pre El coeficiente debe de tener al menos un valor introducido.
		 * @post Devolveremos el valor del coeficiente indicado por el indicador [i].
		 */
		float getCoeficiente(int i) const;
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro grado. Lo definimos const para evitar que accidentalmente alguna sentencia modifique 			 * algún dato miembro de la clase.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Devolveremos el valor del miembro grado.
		 */
		int getGrado() const;
		/**
		 * @brief Devolvemos el valor que tenemos dentro del miembro max_grado. Lo definimos const para evitar que accidentalmente alguna sentencia 			 * modifique algún dato miembro de la clase.
		 * @pre El grado del polinomo NO puede ser negativo.
		 * @post Devolveremos el valor del miembro max_grado.
		 */
		int getMax_Grado() const;
		/**
		 * @brief Imprimimos por pantalla el polinomio hasta el valor de max_grado.
		 * @post Imprimimos por pantalla el Polinomio.
		 */
		void printPolinomio();
		/**
		 * @brief Método que se encarga de pedir los coeficientes al usuario para introducirlos en el vector automáticamente.
		 * @post Se insertarán los datos del usuario en el vector.
		 */
		void DatosPolinomio();
		/**
		 * @brief Método que se encarga de pedir el grado y los coeficientes al usuario para introducirlos en el vector.
		 * @post Se insertarán los datos del usuario en el vector.
		 */
		void DatosPolinomio2();
		/**
		 * @brief Método de testing nº0: 
		 * Imprime por pantalla el contenido por defecto tras la creación de un polinomio
		 * @post Mostrarmos el vector por pantalla.
		 */
		void Testing_0();
		/**
		 * @brief Método de testing nº1: 
		 * Inserta un monomio de grado menor al actual.
		 * @post Mostrarmos el vector por pantalla con un monomio menor al actual.
		 */
		void Testing_1();
		/**
		 * @brief Método de testing nº2: 
		 * Inserta un monomio de grado negativo.
		 * @post Provocará un error por el filtro y se abortará la ejecución porque el grado no puede ser negativo.
		 */
		void Testing_2();
		/**
		 * @brief Método de testing nº3: 
		 * Inserta un monomio de grado mayor al actual, pero que sea menor que max_grado.
		 * @post Se insertará correctamente el valor introducido y se muestra por pantalla.
		 */
		void Testing_3();
		/**
		 * @brief Método de testing nº4: 
		 * Inserta un monomio de grado mayor al actual, y que sea mayor que max_grado.
		 * @post Se insertará correctamente el valor introducido usando el  método resize automáticamente y se muestra por pantalla.
		 */
		void Testing_4();
		/**
		 * @brief Método de testing nº5: 
		 * Inserta un monomio de grado igual al actual y cuyo coeficiente sea 0.
		 * @post 
		 */
		void Testing_5();
		/**
		 * @brief Método de testing nº5.1: 
		 * Si todos los coeficientes anteriores también son 0.
		 * @post 
		 */
		void Testing_5_1();
		/**
		 * @brief Método de testing automatizado. 
		 * Realiza todos los test automáticamente.
		 * @post Se mostrarán los testing desde el 0 hasta el 5.1.
		 */
		void TestingAutom();
		/**
		 * @brief Método que te dejará seleccionar que tipo de testing quieres utilizar. 
		 * Muestra un menú para saleccionar si quieres usar cualquier caso de testing ya programado.
		 * @post Se mostrará un menú donde el FRONT END puede elegir los testing que desee desde el 0 hasta el 5.1 y el testing automático.
		 */
		void MenuTesting();
		/**
		 * @brief Método que suma dos polinomio. Pasando uno por referencia. El resultado se almacena en el polinomio llamante.(en este caso p1)
		 * @pre Debe te tener creado los dos polinomios.
		 * @post Sumará el resultado de los dos polinomios y los alamacenará en el polinomio llamante (en este caso p1).
		 */
		void sumPolinomio(Polinomio &p2);
		/**
		 * @brief Método que suma dos polinomio. Pasando los dos por referencia. El resultado se almacena en el polinomio llamante.(en este caso p1)
		 * @pre Debe te tener creado los dos polinomios.
		 * @post Sumará el resultado de los dos polinomios y los alamacenará en el polinomio llamante (en este caso p1).
		 */
		void sumPolinomiov2(Polinomio &p2,Polinomio &p3);
		/**
		 * @brief Método que suma dos polinomio. Pasando uno por referencia. El resultado se almacena en el polinomio auxiliar (creado en el mismo método) 			 * que devolveremos con un return.
		 * @pre Debe te tener creado los dos polinomios.
		 * @post Sumará el resultado de los dos polinomios y los alamacenará en el polinomio llamante (en este caso p1).
		 */
		Polinomio sumPolinomiov3(const Polinomio &p2);
		/**
		 * @brief  			  
		 * @pre 
		 * @post 
		 */
		Polinomio* sumPolinomiov4(const Polinomio *p2);
};
///////////////////////////////				DEBUG					////////////////////////////////

void Polinomio::setDEBUG(bool DEBUG){
	this->DEBUG = DEBUG;
}
bool Polinomio::getDEBUG(){
	return this->DEBUG;
}
///////////////////////////////				POLINOMIO				///////////////////////////////
Polinomio::Polinomio(){
	
	setDEBUG(true);

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n  ****    CREANDO POLINOMIO    **** " << DEFAULT << endl;
	}

	//Inicializamos los miembros del polinomio.
	this->max_grado = 0;
	this->grado = 0;

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
	}
}
Polinomio::Polinomio(int max){

	setDEBUG(true);

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n ****    CREANDO POLINOMIO CON MAX GRADO    **** " << DEFAULT << endl;
	}
	//Inicializamos los miembros del polinomio.
	this->max_grado = max;
	this->grado = 0;

	//Filtro para que al crear un polinomio no sea de grado negativo, en caso de serlo abortará la ejecución.
	if(this->max_grado >= 0){
		//Creamos un vector dinámico de coeficientes.
		this->coef = new float[max_grado+1];	//Reservo el valor de max_grado+1.

		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->coef == 0){
			cerr << RED << "Error. No hay memoria suficiente. " << DEFAULT;
			cerr << ERROR << "Se abortará la ejecución." << DEFAULT << endl;
			exit(-1);
		}

		//Rellenamos el vector de coeficientes a 0
		for(int i=0; i <= max_grado; i++){
			this->coef[i]= 0.0;
		}

	}else if (this->max_grado < 0){
		cerr << "¡¡ERROR!! un polinomo no puede tener un grado negativo." << endl;
		cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
		exit(-1);
	}

	if(this->getDEBUG() == true){
		cout << GREEN << "El polinomio se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
Polinomio::Polinomio(const Polinomio &p1){

	setDEBUG(true);

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n ****    CREANDO COPIA DEL POLINOMIO    **** " << DEFAULT << endl;
	}

	//Copiamos los miembros del polinomio.
	this->max_grado = p1.getMax_Grado();
	this->grado = p1.getGrado();

	//Filtro para que al crear un polinomio no sea de grado negativo, en caso de serlo abortará la ejecución.
	if(this->max_grado >= 0){
		//Creamos un vector dinámico de coeficientes.
		this->coef = new float[max_grado+1];	//Reservo el valor de max_grado+1.

		//Si no hay memoria suficiente se aborta la ejecución y se sale del programa.
		if (this->coef == 0){
			cerr << RED << "Error. No hay memoria suficiente. " << DEFAULT;
			cerr << ERROR << "Se abortará la ejecución." << DEFAULT << endl;
			exit(-1);
		}

		//Rellenamos el vector de coeficientes a 0
		for(int i=0; i <= max_grado; i++){
			this->coef[i]= 0.0;
		}

		//Copio el contenido de coef[i] en aux[i].
		for(int i = 0;i <= max_grado;i++){
			this->coef[i]=p1.coef[i];
		}

	}else if (this->max_grado < 0){
		cerr << "¡¡ERROR!! un polinomo no puede tener un grado negativo." << endl;
		cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
		exit(-1);
	}

	if(this->getDEBUG() == true){
		cout << GREEN << "La copia del polinomio se ha creado correctamente.\n" << DEFAULT ;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
Polinomio::~Polinomio(){
	
	setDEBUG(true);

	if(this->getDEBUG() == true){
		cout  << PURPLE << "\n ****    BORRANDO POLINOMIO    **** " << DEFAULT << endl;
	}

	//Rellenamos el vector de coeficientes a 0
	for(int i=0; i <= max_grado; i++){
		this->coef[i]= 0.0;
	}

	//Borramos los datos de los miembros del polinomio.
	this->max_grado = 0;
	this->grado = 0;

	//Borramos el valor del puntero.
	this->coef = 0;	

	//Borramos el vector dinámico de coeficientes.
	delete [] coef;

	if(this->getDEBUG() == true){
		cout << GREEN << "El polinomio se ha borrado correctamente." << DEFAULT << endl;
		cout  << PURPLE << "************************************** " << DEFAULT << endl;
	}
}
///////////////////////////////				RESIZE				///////////////////////////////

void Polinomio::resize(int DIM){

	//Reservo memoria para el vector auxiliar con una DIM +1.
	float *aux = new float[DIM+1];

	//Compruebo que hay memoria suficiente.
	if (aux == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}

	//Relleno el vector auxiliar de 0.
	for(int i = 0;i <= DIM;i++){
		aux[i] = 0.0;
	}

	if( DIM > this->getMax_Grado()){

		//Copio el contenido de coef[i] en aux[i].
		for(int i = 0;i <= getMax_Grado();i++){
			aux[i]=coef[i];
		}

	}else if (DIM == getMax_Grado()){

		//Copio el contenido de coef[i] en aux[i].
		for(int i = 0; i <= DIM; i++){
			aux[i]=coef[i];
		}
	}
		//Eliminamos la memoria del vector coef.
		delete [] coef;

		//Reasignamos el puntero de coeficientes.
		coef = aux;

		//Actualizo el máximo grado y el grado.
		max_grado = DIM ;
		grado = max_grado;

}
void Polinomio::resizeAumentarPolinomio(int DIM){

	//Reservo memoria para el vector auxiliar con una DIM +1.
	float *aux = new float[DIM+1];

	//Compruebo que hay memoria suficiente.
	if (aux == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}

	//Relleno el vector auxiliar de 0.
	for(int i = 0;i <= DIM;i++){
		aux[i] = 0.0;
	}

	//Copio el contenido de coef[i] en aux[i].
	for(int i = 0;i <= getMax_Grado();i++){
		aux[i]=coef[i];
	}

	//Eliminamos la memoria del vector coef.
	delete [] coef;

	//Reasignamos el puntero de coeficientes.
	coef = aux;

	//Actualizo el máximo grado y el grado.
	max_grado = DIM;
	grado = max_grado;
}
void Polinomio::resizeDisminuirPolinomio(int DIM){

	//Reservo memoria para el vector auxiliar con una DIM +1.
	float *aux = new float[DIM+1];				

	//Compruebo que hay memoria suficiente.
	if (aux == 0){
		cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
		exit(-1);
	}

	//Relleno el vector auxiliar de 0.
	for(int i = 0; i <= DIM; i++){
		aux[i] = 0.0;
	}

	//Copio el contenido de coef[i] en aux[i].
	for(int i = 0; i <= DIM; i++){
		aux[i]=coef[i];
	}

	//Eliminamos la memoria del vector coef.
	delete [] coef;

	//Reasignamos el puntero de coeficientes.
	coef = aux;

	if(this->getDEBUG() == true){
	}
		max_grado = DIM;
		grado = max_grado;

	if(this->getDEBUG() == true){
	}
}
///////////////////////////////				SET				///////////////////////////////

void Polinomio::setCoeficientev1(int i, float c){

	//Filtro para que el grado que vamos a insertar en el vector sea menos que max_grado.
	if( i > getMax_Grado()){
		cout << " Lo siento no puedo insertar un valor mayor que el grado máximo del polinomio." << endl;
	}else{
		setGrado(i);
		coef[i]=c;
	}
}
void Polinomio::setCoeficientev2(int i, float c){

	//Filtro para que el grado que vamos a insertar en el vector aumente si fuese necesario.
	if(i >= 0){
		if( i >= getMax_Grado()){
			resizeAumentarPolinomio(i+1);
			setGrado(i);
			coef[i]=c;
		}else if (i < getMax_Grado()){
			setGrado(i);
			coef[i]=c;
			}
	}else if (i < 0){
		cerr << RED << "Error un polinomo no puede tener un grado negativo" << DEFAULT << endl;
		cerr << ERROR << "No se insertará ese monomio" << DEFAULT << endl;
	}
}
void Polinomio::setCoeficientev3(int i, float c){

	bool encontrado = false;

	//Filtro para que el grado que vamos a insertar en el vector aumente si fuese necesario.
	if(i >= 0){
		if( i > getMax_Grado() ){
			resize(i);
			coef[i]=c;
		}else if (i < getMax_Grado()){
			setGrado(i);
			coef[i]=c;
		}else if(i == getMax_Grado()){
			if (c == 0.0){
				for(int i = getMax_Grado()-1; i >= 0 && encontrado == false; i--){
					if(coef[i] != 0){
						resize(i);
						encontrado = true;
					}
				}
			}else if (c != 0.0) {
				coef[i]=c;
			}
		}
	}else if (i < 0){
		cerr << RED << "Error un polinomo no puede tener un grado negativo" << DEFAULT << endl;
		cerr << ERROR << "No se insertará ese monomio" << DEFAULT << endl;
	}
}
void Polinomio::setGrado(int i){

	//Filtro para evitar que grado sea negativo. Si es menor que 0 muestra un mensaje y no inserta nada.
	if(i >= 0){
		if( i >= grado){
			this->grado = i;
		}
	}else if (i < 0){
		cerr << RED << "Error un polinomo no puede tener un grado negativo" << DEFAULT << endl;
		cerr << ERROR << "No se insertará ese monomio" << DEFAULT << endl;
	}
}
void Polinomio::setMax_Grado(int i){

	//Filtro para evitar que max_grado sea negativo. Si es 0 muestra un mensaje.
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

void Polinomio::printPolinomio(){

	//setDEBUG(false);
	
	if(this->getDEBUG() == true){
		cout << GREY << "***	DEBUG POLINOMIO  ***" << DEFAULT << endl;
		cout << "DEBUG: Max_grado: " << getMax_Grado() << " y grado: " << getGrado() << endl;	

	cout << GREY << "****************************************" << DEFAULT << endl; 
	      	cout <<"P(x) = ";	
		for(int i = 0; i <= getGrado();i++){
		    cout << coef[i] << "x^" << i;
		    if(i != getGrado()){
		        cout << " + ";
		    }
		}
		cout << endl;
	}

	cout << GREY << "****************************************" << DEFAULT << endl; 

      	cout <<"P(x) = ";
	cout << getCoeficiente(getGrado());
	if(getGrado() > 0){
		cout << "x^" << getGrado();
	}
	for(int i = getGrado()-1; i >= 0; i--){
		if(getCoeficiente(i) != 0.0){
			cout << " + " << getCoeficiente(i) << "x^" << i;		
		}
	}
	cout << endl;

	cout << GREY << "****************************************" << DEFAULT << endl; 

	cout << CYAN << "Máximo grado del polinomio: " << DEFAULT << getMax_Grado() << endl;
}
///////////////////////////////				SUM			///////////////////////////////

void Polinomio::sumPolinomio(Polinomio &p2){

	if(this->getGrado() > p2.getGrado()){
		for(int i = 0; i <= p2.getGrado(); i++){
			this->setCoeficientev3(i,this->getCoeficiente(i) + p2.getCoeficiente(i));	
				for( int i = p2.getGrado()+1;  i < this->getGrado();i++){
					this->coef[i] = p2.coef[i];
				}
		}
	}else if(this->getGrado() < p2.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			this->setCoeficientev3(i, this->getCoeficiente(i) + p2.getCoeficiente(i));	
				for( int i =  this->getGrado()+1; i < p2.getGrado();i++){
					this->coef[i] = p2.coef[i];
				}
		}	
	}else if(this->getGrado() == p2.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			this->setCoeficientev3(i, this->getCoeficiente(i) + p2.getCoeficiente(i));
		}
	}

	this->printPolinomio();
}

void Polinomio::sumPolinomiov2(Polinomio &p2,Polinomio &p3){

	if(p2.getGrado() > p3.getGrado()){
		for(int i = 0; i <= p2.getGrado(); i++){
			this->setCoeficientev3(i,p2.getCoeficiente(i) + p3.getCoeficiente(i));	
				for( int i = p3.getGrado()+1;  i < p2.getGrado();i++){
					this->setCoeficientev3(i, p2.coef[i] = p3.coef[i]);
				}
		}
	}else if(p2.getGrado() < p3.getGrado()){
		for(int i = 0; i <= p3.getGrado(); i++){
			this->setCoeficientev3(i, p2.getCoeficiente(i) + p3.getCoeficiente(i));	
				for( int i =  p3.getGrado()+1; i < p2.getGrado();i++){
					this->setCoeficientev3(i, p2.coef[i] = p3.coef[i]);
				}
		}	
	}else if(p2.getGrado() == p3.getGrado()){
		for(int i = 0; i <= p3.getGrado(); i++){
			this->setCoeficientev3(i, p2.getCoeficiente(i) + p3.getCoeficiente(i));
		}
	}

	this->printPolinomio();
}
Polinomio Polinomio::sumPolinomiov3(const Polinomio &p2){

	Polinomio aux (p2);
	
	this->setCoeficientev3(7,7);
	aux.setCoeficientev3(7,7);
	

	if(this->getGrado() > aux.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			aux.setCoeficientev3(i,this->getCoeficiente(i) + aux.getCoeficiente(i));	
				for( int i =  this->getGrado()+1; i < aux.getGrado();i++){
					 aux.setCoeficientev3(i,aux.coef[i] = this->getCoeficiente(i));
				}
		}
	}else if(this->getGrado() < aux.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			aux.setCoeficientev3(i, this->getCoeficiente(i) + aux.getCoeficiente(i));	
				for( int i =  this->getGrado()+1; i < aux.getGrado();i++){
					 aux.setCoeficientev3(i,aux.coef[i] = this->getCoeficiente(i));
				}
		}	
	}else if(this->getGrado() == aux.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			 aux.setCoeficientev3(i,this->getCoeficiente(i) + aux.getCoeficiente(i));
		}
	}

	return aux;
}
Polinomio* Polinomio::sumPolinomiov4(const Polinomio *p2){

	Polinomio *aux = new Polinomio();

	this->setCoeficientev3(10,7);
	aux->setCoeficientev3(10,7);
	

	if(this->getGrado() > aux->getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			aux->setCoeficientev3(i,this->getCoeficiente(i) + aux->getCoeficiente(i));	
				for( int i =  this->getGrado()+1; i < aux->getGrado();i++){
					 aux->setCoeficientev3(i,aux->coef[i] = this->getCoeficiente(i));
				}
		}
	}else if(this->getGrado() < aux->getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			aux->setCoeficientev3(i, this->getCoeficiente(i) + aux->getCoeficiente(i));	
				for( int i =  this->getGrado()+1; i < aux->getGrado();i++){
					 aux->setCoeficientev3(i,aux->coef[i] = this->getCoeficiente(i));
				}
		}	
	}else if(this->getGrado() == aux->getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			 aux->setCoeficientev3(i,this->getCoeficiente(i) + aux->getCoeficiente(i));
		}
	}

	return aux;
}
///////////////////////////////			OTHER METHODS			///////////////////////////////

void Polinomio::DatosPolinomio(){

	//Declaración de variable.
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
void Polinomio::DatosPolinomio2(){

	//Declaración de variable.
	float va = 0.0;			//Coeficiente
	int x = 0;			//Grado actual


	cout << "Introduzca el grado del monomio. " << endl;
	cout << BLUE << "Recuerde que el máximo grado de este polinomio es " << getMax_Grado() << DEFAULT << endl;
	for(int i = 0; i < getMax_Grado()+1 ;i++){
		cout << "Introduzca el grado del monomio. " << endl;
		cin >> x;
		cout << "Introduzca el valor de su coeficiente. " << endl;
		cin >> va;
		setCoeficientev3(x,va);
		cout << YELLOW << "***" << DEFAULT << endl;
	}
}
///////////////////////////////				TESTING				///////////////////////////////
/**
 * @brief Se mostrarán por pantalla las opciones de testing que el FRONT END quiera usar.
 * @post Se mostrará en el menú las siguientes opciones.
 * @version 1.0
 * @author Carlos Fdez.
 */
void Menu(){

	cout << BLUE <<"/***************************************"<< endl;
		cout << "****	     TESTING POLINOMIO	    ****" << endl;
		cout << "****************************************/ " << DEFAULT;
	cout << PURPLE <<  "\nAquí le mostramos las opciones disponibles para realizar el testing : " << DEFAULT;
	cout << PURPLE <<  "\n[0] " << DEFAULT << " TESTING 0. ";
	cout << PURPLE <<  "\n[1] " << DEFAULT << " TESTING 1. ";
	cout << PURPLE <<  "\n[2] " << DEFAULT << " TESTING 2. ";
	cout << PURPLE <<  "\n[3] " << DEFAULT << " TESTING 3. ";
	cout << PURPLE <<  "\n[4] " << DEFAULT << " TESTING 4. ";
	cout << PURPLE <<  "\n[5] " << DEFAULT << " TESTING 5. ";
	cout << PURPLE <<  "\n[6] " << DEFAULT << " TESTING 5.1. ";
	cout << PURPLE <<  "\n[7] " << DEFAULT << " TESTING AUTOMÁTICO. ";
	cout << PURPLE <<  "\n[8] " << DEFAULT << " Salir. " << endl;

}
void Polinomio::MenuTesting(){

	//Declaración de variables.
	int opcion=0;
	
	//Filtro para que el usuario no se salga de las opciones.
	while(opcion!=8){
		//Mostramos menú anteriormente realizado.
		Menu();
		
		//Pedimos al usuario que escoga una opción de las mostradas previamente.
		cout << "\nEliga usted el programa que desea ejecutar: " << endl;
		cin >> opcion;

			switch (opcion){
			
				case 0:
					Testing_0();
				break;

				case 1:
					Testing_1();
				break;

				case 2:
					Testing_2();
				break;
				
				case 3:
					Testing_3();
				break;
				
				case 4:		
					Testing_4();
				break;
				
				case 5:		
					Testing_5();
				break;
				
				case 6:		
					Testing_5_1();
				break;

				case 7:		
					TestingAutom();
				break;

				case 8:		
					cout << PURPLE << "----------SALIENDO----------\n" ;
					cout << "\nGracias por usar el testing del POLINOMIO " << endl;
					cout << "\n © Carlos Fdez " << DEFAULT << endl;
				break;
				
				default:
					cout << PURPLE << "Lo siento, la opción seleccionada no es correcta. " << DEFAULT << endl;
					cout << PURPLE << "Por favor seleccione otra o pulse 9 para salir. \n" << DEFAULT << endl;
			}
	}
}
void Polinomio::Testing_0(){

	cout  << YELLOW << "\n ****   TESTING 0    **** " << DEFAULT << endl;
	cout << BLUE << "Imprimiendo por pantalla el contenido por defecto tras la creación de un polinomio: " << DEFAULT << endl;
 	
    	printPolinomio();

	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;
    	cout  << YELLOW << "\n ****   TESTING 0 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_1(){

	cout  << YELLOW << "\n ****   TESTING 1    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado menos al actual. " << DEFAULT << endl;
 	
	cout << BLUE << "El grado actual es: " << getGrado() << endl;
    	setCoeficientev3(6,1);
	setCoeficientev3(4,8);

    	printPolinomio();

	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;
    	cout  << YELLOW << "\n ****   TESTING 1 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_2(){

	cout  << YELLOW << "\n ****   TESTING 2    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado negativo. " << DEFAULT << endl;

	cout << BLUE << "El grado actual es: " << getGrado() << endl;
    	setCoeficientev3(-1,4);

    	printPolinomio();

	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;
    	cout  << YELLOW << "\n ****   TESTING 2 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_3(){

	cout  << YELLOW << "\n ****   TESTING 3    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado mayor al actual, pero que sea menor que max_grado. " << DEFAULT << endl;
 	
	cout << BLUE << "El grado actual es: " << getGrado() << endl;
    	setCoeficientev3(1,4);
    	setCoeficientev3(8,87);

    	printPolinomio();

	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;
    	cout  << YELLOW << "\n ****   TESTING 3 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_4(){

	cout  << YELLOW << "\n ****   TESTING 4    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado mayor al actual, y que sea mayor que max_grado. " << DEFAULT << endl;
 	
	cout << BLUE << "El grado actual es: " << getGrado() << endl;
    	setCoeficientev3(3,4);
    	setCoeficientev3(18,87);

    	printPolinomio();

	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;
    	cout  << YELLOW << "\n ****   TESTING 4 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_5(){

	cout  << YELLOW << "\n ****   TESTING 5    **** " << DEFAULT << endl;
	cout << BLUE << "Inserta un monomio de grado igual al actual y cuyo coeficiente sea 0. " << DEFAULT << endl;
 
 	
	cout << BLUE << "El grado actual es: " << getGrado() << endl;
    	setCoeficientev3(18,0);
    	setCoeficientev3(0,4);

    	printPolinomio();

	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;
    	cout  << YELLOW << "\n ****   TESTING 5 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::Testing_5_1(){

	cout  << YELLOW << "\n ****   TESTING 5.1    **** " << DEFAULT << endl;
	cout << BLUE << "Si todos los coeficientes anteriores también son 0. " << DEFAULT << endl;


	cout << BLUE << "El grado actual es: " << getGrado() << endl;
    	setCoeficientev3(8,0);
    	setCoeficientev3(4,0);

    	printPolinomio();

	cout << BLUE << "El grado actual después de insertar los datos es: " << getGrado() << endl;
    	cout  << YELLOW << "\n ****   TESTING 5.1 TERMINADO    **** " << DEFAULT << endl;
}
void Polinomio::TestingAutom(){

	cout  << YELLOW << "\n ****   TESTING AUTOMÁTICO    **** " << DEFAULT << endl;
	cout << BLUE << "Se realizará los testing automatizados. " << DEFAULT << endl;

	Testing_1();	// Inserta un monomio de grado menos al actual.
	Testing_2();	// Inserta un monomio de grado negativo.
	Testing_3();	// Inserta un monomio de grado mayor al actual, pero que sea menor que max_grado.
	Testing_4();	// Inserta un monomio de grado mayor al actual, y que sea mayor que max_grado.
	Testing_5();	// Inserta un monomio de grado igual al actual y cuyo coeficiente sea 0.
	Testing_5_1();	// Si todos los coeficientes anteriores también son 0.

    	cout  << YELLOW << "\n ****   TESTING AUTOMÁTICO TERMINADO    **** " << DEFAULT << endl;
}
/**
 * @brief Módulo que se encarga de pedir al usuario el valor máximo de su polinomio.
 * @param int max	//Número que devolvemos para quear un polinomio de valor exacto.
 * @pre El valor no puede ser negativo, es decir tiene que ser mayor que 0.
 * @post 
 * @version 1.0
 * @author Carlos Fdez.
 */
int GradoPolinomio(int max){

	cout  << PURPLE << "\n ****   POLINOMIO    **** " << DEFAULT << endl;
	cout << BLUE << "Introduzca el máximo grado del polinomio: " << DEFAULT << endl;
	cin >> max;

	// Filtro para que no introduzca el usuario ningún valor negativo. Ya que un Polinomio no puede ser negativo.
	if( max < 0 ){
		cout << ERROR << "El polinomio no puede tener un grado negativo. Se abortará la ejecución. " << DEFAULT << endl;
		exit(-1);
	}

	return max;
}
int main(){

	//Declaración de variable que asignaremos para crear el polinomio de un tamaño inicial.
	int max = 0;
	//max = GradoPolinomio(max);	// Módulo que se encarga de pedir al usuario el grado máximo del polinomio que desea crear.
	bool TESTING = false;		// Variable booleana que activa y desactiva el modo Testing.

	/****		Creación de Polinomios		****/
	Polinomio p1;		// Creación de un Polinomio.
	//Polinomio p1 (max);	// Creación de un Polinomio de max_grado = max (variable introducida por el usuario).
	//Polinomio p2 (p1);	// Creamos una copia del polinomio
	//Polinomio p3 (p1);	// Creamos una copia del polinomio
	//Polinomio *p1;
	Polinomio*p2;
	Polinomio *res;

	/****		Modo DEBUG		****/
	p1.setDEBUG(true);

	/****		Datos introducidos por el usuario	****/
	//p1.DatosPolinomio();	// Pedimos Datos al usuario rellenando de menor grado a mayor todo el Polinomio.(sólo pedimos el valor)
	//p1.DatosPolinomio2();	// Pedimos Datos al usuario. (coeficiente y valor)

	/****		Datos introducidos por el programador FrontEnd en p1	****/
	/*p1.setCoeficientev3(7,35);
	p1.setCoeficientev3(0,6);
	p1.setCoeficientev3(1,6);
	p1.setCoeficientev3(2,6);
	p1.setCoeficientev3(7,6);
	p1.setCoeficientev3(4,6);
	p1.setCoeficientev3(5,6);
	p1.setCoeficientev3(6,6);
	p1.setCoeficientev3(10,6);

	/****		Imprimir Polinomio p1		****/
	//p1.printPolinomio();

	/****		Datos introducidos por el programador FrontEnd en p2	****/
	/*p2.setCoeficientev3(9,7);
	p2.setCoeficientev3(4,20);
	p2.setCoeficientev3(5,25);
	p2.setCoeficientev3(6,30);
	p2.setCoeficientev3(10,50);

	/****		Imprimir Polinomio p2		****/
	//p2.printPolinomio();	// Imprimimos polinomio p2 (copia exacta de p1).
	//p1.setCoeficientev3(10,6);
	//p2.setCoeficientev3(4,50);
	/****		SUMAR 		****/
	//Polinomio *res = new Polinomio();
	res = p1.sumPolinomiov4(p2);
	res->printPolinomio();

	/****		MENÚ TESTING Polinomio p1		****/		
	if(TESTING == true){
		res->MenuTesting();	// Menú donde puedes seleccionar el testing que desees tanto unitario como automático.
	}


}
