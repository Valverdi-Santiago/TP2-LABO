#pragma once
#include <iostream>
#include <string>
#include "cCiudad.h"
#include "cGPS.h"
#include "ListaT.h"
#include "cPeaje.h"
#include "cPersona.h"
#define NMAX 10000 //Kilometros que tiene que hacer el servis 
using namespace std;

class cVehiculo
{
private:
	string Patente;
	string Modelo;
	string Marca;
	float KilometrosRecorridos;
	int AnioLanzamiento;
	float Consumo;
	float NaftaMaxima;
	float NaftaActual;
	float Peso;
	cCiudad *UbicacionActual;
	cGPS *GPS;

public:
	
	cVehiculo();
	cVehiculo(string patente, string modelo, string marca, float kilometrosRecorridos, int anioLanzamiento, float consumo, float naftaMaxima, float naftaActual, float peso, cCiudad *ubicacionActual, cGPS *gps);

	void Viajar(cCiudad *ciudadDestino,cPersona* persona);
	bool VerificarNafta(cCiudad *ciudadDestino);//true alcanza la nafta, false no alcanza 
	void CargarNafta(float litros, cPersona* persona);
	void HacerMantenimiento();
	string To_String();
	void Sumar_KilometrosRecorridos(float kilometros, cPersona* persona);

	string GetClave();
	void Set_Ubicacion(cCiudad *ciudad);

	~cVehiculo();
};
