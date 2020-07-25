#include "Nodo.h"


Nodo::Nodo(int _valor) {
	setValor(_valor);
	setSiguiente(nullptr);
	setAnterior(nullptr);
}

void Nodo::setValor(int _valor) {
	this->valor = _valor;
}

void Nodo::setSiguiente(Nodo* _siguiente) {
	this->siguiente = _siguiente;
}

int Nodo::getValor() {
	return this->valor;
}

Nodo* Nodo::getSiguiente() {
	return this->siguiente;
}

void Nodo::setAnterior(Nodo* _anterior) {
	this->anterior = _anterior;
}

Nodo* Nodo::getAnterior() {
	return this->anterior;
}

int Nodo::getContar() {
	return contar;
}

void Nodo::setContar() {
	contar++;
}

void Nodo::copyContar(int valor) {
	contar = valor;
}


