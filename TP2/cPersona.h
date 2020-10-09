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


	string GetClave();
	cVehiculo* Get_Vehiculo();
	int  Get_Billetera();
	void Set_Vehiculo(cVehiculo *vehiculo);
	
	void Trabajar();


	~cPersona();
};

