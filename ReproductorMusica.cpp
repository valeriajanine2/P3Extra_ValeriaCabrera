#include "ReproductorMusica.hpp"

ReproductorMusica::ReproductorMusica(){
	//constructor vacio
}

ReproductorMusica::~ReproductorMusica(){
	for(int i = 0; i < this->canciones.size(); i++){
		delete canciones.at(i);
	}
	for(int i = 0; i < this->albumes.size(); i++){
		delete albumes.at(i);
	}
	for(int i = 0; i < this->playlists.size(); i++){
		delete playlists.at(i);
	}
	for(int i = 0; i < this->generos.size(); i++){
		delete generos.at(i);
	}
}

void ReproductorMusica::agregarAlbumes(Album* a ){
	this->albumes.push_back(a);
}

void ReproductorMusica::agregarCanciones(Canciones* c){
	this->canciones.push_back(c);
}

void ReproductorMusica::agregarGeneros(Genero* g){
	this->generos.push_back(g);
}

void ReproductorMusica::agregarPlaylist(Playlist* p){
	this->playlists.push_back(p);
}

vector<Album*> ReproductorMusica::getAlbumes(){
	return this->albumes;
}

vector<Canciones*> ReproductorMusica::getCanciones(){
	return this->canciones;
}

vector<Genero*> ReproductorMusica::getGeneros(){
	return this->generos;
}

vector<Playlist*> ReproductorMusica::getPlaylists(){
	return this->playlists;
}

void ReproductorMusica::listarCanciones(){
	for(int i = 0; i < this->canciones.size(); i++){
		Canciones* c = new Canciones();
		c = this->canciones.at(i);
		cout<<i<<") "<<c->getNombre()<<" - "<<c->getArtista()<<" Genero: "<<c->getGenero()->getNombre()<<" Duracion: "<<c->getDuracion()<<endl;
	}
}

void ReproductorMusica::listarAlbums(){
	for(int i = 0; i < this->albumes.size(); i++){
		Album* a = new Album();
		a = this->albumes.at(i);
		cout<<i<<") Nombre: "<<a->getNombre()<<" - "<<a->getArtista()<<endl;
		a->listarCanciones();
		cout<<endl;
	}
}

void ReproductorMusica::listarGeneros(){
	for(int i = 0; i < this->generos.size(); i++){
		Genero* g = new Genero();
		g = this->generos.at(i);
		cout<<i<<") "<<g->getNombre()<<endl;
	}
}

void ReproductorMusica::listarPlaylists(){
	for(int i = 0; i < this->playlists.size(); i++){
		Playlist* p = new Playlist();
		p = this->playlists.at(i);
		cout<<i<<") "<<p->getNombre()<<endl;
		p->listarCanciones();
		cout<<endl;
	}
}