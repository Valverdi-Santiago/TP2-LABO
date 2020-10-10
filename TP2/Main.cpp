#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "cCiudad.h"
#include "cPersona.h"
#include "cCoordenada.h"
#include "cVehiculo.h"
#include "ListaT.h"
#define N 10

using namespace std;

int main()
{
	
	ListaT<cPersona> *ListaPersonas = new ListaT<cPersona>(N);
	ListaT<cVehiculo> *ListaVehiculos = new ListaT<cVehiculo>(N);

	cCiudad* BuenosAires = new cCiudad("BuenosAires", 713.947, new cCoordenada(-34.6083, -58.3712));
	cCiudad* Junin = new cCiudad("Junin", 90.305, new cCoordenada(-34.58382, -60.94332));
	cCiudad* GeneralVillegas = new cCiudad("GeneralVillegas", 18.275, new cCoordenada(-35.03333, -63.01667));
	cCiudad* Chacabuco = new cCiudad("Chacabuco", 38.420, new cCoordenada(-34.64167, -60.47389));
	cCiudad* Lincoln = new cCiudad("Lincoln", 28.050, new cCoordenada(-34.86649, -61.5302));

	cVehiculo Auto1 = cVehiculo("AD324DE", "Polo GTi", "Volkswagen", 12000, 2012, 100, 45, 0, 1325, BuenosAires);
	cVehiculo Auto2 = cVehiculo("AB123JD", "A1", "Audi", 0, 2017, 100, 45, 10, 1700, GeneralVillegas);
	cVehiculo Auto3 = cVehiculo("AG231ED", "Cruze Hatchback", "Chevrolet", 23000, 2014, 100, 60, 20, 1850, BuenosAires);

	
	cPersona Juan =  cPersona("Juan", "Diaz", 0, "41.987.545", &Auto1, BuenosAires);
	cPersona Pablo = cPersona("Pablo", "Rodriguez", 1000, "34.567.654", NULL, Junin);
	cPersona Ines = cPersona("Ines", "Martinez", 1000, "38.675.456", &Auto2, GeneralVillegas);
	cPersona Victoria = cPersona("Victoria", "Diaz", 1000, "42.345.456", &Auto3, BuenosAires);

	ListaPersonas->AgregarItem(&Juan);
	ListaPersonas->AgregarItem(&Pablo);
	ListaPersonas->AgregarItem(&Ines);
	ListaPersonas->AgregarItem(&Victoria);

	ListaVehiculos->AgregarItem(&Auto1);
	ListaVehiculos->AgregarItem(&Auto2);
	ListaVehiculos->AgregarItem(&Auto3);
	Auto1.Viajar(Junin, &Juan);

	ListaPersonas->Listar();
	system("pause");
	delete ListaPersonas;
	delete ListaVehiculos;


	
	
	return 0;
}