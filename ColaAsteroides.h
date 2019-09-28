#pragma once
#include "NodoAsteroide.h"

class ColaAsteroides //Cola
{
public:
	ColaAsteroides();
	~ColaAsteroides();
	void Agregar(Asteroide* nuevo); //Agregar inicio
	void EliminarElemento();
	void MostrarElementos(Graphics^ g);
	int GetN();
	Asteroide* GetAsteroide(int índice);
	
private:
	NodoAsteroide* frente;
	NodoAsteroide* fin;
	int N;
};

inline ColaAsteroides::ColaAsteroides()
{
	frente = NULL;
	fin = NULL;
	N = 0;
}

inline ColaAsteroides::~ColaAsteroides() 
{
	NodoAsteroide* aux;
	while (frente != NULL) 
	{
		aux = frente;
		frente = frente->siguiente;
		delete aux;
		aux = NULL;
	}
	delete frente;
	frente = NULL;
}

inline int ColaAsteroides::GetN() { return N; }

inline Asteroide* ColaAsteroides::GetAsteroide(int índice)
{
	int contador_lista = 1;
	NodoAsteroide* actual = frente;
	NodoAsteroide* anterior = NULL;
	Asteroide* asteroide_retornar = NULL;
	bool encontrado = false;
	if (frente != NULL)
	{
		while ((actual != NULL) && (encontrado != true))
		{
			if (contador_lista == índice + 1)
			{
				asteroide_retornar = actual->GetAsteroide();
				encontrado = true;
			}
			//Se pasa al siguiente nodo de la lista y se aumenta el contador
			anterior = actual;
			actual = actual->siguiente;
			contador_lista++;
		}
	}
	return asteroide_retornar;
}
inline void ColaAsteroides::Agregar(Asteroide* nuevo)
{
	if (N < 7)
	{
		NodoAsteroide* aux = new NodoAsteroide(nuevo);
		aux->siguiente = NULL;
		if (frente == NULL) { frente = aux; } //SI ES QUE LA COLA ESTá VACÍA
		else { fin->siguiente = aux; }
		fin = aux;
		N++;
	}
}

inline void ColaAsteroides::EliminarElemento()
{
	if (frente != NULL)
	{
		NodoAsteroide* aux = frente;
		if (frente == fin)
		{
			frente = NULL;
			fin = NULL;
		}
		else
		{
			frente = frente->siguiente;
		}
		delete aux;
		//NodoAsteroide* aux_borrar;
		//NodoAsteroide* anterior = NULL;
		//aux_borrar = frente;
		//while ((aux_borrar != NULL)) //Recorre la lista
		//{
		//	anterior = aux_borrar;
		//	aux_borrar = aux_borrar->siguiente;
		//}
		//if (aux_borrar != NULL)
		//{
		//	if (anterior == NULL) //El primero se elimina
		//	{
		//		frente = frente->siguiente;
		//		delete aux_borrar;
		//	}
		//	else //No es el primero
		//	{
		//		anterior->siguiente = aux_borrar->siguiente;
		//		delete aux_borrar;
		//	}
		//}
		N--;
	}
}

inline void ColaAsteroides::MostrarElementos(Graphics^ g)
{
	NodoAsteroide* aux = frente;
	while (aux != NULL)
	{
		aux->Mostrar(g);
		aux = aux->siguiente;
	}
}