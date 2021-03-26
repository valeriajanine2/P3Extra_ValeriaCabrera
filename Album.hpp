#ifndef ALBUM_H
#define ALBUM_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Canciones.hpp"
//#include "Playlist.hpp"

using namespace std;

class Album{
	private:
		string nombre;
		vector<Canciones*> listaCanciones;
		string artista;
		
	public:
		Album();
		Album(string,vector<Canciones*>,string);
		Album(string);
		~Album();
		void setNombre(string);
		void setArtista(string);
		string getNombre();
		string getArtista();
		vector<Canciones*> getCanciones();
		void listarCanciones();
		Album* operator * (int);
		Album* operator + (Canciones*);
		void setListaCanciones(vector<Canciones*>);
		void guardarAlbum(ofstream*);
		Album* cargarAlbum(ifstream*,vector<Canciones*>);
};

#endif