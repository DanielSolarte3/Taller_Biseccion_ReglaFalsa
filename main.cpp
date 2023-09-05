#include<iostream>
#include <string>

#include "biseccion.h"
#include "expression.h"
#include "reglafalsa.h"

using raices::biseccion;
using raices::reglafalsa;
using std::cin;
using std::cout;
using std::endl;
using std::string;


/**
* @brief Menu de opciones
*/
void menu();

/**
* @brief Metodo 1.
* @param str_f String de la funcion
*/

void metodo_biseccion(string str_f);

/**
* @brief Metodo 2.
* @param str_f String de la funcion
*/

void metodo_reglaFalsa(string str_f);

int main () {
	menu();
	return 0;
}

void menu(){
	int metodo /*!< Opcion menu de metodos*/;
	int funcion; /*!< Opcion menu de funciones*/
	string str_f1 = "x^2 - cos(x)";
	string str_f2 = "x^3 + 4*(x^2)-10";
	
	do{
		cout << "\n==============================================================\n" << endl;
		cout << "1. Metodo de Biseccion " << endl;
		cout << "2. Regla Falsa" << endl;
		cout << "3. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> metodo;
		
		switch(metodo){
		case 1:
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "1. " << str_f1 << endl;
			cout << "2. " << str_f2 << endl;
			cout << "Ingrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_biseccion(str_f1);
				break;
			case 2:
				metodo_biseccion(str_f2);
				break;
			}			
			break;
			
		case 2:
			cout << "Seleccione la funcion a evaluar: " << endl;
			cout << "1. " << str_f1 << endl;
			cout << "2. " << str_f2 << endl;
			cout << "Ingrese una opcion: ";
			cin >> funcion;
			switch(funcion){
			case 1:
				metodo_reglaFalsa(str_f1);
				break;
			case 2:
				metodo_reglaFalsa(str_f2);
				break;
			}			
			break;
			
		case 3: 
			
			cout << "Saliendo..." << endl;
			exit(0);	
			break;
			
		default:
			cout << "Opcion invalida" << endl;
		}
		
	}while(metodo != 4);
}

void metodo_biseccion(string str_f) {
	
	double xa, xb, tol;
	int n;
	
	cout << "Metodo de biseccion" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xa;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xb;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de biseccion pasando 
	//la funcion como parametro
	
	biseccion bis(str_f);
	
	solucion sol = bis.calcular(xa, xb, tol, n);
	
	sol.imprimir();
}

void metodo_reglaFalsa(string str_f) {
	
	double xi, xs, tol;
	int n;
	
	cout << "Metodo de regla Falsa" << endl;
	cout << "Funcion a evaluar: " << str_f << endl;
	cout << "Ingrese el valor inferior del intervalo: ";
	cin >> xi;
	cout << "Ingrese el valor superior del intervalo: ";
	cin >> xs;
	cout << "Ingrese la tolerancia (en porcentaje): ";
	cin >> tol;
	cout << "Ingrese el maximo numero de iteraciones: ";
	cin >> n;
	//Crear una instancia de regla falsa pasando 
	//la funcion como parametro
	
	reglafalsa rf(str_f);
	
	solucion sol = rf.calcular(xi,xs,tol,n);
	
	sol.imprimir();
	
}

