#include "ReproductorMusica.hpp"

ReproductorMusica::ReproductorMusica() {
	//constructor vacio
}

ReproductorMusica::~ReproductorMusica() {
	for(int i = 0; i < this->canciones.size(); i++) {
		delete canciones.at(i);
	}
	for(int i = 0; i < this->albumes.size(); i++) {
		delete albumes.at(i);
	}
	for(int i = 0; i < this->playlists.size(); i++) {
		delete playlists.at(i);
	}
	for(int i = 0; i < this->generos.size(); i++) {
		delete generos.at(i);
	}
}

void ReproductorMusica::agregarAlbumes(Album* a ) {
	this->albumes.push_back(a);
}

void ReproductorMusica::agregarCanciones(Canciones* c) {
	this->canciones.push_back(c);
}

void ReproductorMusica::agregarGeneros(Genero* g) {
	this->generos.push_back(g);
}

void ReproductorMusica::agregarPlaylist(Playlist* p) {
	this->playlists.push_back(p);
}

vector<Album*> ReproductorMusica::getAlbumes() {
	return this->albumes;
}

vector<Canciones*> ReproductorMusica::getCanciones() {
	return this->canciones;
}

vector<Genero*> ReproductorMusica::getGeneros() {
	return this->generos;
}

vector<Playlist*> ReproductorMusica::getPlaylists() {
	return this->playlists;
}

void ReproductorMusica::listarCanciones() {
	for(int i = 0; i < this->canciones.size(); i++) {
		Canciones* c = new Canciones();
		c = this->canciones.at(i);
		cout<<i<<") "<<c->getNombre()<<" - "<<c->getArtista()<<" Genero: "<<c->getGenero()->getNombre()<<" Duracion: "<<c->getDuracion()<<endl;
	}
}

void ReproductorMusica::listarAlbums() {
	for(int i = 0; i < this->albumes.size(); i++) {
		Album* a = new Album();
		a = this->albumes.at(i);
		cout<<i<<") Nombre: "<<a->getNombre()<<" - "<<a->getArtista()<<endl;
		a->listarCanciones();
		cout<<endl;
	}
}

void ReproductorMusica::listarGeneros() {
	for(int i = 0; i < this->generos.size(); i++) {
		Genero* g = new Genero();
		g = this->generos.at(i);
		cout<<i<<") "<<g->getNombre()<<endl;
	}
}

void ReproductorMusica::listarPlaylists() {
	for(int i = 0; i < this->playlists.size(); i++) {
		Playlist* p = new Playlist();
		p = this->playlists.at(i);
		cout<<i<<") "<<p->getNombre()<<endl;
		p->listarCanciones();
		cout<<endl;
	}
}

void ReproductorMusica::MultAlbum(Album* a,int num) {
	Album* al = new Album();

	al = a->operator *(num);

	Playlist* play = new Playlist(al->getNombre(),al->getCanciones());

	this->playlists.push_back(play);

	cout<<"Playlist: "<<endl;
	cout<<"Nombre: "<<play->getNombre()<<"\nCanciones: "<<endl;
	play->listarCanciones();
}

void ReproductorMusica::CancionAPlaylist(Playlist* play, Canciones* s,int aux) {
	cout<<"cancion que se agrega: "<<s->getNombre()<<endl;

	Playlist* nuevaP = new Playlist();

	nuevaP = play->operator +(s);
	if(aux==1)
		this->playlists.push_back(nuevaP);
	
	play->setListaCanciones(nuevaP->getListaCanciones());
}

void ReproductorMusica::AlbumAPlaylist(Playlist* tempP, Album* tempA) {
	Playlist* nueva = new Playlist();

	nueva = tempP->operator +(tempA);

	this->playlists.push_back(nueva);
}

void ReproductorMusica::CancionAAlbum(Album* album, Canciones* s,int aux) {
	Album* nuevoA = new Album();

	nuevoA = album->operator +(s);

	nuevoA->setArtista(s->getArtista());

	if(aux==1)
		this->albumes.push_back(nuevoA);

	int cont = 0;

	for(int i = 0; i < nuevoA->getCanciones().size(); i++) {
		Canciones* c = new Canciones();
		c = nuevoA->getCanciones().at(i);
		if(c->getArtista()!=s->getArtista()) {
			cont++;
		}
	}

	if(cont>0) {
		album->setArtista("Various Artists");
	}

	album->setListaCanciones(nuevoA->getCanciones());
}

void ReproductorMusica::PlaylistAPlaylist(Playlist* play1,Playlist* play2) {
	Playlist* nueva = new Playlist();

	nueva = play1->operator +(play2);

	this->playlists.push_back(nueva);
}

void ReproductorMusica::PlaylistMenosCancion(Playlist* play, Canciones* c) {
	Playlist* nueva = new Playlist();

	nueva = play->operator -(c);

	play->setListaCanciones(nueva->getListaCanciones());
}

void ReproductorMusica::PlaylistMenosGenero(Playlist* play, Genero* g) {
	Playlist* nueva = new Playlist();

	nueva = play->operator -(g);

	play->setListaCanciones(nueva->getListaCanciones());
}