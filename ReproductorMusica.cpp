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
