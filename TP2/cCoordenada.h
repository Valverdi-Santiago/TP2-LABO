#pragma once
#include <iostream>
#include <math.h>


using namespace std;

class cCoordenada
{
public:
	float Latitud;
	float Longitud;

	cCoordenada();
	cCoordenada(float latitud, float longitud);
	cCoordenada(cCoordenada &coordenada);

	float CalcularDistancia(float latitud, float longitud);
	string To_String();

	float Get_Latitud();
	float Get_Longitud();

	~cCoordenada();
};