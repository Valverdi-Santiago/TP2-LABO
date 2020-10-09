#pragma once
#include <iostream>
#include <string>
#include "cCoordenada.h"

using namespace std;

class cCiudad
{
private:
	string Nombre;
	float Poblacion;
	cCoordenada *Coordenadas;

public:
	cCiudad();
	cCiudad(string nombre, float poblacion, cCoordenada *coordenada);

	string To_String();
	void Imprimir();

	cCoordenada* Get_Coordenadas();
	string Get_Nombre();
	string GetClave();
	float Get_Lat();
	float Get_Long();

	~cCiudad();
};

