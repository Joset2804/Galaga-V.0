#pragma once
#include "Enemigos.h"

class NodoEnemigo
{
public:
	NodoEnemigo(Enemigos* nuevo);
	~NodoEnemigo();
	Enemigos* GetEnemigo();
public:
	Enemigos* objEnemigo;
	NodoEnemigo* siguiente;
};

inline NodoEnemigo::NodoEnemigo(Enemigos* nuevo)
{
	objEnemigo = nuevo;
	siguiente = NULL;
}

inline NodoEnemigo::~NodoEnemigo() {}
inline Enemigos* NodoEnemigo::GetEnemigo() { return objEnemigo; }