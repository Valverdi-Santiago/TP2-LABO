#include "cVehiculo.h"
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
bool cVehiculo::Viajar(cCiudad * ciudadDestino, cPersona* persona)
{
	if (persona->Get_Vehiculo ()== NULL)
	{
		cout<<"sin auto para viajar"<<endl;
		return -1;
	}
	float kilometros = UbicacionActual->Get_Coordenadas()->CalcularDistancia(ciudadDestino->Get_Lat(), ciudadDestino->Get_Long());
	int Cant = rand() % (int)(ceil(kilometros / 50) + 1);
	int i;
	int aux = 0;
	aux = (kilometros / Consumo)*Valor_Nafta;
	aux = aux + Peaje_Max * 10;
	cPeaje* peaje1 = new cPeaje("peaje1",0);
	cPeaje* peaje2 = new cPeaje("peaje2", 0);
	cPeaje* peaje3= new cPeaje("peaje3", 0);
	cPeaje* peaje4 = new cPeaje("peaje4", 0);
	cPeaje* peaje5 = new cPeaje("peaje5", 0);

	ListaT<cPeaje> *ListaPeajes = new ListaT<cPeaje>(Cant); //VER SI ESTA BIEN
	
	ListaPeajes->AgregarItem(peaje1);
	ListaPeajes->AgregarItem(peaje2);
	ListaPeajes->AgregarItem(peaje3);
	ListaPeajes->AgregarItem(peaje4);
	ListaPeajes->AgregarItem(peaje5);
	
	while(persona->Get_Billetera() < aux)
	{	
		persona->Trabajar();
	}
	
	
	
	if (UbicacionActual->Get_Lat() == ciudadDestino->Get_Lat() && UbicacionActual->Get_Long() == ciudadDestino->Get_Long())
		cout << "ya se encuentra en esa ciudad." << endl;
	else
	{
			cout << "Viaje: " << UbicacionActual->Get_Nombre() << " --> " << ciudadDestino->Get_Nombre() << endl;
			Sumar_KilometrosRecorridos(kilometros,persona,Cant,ListaPeajes); //Sumo los kilometros que recorri
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
void cVehiculo::Sumar_KilometrosRecorridos(float kilometros,cPersona * persona,int Cant, ListaT<cPeaje>* ListaPeajes)
{
	int n = 0;

	float aux=0;
	int aux2 = 0;
	int DistEntrePeajes = 0;
	float Valor = 0;
	
	DistEntrePeajes = int(kilometros) / Cant;


	for (int i = 0; i < kilometros; i++)
	{
		if (DistEntrePeajes * n == kilometros)
		{
			Valor = ListaPeajes->CobrarPeaje(persona, Peso);
			ListaPeajes->Get_Caja(ListaPeajes->BucarItem(n), Valor);
			n++;
			
		}
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