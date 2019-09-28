#pragma once
#include "NodoBala.h"

class ListaBalas
{
public:
	ListaBalas();
	~ListaBalas();
	void Disparar(int x, int y, int �ndiceW, int �ndiceH, int w, int h);
	int GetNBalas();
	Bala* GetBala(int �ndice);
	void MoverBalas(Graphics^ g, int tipo); //1: jugador | 2: enemigo
	void EliminarBalas();
private:
	NodoBala* primero;
	NodoBala* �ltimo;
	int N_balas;
};

inline ListaBalas::ListaBalas()
{
	primero = NULL;
	�ltimo = NULL;
	N_balas = 0;
}

inline ListaBalas::~ListaBalas() {}

inline int ListaBalas::GetNBalas() { return N_balas; }

inline Bala* ListaBalas::GetBala(int �ndice) 
{
	int contador_lista = 1;
	NodoBala* actual = primero;
	NodoBala* anterior = NULL;
	Bala* bala_retornar = new Bala();
	bool encontrado = false;
	if (primero != NULL)
	{
		while ((actual != NULL) && (encontrado != true))
		{
			if (contador_lista == �ndice + 1)
			{
				bala_retornar = actual->GetBala();
				encontrado = true;
			}
			//Se pasa al siguiente nodo de la lista y se aumenta el contador
			anterior = actual;
			actual = actual->siguiente;
			contador_lista++;
		}
	}
	return bala_retornar;
}
inline void ListaBalas::Disparar(int x, int y, int �ndiceW, int �ndiceH, int w, int h) //A�adir bala - LISTA
{
	int dxdy, r;
	r = 10;
	dxdy = 10;
	Bala* bala1 = new Bala(x + (w / 2), y + h, dxdy * 0, dxdy, r);
	//AGREGANDO BALA A UN NODO
	NodoBala* nodo = new NodoBala(bala1);
	//AGREGANDO EL NODO A LA LISTA
	if (primero == NULL)
	{
		primero = nodo;
		primero->siguiente = NULL;
		�ltimo = nodo;
	}
	else
	{
		�ltimo->siguiente = nodo;
		nodo->siguiente = NULL;
		�ltimo = nodo;
	}
	N_balas++;
}

inline void ListaBalas::EliminarBalas()
{
	NodoBala* actual = primero;
	NodoBala* anterior = NULL;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			if (actual->objBala->GetEliminar() == true)
			{
				if (actual == primero)
				{
					primero = primero->siguiente; //Se elimina el primero
				}
				else
				{
					if (actual == �ltimo) //Se elimina el �ltimo
					{
						anterior->siguiente = NULL;
						�ltimo = anterior;
					}
					else
					{
						anterior->siguiente = actual->siguiente; //Saltar el nodo a eliminar
					}
				}
				N_balas--; //Se disminuye la cantidad, porque se est� eliminando una bala
			}
			//Se pasa al siguiente nodo de la lista
			anterior = actual;
			actual = actual->siguiente;
		}
	}
}

inline void ListaBalas::MoverBalas(Graphics^ g, int tipo)
{
	if (N_balas > 0)
	{
		if (primero != NULL)
		{
			EliminarBalas();
			NodoBala* actual = new NodoBala();
			actual = primero;
			while (actual != NULL)
			{
				actual->objBala->SetColor(tipo);
				actual->objBala->Mover(g);
				actual = actual->siguiente;
			}
		}
	}
}