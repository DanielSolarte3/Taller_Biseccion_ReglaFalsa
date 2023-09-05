#include<iostream>
#include <string>

#include "biseccion.h"
#include "expression.h"
#include "reglafalsa.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using raices::biseccion;
using raices::reglafalsa;

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
	//Funcion 1 biseccion
	metodo_biseccion("x^2 - cos(x)");
	printf("===============================================================================================\n");
	//Funcion 2 biseccion
	metodo_biseccion("x^3 + 4*(x^2) - 10");
	printf("===============================================================================================\n");
	//Funcion 1 regla Falsa
	metodo_reglaFalsa("x^2 - cos(x)");
	printf("===============================================================================================\n");
	//Funcion 2 regla Falsa
	metodo_reglaFalsa("x^3 + 4*(x^2) - 10");
	return 0;
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
