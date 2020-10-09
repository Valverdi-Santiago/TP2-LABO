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
	ListaT<cCiudad>* Get_ListaCiudadesFavoritas();
	~cGPS();
};

cGPS::cGPS()
{
}

cCiudad * cGPS::BuscarCiudad(string nombre)
{
	return ListaCiudadesFavoritas->BucarItem(nombre);
}

inline ListaT<cCiudad>* cGPS::Get_ListaCiudadesFavoritas()
{
	return ListaCiudadesFavoritas;
}


cGPS::~cGPS()
{
	delete ListaCiudadesFavoritas;
}