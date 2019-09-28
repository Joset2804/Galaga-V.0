#pragma once
#include "Elementos.h"
#include "iostream"
#include "Bala.h"
#include "ListaBalas.h"

class Enemigos :public Elementos
{
public:
	Enemigos();
	Enemigos(int x, int y, int dx, int dy, int tipo);
	~Enemigos();
	void SetImagen(char* nivel);
	void Mostrar(Graphics^ g);
	//Disparo
	void SetDX_DY(Graphics^ g);
	void Mover(Graphics^g, int nivel);
	void SetX_Original(int nuevo) { x_original = nuevo; }
	void SetY_Original(int nuevo) { y_original = nuevo; }
	int GetX_Original() { return x_original; }
	int GetY_Original() { return y_original; }
	ListaBalas* GetListaBalas();
private:
	int tipo;
	char* imagen;
	//BALAS
	ListaBalas* objListaBalas;
	int x_original;
	int y_original;
};

inline Enemigos::Enemigos()
{
	imagen = new char[250];
	índiceW = índiceH = w = h = tipo = 0;
	objListaBalas = new ListaBalas();
}

inline Enemigos::Enemigos(int x, int y, int dx, int dy, int tipo) :Elementos(x, y, dx, dy)
{
	imagen = new char[250];
	índiceW = índiceH = w = h = 0;
	this->tipo = tipo;
	this->x = 100;
	this->y = 100;
	this->dx = 0;
	this->dy = 0;
	objListaBalas = new ListaBalas();
}

inline Enemigos::~Enemigos() { delete imagen; delete objListaBalas; }

inline void Enemigos::SetImagen(char* nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	w = bmp->Width;
	h = bmp->Height;
	delete bmp;
}

inline ListaBalas* Enemigos::GetListaBalas() { if (objListaBalas != NULL) { return objListaBalas; } }
inline void Enemigos::Mostrar(Graphics^ g)
{
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	Rectangle porción = Rectangle(índiceW * w, índiceH * h, w, h);
	Rectangle zoom = Rectangle(x, y, 45, 45);
	bmp->MakeTransparent(bmp->GetPixel(1, 1));
	g->DrawImage(bmp, zoom, porción, GraphicsUnit::Pixel);
}

inline void Enemigos::SetDX_DY(Graphics^ g) //PRIMER LAMBDA
{
	auto Eliminar = [&](bool condición) {if (condición) { x = GetX_Original(); y = GetY_Original(); }};
	Eliminar((y + dy) < 0);
	Eliminar((y + dy + h) > g->VisibleClipBounds.Height);
}

inline void Enemigos::Mover(Graphics^g, int nivel)
{
	SetDX_DY(g);
	y = y + dy;
}