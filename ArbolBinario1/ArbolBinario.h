#pragma once
#include<iostream>
#include<sstream>
#include"NodoArbol.h"
class ArbolBinario
{

	//int Buscar(NodoArbol* raiz, string valor) {
	//if (raiz == nullptr) {
	//     return -1;
	//	}
	//else if (valor == raiz->GetValor()) {
	//	return 1;
	//}
	//else
	//{
	//	string tmp = raiz->GetValor();
	//	stringstream converter1(valor);
	//	stringstream converter2(tmp);
	//	int nuevo = 0;
	//	int actual = 0;
	//	converter1 >> nuevo;
	//	converter2 >> actual;

	//	if (nuevo >= actual) {
	//	return Buscar(raiz->GetDerecho(), valor);
	//	}
	//	else if (nuevo < actual) {
	//	return Buscar(raiz->GetIzquierdo(), valor);
	//	}

	//
	//}
	//}

private:

	NodoArbol* Encontrar(NodoArbol* nodoPadre, string valor)
	{
		stringstream converter1(valor);
		stringstream converter2(nodoPadre->GetValor());

		int valorString = 0;
		int valorActual = 0;
		converter1 >> valorString;
		converter2 >> valorActual;

		if (nodoPadre == nullptr)
			return nullptr;
		else if (nodoPadre->GetValor() == valor)
			return nodoPadre;
		else if (valorString < valorActual)
			return Encontrar(nodoPadre->GetIzquierdo(), valor);
		else
			return Encontrar(nodoPadre->GetDerecho(), valor);
	}

	void Insertar(NodoArbol* nodoPadre, string value)
	{
		string valorActualString = nodoPadre->GetValor();

		stringstream converter1(value);
		stringstream converter2(valorActualString);

		int nuevoValor = 0;
		int valorActual = 0;
		converter1 >> nuevoValor;
		converter2 >> valorActual;

		if (nuevoValor >= valorActual)
		{
			if (nodoPadre->GetDerecho() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				nodoPadre->SetDerecho(nuevo);
				nuevo->SetPadre(nodoPadre);
				return;

			}
			else {
				Insertar(nodoPadre->GetDerecho(), value);
			}
		}
		else if (nuevoValor < valorActual)
		{
			if (nodoPadre->GetIzquierdo() == nullptr) {
				NodoArbol* nuevo = new NodoArbol(value);
				nodoPadre->SetIzquierdo(nuevo);
				nuevo->SetPadre(nodoPadre);
				return;

			}
			else {
				Insertar(nodoPadre->GetIzquierdo(), value);
			}
		}
	}

public:

	NodoArbol* Raiz;
	int Count;

	ArbolBinario() :Raiz(nullptr) {
		Count = 0;
	}

	void Eliminar(string valor)
	{
		NodoArbol* valorEncontrado = Buscar(valor);
		NodoArbol* padreEncontrado = valorEncontrado->GetPadre();

		if (valorEncontrado->GetDerecho() == nullptr) {
			if (padreEncontrado == nullptr)
				Raiz = valorEncontrado->GetIzquierdo();
			else {
				if (padreEncontrado->toInt() > valorEncontrado->toInt()) {
					padreEncontrado->SetIzquierdo(valorEncontrado->GetIzquierdo());
				}
				else if (padreEncontrado->toInt() < valorEncontrado->toInt())
				{
					padreEncontrado->SetDerecho(valorEncontrado->GetIzquierdo());
				}
			}
		}
		else if (valorEncontrado->GetDerecho()->GetIzquierdo() == nullptr)
		{
			valorEncontrado->GetDerecho()->SetIzquierdo(valorEncontrado->GetIzquierdo());

			if (padreEncontrado == nullptr)
				Raiz = valorEncontrado->GetDerecho();
			else
			{
				if (padreEncontrado->toInt() > valorEncontrado->toInt())
				{
					padreEncontrado->SetIzquierdo(valorEncontrado->GetDerecho());
				}
				else if (padreEncontrado->toInt() < valorEncontrado->toInt())
				{
					padreEncontrado->SetDerecho(valorEncontrado->GetDerecho());
				}
			}
		}
		else
		{
			NodoArbol* masIzquierdo = valorEncontrado->GetDerecho()->GetIzquierdo();
			NodoArbol* masIzquierdoPadre = valorEncontrado->GetDerecho();

			while (masIzquierdo->GetIzquierdo() != nullptr) {
				masIzquierdoPadre = masIzquierdo;
				masIzquierdo = masIzquierdo->GetIzquierdo();
			}
			if (Raiz == valorEncontrado) {
				Raiz = masIzquierdo;
			}
			if (masIzquierdo->GetDerecho() != nullptr) {
				masIzquierdoPadre->SetIzquierdo(masIzquierdo->GetDerecho());
				masIzquierdo->GetDerecho()->SetPadre(masIzquierdoPadre);

				if (padreEncontrado->toInt() < valorEncontrado->toInt()) {
					valorEncontrado->GetDerecho()->SetPadre(masIzquierdo);
					valorEncontrado->GetIzquierdo()->SetPadre(masIzquierdo);
					masIzquierdo->SetDerecho(valorEncontrado->GetDerecho());
					masIzquierdo->SetIzquierdo(valorEncontrado->GetIzquierdo());
					masIzquierdo->SetPadre(padreEncontrado);
					padreEncontrado->SetDerecho(masIzquierdo);

					delete valorEncontrado;

				}
				else {
					valorEncontrado->GetDerecho()->SetPadre(masIzquierdo);
					valorEncontrado->GetIzquierdo()->SetPadre(masIzquierdo);
					masIzquierdo->SetDerecho(valorEncontrado->GetDerecho());
					masIzquierdo->SetIzquierdo(valorEncontrado->GetIzquierdo());
					masIzquierdo->SetPadre(padreEncontrado);
					padreEncontrado->SetIzquierdo(masIzquierdo);

					delete valorEncontrado;

				}
			}
			else{
				if (padreEncontrado->toInt() < valorEncontrado->toInt()) {
					valorEncontrado->GetDerecho()->SetPadre(masIzquierdo);
					valorEncontrado->GetIzquierdo()->SetPadre(masIzquierdo);
					masIzquierdo->SetDerecho(valorEncontrado->GetDerecho());
					masIzquierdo->SetIzquierdo(valorEncontrado->GetIzquierdo());
					masIzquierdo->SetPadre(padreEncontrado);
					padreEncontrado->SetDerecho(masIzquierdo);
					masIzquierdoPadre->SetIzquierdo(nullptr);

					delete valorEncontrado;
				}
				else {
					valorEncontrado->GetDerecho()->SetPadre(masIzquierdo);
					valorEncontrado->GetIzquierdo()->SetPadre(masIzquierdo);
					masIzquierdo->SetDerecho(valorEncontrado->GetDerecho());
					masIzquierdo->SetIzquierdo(valorEncontrado->GetIzquierdo());
					masIzquierdo->SetPadre(padreEncontrado);
					padreEncontrado->SetIzquierdo(masIzquierdo);
					masIzquierdoPadre->SetIzquierdo(nullptr);
					delete valorEncontrado;

				}
			}

			masIzquierdo->GetDerecho();
			padreEncontrado->GetDerecho();
			masIzquierdoPadre->GetDerecho();
		}


	}


	void Agregar(string valor) {
		if (Count == 0) {
			NodoArbol* nuevo = new NodoArbol(valor);
			Raiz = nuevo;

		}
		else {

			Insertar(Raiz, valor);

		}
		Count++;

	}

	NodoArbol* Buscar(string valor)
	{
		return Encontrar(Raiz, valor);
	}

	int obteneraltura(NodoArbol* _raiz) {
		if (_raiz == NULL) {

			return 0;
		}


		int alturaiz = obteneraltura(_raiz->GetIzquierdo());
		int alturader = obteneraltura(_raiz->GetDerecho());
		if (alturaiz > alturader) {

			return alturaiz + 1;
		}
		else {
			return alturader + 1;
		}
	}

	void alturaRec() {
		if (Raiz == nullptr) {
			cout << 0;
		}
		else {
			int altura = obteneraltura(Raiz);
			cout << altura;
		}
	}

	int	Inorder(NodoArbol* Nodo) {
		if (Nodo == nullptr) {
			return 0;
		}
		else {
			
			Inorder(Nodo->GetIzquierdo());
			cout << Nodo->GetValor() << endl;
		    Inorder(Nodo->GetDerecho());
			
		}

	}

	void Print() {
		Inorder(Raiz);
	}









};

	



