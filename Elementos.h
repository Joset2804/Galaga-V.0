#pragma once
enum Dirección { arriba, abajo, izquierda, derecha, ninguno };

using namespace System;
using namespace System::Drawing;

class Elementos
{
public:
	Elementos();
	Elementos(int x, int y, int dx, int dy);
	~Elementos();
	void SetX(int nuevo);
	void SetY(int nuevo);
	void SetEliminar(bool nuevo);
	bool GetEliminar();
	int GetX();
	int GetY();
	void SetDX(int dx);
	void SetDY(int dy);
	int GetDX();
	int GetDY();
	//VIDAS
	void SetVida(int nueva_vida);
	int GetVida();
	void SetVidaOriginal(int nueva_vida);
	int GetVidaOriginal();
	void SetW(int w);
	void SetH(int h);
	int GetW();
	int GetH();
	int GetÍndiceW();
	int GetÍndiceH();
protected:
	int x, y, dx, dy, índiceW, índiceH, w, h;
	bool eliminar;
	int vida;
	int vida_original;
};

inline Elementos::Elementos()
{
	x = y = dx = dy = índiceW = índiceH = w = 0;
	eliminar = false;
	vida = 0;
	vida_original = 0;
}

inline Elementos::Elementos(int x, int y, int dx, int dy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	eliminar = false;
	vida = 0;
	vida_original = 0;
}

inline Elementos::~Elementos() {}
inline void Elementos::SetX(int nuevo) { this->x = nuevo; }
inline void Elementos::SetY(int nuevo) { this->y = nuevo; }
inline int Elementos::GetX() { return x; }
inline int Elementos::GetY() { return y; }
inline int Elementos::GetDX() { return dx; }
inline int Elementos::GetDY() { return dy; }
inline void Elementos::SetDX(int dx) { this->dx = dx; }
inline void Elementos::SetDY(int dy) { this->dy = dy; }
inline void Elementos::SetEliminar(bool nuevo) { this->eliminar = nuevo; }
inline bool Elementos::GetEliminar() { return eliminar; }
//VIDAS
inline void Elementos::SetVida(int nueva_vida) { this->vida = nueva_vida; }
inline int Elementos::GetVida() { return vida; }
//VIDA ORIGINAL
inline void Elementos::SetVidaOriginal(int nueva_vida) { this->vida_original = nueva_vida; }
inline int Elementos::GetVidaOriginal() { return vida_original; }

inline void Elementos::SetW(int w) { this->w = w; }
inline void Elementos::SetH(int h) { this->h = h; }
inline int Elementos::GetW() { return w; }
inline int Elementos::GetH() { return h; }
inline int Elementos::GetÍndiceW() { return índiceW; }
inline int Elementos::GetÍndiceH() { return índiceH; }

/*
1. Hace uso de templates en cada estructura de datos usada --- NO SÉ xd
2. Hace uso de al menos 3 lambdas o funciones recursivas en cada estructura de datos usada. --- FALTA 1 creo
3. Implementa en su solución más de una estructura de datos tipo lista enlace simple o lista  --- ListaEnemigos y ListaBalas LISTO
4. Implementa en su solución más de una estructura de datos tipo pila o cola. --- 1 PILA (Vidas) y 1 COLA (Asteroides) - LISTO
5. Define el formato de archivo e implementa el uso de archivos planos para guardar y cargar partidas. --- LISTO
6. GitHub --- ???
*/