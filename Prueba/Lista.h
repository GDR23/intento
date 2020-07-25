#pragma once
#include"Nodo.h"
class Lista
{
private:
	Nodo* primero;

public:
	int count;
	Lista();
	bool estaVacia();
	void agregarElemento(int);
	void ordenar();
	void imprimir();
	void repeticiones();
	void Resultado();
	bool confirmacion(int);
	void Funcion();

};

