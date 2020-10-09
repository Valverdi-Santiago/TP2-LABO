#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "cPersona.h"
#include <iomanip>
#include <ctime>
#include <sstream>
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
	
	float Cobrar(cPersona* persona,float peso);

};

