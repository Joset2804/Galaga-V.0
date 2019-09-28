#pragma once
#include "Vida.h"

class NodoVida
{
public:
	NodoVida(Vida* nuevo);
	~NodoVida();
	NodoVida* GetSiguiente();
	void SetSiguiente(NodoVida* siguiente);
	Vida* GetVida();
	void Mostrar(Graphics^ g);
public:
	NodoVida* siguiente;
	Vida* vida;
};

inline NodoVida::NodoVida(Vida* nuevo)
{
	vida = nuevo;
	siguiente = NULL;
}

inline NodoVida::~NodoVida() {}
inline NodoVida* NodoVida::GetSiguiente() { return siguiente; }
inline void NodoVida::SetSiguiente(NodoVida* siguiente) { this->siguiente = siguiente; }
inline Vida* NodoVida::GetVida() { return vida; }
inline void NodoVida::Mostrar(Graphics^ g) { vida->Mostrar(g); }