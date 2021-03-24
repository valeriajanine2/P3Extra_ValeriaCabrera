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