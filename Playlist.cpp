#include "PLaylist.hpp"

Playlist::Playlist(){
	//constructor vacio
}

Playlist::Playlist(string nombre, vector<Canciones*> listaCanciones){
	this->nombre=nombre;
	this->listaCanciones=listaCanciones;
}

Playlist::Playlist(string nombre){
	this->nombre=nombre;
}

Playlist::~Playlist(){
	//destruir el objeto
}

void Playlist::listarCanciones(){
	//cout<<"Album: "<<this->nombre<<endl;
	
	for(int i = 0; i < this->listaCanciones.size(); i++){
		Canciones* c = new Canciones();
		c = this->listaCanciones.at(i);
		cout<<"	"<<i<<") "<<c->getNombre()<<" - "<<c->getArtista()<<" Genero: "<<c->getGenero()->getNombre()<<" Duracion: "<<c->getDuracion()<<endl;
	}
}

Playlist* Playlist::operator +(Canciones* c){
	
	string name = this->nombre;
	Playlist* play = new Playlist(name);
	vector<Canciones*> songs = this->listaCanciones;
	songs.push_back(c);
	play->setListaCanciones(songs);
	return play;
}

Playlist* Playlist::operator +(Playlist* play){
	
	vector<Canciones*> songs;
	
	for(int i = 0; i < this->listaCanciones.size(); i++){
		Canciones* c = new Canciones();
		c = this->listaCanciones.at(i);
		songs.push_back(c);
	}
	
	for(int i = 0; i < play->getListaCanciones().size(); i++){
		Canciones* c = new Canciones();
		c = play->getListaCanciones().at(i);
		songs.push_back(c);
	}
	
	string name = "Union " + this->getNombre() + " " + play->getNombre();
	
	Playlist* p = new Playlist(name,songs);
	
	return p;
	
}

Playlist* Playlist::operator +(Album* album){
	
	Playlist* p = new Playlist(this->nombre);
	
	vector<Canciones*> songs = this->listaCanciones;
	for(int i = 0; i < album->getCanciones().size(); i++){
		Canciones* c = new Canciones();
		c = album->getCanciones().at(i);
		songs.push_back(c);
	}
	
	p->setListaCanciones(songs);
	
	return p;
	
}

Playlist* Playlist::operator -(Canciones* c){
	
	Playlist* play = new Playlist(this->nombre);
	
	vector<Canciones*> temp = this->getListaCanciones();
	
	for(int i = 0; i < temp.size(); i++){
		Canciones* s = new Canciones();
		s = temp.at(i);
		if(c->getNombre()==s->getNombre()){
			temp.erase(temp.begin() + i);
		}
	}
	
	play->setListaCanciones(temp);
	
	return play;
	
}

Playlist* Playlist::operator -(Genero* g){
	
	Playlist* play = new Playlist(this->nombre);
	
	vector<Canciones*> temp = this->getListaCanciones();
	
	for(int i = 0; i < temp.size(); i++){
		Canciones* s = new Canciones();
		s = temp.at(i);
		Genero* gen = s->getGenero();
		if(g->getNombre()==gen->getNombre()){
			temp.erase(temp.begin() + i);
		}
	}
	
	play->setListaCanciones(temp);
	
	return play;
}

void Playlist::setNombre(string nombre){
	this->nombre=nombre;
}

string Playlist::getNombre(){
	return this->nombre;
}

vector<Canciones*> Playlist::getListaCanciones(){
	return this->listaCanciones;
}

void Playlist::setListaCanciones(vector<Canciones*> listaCanciones){
	this->listaCanciones=listaCanciones;
}