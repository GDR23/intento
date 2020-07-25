#pragma once
class Nodo
{
private:
	int valor;
	int contar=0;
	Nodo* siguiente;
	Nodo* anterior;

public:
	Nodo(int);

	void setValor(int);
	void setSiguiente(Nodo*);
	void setAnterior(Nodo*);
	Nodo* getAnterior();
	int getValor();
	Nodo* getSiguiente();
	int getContar();
	void setContar();
	void copyContar(int);

};

