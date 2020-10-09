#include "cCoordenada.h"
#include <string>

#define R 6371e3 //Radio de la tierra
#define PI 3.14159265358979323846


cCoordenada::cCoordenada()
{
	Latitud = 0.0;
	Longitud = 0.0;
}

cCoordenada::cCoordenada(float latitud, float longitud)
{
	Latitud = latitud;
	Longitud = longitud;
}

cCoordenada::cCoordenada(cCoordenada & coordenada)
{
	Latitud = coordenada.Get_Latitud();
	Longitud = coordenada.Get_Longitud();
}

/*Latitud 1= Latitud(de la clase)    Longitud 1= Longitud(de la clase)
Latitud 2= lat(me la pasan por parametro)   Longitud 2= lon(me la pasan por parametro)   ->Serian las coordenadas, hacia donde quiero viajar.
*/

//Devuelve los kilometros(float) que hay entre la ciudad de origen(donde esta) y la ciudad de destino
float cCoordenada::CalcularDistancia(float latitud, float longitud)
{
	double Omega1, Omega2, Delta1, Delta2;

	Omega1 = Latitud * PI / 180;// En radianes
	Omega2 = latitud * PI / 180;
	Delta1 = (latitud - Latitud) * PI / 180;
	Delta2 = (longitud - Longitud) * PI / 180;

	double a, c, d;

	a = (sin(Delta1 / 2) * sin(Delta1 / 2)) + (cos(Omega1) * cos(Omega2) * sin(Delta2 / 2) * sin(Delta2 / 2));
	c = 2 * atan2(sqrt(a), sqrt(1 - a));
	d = c * R;// En metros

	return (float)(d / 1000);// En kilometros
}

//Devuelve un string con todos los datos de una coordenada
string cCoordenada::To_String()
{
	return ("Coordenadas: (" + to_string(Latitud) + "," + to_string(Longitud) + ")");
}

//Devuelve la latitud(float) de x coordenada
float cCoordenada::Get_Latitud()
{
	return Latitud;
}

//Devuelve la longitud(float) de x coordenada
float cCoordenada::Get_Longitud()
{
	return Longitud;
}


cCoordenada::~cCoordenada()
{
}