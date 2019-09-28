#pragma once
#include "Bala.h"
#include "iostream"

class NodoBala
{
public:
	NodoBala(Bala* nuevo);
	NodoBala();
	~NodoBala();
	Bala* GetBala();
public:
	Bala* objBala;
	NodoBala* siguiente;
};

inline NodoBala::NodoBala(Bala* nuevo)
{
	objBala = nuevo;
	siguiente = NULL;
}
inline NodoBala::NodoBala()
{
	objBala = new Bala();
	siguiente = NULL;
}
inline NodoBala::~NodoBala() {}
inline Bala* NodoBala::GetBala() { return objBala; }