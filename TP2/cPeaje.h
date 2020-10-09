//#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "cPersona.h"
using namespace std;

class cPeaje
{

private:
	string Nombre;
	float Caja;

public:
	cPeaje();
	cPeaje(string nombre,float caja);
	~cPeaje();
	
	float CobrarPeaje(cPersona* persona,float peso);
	void SumarDineroGanado(float plata);
};

