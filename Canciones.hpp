#ifndef Canciones_H
#define Canciones_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Genero.hpp"

using namespace std;

class Canciones{
	private:
		int idCancion;
		string nombre;
		string artista;
		Genero* genero;
		string duracion;
		
	public:
		Canciones();
		Canciones(int,string,string,Genero*,string);
		~Canciones();
		void setID(int);
		void setNombre(string);
		void setArtista(string);
		void setGenero(Genero*);
		void setDuracion(string);
		int getID();
		string getNombre();
		string getArtista();
		Genero* getGenero();
		string getDuracion();
		void guardarCancion(ofstream*);
		Canciones* cargarCancion(ifstream*,vector<Genero*>);
};

#endif