#pragma once
#include "NodoVida.h"

class PilaVida
{
public:
	PilaVida();
	~PilaVida();
	void Push(Vida* nuevo);
	void Pop();
	void MostrarElementos(Graphics^ g);

private:
	NodoVida* pila;
	int x;
	int cantidad;
};

inline PilaVida::PilaVida() { x = cantidad = 0; pila = NULL; }

inline PilaVida::~PilaVida() {}

inline void PilaVida::Push(Vida* nuevo)
{
	if (cantidad < 10)
	{
		nuevo->SetX(x);
		NodoVida* aux = new NodoVida(nuevo);
		aux->siguiente = pila;
		pila = aux;
		x += 33;
		cantidad++;
	}
}

inline void PilaVida::Pop()
{
	if (cantidad > 0)
	{
		NodoVida* aux = pila;
		pila = pila->siguiente;
		delete aux;
		x -= 33;
		cantidad--;
	}
}

inline void PilaVida::MostrarElementos(Graphics^ g)
{
	NodoVida* aux = pila;
	while (aux != NULL)
	{
		aux->Mostrar(g);
		aux = aux->siguiente;
	}
}