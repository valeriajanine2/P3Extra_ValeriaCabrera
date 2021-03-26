#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ReproductorMusica.hpp"
#include "Album.hpp"
#include "Canciones.hpp"
#include "Genero.hpp"
#include "Playlist.hpp"


using namespace std;

int main(int argc, char** argv) {
	
	//crear archivos binarios
	ofstream* ofCanciones = new ofstream("canciones.sng",ios::out|ios::binary);
	ofstream* ofGeneros = new ofstream("generos.gnr",ios::out|ios::binary);
	ofstream* ofPlaylists = new ofstream("playlists.plt",ios::out|ios::binary);
	ofstream* ofAlbums = new ofstream("albums.alb",ios::out|ios::binary);
	
	int opcion=0;
	
	ReproductorMusica* reproductor = new ReproductorMusica();
	
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
							if(reproductor->getGeneros().size()!=0){
								string 	nombre, artista, duracion;
								Genero* g = new Genero();
								int index;
								int id;
								cout<<"ID: ";
								cin>>id;
								cout<<"Nombre: ";
								cin>>nombre;
								cout<<"Arista: ";
								cin>>artista;
								reproductor->listarGeneros();
								cout<<"Ingrese el numero del indice del genero: ";
								cin>>index;
								while(index>reproductor->getGeneros().size() || index<0){
									cout<<"El numero ingresado no es un indice de la lista"<<endl;
									cout<<"Ingrese el numero del indice del genero: ";
									cin>>index;
								}//fin de la validacion
								g = reproductor->getGeneros().at(index);
								cout<<"Ingrese la duracion en formato 00:00: ";
								cin>>duracion;
								
								Canciones* song = new Canciones(id,nombre,artista,g,duracion);
								
								reproductor->agregarCanciones(song);
								
								cout<<endl;
								
								
							}else{
								cout<<"No se puede crear una cancion si no hay generos creados"<<endl;
							}
							
							
							break;
						}
						
						case 2:{
							
							//modificar Canciones
							if(reproductor->getGeneros().size()!=0){
								string 	nombre, artista, duracion;
								Genero* g = new Genero();
								int index, i;								
								
								cout<<"Ingrese el numero de la cancion a modificar: ";
								cin>>i;
								while(i>reproductor->getCanciones().size() || i<0){
									cout<<"El numero igresado no es un indice"<<endl;
									cout<<"Ingrese el numero de la cancion a modificar: ";
									cin>>i;
								}//fin de la validacion
								
								cout<<"Nuevo Nombre: ";
								cin>>nombre;
								cout<<"Nuevo Arista: ";
								cin>>artista;
								reproductor->listarGeneros();
								cout<<"Ingrese el numero del indice del genero: ";
								cin>>index;
								while(index>reproductor->getGeneros().size() || index<0){
									cout<<"El numero ingresado no es un indice de la lista"<<endl;
									cout<<"Ingrese el numero del indice del genero: ";
									cin>>index;
								}//fin de la validacion
								cout<<"Ingrese la nueva duracion en formato 00:00: ";
								cin>>duracion;
								
								g = reproductor->getGeneros().at(index);
								
								Canciones* song = new Canciones();
								
								song = reproductor->getCanciones().at(i);
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
							
							if(reproductor->getGeneros().size()!=0){
								
								int index;
								
								cout<<"Ingrese el indice de la cancion que desea eliminar: ";
								cin>>index;
								while(index>reproductor->getCanciones().size() || index<0){
									cout<<"No existe una cancion en ese indice"<<endl;
									cout<<"Ingrese el indice de la cancion que desea eliminar: ";
									cin>>index;
								}
								
								reproductor->getCanciones().erase(reproductor->getCanciones().begin()+index);
								
								cout<<endl;
								
							}else{
								cout<<"No se puede crear una cancion si no hay generos creados"<<endl;
							}
							
							
							break;
						}
						
						case 4:{
							
							//listar Canciones
							
							reproductor->listarCanciones();
							
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
							
							reproductor->agregarGeneros(g);
							
							cout<<endl;
							
							break;
						}
						
						case 6:{
							
							//modificar genero
							
							int index;
							string nombre;
							
							cout<<"Ingrese el numero del genero que desea modificar: ";
							cin>>index;
							while(index>reproductor->getGeneros().size() || index<0){
								cout<<"No existe un genero con ese indice"<<endl;
								cout<<"Ingrese el numero del genero que desea modificar: ";
								cin>>index;
							}
							
							cout<<"Nuevo nombre: ";
							cin>>nombre;
							
							Genero* g = new Genero();
							g = reproductor->getGeneros().at(index);
							g->setNombre(nombre);
							
							cout<<endl;
							
							break;
						}
						
						case 7:{
							
							//eliminar genero
							
							int index;
							
							cout<<"Ingrese el numero del genero que desea eliminar: ";
							cin>>index;
							while(index>reproductor->getGeneros().size() || index<0){
								cout<<"No existe un genero con ese indice"<<endl;
								cout<<"Ingrese el numero del genero que desea eliminar: ";
								cin>>index;
							}
							
							reproductor->getGeneros().erase(reproductor->getGeneros().erase(reproductor->getGeneros().begin()+index));
							
							cout<<endl;
							
							break;
						}
						
						case 8:{
							
							//listar genero
							
							reproductor->listarGeneros();
							cout<<endl;
							
							break;
						}
						
						case 9:{
							
							//listar albumes
							
							reproductor->listarAlbums();
							cout<<endl;
							
							break;
						}
						
						case 10:{
							
							//listar playlists
							
							reproductor->listarPlaylists();
							
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
				
				if(reproductor->getAlbumes().size()!=0){
					
					reproductor->listarAlbums();
				
					int index, num;
					
					cout<<"Ingrese el indice del album que desea utilizar: ";
					cin>>index;
					
					while(index>reproductor->getAlbumes().size() || index<0){
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
					a = reproductor->getAlbumes().at(index);
					
					reproductor->MultAlbum(a,num);
					
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
								
								reproductor->listarCanciones();
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>index;
								
								while(index>reproductor->getCanciones().size() || index<0){
									cout<<"No existe una cancion con ese indice"<<endl;
									cout<<"Ingrese el indice de la cancion que desea agregar: ";
									cin>>index;
								}//fin de la validacion
								
								Playlist* play = new Playlist(nombre);
								Canciones* s = new Canciones();
								s = reproductor->getCanciones().at(index);
								
								reproductor->CancionAPlaylist(play,s,o);
								
								
							}else if(o==0){
								
								int index,in;
								reproductor->listarPlaylists();
								cout<<"Ingrese el indice de la playlist ";
								cin>>index;
								
								Playlist* p = new Playlist();
								p = reproductor->getPlaylists().at(index);
								
								reproductor->listarCanciones();
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>in;
								
								Canciones* s = new Canciones();
								s = reproductor->getCanciones().at(in);
								
								reproductor->CancionAPlaylist(p,s,o);
															
								
							}else{
								cout<<"Lea las instrucciones :)"<<endl;
							}
							
							break;
						}
						
						case 2:{
							
							//agregar album a playlist
							
							int index1,index2;	
							
							reproductor->listarAlbums();
							cout<<"Ingrese el indice del album que desea agregar a la playlist: ";
							cin>>index1;
							
							while(index1>reproductor->getAlbumes().size() || index1<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice del album que desea agregar a la playlist: ";
								cin>>index1;
							}//fin de la validacion
							
							Album* tempA = new Album();
							tempA=reproductor->getAlbumes().at(index1);
							
							reproductor->listarPlaylists();
							cout<<"Ingrese el indice de la playlist que desea agregar: ";
							cin>>index2;
							
							while(index2>reproductor->getPlaylists().size() || index2<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice de la playlist que desea agregar: ";
								cin>>index2;
							}//fin de la validacion
							
							Playlist* tempP = new Playlist();
							tempP = reproductor->getPlaylists().at(index2);
							
							reproductor->AlbumAPlaylist(tempP,tempA);
							
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
								
								reproductor->listarCanciones();
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>index;
								
								while(index>reproductor->getCanciones().size() || index<0){
									cout<<"No existe una cancion con ese indice"<<endl;
									cout<<"Ingrese el indice de la cancion que desea agregar: ";
									cin>>index;
								}//fin de la validacion
								
								Album* album = new Album(nombre);
								Canciones* s = new Canciones();
								s = reproductor->getCanciones().at(index);
								
								reproductor->CancionAAlbum(album,s,o);
								
								
							}else if(o==0){
								
								int index,in;
								reproductor->listarAlbums();
								cout<<"Ingrese el indice del album: ";
								cin>>index;
								
								Album* a = new Album();
								a = reproductor->getAlbumes().at(index);
								
								reproductor->listarCanciones();
								cout<<"Ingrese el indice de la cancion que desea agregar: ";
								cin>>in;
								
								Canciones* s = new Canciones();
								s = reproductor->getCanciones().at(in);
								
								reproductor->CancionAAlbum(a,s,o);
								
								
							}else{
								cout<<"Lea las instrucciones :)"<<endl;
							}
							
							break;
						}
						
						case 4:{
							
							//agregar playlist a playlist
							
							reproductor->listarPlaylists();
							int index1,index2;
							
							cout<<"Ingrese el indice de la primera playlist: ";
							cin>>index1;
							
							while(index1>reproductor->getPlaylists().size() || index1<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice de la primera playlist: ";
								cin>>index1;
							}//fin de la validacion
							
							cout<<"Ingrese el indice de la segunda playlist: ";
							cin>>index2;
							
							while(index2>reproductor->getPlaylists().size() || index2<0){
								cout<<"No existe un album en ese indice"<<endl;
								cout<<"Ingrese el indice de la segunda playlist: ";
								cin>>index2;
							}//fin de la validacion
							
							Playlist* play1 = new Playlist();
							Playlist* play2 = new Playlist();
							
							play1 = reproductor->getPlaylists().at(index1);
							play2 = reproductor->getPlaylists().at(index2);
							
							reproductor->PlaylistAPlaylist(play1,play2);
							
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
							reproductor->listarPlaylists();;
							cout<<"Ingrese el indice de la playlist que desea: ";
							cin>>index1;
							
							Playlist* play = new Playlist();
							play = reproductor->getPlaylists().at(index1);
							
							reproductor->listarCanciones();;
							cout<<"Ingrese el numero de la cancion que desea eliminar: ";
							cin>>index2;
							
							Canciones* c = new Canciones();
							c = reproductor->getCanciones().at(index2);
							
							reproductor->PlaylistMenosCancion(play,c);
							
							break;
						}
						
						case 2:{
							
							int index1, index2;
							reproductor->listarPlaylists();
							cout<<"Ingrese el indice de la playlist que desea: ";
							cin>>index1;
							
							Playlist* play = new Playlist();
							play = reproductor->getPlaylists().at(index1);
							
							reproductor->listarGeneros();
							cout<<"Ingrese el indice del genero que desea: ";
							cin>>index2;
							
							Genero* g = new Genero();
							g = reproductor->getGeneros().at(index2);
							
							reproductor->PlaylistMenosGenero(play,g);
							
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
	
	ofCanciones->close();
	ofGeneros->close();
	ofPlaylists->close();
	ofAlbums->close();
	
	delete reproductor;
	
	return 0;
}