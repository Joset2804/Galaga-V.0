#pragma once
#include "Asteroide.h"

class NodoAsteroide
{
public:
	NodoAsteroide(Asteroide* elemento);
	~NodoAsteroide();
	NodoAsteroide* GetSiguiente();
	void SetSiguiente(NodoAsteroide* siguiente);
	Asteroide* GetAsteroide();
	void Mostrar(Graphics^ g);
public:
	NodoAsteroide* siguiente;
	Asteroide* asteroide;
};

inline NodoAsteroide::NodoAsteroide(Asteroide* nuevo)
{
	asteroide = nuevo;
	siguiente = NULL;
}

inline NodoAsteroide::~NodoAsteroide() {}
inline NodoAsteroide* NodoAsteroide::GetSiguiente() { return siguiente; }
inline void NodoAsteroide::SetSiguiente(NodoAsteroide* siguiente) { this->siguiente = siguiente; }
inline Asteroide* NodoAsteroide::GetAsteroide() { return asteroide; }
inline void NodoAsteroide::Mostrar(Graphics^ g) { asteroide->Mover(g); }