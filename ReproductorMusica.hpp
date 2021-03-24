#ifndef REPRODUCTORMUSICA_H
#define REPRODUCTORMUSICA_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Canciones.hpp"
#include "Genero.hpp"
#include "Album.hpp"
#include "Playlist.hpp"

using namespace std;

class ReproductorMusica{
	private:
		vector<Canciones*> canciones;
		vector<Genero*> generos;
		vector<Playlist*> playlists;
		vector<Album*> albumes;
	public:
		ReproductorMusica();
		~ReproductorMusica();
		static void cargarArchivos(string,string,string,string);
		void escribirCanciones(string);
		void escribirAlbumes(string);
		void escribirGeneros(string);
		void escribirPlaylists(string);
};

#endif