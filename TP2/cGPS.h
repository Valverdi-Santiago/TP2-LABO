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
	unsigned int Get_CantidadCiudadesFavoritas();
	void Listar();

	~cGPS();
};

