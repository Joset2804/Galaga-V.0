#pragma once
#include "NodoEnemigo.h"

class ListaEnemigos
{
public:
	ListaEnemigos();
	~ListaEnemigos();
	int GetN();
	Enemigos* GetEnemigos(int índice);
	void Disparar();
	void AñadirEnemigo(Graphics^ g, int x, int y, int dx, int dy, int nivel);
	void AñadirEnemigos(Graphics^ g, int nivel, int cantidad);
	void EliminarEnemigos();
	void MoverEnemigos(Graphics^ g, int nivel);
private:
	NodoEnemigo* primero;
	NodoEnemigo* último;
	int N;
};

inline ListaEnemigos::ListaEnemigos()
{
	N = 0;
	primero = NULL;
	último = NULL;
}

inline ListaEnemigos::~ListaEnemigos() {}

inline int ListaEnemigos::GetN() { return N; }

inline Enemigos* ListaEnemigos::GetEnemigos(int índice) 
{ 
	int contador_lista = 1;
	NodoEnemigo* actual = primero;
	NodoEnemigo* anterior = NULL;
	Enemigos* enemigo_retornar = new Enemigos();
	bool encontrado = false;
	if (primero != NULL)
	{
		while ((actual != NULL) && (encontrado != true))
		{
			if (contador_lista == índice + 1)
			{
				enemigo_retornar = actual->GetEnemigo();
				encontrado = true;
				return enemigo_retornar;
			}
			//Se pasa al siguiente nodo de la lista y se aumenta el contador
			anterior = actual;
			actual = actual->siguiente;
			contador_lista++;
		}
	}
	return enemigo_retornar;
}

inline void ListaEnemigos::Disparar()
{
	NodoEnemigo* actual = primero;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			actual->objEnemigo->GetListaBalas()->Disparar(actual->objEnemigo->GetX(), actual->objEnemigo->GetY(), 
				actual->objEnemigo->GetÍndiceW(), actual->objEnemigo->GetÍndiceH(), actual->objEnemigo->GetW(), actual->objEnemigo->GetH());
			actual = actual->siguiente;
		}
	}
}

inline void ListaEnemigos::AñadirEnemigo(Graphics^g, int x, int y, int dx, int dy, int nivel)
{
	//Crear Enemigo a partir de los parámetros
	Enemigos* objEnemigo = new Enemigos(x, y, dx, dy, 2);
	objEnemigo->SetImagen("SpritesEnemigos.png");
	objEnemigo->SetVida(1);
	objEnemigo->SetVidaOriginal(1);
	//AGREGANDO ENEMIGO A UN NODO
	NodoEnemigo* nodo = new NodoEnemigo(objEnemigo);
	//AGREGANDO EL NODO A LA LISTA
	if (primero == NULL)
	{
		primero = nodo;
		primero->siguiente = NULL;
		último = nodo;
	}
	else
	{
		último->siguiente = nodo;
		nodo->siguiente = NULL;
		último = nodo;
	}
	N++;
}

inline void ListaEnemigos::AñadirEnemigos(Graphics^ g, int nivel, int cantidad)
{
	auto añadir_enemigo = [&](Graphics^ g, int cant, int nivel)
	{
		for (int i = 0; i < cant; i++)
		{
			AñadirEnemigo(g, 0, 0, 0, 0, nivel);
		}
	};
	añadir_enemigo(g, cantidad, nivel);
	//for (int i = 0; i < cantidad; i++)
	//{
	//	AñadirEnemigo(g, 0, 0, 0, 0, nivel);
	//}
	int x, y, dx, dy;
	dx = dy = 0;
	x = y = 50;
	//Se modifica los datos de los enemigos
	NodoEnemigo* actual = primero;
	if (primero != NULL)
	{
		int cont = 0;
		while (actual != NULL)
		{
			if (x >= g->VisibleClipBounds.Width - 50)
			{
				y += 50;
				x = 50;
			}
			if (cont > 2 && (x <= g->VisibleClipBounds.Width - 300))
			{
				x += 250;
				cont = 0;
			}
			actual->GetEnemigo()->SetX(x);
			actual->GetEnemigo()->SetY(y);
			actual->GetEnemigo()->SetX_Original(x);
			actual->GetEnemigo()->SetY_Original(y);
			actual->GetEnemigo()->SetDX(0);
			actual->GetEnemigo()->SetDY(15);
			actual = actual->siguiente;
			x += 50;
			cont++;
		}
	}
}

inline void ListaEnemigos::EliminarEnemigos()
{
	NodoEnemigo* actual = primero;
	NodoEnemigo* anterior = NULL;
	if (primero != NULL && N > 0)
	{
		while (actual != NULL)
		{
			if (actual->objEnemigo->GetEliminar() == true)
			{
				if (actual == primero)
				{
					primero = primero->siguiente; //Se elimina el primero
				}
				else
				{
					if (actual == último) //Se elimina el último
					{
						anterior->siguiente = NULL;
						último = anterior;
					}
					else
					{
						anterior->siguiente = actual->siguiente; //Saltar el nodo a eliminar
					}
				}
				N--; //Se disminuye la cantidad, porque se está eliminando un enemigo
			}
			//Se pasa al siguiente nodo de la lista
			anterior = actual;
			actual = actual->siguiente;
		}
	}
}

inline void ListaEnemigos::MoverEnemigos(Graphics^ g, int nivel)
{
	EliminarEnemigos();
	NodoEnemigo* actual = primero;
	if (primero != NULL)
	{
		while (actual != NULL)
		{
			actual->objEnemigo->Mover(g, nivel);
			actual->objEnemigo->GetListaBalas()->MoverBalas(g, 2);
			actual = actual->siguiente;
		}
	}
}