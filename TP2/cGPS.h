#pragma once
#include <iostream>
#include "cCiudad.h"
#include"ListaT.h"

using namespace std;
class cGPS
{
	ListaT<cCiudad> *ListaCiudadesFavoritas = new ListaT<cCiudad>(10);

public:
	cGPS();
	cCiudad* BuscarCiudad(string nombre);
	~cGPS();
};

cGPS::cGPS()
{
}

cCiudad * cGPS::BuscarCiudad(string nombre)
{
	return ListaCiudadesFavoritas->BucarItem(nombre);
}


cGPS::~cGPS()
{
	delete ListaCiudadesFavoritas;
}