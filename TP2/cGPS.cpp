#include "cGPS.h"



cGPS::cGPS()
{
}

cCiudad * cGPS::BuscarCiudad(string nombre)
{
	return ListaCiudadesFavoritas->BucarItem(nombre);
}

ListaT<cCiudad>* cGPS::Get_ListaCiudadesFavoritas()
{
	return ListaCiudadesFavoritas;
}

unsigned int cGPS::Get_CantidadCiudadesFavoritas()
{
	return ListaCiudadesFavoritas->Get_Ocupados();
}

void cGPS::Listar()
{
	cout << "----------Ciudades Favoritas GPS.----------" << endl;
	ListaCiudadesFavoritas->Listar();
}


cGPS::~cGPS()
{
	delete ListaCiudadesFavoritas;
}



