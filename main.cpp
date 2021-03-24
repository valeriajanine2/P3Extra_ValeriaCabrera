#include <iostream>
#include <string>
#include <vector>
#include "Album.hpp"
#include "Canciones.hpp"
#include "Genero.hpp"
#include "Playlist.hpp"


using namespace std;

void listarGeneros(vector<Genero*> lista){
	for(int i = 0; i < lista.size(); i++){
		Genero* g = new Genero();
		g = lista.at(i);
		cout<<i<<") "<<g->getNombre()<<endl;
	}
}

void listarCanciones(vector<Canciones*> lista){
	for(int i = 0; i < lista.size(); i++){
		Canciones* c = new Canciones();
		c = lista.at(i);
		cout<<i<<") "<<c->getNombre()<<" - "<<c->getArtista()<<" Genero: "<<c->getGenero()->getNombre()<<" Duracion: "<<c->getDuracion()<<endl;
	}
}

void listarAlbumes(vector<Album*> lista){
	for(int i = 0; i < lista.size(); i++){
		Album* a = new Album();
		a = lista.at(i);
		cout<<i<<") Nombre: "<<a->getNombre()<<" - "<<a->getArtista()<<endl;
		a->listarCanciones();
		cout<<endl;
	}
}

void listarPlaylists(vector<Playlist*> lista){
	for(int i = 0; i < lista.size(); i++){
		Playlist* p = new Playlist();
		p = lista.at(i);
		cout<<i<<") "<<p->getNombre()<<endl;
		p->listarCanciones();
		cout<<endl;
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Album* album = new Album();
	Canciones* canciones = new Canciones();
	Genero* genero = new Genero();
	Playlist* playlist = new Playlist();
	
	int opcion=0;
	
	
	vector<Genero*> genres;
	vector<Canciones*> songs;
	vector<Playlist*> playlists;
	vector<Album*> albums;
	
	while(opcion!=5){
		
		cout<<"MENU\n1) Mantenimiento\n2) Sobrecargar el Operador *\n3) Sobrecargar el Operador +\n4) Sobrecargar el Operador -\n5) Salir"<<endl;
		cout<<"Ingrese el numero de la opcion que desea realizar: ";
		cin>>opcion;
		
		
		int opcion2=0;
		
		switch(opcion){
			
			case 1:{
				
				while(opcion2!=11){
				
				
					cout<<"1) Agregar Cancion\n2) Modificar Cancion\n3) Eliminar Cancion\n4) Listar Canciones\n";
					cout<<"5) Agregar Genero\n6) Modificar Genero\n7) Eliminar Genero\n8) Listar Generos\n";
					cout<<"9) Listar Albumes\n10) Listar Playlists\n11) Salir"<<endl;
					cout<<"Ingrese el numero de la opcion que desea realizar: ";
					cin>>opcion2;
					
					
					switch(opcion2){
						case 1:{
							
							//agregar Canciones
							if(genres.size()!=0){
								string 	nombre, artista, duracion;
								Genero* g = new Genero();
								int index;
								
								cout<<"Nombre: ";
								cin>>nombre;
								cout<<"Arista: ";
								cin>>artista;
								listarGeneros(genres);
								cout<<"Ingrese el numero del indice del genero: ";
								cin>>index;
								while(index>genres.size() || index<0){
									cout<<"El numero ingresado no es un indice de la lista"<<endl;
									cout<<"Ingrese el numero del indice del genero: ";
									cin>>index;
								}//fin de la validacion
								g = genres.at(index);
								cout<<"Ingrese la duracion en formato 00:00: ";
								cin>>duracion;
								
								Canciones* song = new Canciones(nombre,artista,g,duracion);
								
								songs.push_back(song);
								
								cout<<endl;
								
								
							}else{
								cout<<"No se puede crear una cancion si no hay generos creados"<<endl;
							}
							
							
							break;
						}
						
						case 2:{
							
							//modificar Canciones
							if(genres.size()!=0){
								string 	nombre, artista, duracion;
								Genero* g = new Genero();
								int index, i;								
								
								cout<<"Ingrese el numero de la cancion a modificar: ";
								cin>>i;
								while(i>songs.size() || i<0){
									cout<<"El numero igresado no es un indice"<<endl;
									cout<<"Ingrese el numero de la cancion a modificar: ";
									cin>>i;
								}//fin de la validacion
								
								cout<<"Nuevo Nombre: ";
								cin>>nombre;
								cout<<"Nuevo Arista: ";
								cin>>artista;
								listarGeneros(genres);
								cout<<"Ingrese el numero del indice del genero: ";
								cin>>index;
								while(index>genres.size() || index<0){
									cout<<"El numero ingresado no es un indice de la lista"<<endl;
									cout<<"Ingrese el numero del indice del genero: ";
									cin>>index;
								}//fin de la validacion
								g = genres.at(index);
								cout<<"Ingrese la nueva duracion en formato 00:00: ";
								cin>>duracion;
								
								Canciones* song = new Canciones();
								
								song = songs.at(i);
								song->setNombre(nombre);
								song->setArtista(artista);
								song->setGenero(g);
								song->setDuracion(duracion);
								
								cout<<endl;
								
							}else{
								cout<<"No se puede crear una cancion si no hay generos creados"<<endl;
							}
							
							break;
						}
						
						case 3:{
							
							//eliminar Canciones
							
							if(genres.size()!=0){
								
								int index;
								
								cout<<"Ingrese el indice de la cancion que desea eliminar: ";
								cin>>index;
								while(index>songs.size() || index<0){
									cout<<"No existe una cancion en ese indice"<<endl;
									cout<<"Ingrese el indice de la cancion que desea eliminar: ";
									cin>>index;
								}
								
								songs.erase(songs.begin()+index);
								
								cout<<endl;
								
							}else{
								cout<<"No se puede crear una cancion si no hay generos creados"<<endl;
							}
							
							
							break;
						}
						
						case 4:{
							
							//listar Canciones
							
							listarCanciones(songs);
							
							cout<<endl;
							
							break;
						}
						
						case 5:{
							
							//crear genero
							int id;
							string nombre;
							cout<<"ID: ";
							cin>>id;
							cout<<"Nombre: ";
							cin>>nombre;
							
							Genero* g = new Genero(id,nombre);
							
							genres.push_back(g);
							
							cout<<endl;
							
							break;
						}
						
						case 6:{
							
							//modificar genero
							
							int index;
							string nombre;
							
							cout<<"Ingrese el numero del genero que desea modificar: ";
							cin>>index;
							while(index>genres.size() || index<0){
								cout<<"No existe un genero con ese indice"<<endl;
								cout<<"Ingrese el numero del genero que desea modificar: ";
								cin>>index;
							}
							
							cout<<"Nuevo nombre: ";
							cin>>nombre;
							
							Genero* g = new Genero();
							g = genres.at(index);
							g->setNombre(nombre);
							
							cout<<endl;
							
							break;
						}
						
						case 7:{
							
							//eliminar genero
							
							int index;
							
							cout<<"Ingrese el numero del genero que desea eliminar: ";
							cin>>index;
							while(index>genres.size() || index<0){
								cout<<"No existe un genero con ese indice"<<endl;
								cout<<"Ingrese el numero del genero que desea eliminar: ";
								cin>>index;
							}
							
							genres.erase(genres.erase(genres.begin()+index));
							
							cout<<endl;
							
							break;
						}
						
						case 8:{
							
							//listar genero
							
							listarGeneros(genres);
							cout<<endl;
							
							break;
						}
						
						case 9:{
							
							//listar albumes
							
							listarAlbumes(albums);
							cout<<endl;
							
							break;
						}
						
						case 10:{
							
							//listar playlists
							
							listarPlaylists(playlists);
							
							break;
						}
						
						case 11:{
							//solo por la validacion
							break;
						}
						
						default: {
							cout<<"Asegurese de ingresar una de las opciones del menu"<<endl;
							break;
						}
					}
				
				}
				
				break;
			}
			
			case 2:{
				
				if(albums.size()!=0){
					
					listarAlbumes(albums);
				
					int index, num;
					
					cout<<"Ingrese el indice del album que desea utilizar: ";
					cin>>index;
					
					while(index>albums.size() || index<0){
						cout<<"No existe un album en ese indice: "<<endl;
						cout<<"Ingrese el indice del album que desea utilizar: ";
						cin>>index;
					}//fin de la validacion
					
					cout<<"Ingrese el numero de veces a multiplicar: ";
					cin>>num;
					
					while(num<=1){
						cout<<"Asegurese que el numero sea mayor de 1";
						cout<<"Ingrese el numero de veces a multiplicar: ";
						cin>>num;
					}
					
					Album* a = new Album();
					a = albums.at(index);
					
					Album* al = new Album();
					
					al = a->operator *(num);
					
					Playlist* play = new Playlist(al->getNombre(),al->getCanciones());
					
					playlists.push_back(play);
					
					cout<<"Playlist: "<<endl;
					cout<<"Nombre: "<<play->getNombre()<<"\nCanciones: "<<endl;
					play->listarCanciones();
					
				}else{
					cout<<"No se han creado albums aun";
				}
				
				break;
			}
			
			case 3:{
				
				int opcion3=0;
				
				while(opcion3!=5){
					
					cout<<"1) Agregar cancion a playlist\n2) Agregar album a playlist\n3) Agregar cancion a album\n4) Unificar Playlists\n5) Salir"<<endl;
					cout<<"Ingrese la opcion que desea realizar: ";
					cin>>opcion3;
					
					switch(opcion3){
						
						case 1:{
							
							//agregar Canciones a playlist
							
							int o;
							
							cout<<"Ingrese 1 si quiere crear una playlist nueva, ingrese 0 si desea usar una playlist existente: ";
							cin>>o;
							
							if(o==1){
								
								string nombre;
								int index;
								cout<<"Ingrese el nombre de la playlist: ";
								cin>>nombre;
								
								listarCanciones(songs);
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>index;
								
								while(index>songs.size() || index<0){
									cout<<"No existe una cancion con ese indice"<<endl;
									cout<<"Ingrese el indice de la cancion que desea agregar: ";
									cin>>index;
								}//fin de la validacion
								
								Playlist* play = new Playlist(nombre);
								Canciones* s = new Canciones();
								s = songs.at(index);
								
								cout<<"cancion que se agrega: "<<s->getNombre()<<endl;
								
								Playlist* nuevaP = new Playlist();
								
								//no me bajes puntos por usarlo como operator en vez de solo el + pleasee :(
								//no lo vimos en clase tenenos compasion hahaha <3
								nuevaP = play->operator +(s);
								
								playlists.push_back(nuevaP);
								
								
							}else if(o==0){
								
								int index,in;
								listarPlaylists(playlists);
								cout<<"Ingrese el indice de la playlist ";
								cin>>index;
								
								Playlist* p = new Playlist();
								p = playlists.at(index);
								
								listarCanciones(songs);
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>in;
								
								Canciones* s = new Canciones();
								s = songs.at(in);
								
								Playlist* temp = new Playlist();
								temp = p->operator +(s);
								
								p->setListaCanciones(temp->getListaCanciones());
								
								
								
								
							}else{
								cout<<"Lea las instrucciones :)"<<endl;
							}
							
							break;
						}
						
						case 2:{
							
							//agregar album a playlist
							
							int index1,index2;	
							
							listarAlbumes(albums);
							cout<<"Ingrese el indice del album que desea agregar a la playlist: ";
							cin>>index1;
							
							while(index1>albums.size() || index1<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice del album que desea agregar a la playlist: ";
								cin>>index1;
							}//fin de la validacion
							
							Album* tempA = new Album();
							tempA=albums.at(index1);
							
							listarPlaylists(playlists);
							cout<<"Ingrese el indice de la playlist que desea agregar: ";
							cin>>index2;
							
							while(index2>playlists.size() || index2<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice de la playlist que desea agregar: ";
								cin>>index2;
							}//fin de la validacion
							
							Playlist* tempP = new Playlist();
							tempP = playlists.at(index2);
							
							Playlist* nueva = new Playlist();
							
							nueva = tempP->operator +(tempA);
							
							playlists.push_back(nueva);
							
							break;
						}
						
						case 3:{
							
							//agregar Canciones a album
							
							int o;
							
							cout<<"Ingrese 1 si quiere crear un album nuevo, ingrese 0 si desea usar un album existente: ";
							cin>>o;
							
							if(o==1){
								
								string nombre;
								int index;
								cout<<"Ingrese el nombre del album: ";
								cin>>nombre;
								
								listarCanciones(songs);
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>index;
								
								while(index>songs.size() || index<0){
									cout<<"No existe una cancion con ese indice"<<endl;
									cout<<"Ingrese el indice de la cancion que desea agregar: ";
									cin>>index;
								}//fin de la validacion
								
								Album* album = new Album(nombre);
								Canciones* s = new Canciones();
								s = songs.at(index);
								
								//cout<<"Canciones que se agrega: "<<s->getNombre()<<endl;
								
								Album* nuevoA = new Album();
								
								//no me bajes puntos por usarlo como operator en vez de solo el + pleasee :(
								//no lo vimos en clase tenenos compasion hahaha <3
								nuevoA = album->operator +(s);
								
								nuevoA->setArtista(s->getArtista());
								
								albums.push_back(nuevoA);
								
								
							}else if(o==0){
								
								int index,in;
								listarAlbumes(albums);
								cout<<"Ingrese el indice del album: ";
								cin>>index;
								
								Album* a = new Album();
								a = albums.at(index);
								
								listarCanciones(songs);
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>in;
								
								Canciones* s = new Canciones();
								s = songs.at(in);
								
								Album* temp = new Album();
								temp = a->operator +(s);
								
								int cont = 0;
								
								for(int i = 0; i < temp->getCanciones().size(); i++){
									Canciones* c = new Canciones();
									c = temp->getCanciones().at(i);
									if(c->getArtista()!=s->getArtista()){
										cont++;
									}
								}
								
								if(cont>0){
									a->setArtista("Various Artists");
								}
								
								a->setListaCanciones(temp->getCanciones());
								
								
								
							}else{
								cout<<"Lea las instrucciones :)"<<endl;
							}
							
							break;
						}
						
						case 4:{
							
							//agregar playlist a playlist
							
							listarPlaylists(playlists);
							int index1,index2;
							
							cout<<"Ingrese el indice de la primera playlist: ";
							cin>>index1;
							
							while(index1>playlists.size() || index1<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice de la primera playlist: ";
								cin>>index1;
							}//fin de la validacion
							
							cout<<"Ingrese el indice de la segunda playlist: ";
							cin>>index2;
							
							while(index2>playlists.size() || index2<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice de la segunda playlist: ";
								cin>>index2;
							}//fin de la validacion
							
							Playlist* play1 = new Playlist();
							Playlist* play2 = new Playlist();
							
							play1 = playlists.at(index1);
							play2 = playlists.at(index2);
							
							Playlist* nueva = new Playlist();
							
							nueva = play1->operator +(play2);
							
							playlists.push_back(nueva);
							
							break;
						}
						
						case 5:{
							//solo por validacion
							break;
						}
						
						default:{
							cout<<"Asegurese de ingresar una de las opciones"<<endl;
							break;
						}
						
					}
					
				}
				
				break;
			}
			
			case 4:{
				
				int opcion4 = 0;
				
				while(opcion4!=3){
					
					cout<<"1) Eliminar Canciones de Playlist\n2) Eliminar Canciones por Genero\n3) Salir"<<endl;
					cout<<"Ingrese el numero de la opcion que desea realizar: ";
					cin>>opcion4;
					
					switch(opcion4){
						case 1:{
							
							int index1, index2;
							listarPlaylists(playlists);
							cout<<"Ingrese el indice de la playlist que desea: ";
							cin>>index1;
							
							Playlist* play = new Playlist();
							play = playlists.at(index1);
							
							listarCanciones(play->getListaCanciones());
							cout<<"Ingrese el numero de la cancion que desea eliminar: ";
							cin>>index2;
							
							Canciones* c = new Canciones();
							c = songs.at(index2);
							
							Playlist* nueva = new Playlist();
							
							nueva = play->operator -(c);
							
							play->setListaCanciones(nueva->getListaCanciones());
							
							break;
						}
						
						case 2:{
							
							int index1, index2;
							listarPlaylists(playlists);
							cout<<"Ingrese el indice de la playlist que desea: ";
							cin>>index1;
							
							Playlist* play = new Playlist();
							play = playlists.at(index1);
							
							listarGeneros(genres);
							cout<<"Ingrese el indice del genero que desea: ";
							cin>>index2;
							
							Genero* g = new Genero();
							g = genres.at(index2);
							
							Playlist* nueva = new Playlist();
							
							nueva = play->operator -(g);
							
							play->setListaCanciones(nueva->getListaCanciones());
							
							break;
						}
						
						case 3:{
							//solo por validacion
							break;
						}
						
						default:{
							cout<<"Asegurese de ingresar una de las opciones del menu"<<endl;
							break;
						}
					}
					
				}
				
				
				break;
			}
			
			case 5:{
				cout<<"Adios, tenga buen dia <3";
				break;
			}
			
			default: {
				cout<<"Asegurese de ingresar una de las opciones del menu"<<endl;
				break;
			}
			
		}//fin del switch
		
		
	}//fin del while principal
	
	
	delete genero;
	delete canciones;
	delete album;
	delete playlist;
	
	for(int i = 0; i < genres.size(); i++){
		delete genres.at(i);
	}
	
	for(int i = 0; i < songs.size(); i++){
		delete songs.at(i);
	}
	
	
	return 0;
}