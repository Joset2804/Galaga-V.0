//#pragma once
//#include "fstream"
//#include "iostream"
//#include "conio.h"
//#include "string"
//#include "ColaPuntaje.h"
//
//class ClaseRanking
//{
//public:
//	ClaseRanking();
//	~ClaseRanking();
//
//	//MANEJO DE PUNTAJES
//	void EscribirPuntajeYJugador(int puntaje, std::string nombre_jugador);
//	void LeerPuntajesYJugadores();
//	std::string GetInformaciónJugadores();
//	std::string GetInformaciónPuntaje();
//	ColaPuntaje* GetColaPuntaje();
//private:
//	std::ifstream archivo_nombres_lectura; //Leer nombres
//	std::ifstream archivo_puntajes_lectura; //Leer puntajes
//	std::ofstream archivo_nombres_escritura; //Escribir nombres
//	std::ofstream archivo_puntajes_escritura; //Escribir puntajes
//	ColaPuntaje* objColaPuntaje;
//	bool lectura_hecha;
//};
//
//inline ClaseRanking::ClaseRanking() { objColaPuntaje = new ColaPuntaje(); lectura_hecha = false; }
//inline ClaseRanking::~ClaseRanking(){}
//
////MANEJO DE PUNTAJES
//
//inline ColaPuntaje* ClaseRanking::GetColaPuntaje() { return objColaPuntaje; }
//
//inline void ClaseRanking::EscribirPuntajeYJugador(int puntaje, std::string nombre_jugador)
//{
//	if (lectura_hecha == false) { LeerPuntajesYJugadores(); }
//	Puntaje* objPuntaje = new Puntaje(); //Guardar los puntajes en un objeto puntaje
//	objPuntaje->SetNombre(nombre_jugador);
//	objPuntaje->SetPuntaje(std::to_string(puntaje));
//	objColaPuntaje->Agregar(objPuntaje); //Agregar el puntaje a la cola
//
//	archivo_puntajes_escritura.open("TopPuntajes.txt", std::ios::out); //Se abren los archivos
//	archivo_nombres_escritura.open("TopJugadores.txt", std::ios::out); //Se abren los archivos
//
//	if (archivo_puntajes_escritura.is_open() && archivo_nombres_escritura.is_open()) //Si el archivo está abierto
//	{
//		ColaPuntaje* auxColaPuntaje = objColaPuntaje;
//		std::string puntaje_info; std::string nombre_info;
//		while (auxColaPuntaje->GetPrimero() != NULL)
//		{
//			Puntaje* aux = auxColaPuntaje->EliminarPuntajeRetorno();
//			puntaje_info = puntaje_info + "\n" + aux->GetPuntaje();
//			nombre_info = nombre_info + "\n" + aux->GetNombre();
//		}
//		archivo_puntajes_escritura << auxColaPuntaje->GetÚltimo()->GetPuntaje() << std::endl << puntaje_info;	//Ingresamos datos al archivo
//		archivo_nombres_escritura << auxColaPuntaje->GetÚltimo()->GetNombre() << std::endl << nombre_info; //Ingresamos datos al archivo
//		archivo_nombres_escritura.close(); //Cerramos el archivo
//		archivo_puntajes_escritura.close(); //Cerramos el archivo
//	}
//}
//
//inline void ClaseRanking::LeerPuntajesYJugadores() //LECTURA CON COLA
//{
//	archivo_puntajes_lectura.open("TopPuntajes.txt", std::ios::app);
//	archivo_nombres_lectura.open("TopJugadores.txt", std::ios::app);
//	if (archivo_puntajes_lectura.is_open() && archivo_nombres_lectura.is_open()) //Si el archivo está abierto
//	{
//		Puntaje* objPuntaje;
//		std::string aux_puntajes;
//		std::string aux_nombres;
//		getline(archivo_puntajes_lectura, aux_puntajes); //lectura adelantada de puntajes
//		getline(archivo_nombres_lectura, aux_nombres); //lectura adelantada de nombres
//		objColaPuntaje->Agregar(new Puntaje(aux_puntajes, aux_nombres));
//		while (!archivo_puntajes_lectura.eof() && !archivo_nombres_lectura.eof()) //Lectura hasta que lea TODO - eof = end of file
//		{
//			getline(archivo_puntajes_lectura, aux_puntajes); //leemos línea por línea y se copia en archivo_puntajes_lectura
//			getline(archivo_nombres_lectura, aux_nombres); //leemos línea por línea y se copia en archivo_nombres_lectura
//			objColaPuntaje->Agregar(new Puntaje(aux_puntajes, aux_nombres));
//		}
//		archivo_puntajes_lectura.close();
//		archivo_nombres_lectura.close();
//	}
//	lectura_hecha = true;
//}
//
//inline std::string ClaseRanking::GetInformaciónPuntaje() 
//{
//	ColaPuntaje* auxColaPuntaje = objColaPuntaje;
//	std::string puntaje_info = "";
//	Puntaje* aux;
//	while (auxColaPuntaje->GetPrimero() != NULL)
//	{
//		aux = auxColaPuntaje->EliminarPuntajeRetorno();
//		puntaje_info = puntaje_info + "\n" + aux->GetPuntaje();
//	}
//	return puntaje_info;
//}
//inline std::string ClaseRanking::GetInformaciónJugadores() 
//{ 
//	ColaPuntaje* auxColaPuntaje = objColaPuntaje;
//	std::string nombre_info = "";
//	Puntaje* aux;
//	while (auxColaPuntaje->GetPrimero() != NULL)
//	{
//		aux = auxColaPuntaje->EliminarPuntajeRetorno();
//		nombre_info = nombre_info + "\n" + aux->GetNombre();
//	}
//	return nombre_info;
//}

#pragma once
#include "fstream"
#include "iostream"
#include "conio.h"
#include "string"

class ClaseRanking
{
public:
	ClaseRanking();
	~ClaseRanking();

	//MANEJO DE PUNTAJES
	void EscribirPuntaje(int puntaje);
	void EscribirJugador(std::string nombre_jugador);
	void LeerPuntajes();
	void LeerJugadores();
	std::string GetInformaciónJugadores();
	std::string GetInformaciónPuntaje();

private:
	std::ifstream archivo_nombres_lectura; //Leer nombres
	std::ifstream archivo_puntajes_lectura; //Leer puntajes
	std::ofstream archivo_nombres_escritura; //Escribir nombres
	std::ofstream archivo_puntajes_escritura; //Escribir puntajes
	std::string información_nombres; //Información a leer del archivo de nombres A REEMPLAZAR POR LA COLA
	std::string información_puntajes; //Información a leer del archivo de puntajes A REEMPLAZAR POR LA COLA
};

inline ClaseRanking::ClaseRanking() {}
inline ClaseRanking::~ClaseRanking(){}

//MANEJO DE PUNTAJES

inline void ClaseRanking::EscribirPuntaje(int puntaje) //GUARDAMOS LA INFORMACIÓN EN EL ARCHIVO
{
	LeerPuntajes();
	archivo_puntajes_escritura.open("TopPuntajes.txt", std::ios::out);
	if (archivo_puntajes_escritura.is_open()) //Si el archivo está abierto
	{
		//Ingresamos datos al archivo
		archivo_puntajes_escritura << puntaje << std::endl << información_puntajes;
		//Cerramos el archivo
		archivo_puntajes_escritura.close();
	}
}

inline void ClaseRanking::EscribirJugador(std::string nombre_jugador) //GUARDAMOS LA INFORMACIÓN EN EL ARCHIVO
{
	LeerJugadores();
	archivo_nombres_escritura.open("TopJugadores.txt", std::ios::out);
	if (archivo_nombres_escritura.is_open()) //Si el archivo está abierto
	{
		//Ingresamos datos al archivo
		archivo_nombres_escritura << nombre_jugador << std::endl << información_nombres;
		//Cerramos el archivo
		archivo_nombres_escritura.close();
	}
}

inline void ClaseRanking::LeerPuntajes() //PEDIMOS LA INFORMACIÓN AL ARCHIVO
{
	archivo_puntajes_lectura.open("TopPuntajes.txt", std::ios::app);
	if (archivo_puntajes_lectura.is_open()) //Si el archivo está abierto
	{
		getline(archivo_puntajes_lectura, información_puntajes); //lectura adelantada
		while (!archivo_puntajes_lectura.eof()) //Lectura hasta que lea TODO - eof = end of file
		{
			std::string aux;
			getline(archivo_puntajes_lectura, aux); //leemos línea por línea y se copia en archivo_puntajes_lectura
			información_puntajes = información_puntajes + "\n" + aux;
		}
		archivo_puntajes_lectura.close();
	}
}

inline void ClaseRanking::LeerJugadores() //PEDIMOS LA INFORMACIÓN AL ARCHIVO
{
	archivo_nombres_lectura.open("TopJugadores.txt", std::ios::app);
	if (archivo_nombres_lectura.is_open()) //Si el archivo está abierto
	{
		getline(archivo_nombres_lectura, información_nombres); //lectura adelantada
		while (!archivo_nombres_lectura.eof()) //Lectura hasta que lea TODO | eof = end of file
		{
			std::string aux;
			getline(archivo_nombres_lectura, aux); //leemos línea por línea
			información_nombres = información_nombres + "\n" + aux;
		}
		archivo_nombres_lectura.close();
	}
}

inline std::string ClaseRanking::GetInformaciónPuntaje() { return información_puntajes; }
inline std::string ClaseRanking::GetInformaciónJugadores() { return información_nombres; }