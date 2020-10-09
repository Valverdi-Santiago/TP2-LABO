#include "cCiudad.h"



cCiudad::cCiudad()
{
	Nombre = " ";
	Poblacion = 0.0;
	Coordenadas = NULL;
}


cCiudad::cCiudad(string nombre, float poblacion, cCoordenada *coordenada)
{
	Nombre = nombre;
	Poblacion = poblacion;
	Coordenadas = coordenada;
}

//Devuelve un string con todos los datos de una ciudad
string cCiudad::To_String()
{
	if (Nombre != " ")
		return ("  " + Nombre + " -Poblacion: " + to_string(Poblacion) + "  -" + Coordenadas->To_String());
	else
		return "No tiene ciudad.";
}

void cCiudad::Imprimir()
{
	cout << "---CIUDAD---" << endl;
	cout << "" << Nombre << " .poblacion: " << Poblacion << ".coordenadas: (" << Coordenadas->Get_Latitud() << ", " << Coordenadas->Get_Longitud() << endl;
}

//Devuelve las coordenadas(*coordenadas) de una ciudad
cCoordenada * cCiudad::Get_Coordenadas()
{
	return Coordenadas;
}

//Devuelve el nombre(string) de la ciudad
string cCiudad::Get_Nombre()
{
	return Nombre;
}
//Me devuelve la clave que voy a usar para la lista (nombre)
string cCiudad::GetClave()
{
	return Nombre;
}

//Devuelve la latitud(float) de una ciudad
float cCiudad::Get_Lat()
{
	return Coordenadas->Get_Latitud();
}

//Devuelve la longitud(float) de una ciudad
float cCiudad::Get_Long()
{
	return Coordenadas->Get_Longitud();
}

void cCiudad::Imprimir()
{
	cout << Nombre << endl;
}

cCiudad::~cCiudad()
{
}
