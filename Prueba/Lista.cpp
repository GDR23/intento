#include "Lista.h"
#include <iostream>
using namespace std;
Lista::Lista() :primero(nullptr) {

}

bool Lista::estaVacia() {
	return primero == nullptr;
}

void Lista::agregarElemento(int _valor) {
	Nodo* nuevo = new Nodo(_valor);

	if (estaVacia()) {
		primero = nuevo;
		count++;
		return;
	}
	else {
		Nodo* tmp = primero;
		while (tmp->getSiguiente() != nullptr) {
			tmp = tmp->getSiguiente();


		}
		tmp->setSiguiente(nuevo);
		nuevo->setAnterior(tmp);
		count++;
	}

}

void Lista::ordenar() {
	Nodo* ordenar = primero;
	Lista listtmp;
	while (ordenar != nullptr) {
		Nodo* nuevo = new Nodo(ordenar->getValor());

		if (listtmp.primero == nullptr) {
			listtmp.primero = nuevo;
		}
		else {
			int cont = 0;
			Nodo* tmp2 = listtmp.primero;
			while (cont!=1) {

				if(nuevo->getValor() >= tmp2->getValor() && tmp2->getSiguiente()==nullptr) {
					tmp2->setSiguiente(nuevo);
					nuevo->setAnterior(tmp2);
					cont++;
			
				}
				else if (nuevo->getValor() <= tmp2->getValor() && tmp2->getAnterior() == nullptr) {
					nuevo->setSiguiente(tmp2);
					listtmp.primero = nuevo;
					cont++;
				}
				else if (nuevo->getValor() >= tmp2->getValor() && nuevo->getValor()<= tmp2->getSiguiente()->getValor()) {
					nuevo->setSiguiente(tmp2->getSiguiente());
					nuevo->setAnterior(tmp2);
					tmp2->getSiguiente()->setAnterior(nuevo);
					tmp2->setSiguiente(nuevo);
					cont++;
				}
				tmp2 = tmp2->getSiguiente();
			


			}
		}
		ordenar = ordenar->getSiguiente();

	}

	primero = listtmp.primero;


}



void Lista::imprimir() {
	if (estaVacia()) {
		cout << "LISTA VACIA";
		return;
	}
	Nodo* actual = primero;
	while (actual != nullptr) {
		cout << "[" << actual->getValor() << "]";
		actual = actual->getSiguiente();
	}
}

void Lista::repeticiones() {
	Nodo* tmp = primero;


	while (tmp != nullptr) {
		Nodo* recorrido = primero;
		while (recorrido != nullptr) {
			if (tmp->getValor() == recorrido->getValor()) {
				tmp->setContar();

			}
			recorrido = recorrido->getSiguiente();
		}
		
		tmp = tmp->getSiguiente();
	}

}

bool Lista::confirmacion(int valor) {
	Nodo* tmp = primero;
	while (tmp != nullptr) {
		if (tmp->getValor() == valor) {
			return true;
		}
		tmp = tmp->getSiguiente();
	}
	return false;
}
void Lista::Resultado(){
	Nodo* tmp = primero;
	Lista final;
	while (tmp != nullptr) {
	
		if (final.primero == nullptr) {
			Nodo* nuevo = new Nodo(tmp->getValor());
			nuevo->copyContar(tmp->getContar());
			final.primero = nuevo;
		}
		else {
			int cont = 0;
			Nodo* tmp2 = final.primero;
			while (cont != 1 && tmp2!=nullptr) {
				if (final.confirmacion(tmp->getValor())==false) {
					Nodo* nuevo = new Nodo(tmp->getValor());
					nuevo->copyContar(tmp->getContar());
					if (nuevo->getContar() >= tmp2->getContar() && tmp2->getAnterior() == nullptr) {
						
						nuevo->setSiguiente(tmp2);
						tmp2->setAnterior(nuevo);
						final.primero = nuevo;
						cont++;

					}
					else if (nuevo->getContar() <= tmp2->getContar() && tmp2->getSiguiente() == nullptr) {
						tmp2->setSiguiente(nuevo);
						nuevo->setAnterior(tmp2);
					
						cont++;
					}
					else if (nuevo->getContar() <= tmp2->getContar() && nuevo->getContar() >= tmp2->getSiguiente()->getContar()) {
						nuevo->setSiguiente(tmp2->getSiguiente());
						nuevo->setAnterior(tmp2);
						tmp2->getSiguiente()->setAnterior(nuevo);
						tmp2->setSiguiente(nuevo);
						cont++;
					}
				}

				tmp2 = tmp2->getSiguiente();



			}
		}
		tmp = tmp->getSiguiente();

	}

	Nodo* imprimir = final.primero;
	cout << "\nLISTA" << "\t" << "REPETICIONES"<<endl;
	while (imprimir != nullptr) {
		cout << "[" << imprimir->getValor() << "]" << "\t" << imprimir->getContar()<<endl;
		imprimir = imprimir->getSiguiente();
	}


}

void Lista::Funcion() {
	
	ordenar();
	imprimir();
	repeticiones();
	Resultado();
}
