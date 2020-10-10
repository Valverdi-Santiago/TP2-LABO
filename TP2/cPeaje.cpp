#include "cPeaje.h"

cPeaje::cPeaje()
{
	Nombre = " ";
	Caja = 0.0;
}

cPeaje::cPeaje(string nombre, float caja)
{
	Nombre = nombre;
	Caja = caja;
}

cPeaje::~cPeaje()
{
}

float cPeaje::CobrarPeaje(cPersona* persona, float peso)
{	
	int valor = 0;
	auto t = time(nullptr);
	auto tm = *localtime(&t);
	ostringstream oss;
	cout << put_time(&tm, "%H") << endl;
	oss << put_time(&tm, "%H");
	auto str = oss.str();


	if (str.compare("17") != 0|| str.compare("18") != 0||str.compare("19") != 0 || str.compare("20") != 0 || str.compare("21") != 0)
	{
		valor = 20;
		cout << "pico1" << endl; 
	}
	else
	if (str.compare("11") != 0 || str.compare("12") != 0 || str.compare("13") != 0 || str.compare("14") != 0 || str.compare("15") != 0)
	{
		valor = 30;
		cout << "pico2" << endl;
	}
	else { valor = 10; }
	
	if (peso > 1801) { valor = valor * 1.5; }
	else if (peso > 1501) { valor = valor * 1.2; }
	Caja += valor;
	return valor;


}

void cPeaje::SumarDineroGanado(float plata)
{
	Caja += plata;
}

string cPeaje::GetClave()
{
	return Nombre;
}
