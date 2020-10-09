#include "cVehiculo.h"
#include <string>
#define Valor_Nafta  60
#define Peaje_Max 30


cVehiculo::cVehiculo()
{
	Patente = " ";
	Modelo = " ";
	Marca = " ";
	KilometrosRecorridos = 0.0;
	AnioLanzamiento = 0;
	NaftaActual = 0;
	NaftaMaxima = 0;
	Consumo = 0;
	Peso = 0;
	UbicacionActual = NULL;
	GPS = NULL;
}

cVehiculo::cVehiculo(string patente, string modelo, string marca, float kilometrosRecorridos, int anioLanzamiento, float consumo, float naftaMaxima, float naftaActual, float peso, cCiudad *ubicacionActual)
{
	GPS = new cGPS();

	Patente = patente;
	Modelo = modelo;
	Marca = marca;
	KilometrosRecorridos = kilometrosRecorridos;
	AnioLanzamiento = anioLanzamiento;
	Consumo = consumo;
	NaftaActual = naftaActual;
	NaftaMaxima = naftaMaxima;
	Peso = peso;
	UbicacionActual = ubicacionActual;
	
}

//Viaja desde la ciudad que se encuentra hacia la ciudad que le paso por parametro (ciudad destino). No devuelve nada.
void cVehiculo::Viajar(cCiudad * ciudadDestino, cPersona* persona)
{
	float kilometros = UbicacionActual->Get_Coordenadas()->CalcularDistancia(ciudadDestino->Get_Lat(), ciudadDestino->Get_Long());
	
	int aux = 0;
	aux = (kilometros / Consumo)*Valor_Nafta;
	aux = aux + Peaje_Max * 10;


	ListaT<cPeaje> *ListaPeajes = new ListaT<cPeaje>(10); //VER SI ESTA BIEN

	while(persona->Get_Billetera() < aux)
	{	
		persona->Trabajar();
	}
	if (UbicacionActual->Get_Coordenadas() == ciudadDestino->Get_Coordenadas())
		cout << "ya se encuentra en esa ciudad." << endl;
	else
	{
			cout << "Viaje: " << UbicacionActual->Get_Nombre() << " --> " << ciudadDestino->Get_Nombre() << endl;
			Sumar_KilometrosRecorridos(kilometros,persona); //Sumo los kilometros que recorri
			Set_Ubicacion(ciudadDestino);

	}
	delete ListaPeajes;
}

//Verifica si la nafta que tiene le alcanza para viajar hacia la ciudad de destino que le paso. Me devuelve un true si le alcanza y un false si no.
bool cVehiculo::VerificarNafta(cCiudad * ciudadDestino)
{
	float kilometros = UbicacionActual->Get_Coordenadas()->CalcularDistancia(ciudadDestino->Get_Lat(), ciudadDestino->Get_Long());
	float kmxl = Consumo * NaftaActual;//Kilometros por litro q necesito (ver si esta bien)

	if (kmxl > NaftaActual)
	{
		cout << "Nafta suficiente." << endl;
		return true;
	}
	else
	{
		cout << "Nafta insuficiente." << endl;
		return false;
	}
}

//Carga el tanque con los litros que le paso.
void cVehiculo::CargarNafta(float litros,cPersona *persona)
{
	float aux;
	
	if (litros > 0 && (litros + NaftaActual) <= NaftaMaxima &&persona->Get_Billetera()>=Valor_Nafta*litros)
	{
		NaftaActual += litros;
		persona->Billetera = persona->Billetera - (Valor_Nafta * litros);
		

		if (NaftaActual == NaftaMaxima)
			cout << "Tanque lleno." << endl;
		
	}
	else
	{
		if (litros < 0)
		{		cout << "Valor de nafta negativo." << endl;
		
		}
		else
			if (persona->Get_Billetera() <= Valor_Nafta * litros)
			{
				cout << "Dinero insuficiente " << endl;
				
				
			}
		else
		{
			aux = (NaftaActual + litros) - NaftaMaxima;
			NaftaActual = NaftaMaxima;

			cout << "Tanque lleno, sobraron " << aux << " litros de nafta." << endl;
			persona->Billetera =persona->Billetera- (NaftaMaxima - NaftaActual) * Valor_Nafta;
		}
	}
}

//A los X kilometros hace el mantenimiento del auto. 
void cVehiculo::HacerMantenimiento()
{
	if (KilometrosRecorridos > NMAX)
		cout << "Haciendo mantenimiento." << endl;
}

//Me devuelve un string con todos los datos del vehiculo.
string cVehiculo::To_String()
{
	return ("Vehiculo: " + Modelo + ", " + Marca + ", " + to_string(AnioLanzamiento) + " -Patente: " + Patente + "\nUbicacion actual del vehiculo: " + UbicacionActual->To_String());
}

//Suma los kilometros que va recorriendo el vehiculo.
void cVehiculo::Sumar_KilometrosRecorridos(float kilometros,cPersona * persona) //VER SI ES LO Q QUIERE DAMI
{
	float aux=0;
	int aux2 = 0;
	for (int i = 0; i < kilometros; i++)
	{
		
		KilometrosRecorridos += 1;
		aux2 = KilometrosRecorridos;
		if(aux==Consumo)
		NaftaActual -= 1;

		if (NaftaActual == 0)
		{
			aux = (kilometros-i)/Consumo;//calculo los litros que me faltan
			CargarNafta(aux,persona);//cargo los litros que faltan y le paso la persona
		}
	}
	
}

//Me devuelve la clave(patente) del vehiculo
string cVehiculo::GetClave()
{
	return Patente;
}

//Cambia la ubicacion (ciudad) del vehiculo.
void cVehiculo::Set_Ubicacion(cCiudad * ciudad)
{
	UbicacionActual = ciudad;
}

cVehiculo::~cVehiculo()
{
}