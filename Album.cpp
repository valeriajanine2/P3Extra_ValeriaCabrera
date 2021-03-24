#include "Album.hpp"

Album::Album(){
	//constructor vacio
}

Album::Album(string nombre,vector<Canciones*> listaCanciones,string artista){
	this->nombre=nombre;
	this->artista=artista;
	this->listaCanciones=listaCanciones;
}

Album::Album(string nombre){
	this->nombre=nombre;
}

Album::~Album(){
	//destruir el objeto
}

void Album::listarCanciones(){
	
	for(int i = 0; i < listaCanciones.size(); i++){
		Canciones* c = new Canciones();
		c = listaCanciones.at(i);
		cout<<"	"<<i<<") "<<c->getNombre()<<" - "<<c->getArtista()<<" Genero: "<<c->getGenero()->getNombre()<<" Duracion: "<<c->getDuracion()<<endl;
	}
}

Album* Album::operator *(int num){
	
	vector<Canciones*> nuevaLista;
	
	for(int i = 0; i < num; i++){
		for(int j = 0; j < listaCanciones.size(); j++){
			Canciones* c = new Canciones();
			c = listaCanciones.at(j);
			nuevaLista.push_back(c);
		}
	}
	
	string name = this->nombre +" "+std::to_string(num) + " veces";
	
	Album* a = new Album(name,nuevaLista,this->artista);
	return a;
	
}

Album* Album::operator +(Canciones* c){
	
	string name = this->nombre;
	
	Album* al = new Album(name);
	vector<Canciones*> songs = this->listaCanciones;
	songs.push_back(c);
	al->setListaCanciones(songs);
	
	return al;
	
}


void Album::setNombre(string nombre){
	this->nombre=nombre;
}

string Album::getNombre(){
	return this->nombre;
}

void Album::setArtista(string artista){
	this->artista=artista;
}

string Album::getArtista(){
	return this->artista;
}

vector<Canciones*> Album::getCanciones(){
	return this->listaCanciones;
}

void Album::setListaCanciones(vector<Canciones*> listaCanciones){
	this->listaCanciones = listaCanciones;
}
