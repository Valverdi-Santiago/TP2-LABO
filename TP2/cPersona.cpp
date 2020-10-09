#include "cPersona.h"



cPersona::cPersona() : DNI(" ")
{
	Nombre = " ";
	Apellido = " ";
	Billetera = 1000;
	Vehiculo = NULL;
	CiudadOrigen = NULL;
}

cPersona::cPersona(string nombre, string apellido, int billetera, const string dni, cVehiculo *vehiculo, cCiudad *ciudadorigen) :DNI(dni)
{
	Nombre = nombre;
	Apellido = apellido;
	Vehiculo = vehiculo;
	CiudadOrigen = ciudadorigen;
	if (billetera >= 1000) //PREGUNTAR SI ESTA BIEN ASI O SI LO PASO POR DEFECTO
		Billetera = billetera;
	else
		Billetera = 1000;
}

//Verifica que la persona que le paso por parametro sea distinta a la persona q le pertenece el vehiculo, de ser asi, lo vende.
void cPersona::VenderVehiculo(cPersona * cliente)
{
	if (cliente->Get_Vehiculo() != Vehiculo)
	{
		cliente->Set_Vehiculo(Vehiculo);
		Vehiculo = NULL;
	}
	else
		cout << "El vehiculo pertenece a la misma persona que le estoy vendiendo." << endl;
}

//Imprime en pantalla todos los datos de la persona.
void cPersona::Imprimir()
{
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "Nombre y Apellido: " << Nombre << " " << Apellido << "\nDNI: " << DNI << endl;
	if (Vehiculo != NULL)//Podemos no tener un vehiculo
	{
		
		//cout << Vehiculo->To_String() << endl;
		

	}	
	else
	cout << "No tiene vehiculo." << endl;
	cout << "Ciudad de origen: " << CiudadOrigen->To_String() << endl; //Siempre tenemos una ciudad de origen
	cout << endl;
}

//Devuelve el vehiculo que tiene la persona.
cVehiculo * cPersona::Get_Vehiculo()
{
	if (Vehiculo != NULL)
		return Vehiculo;
}

//Me devuelve la clave(dni) de una persona
string cPersona::GetClave()
{
	return DNI;
}

//Modifica el Vehiculo que tiene la persona. Generalmente lo uso para el metodo vender vehiculo.
void cPersona::Set_Vehiculo(cVehiculo * vehiculo)
{
	Vehiculo = vehiculo;
}
int cPersona::Get_Billetera() 
{
	return Billetera;
}
void cPersona::Trabajar() 
{
	Billetera += 100;
}


cPersona::~cPersona()
{
}