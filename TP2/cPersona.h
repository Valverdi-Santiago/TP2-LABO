#pragma once
#include <string>
#include <iostream>
//#include "cVehiculo.h"
#include "cCiudad.h"
class cVehiculo;

using namespace std;

class cPersona
{
protected:

	string Nombre;
	string Apellido;
	const string DNI;
	cVehiculo *Vehiculo;
	cCiudad *CiudadOrigen;

public:
	int Billetera;

	cPersona();
	cPersona(string nombre, string apellido, int billetera, const string dni, cVehiculo *vehiculo, cCiudad *ciudadorigen);

	void VenderVehiculo(cPersona *cliente);
	void Imprimir();

	cVehiculo* Get_Vehiculo();
	void Set_Vehiculo(cVehiculo *vehiculo);
	int  Get_Billetera();
	void Trabajar();


	~cPersona();
};

