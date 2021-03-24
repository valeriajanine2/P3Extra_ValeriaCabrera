#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Canciones.hpp"
#include "Album.hpp"

using namespace std;

class Playlist{
	private:
		string nombre;
		vector<Canciones*> listaCanciones;
		
	public:
		Playlist();
		Playlist(string,vector<Canciones*>);
		Playlist(string);
		~Playlist();
		void setNombre(string);
		string getNombre();
		vector<Canciones*> getListaCanciones();
		void setListaCanciones(vector<Canciones*>);
		void listarCanciones();
		Playlist* operator + (Canciones*);
		Playlist* operator + (Playlist*);
		Playlist* operator + (Album*);
		Playlist* operator - (Canciones*);
		Playlist* operator - (Genero*);
};

#endif