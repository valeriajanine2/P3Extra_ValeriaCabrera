#include "Genero.hpp"

Genero::Genero(){
	//constructor vacio
}

Genero::Genero(int idGenero,string nombre){
	this->idGenero=idGenero;
	this->nombre=nombre;
}

Genero::~Genero(){
	//destruir el objeto
}

void Genero::setNombre(string nombre){
	this->nombre=nombre;
}

string Genero::getNombre(){
	return this->nombre;
}

void Genero::setID(int idGenero){
	this->idGenero=idGenero;
}

int Genero::getID(){
	return this->idGenero;
}