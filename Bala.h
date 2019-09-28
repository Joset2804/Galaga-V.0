#pragma once
#include "Elementos.h"

class Bala :public Elementos
{
public:
	Bala();
	Bala(int x, int y, int dx, int dy, int r);
	~Bala();
	int GetW();
	int GetH();
	void Mostrar(Graphics^ g);
	void Mover(Graphics^ g);
	void SetColor(int color);
private:
	int r;
	int color; //1: celeste - 2: anaranjado
};

inline Bala::Bala()
{
	this->x = 0;
	this->y = 0;
	this->dx = 0;
	this->dy = 0;
	this->r = 10;
	this->color = 2;
}

inline Bala::Bala(int x, int y, int dx, int dy, int r) :Elementos(x, y, dx, dy)
{
	this->r = r;
	this->color = 2;
}
inline Bala::~Bala() {}
inline int Bala::GetW() { return r/2; }
inline int Bala::GetH() { return r; }
inline void Bala::Mostrar(Graphics^ g)
{
	Color colorM;
	if (color == 1) { colorM = Color::Black; } //Jugador
	else
	{
		if (color == 2) { colorM = Color::DarkRed; } //Enemigo
	}
	g->FillEllipse(gcnew SolidBrush(colorM), x - r / 3, y - r, r / 2, 2 * r);
	g->DrawEllipse(gcnew Pen(Color::White, 1), x - r / 3, y - r, r / 2, 2 * r);
}

inline void Bala::Mover(Graphics^ g)
{
	if ((y + dy < 0) || ((y + dy + (2 * r)) > g->VisibleClipBounds.Height) || (x + dx < 0) || ((x + dx + (2 * r)) > g->VisibleClipBounds.Width)) { eliminar = true; }
	x = x + dx;
	y = y + dy;
	Mostrar(g);
}
inline void Bala::SetColor(int color) { this->color = color; }