#pragma once
#include "Elementos.h"
#include "iostream"

class Vida :public Elementos
{
public:
	Vida(int x, int y, int dx, int dy);
	~Vida();
	void Mostrar(Graphics^ g);
	void SetImagen(char* nuevo);
public:
	char* imagen;
};

inline Vida::Vida(int x, int y, int dx, int dy) :Elementos(x, y, dx, dy)
{
	imagen = new char[250];
	índiceW = índiceH = w = h = 0;
}

inline Vida::~Vida() { delete imagen; }

inline void Vida::SetImagen(char* nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	w = bmp->Width;
	h = bmp->Height;
	delete bmp;
}

inline void Vida::Mostrar(Graphics^ g)
{
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	Rectangle porción = Rectangle(índiceW * w, índiceH * h, w, h);
	Rectangle zoom = Rectangle(x, y, 30, 30);
	bmp->MakeTransparent(bmp->GetPixel(1, 1));
	g->DrawImage(bmp, zoom, porción, GraphicsUnit::Pixel);
}