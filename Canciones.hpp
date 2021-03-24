#ifndef Canciones_H
#define Canciones_H
#include <iostream>
#include <string>
#include <fstream>
#include "Genero.hpp"

using namespace std;

class Canciones{
	private:
		string nombre;
		string artista;
		Genero* genero;
		string duracion;
		
	public:
		Canciones();
		Canciones(string,string,Genero*,string);
		~Canciones();
		void setNombre(string);
		void setArtista(string);
		void setGenero(Genero*);
		void setDuracion(string);
		string getNombre();
		string getArtista();
		Genero* getGenero();
		string getDuracion();
};

#endif