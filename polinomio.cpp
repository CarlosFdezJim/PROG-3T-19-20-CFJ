//
//	polinomio.cpp
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

	setDEBUG(true);
	
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
		}	

	}else if(this->getGrado() < p2.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			this->setCoeficientev3(i, this->getCoeficiente(i) + p2.getCoeficiente(i));	
		}
			for( int i =  this->getGrado()+1; i <= p2.getGrado();i++){
				this->setCoeficientev3(i, p2.coef[i]);
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
		for(int i = 0; i <= p3.getGrado(); i++){
			this->setCoeficientev3(i,p2.getCoeficiente(i) + p3.getCoeficiente(i));	
		}
			for( int i = p3.getGrado()+1; i <= p2.getGrado();i++){
				this->setCoeficientev3(i,p2.coef[i]);
			}
		
	}else if(p2.getGrado() < p3.getGrado()){
		for(int i = 0; i <= p2.getGrado(); i++){
			this->setCoeficientev3(i, p2.getCoeficiente(i) + p3.getCoeficiente(i));	
		}		
			for( int i = p2.getGrado()+1; i <= p3.getGrado();i++){
				this->setCoeficientev3(i, p3.coef[i]);
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

	if(this->getGrado() > aux.getGrado()){
		for(int i = 0; i <= aux.getGrado(); i++){
			aux.setCoeficientev3(i,this->getCoeficiente(i) + aux.getCoeficiente(i));	
		}
			for( int i = aux.getGrado()+1; i <= this->getGrado();i++){
				 aux.setCoeficientev3(i,this->getCoeficiente(i));
			}
			
	}else if(this->getGrado() < aux.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			aux.setCoeficientev3(i, this->getCoeficiente(i) + aux.getCoeficiente(i));	
		}		
			for( int i = this->getGrado()+1; i <= aux.getGrado();i++){
				 aux.setCoeficientev3(i,aux.getCoeficiente(i));
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

	this->setCoeficientev3(4,5);
	aux->setCoeficientev3(4,35);
	
	if(this->getGrado() > aux->getGrado()){
		for(int i = 0; i <= aux->getGrado(); i++){
			aux->setCoeficientev3(i,this->getCoeficiente(i) + aux->getCoeficiente(i));	
		}		
			for( int i = aux->getGrado()+1; i <= this->getGrado();i++){
				 aux->setCoeficientev3(i, this->getCoeficiente(i));
			}
		
	}else if(this->getGrado() < aux->getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			aux->setCoeficientev3(i, this->getCoeficiente(i) + aux->getCoeficiente(i));	
		}		
			for( int i = this->getGrado()+1; i <= aux->getGrado();i++){
				 aux->setCoeficientev3(i, aux->getCoeficiente(i));
			}
			
	}else if(this->getGrado() == aux->getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			 aux->setCoeficientev3(i,this->getCoeficiente(i) + aux->getCoeficiente(i));
		}
	}

	return aux;
}
///////////////////////////////			SOBRECARGA			///////////////////////////////

Polinomio Polinomio::operator+(const Polinomio &p){

	Polinomio aux(p);

	if(this->getGrado() > aux.getGrado()){
		for(int i = 0; i <= aux.getGrado(); i++){
			aux.setCoeficientev3(i,this->getCoeficiente(i) + aux.getCoeficiente(i));	
		}
			for( int i = aux.getGrado()+1; i <= this->getGrado();i++){
				 aux.setCoeficientev3(i,this->getCoeficiente(i));
			}
			
	}else if(this->getGrado() < aux.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			aux.setCoeficientev3(i, this->getCoeficiente(i) + aux.getCoeficiente(i));	
		}		
			for( int i = this->getGrado()+1; i <= aux.getGrado();i++){
				 aux.setCoeficientev3(i,aux.getCoeficiente(i));
			}
			
	}else if(this->getGrado() == aux.getGrado()){
		for(int i = 0; i <= this->getGrado(); i++){
			 aux.setCoeficientev3(i,this->getCoeficiente(i) + aux.getCoeficiente(i));
		}
	}
	
	return aux;
}
void Polinomio::operator=(const Polinomio &p){

	delete[] this->coef;

	//Inicializamos los miembros del polinomio.
	this->max_grado = p.max_grado;
	this->grado = p.grado;

	//Filtro para que al crear un polinomio no sea de grado negativo, en caso de serlo abortará la ejecución.
	if(this->max_grado >= 0){
		//Creamos un vector dinámico de coeficientes.
		this->coef = new float[this->getMax_Grado()+1];	//Reservo el valor de max_grado+1.


		//Rellenamos el vector de coeficientes a 0
		for(int i=0; i <= this->getMax_Grado(); i++){
			this->coef[i]= p.coef[i];
		}

	}else if (this->max_grado < 0){
		cerr << "¡¡ERROR!! un polinomo no puede tener un grado negativo." << endl;
		cerr << RED << "Se abortará la ejecución" << DEFAULT << endl;
		exit(-1);
	}


}
ostream& operator<<(ostream &flujo, const Polinomio &p){
	
	cout << GREY << "***	DEBUG POLINOMIO  ***" << DEFAULT << endl;
	cout << "DEBUG: Max_grado: " << p.getMax_Grado() << " y grado: " << p.getGrado() << endl;	

	flujo << GREY << "****************************************" << DEFAULT << endl; 
	      	flujo << "P(x) = ";	
		for(int i = 0; i <= p.getGrado();i++){
		    flujo << p.coef[i] << "x^" << i;
		    if(i != p.getGrado()){
		        flujo << " + ";
		    }
		}
		flujo << endl;

	flujo << GREY << "****************************************" << DEFAULT << endl; 

      	flujo <<"P(x) = ";
	flujo << p.getCoeficiente(p.getGrado());
	if(p.getGrado() > 0){
		flujo << "x^" << p.getGrado();
	}
	for(int i = p.getGrado()-1; i >= 0; i--){
		if(p.getCoeficiente(i) != 0.0){
			flujo << " + " << p.getCoeficiente(i) << "x^" << i;		
		}
	}
	flujo << endl;

	flujo << GREY << "****************************************" << DEFAULT << endl; 

	flujo << CYAN << "Máximo grado del polinomio: " << DEFAULT << p.getMax_Grado() << endl;
	
	return flujo;
}
ostream& operator<<(ostream &flujo, Polinomio* p){
	
	cout << GREY << "***	DEBUG POLINOMIO  ***" << DEFAULT << endl;
	cout << "DEBUG: Max_grado: " << p->getMax_Grado() << " y grado: " << p->getGrado() << endl;	

	flujo << GREY << "****************************************" << DEFAULT << endl; 
	      	flujo << "P(x) = ";	
		for(int i = 0; i <= p->getGrado();i++){
		    flujo << p->coef[i] << "x^" << i;
		    if(i != p->getGrado()){
		        flujo << " + ";
		    }
		}
		flujo << endl;

	flujo << GREY << "****************************************" << DEFAULT << endl; 

      	flujo <<"P(x) = ";
	flujo << p->getCoeficiente(p->getGrado());
	if(p->getGrado() > 0){
		flujo << "x^" << p->getGrado();
	}
	for(int i = p->getGrado()-1; i >= 0; i--){
		if(p->getCoeficiente(i) != 0.0){
			flujo << " + " << p->getCoeficiente(i) << "x^" << i;		
		}
	}
	flujo << endl;

	flujo << GREY << "****************************************" << DEFAULT << endl; 

	flujo << CYAN << "Máximo grado del polinomio: " << DEFAULT << p->getMax_Grado() << endl;
	
	return flujo;
}
istream& operator>>(std::istream &flujo, Polinomio &p){
	
	//Declaración de variables
	int i;		//Variable que nos indica el grado de este polinomio.
	float c;	//Variable que ingresa el valor de este polinomio.
	
		cout << "Introduciremos los datos en el polinomoi como deseemos,"; 
		cout << RED << " recuerda que para terminar debes de pulsar -1 en el grado del monomio." << DEFAULT << endl;
	do{

		cout << "Introduzca el grado del monomio. " << endl;
		flujo >> i;
		cout << "Introduzca el valor de su coeficiente. " << endl;
		flujo >> c;
		
		if(i >= 0){
			p.setCoeficientev3(i,c);
		}
	}while(i >= 0);
	
	return flujo;
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
    	setCoeficientev3(15,0);
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
