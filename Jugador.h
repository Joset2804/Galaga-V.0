#pragma once
#include "Elementos.h"
#include "iostream"
#include "Bala.h"

class Jugador :public Elementos
{
public:
	Jugador();
	Jugador(int x, int y, int dx, int dy, int tipo);
	~Jugador();
	void SetImagen(char* nivel);
	void Mostrar(Graphics^ g);
	//Disparo
	Bala* GetBala(int índice);
	void Disparar(int x, int y, int índiceW, int índiceH, int w, int h); //Añadir bala
	void EliminarBalas();
	void MoverBalas(Graphics^ g);
	int GetNBalas();
	void SetDX_DY(Dirección tecla);
	void Mover(Graphics^g, Dirección teclapulsada, int nivel);

private:
	int tipo;
	char* imagen;
	//BALAS
	Bala** arreglo_balas;
	int N_balas;
};

inline Jugador::Jugador()
{
	imagen = new char[250];
	índiceW = índiceH = w = h = tipo = 0;
	N_balas = 0;
	arreglo_balas = new Bala*[N_balas];
}

inline Jugador::Jugador(int x, int y, int dx, int dy, int tipo) :Elementos(x, y, dx, dy)
{
	imagen = new char[250];
	índiceW = índiceH = w = h = 0;
	N_balas = 0;
	arreglo_balas = new Bala*[N_balas];
	this->tipo = tipo;
	this->x = 100;
	this->y = 100;
}

inline Jugador::~Jugador()
{
	delete imagen;
	delete[] arreglo_balas;
}

inline void Jugador::SetImagen(char* nuevo)
{
	strcpy(imagen, nuevo);
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	w = bmp->Width / 3; //Son 3 columnas
	h = bmp->Height / 4; //Son 4 filas
	delete bmp;
}

inline int Jugador::GetNBalas() { return N_balas; }
inline Bala* Jugador::GetBala(int índice) { return arreglo_balas[índice]; }

inline void Jugador::Disparar(int x, int y, int índiceW, int índiceH, int w, int h) //Añadir bala
{
	int dxdy, r;
	r = 10;
	dxdy = 10;
	//Hacia izquierda = x, y + (h / 2)//Hacia derecha = x + w, y + (h / 2)//Hacia abajo = x + (w / 2), y + h//Hacia arriba = x + (w / 2), y
	Bala* bala1 = new Bala(x + (w / 2), y, dxdy * 0, dxdy * -1, r);
	//AGREGANDO BALA
	Bala** aux = new Bala*[N_balas + 1];
	for (int i = 0; i < N_balas; i++)
	{
		aux[i] = arreglo_balas[i];
	}
	aux[N_balas] = bala1;
	N_balas = N_balas + 1;
	delete[] arreglo_balas;
	arreglo_balas = aux;
}

inline void Jugador::EliminarBalas()
{
	int cantidad = 0;
	for (int i = 0; i < N_balas; i++)
	{
		if (arreglo_balas[i]->GetEliminar())
		{
			cantidad++;
		}
	}
	Bala** aux = new Bala*[N_balas - cantidad];
	int h = 0;
	for (int i = 0; i < N_balas; i++)
	{
		if (!arreglo_balas[i]->GetEliminar())
		{
			aux[h] = arreglo_balas[i];
			h++;
		}
	}
	N_balas = N_balas - cantidad;
	delete[] arreglo_balas;
	arreglo_balas = aux;
}

inline void Jugador::MoverBalas(Graphics^ g)
{
	//Cambio de color
	if (tipo == 1)
	{
		for (int i = 0; i < N_balas; i++)
		{
			arreglo_balas[i]->SetColor(1);
		}
	}
	for (int i = 0; i < N_balas; i++)
	{
		arreglo_balas[i]->Mover(g);
	}
	EliminarBalas();
}

inline void Jugador::Mostrar(Graphics^ g)
{
	Bitmap^ bmp = gcnew Bitmap(gcnew String(imagen));
	Rectangle porción = Rectangle(índiceW * w, índiceH * h, w, h);
	Rectangle zoom = Rectangle(x, y, w, h);
	bmp->MakeTransparent(bmp->GetPixel(1, 1));
	g->DrawImage(bmp, zoom, porción, GraphicsUnit::Pixel);
}

inline void Jugador::SetDX_DY(Dirección tecla)
{
	switch (tecla)
	{
	case arriba: {dx = 0; dy = -50; break; }
	case abajo: {dx = 0; dy = 50; break; }
	case izquierda: {dx = -50; dy = 0; break; }
	case derecha: {dx = 50; dy = 0; break; }
	case ninguno: {dx = 0; dy = 0; break; }
	}
}

inline void Jugador::Mover(Graphics^g, Dirección teclapulsada, int nivel)
{
	índiceW++;
	if (índiceW >= 3) { índiceW = 0; }
	if (((x + dx) < 0) || ((x + dx + w) > g->VisibleClipBounds.Width)) { dx = 0; }
	if (((y + dy) < g->VisibleClipBounds.Height / 2) || ((y + dy + h) > g->VisibleClipBounds.Height)) { dy = 0; }
	x = x + dx;
	y = y + dy;
	Mostrar(g);
	dx = dy = 0;
}