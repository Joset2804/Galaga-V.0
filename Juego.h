#pragma once
#include "Jugador.h"
#include "ColaAsteroides.h"
#include "ListaEnemigos.h"
#include "PilaVida.h"

template <class T>
class Juego
{
private:
	Jugador* objJugador;
	ListaEnemigos* objListaEnemigos;
	ColaAsteroides* objColaAsteroides;
	PilaVida* objPilaVida;
	int nivel;
	int número_enemigosG;
	int puntaje;
public:
	Juego();
	~Juego();
	void CrearTanqueJugador(Graphics^ g);
	void DispararJugador();
	int GetVidaJugador();

	//Vidas (Corazones)
	void AgregarVidas(Graphics^ g);
	void AgregarVidasIniciales(Graphics^ g, int cantidad);
	void EliminarVida(Graphics^ g);
	void MostrarVidas(Graphics^ g);
	//Asteroides
	void AgregarAsteroide(Graphics^ g);
	void EliminarAsteroide(Graphics^ g);
	void MostrarAsteroide(Graphics^ g);
	//Enemigos grandes
	void DispararEnemigos();
	void AñadirEnemigos(Graphics^ g);
	// --------------------------
	void SetDX_DY(Dirección teclapulsada);

	//Colisión de Jugador a ENEMIGOS GRANDES
	bool ColisiónEGrandes(Bala* objBala, Enemigos* objEnemigos);
	void VerificarColisiónConEGrandes(Graphics^ g);

	//Colisión de Jugador a ASTEROIDES
	bool ColisiónAsteroides(Bala* objBala, Asteroide* objAsteroide);
	void VerificarColisiónConAsteroides();

	//Colisión de Enemigos Grandes a Jugador
	bool ColisiónGrandeAJugador(Bala* objBala, Jugador* objJugador);
	void VerificarColisiónDeGrandeConJugador();

	//--------------------------------------------
	void MoverTodos(Graphics^ g, Dirección teclapulsada);
	void MoverEnemigosJ(Graphics^ g);
	void CambioNivel(Graphics^ g); //NIVELES
	int GetNivel();
	int GetPuntaje();
	Jugador* GetJugador();
	void SetNivel(int nuevo);
	void SetPuntaje(int nuevo);
	void SetVidas(int vidas);
};

template <class T>
inline Juego<T>::Juego<T>()
{
	objJugador = NULL;
	objListaEnemigos = new ListaEnemigos();
	objColaAsteroides = new ColaAsteroides();
	objPilaVida = new PilaVida();
	nivel = 1;
	número_enemigosG = 0;
	puntaje = 0;
}

template <class T>
inline Juego<T>::~Juego<T>()
{
	delete objJugador;
	delete objColaAsteroides;
	delete objPilaVida;
	delete objListaEnemigos;
}

template <class T>
inline void Juego<T>::CrearTanqueJugador(Graphics^ g)
{
	if (objJugador == NULL)
	{
		objJugador = new Jugador(0, 0, 0, 0, 1);
		objJugador->SetImagen("SpritesJugador.png");
		objJugador->SetVida(10);
		objJugador->SetVidaOriginal(10);
		objJugador->SetX(g->VisibleClipBounds.Width / 2);
		objJugador->SetY(g->VisibleClipBounds.Height / 2);
	}
}

template <class T>
inline void Juego<T>::DispararJugador()
{
	objJugador->Disparar(objJugador->GetX(), objJugador->GetY(), objJugador->GetÍndiceW(), objJugador->GetÍndiceH(), objJugador->GetW(), objJugador->GetH());
}
template <class T> inline int Juego<T>::GetVidaJugador() { return objJugador->GetVida(); }

//DISPARO Y CREACIÓN DE ENEMIGOS GRANDES
template <class T> inline void Juego<T>::DispararEnemigos() { objListaEnemigos->Disparar(); }
template <class T> inline void Juego<T>::AñadirEnemigos(Graphics^ g)
{
	número_enemigosG = 6 * nivel;
	objListaEnemigos->AñadirEnemigos(g, nivel, número_enemigosG);
}

//OTROS
template <class T> inline void Juego<T>::SetDX_DY(Dirección teclapulsada) { objJugador->SetDX_DY(teclapulsada); }
//Colisión de Jugador a ENEMIGOS GRANDES

template <class T> inline bool Juego<T>::ColisiónEGrandes(Bala* objBala, Enemigos* objEnemigos)
{
	Rectangle rectBala = Rectangle(objBala->GetX(), objBala->GetY(), objBala->GetW(), objBala->GetH());
	Rectangle rectEnemigos = Rectangle(objEnemigos->GetX(), objEnemigos->GetY(), objEnemigos->GetW(), objEnemigos->GetH());
	return rectBala.IntersectsWith(rectEnemigos);
}

template <class T> inline void Juego<T>::VerificarColisiónConEGrandes(Graphics^ g)
{
	for (int i = 0; i < objListaEnemigos->GetN(); i++) //Recorrer todos los enemigos
	{
		for (int j = 0; j < objJugador->GetNBalas(); j++) //Recorrer todas las balas
		{
			if ((objJugador->GetBala(j)->GetEliminar() == false) && (objListaEnemigos->GetEnemigos(i)->GetEliminar() == false))
			{
				if (ColisiónEGrandes(objJugador->GetBala(j), objListaEnemigos->GetEnemigos(i)))
				{
					objJugador->GetBala(j)->SetEliminar(true);
					objListaEnemigos->GetEnemigos(i)->SetVida(objListaEnemigos->GetEnemigos(i)->GetVida() - 1);
					if (objListaEnemigos->GetEnemigos(i)->GetVida() == 0)
					{
						objListaEnemigos->GetEnemigos(i)->SetEliminar(true);
						puntaje = puntaje + 50;
						if (puntaje % 500 == 0)
						{
							objJugador->SetVida(objJugador->GetVida() + 1);
							AgregarVidas(g);
						}
						número_enemigosG--;
					}
				}
			}
		}
	}
}

//Colisión de Enemigos Grandes a Jugador
template <class T> inline bool Juego<T>::ColisiónGrandeAJugador(Bala* objBala, Jugador* objJugador)
{
	Rectangle rectBala = Rectangle(objBala->GetX(), objBala->GetY(), objBala->GetW(), objBala->GetH());
	Rectangle rectJugador = Rectangle(objJugador->GetX(), objJugador->GetY(), objJugador->GetW(), objJugador->GetH());
	return rectBala.IntersectsWith(rectJugador);
}

template <class T> inline void Juego<T>::VerificarColisiónDeGrandeConJugador()
{
	//Es solo un jugador - Son muchos enemigos grandes con muchas balas
	for (int j = 0; j < objListaEnemigos->GetN(); j++) //Recorrer todos los enemigos grandes
	{
		for (int i = 0; i < objListaEnemigos->GetEnemigos(j)->GetListaBalas()->GetNBalas(); i++) //Recorrer todas las balas de cada enemigo grande
		{
			if ((objListaEnemigos->GetEnemigos(j)->GetEliminar() == false) && (objListaEnemigos->GetEnemigos(j)->GetListaBalas()->GetBala(i)->GetEliminar() == false))
			{
				if (ColisiónGrandeAJugador(objListaEnemigos->GetEnemigos(j)->GetListaBalas()->GetBala(i), objJugador))
				{
					objListaEnemigos->GetEnemigos(j)->GetListaBalas()->GetBala(i)->SetEliminar(true);
					objJugador->SetVida(objJugador->GetVida() - 1);
					objPilaVida->Pop();
				}
			}
		}
	}
}

//Colisión de Jugador a ASTEROIDES

template <class T> inline bool Juego<T>::ColisiónAsteroides(Bala* objBala, Asteroide* objAsteroide)
{
	Rectangle rectBala = Rectangle(objBala->GetX(), objBala->GetY(), objBala->GetW(), objBala->GetH());
	Rectangle rectAsteroide = Rectangle(objAsteroide->GetX(), objAsteroide->GetY(), 100, 100);
	return rectBala.IntersectsWith(rectAsteroide);
}

template <class T> inline void Juego<T>::VerificarColisiónConAsteroides()
{
	for (int i = 0; i < objColaAsteroides->GetN(); i++) //Recorrer todos los asteroides
	{
		for (int j = 0; j < objJugador->GetNBalas(); j++) //Recorrer todas las balas
		{
			if ((objJugador->GetBala(j)->GetEliminar() == false) && (objColaAsteroides->GetAsteroide(i)->GetEliminar() == false))
			{
				if (ColisiónAsteroides(objJugador->GetBala(j), objColaAsteroides->GetAsteroide(i)))
				{
					objJugador->GetBala(j)->SetEliminar(true);
				}
			}
		}
	}
}
// ----------------------------------------------------

template <class T> inline void Juego<T>::MoverTodos(Graphics^ g, Dirección teclapulsada)
{
	objJugador->Mover(g, teclapulsada, nivel);
	objJugador->MoverBalas(g);
	objListaEnemigos->MostrarEnemigos(g, nivel);
	objListaEnemigos->DisparoEnemigos(g, nivel);
	MostrarAsteroide(g);
	MostrarVidas(g);
	VerificarColisiónConEGrandes(g);
	VerificarColisiónDeGrandeConJugador();
	VerificarColisiónConAsteroides();
}

template <class T> inline void Juego<T>::MoverEnemigosJ(Graphics^ g)
{
	objListaEnemigos->MoverEnemigos(g, nivel);
}

template <class T> inline void Juego<T>::CambioNivel(Graphics^ g)
{
	if (objListaEnemigos->GetN() <= 0)
	{
		nivel++;
		AñadirEnemigos(g);
	}
}
template <class T> inline int Juego<T>::GetNivel() { return nivel; }
template <class T> inline int Juego<T>::GetPuntaje() { return puntaje; }

//Asteroides
template <class T> inline void Juego<T>::AgregarAsteroide(Graphics^ g)
{
	Random^ r = gcnew Random();
	Asteroide* nuevo = new Asteroide(r->Next(1, g->VisibleClipBounds.Width), r->Next(g->VisibleClipBounds.Height / 2, g->VisibleClipBounds.Height), 0, 0);
	nuevo->SetImagen("SpriteAsteroide.png");
	objColaAsteroides->Agregar(nuevo);
}
template <class T> inline void Juego<T>::MostrarAsteroide(Graphics^ g) { objColaAsteroides->MostrarElementos(g); }
template <class T> inline void Juego<T>::EliminarAsteroide(Graphics^ g) { objColaAsteroides->EliminarElemento(); }

//Vidas (Corazones)
template <class T> inline void Juego<T>::AgregarVidas(Graphics^ g)
{
	Vida* nuevo = new Vida(0, g->VisibleClipBounds.Height - 30, 0, 0);
	nuevo->SetImagen("SpriteVida.png");
	objPilaVida->Push(nuevo);
}

template <class T> inline void Juego<T>::AgregarVidasIniciales(Graphics^ g, int cantidad) 
{ 
	for (int i = 0; i < cantidad; i++) 
	{ 
		AgregarVidas(g); 
	} 
}

template <class T> inline void Juego<T>::MostrarVidas(Graphics^ g) { objPilaVida->MostrarElementos(g); }
template <class T> inline void Juego<T>::EliminarVida(Graphics^ g) { objPilaVida->Pop(); }
template <class T> inline Jugador* Juego<T>::GetJugador() { return objJugador; }
template <class T> inline void Juego<T>::SetNivel(int nuevo) { nivel = nuevo; }
template <class T> inline void Juego<T>::SetPuntaje(int nuevo) { puntaje = nuevo; }
template <class T> inline void Juego<T>::SetVidas(int vidas) { objJugador->SetVida(vidas); }