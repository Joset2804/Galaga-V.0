#pragma once
#include "Elementos.h"
#include "iostream"

class Asteroide :public Elementos
{
public:
	Asteroide(int x, int y, int dx, int dy);
	~Asteroide();
	void Mostrar(Graphics^ g);
	void SetImagen(char* nuevo);
	void Mover(Graphics^ g);
public:
	char* imagen;
	int tipo;
};

inline Asteroide::Asteroide(int x, int y, int dx, int dy) :Elementos(x, y, dx, dy)
{
	imagen = new char[250];
	índiceW = índiceH = w = h = tipo = 0;
}

inline Asteroide::~Asteroide() { delete imagen; }

inline void Asteroide::SetImagen(char* nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	w = bmp->Width;
	h = bmp->Height;
	delete bmp;
}

inline void Asteroide::Mostrar(Graphics^ g)
{
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	Rectangle porción = Rectangle(índiceW * w, índiceH * h, w, h);
	Rectangle zoom = Rectangle(x, y, 100, 100);
	bmp->MakeTransparent(bmp->GetPixel(1, 1));
	g->DrawImage(bmp, zoom, porción, GraphicsUnit::Pixel);
}

inline void Asteroide::Mover(Graphics^ g)
{
	/*índiceW++;
	if (índiceW > 7)
	{
		índiceW = 0;
		índiceH++;
	}
	if (índiceH > 7)
	{
		índiceH = 0;
	}*/
	Mostrar(g);
}