#pragma once
#include "iostream"
#include "string"
#include "conio.h"

class Puntaje
{
public:
	Puntaje();
	Puntaje(std::string nuevo_p, std::string nuevo_n);
	~Puntaje();
	void SetNombre(std::string nuevo);
	void SetPuntaje(std::string nuevo);
	void SetSiguiente(Puntaje* nuevo);
	std::string GetPuntaje();
	std::string GetNombre();
	Puntaje* GetSiguiente();
private:
	std::string nombre;
	std::string puntaje;
	Puntaje* siguiente;
};

inline Puntaje::Puntaje()
{
	nombre = "";
	puntaje = "";
	siguiente = NULL;
}

inline Puntaje::Puntaje(std::string nuevo_p, std::string nuevo_n)
{
	nombre = nuevo_p;
	puntaje = nuevo_n;
	siguiente = NULL;
}

inline Puntaje::~Puntaje() {}

inline void Puntaje::SetNombre(std::string nuevo) { nombre = nuevo; }
inline void Puntaje::SetPuntaje(std::string nuevo) { puntaje = nuevo; }
inline void Puntaje::SetSiguiente(Puntaje* nuevo) { siguiente = nuevo; }
inline std::string Puntaje::GetPuntaje() { return puntaje; }
inline std::string Puntaje::GetNombre() { return nombre; }
inline Puntaje* Puntaje::GetSiguiente() { return siguiente; }