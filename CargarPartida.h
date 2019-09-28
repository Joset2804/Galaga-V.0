#pragma once
#pragma once
#include "fstream"
#include "iostream"
#include "conio.h"
#include "string"

class CargarPartida
{
public:
	CargarPartida();
	~CargarPartida();

	void EscribirDatosPartida(int x_, int y_, int nivel_, int vidas_, int puntaje_, std::string nombre_);
	void LeerDatosPartida();
	int GetX();
	int GetY();
	int GetNivel();
	int GetVidas();
	int GetPuntaje();
	std::string GetNombre();

private:
	std::ifstream archivo_datos_partida_lectura; //Leer datos partida ***
	std::ofstream archivo_datos_partida_escritura; //Escribir datos partida ***
	std::string información_datos_partida; //Información a leer del archivo de datos partida ***
	int x;
	int y;
	int nivel;
	int vidas;
	int puntaje;
	std::string nombre;
};

inline CargarPartida::CargarPartida() {}
inline CargarPartida::~CargarPartida() {}

inline void CargarPartida::EscribirDatosPartida(int x_, int y_, int nivel_, int vidas_, int puntaje_, std::string nombre_) //GUARDAMOS LA INFORMACIÓN EN EL ARCHIVO * DATOS PARTIDA
{
	LeerDatosPartida();
	archivo_datos_partida_escritura.open("DatosPartida.txt", std::ios::out);
	if (archivo_datos_partida_escritura.is_open()) //Si el archivo está abierto
	{
		//Ingresamos datos al archivo
		archivo_datos_partida_escritura << x_ << std::endl << y_ << std::endl << nivel_ << std::endl << vidas_ << std::endl << puntaje_ << std::endl << nombre_;
		//Cerramos el archivo
		archivo_datos_partida_escritura.close();
	}
}

inline void CargarPartida::LeerDatosPartida() //PEDIMOS LA INFORMACIÓN AL ARCHIVO * DATOS PARTIDA
{
	archivo_datos_partida_lectura.open("DatosPartida.txt", std::ios::app);
	if (archivo_datos_partida_lectura.is_open()) //Si el archivo está abierto
	{
		std::string aux;
		getline(archivo_datos_partida_lectura, aux); x = stoi(aux);
		std::string aux2;
		getline(archivo_datos_partida_lectura, aux2); y = stoi(aux2);
		std::string aux3;
		getline(archivo_datos_partida_lectura, aux3); nivel = stoi(aux3);
		std::string aux4;
		getline(archivo_datos_partida_lectura, aux4); vidas = stoi(aux4);
		std::string aux5;
		getline(archivo_datos_partida_lectura, aux5); puntaje = stoi(aux5);
		std::string aux6;
		getline(archivo_datos_partida_lectura, aux6); nombre = aux6;
		archivo_datos_partida_lectura.close();
	}
}

inline int CargarPartida::GetX() { return x; }
inline int CargarPartida::GetY() { return y; }
inline int CargarPartida::GetNivel() { return nivel; }
inline int CargarPartida::GetVidas() { return vidas; }
inline int CargarPartida::GetPuntaje() { return puntaje; }
inline std::string CargarPartida::GetNombre() { return nombre; }