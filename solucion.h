#ifndef SOLUCION_H
#define SOLUCION_H

#include <cfloat>
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

using std::cout;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;

void imprimir();

namespace raices { // Agrupa diferentes definiciones de clases, funciones y variables
	/**
	* @brief Aproximacion de una solucion
	*/
	struct aproximacion { // Clase donde sus atributos son publicos por defecto
		double xAnt;/*!< Valor anterior */
		double xNueva;/*!< Valor anterior */
		double erp;/*!< Error relativo porcentual entre los dos valores */
	};
	
	/**
	* @brief Solucion a un metodo numerico para encontrar una raiz
	*/
	struct solucion {
		double raiz = NAN; /*!< Raiz encontrada, NAN si no se pudo hallar */ 
		vector<aproximacion> aproximaciones; /*!< Vector de aproximaciones */
		
		/**
		* @brief Adiciona una nueva aproximacion
		* @param a Aproximacion
		*/
		void adicionar(aproximacion a) {
			aproximaciones.push_back(a); // Adiciona una nueva a
		}
		
		void imprimir(){
			if (std::isnan(raiz)) {
				cout << "No se pudo obtener la raiz con los datos dados"<<endl;
			}else {
				cout << "La raiz es: " << raiz <<endl;
				cout << "Aproximaciones: "<< endl;
				for (unsigned int i = 0; i< aproximaciones.size(); i++) {
					cout << setw(20)
						<< setprecision(10)
						<< aproximaciones[i].xAnt
						<< setw(20)
						<< setprecision(10)
						<< aproximaciones[i].xNueva
						<< setw(20)
						<< setprecision(10)
						<< aproximaciones[i].erp
						<<endl;
				}
			}
		}
	};
};



#endif
