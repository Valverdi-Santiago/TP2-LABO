#pragma once
#include <string>
#define NMAX 10

using namespace std;
template<class T>

class ListaT
{
protected:
	T **vector;
	unsigned int Ocupados;
	unsigned int Tamanio;

public:
	ListaT(unsigned int tamanio = NMAX);

	bool AgregarItem(T *item);
	void Listar();
	T* BucarItem(string clave);

	T* Quitar(string clave);
	T* Quitar(T *item);

	void Eliminar(string clave);
	void Eliminar(T *item);

	unsigned int Get_ItemPos(string clave);
	unsigned int Get_Ocupados();
	unsigned int Get_Tamanio();

	~ListaT();
};


template<class T>
ListaT<T>::ListaT::ListaT(unsigned int tamanio)
{
	vector = new T*[tamanio];
	for (unsigned int i = 0; i < tamanio; i++)
	{
		vector[i] = NULL;
	}
	Tamanio = tamanio;
	Ocupados = 0;
}

template<class T>
inline bool ListaT<T>::AgregarItem(T * item)
{
	T *aux = BucarItem(item->GetClave());
	if (aux != NULL)
		throw new exception("Ya se encuentra en la lista.");
	if (Ocupados < Tamanio)
		vector[Ocupados++] = item;
	else
		throw new exception("No hay lugar suficiente para agregar a la lista.");
	return true;
}

template<class T>
inline void ListaT<T>::Listar() //VER QUE MI CLASE TENGA IMRPIMIR
{
	for (unsigned int i = 0; i < Ocupados; i++)
	{
		vector[i]->Imprimir();
	}
}

template<class T>
inline T * ListaT<T>::BucarItem(string clave)
{
	for (unsigned int i = 0; i < Ocupados; i++)
	{
		if (vector[i]->GetClave() == clave)
			return vector[i];
	}
	return NULL;
}

template<class T>
inline T * ListaT<T>::Quitar(string clave)
{
	unsigned int pos = Get_ItemPos(clave);
	if (pos >= Ocupados)
		throw new exception("Posicion invalida.");
	T *aux = vector[pos];
	for (unsigned int i = 0; i < Ocupados - 1; i++)
	{
		vector[i] = vector[i + 1];
	}
	vector[Ocupados - 1] = NULL;
	Ocupados--;
	return aux;
}

template<class T>
inline T * ListaT<T>::Quitar(T * item)
{
	unsigned int pos = Get_ItemPos(item->GetClave());
	if (pos >= Ocupados)
		return NULL;
	return Quitar(item->GetClave());
}

template<class T>
inline void ListaT<T>::Eliminar(string clave)
{
	unsigned int pos = Get_ItemPos(clave);
	if (pos >= Ocupados)
		throw new exception("No se puede eliminar.");
	if (pos < Ocupados)
	{
		T *aux = Quitar(clave);
		if (aux != NULL)
			delete aux;
		else
			throw new exception("No se encontro.");
	}
}

template<class T>
inline void ListaT<T>::Eliminar(T * item)
{
	Eliminar(item->GetClave());
}

template<class T>
inline unsigned int ListaT<T>::Get_ItemPos(string clave) //PONER GETCLAVE EN LAS CLASES Q USAN LA LISTA
{
	for (unsigned int i = 0; i < Ocupados; i++)
	{
		if (vector[i]->GetClave() == clave)
			return i;
	}
	return -1;
}

template<class T>
inline unsigned int ListaT<T>::Get_Ocupados()
{
	return Ocupados;
}

template<class T>
inline unsigned int ListaT<T>::Get_Tamanio()
{
	return Tamanio;
}

template<class T>
ListaT<T>::ListaT::~ListaT()
{
	if (vector != NULL)
	{
		for (unsigned int i = 0; i < Ocupados; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}
}
