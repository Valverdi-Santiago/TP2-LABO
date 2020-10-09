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

inline unsigned int cGPS::Get_CantidadCiudadesFavoritas()
{
	return ListaCiudadesFavoritas->Get_Ocupados();
}

inline void cGPS::Listar()
{
	cout << "----------Ciudades Favoritas GPS.----------" << endl;
	ListaCiudadesFavoritas->Listar();
}


cGPS::~cGPS()
{
	delete ListaCiudadesFavoritas;
}