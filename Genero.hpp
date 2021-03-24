#ifndef GENERO_H
#define GENERO_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Genero{
	private:
		int idGenero;
		string nombre;
		
	public:
		Genero();
		Genero(int,string);
		~Genero();
		void setNombre(string);
		void setID(int);
		string getNombre();
		int getID();
};

#endif