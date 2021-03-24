#include "Canciones.hpp"

Canciones::Canciones(){
	//constructor vacio
}

Canciones::Canciones(string nombre,string artista,Genero* genero, string duracion){
	this->nombre=nombre;
	this->artista=artista;
	this->genero=genero;
	this->duracion=duracion;
}

Canciones::~Canciones(){
	//destruir el objeto
}

void Canciones::setNombre(string nombre){
	this->nombre=nombre;
}

string Canciones::getNombre(){
	return this->nombre;
}

void Canciones::setArtista(string nombre){
	this->artista=artista;
}

string Canciones::getArtista(){
	return this->artista;
}

Genero* Canciones::getGenero(){
	return this->genero;
}

void Canciones::setGenero(Genero* genero){
	this->genero=genero;
}

void Canciones::setDuracion(string nombre){
	this->duracion=duracion;
}

string Canciones::getDuracion(){
	return this->duracion;
}