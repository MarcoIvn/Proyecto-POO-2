#include "cEpisodio.h"

Episodio::Episodio():Video(){
}

Episodio::Episodio(string _titulo, int _temporada,int _id, string _nombre, int _duracion, string _genero , float _rating, int _raters):Video(_id, _nombre, _duracion, _genero , _rating, _raters){
        titulo = _titulo;
        temporada = _temporada;
}

void Episodio::setRating(float _rating){
    rating = _rating;
}

void Episodio::setRaters(int _raters){
    raters = _raters;
}

float Episodio::getRating(){
    return Video::getRating();
}

int Episodio::getRaters(){
    return Video::getRaters();
}

string Episodio::toString(){
    string txt;
    txt = "Titulo: " + titulo + "   ";
    txt += "Temporada: " + to_string(temporada) + "   ";
    txt += "Serie: " + nombre + "   ";
    txt += "Duracion: " + to_string(duracion) + "   ";
    txt += "Genero: " + genero + "   ";
    txt += "Rating : " + to_string(rating) + "   ";
    txt += "Raters: " + to_string(raters) + "   ";
    return txt;
}

string Episodio::getGenero(){
    return Video::getGenero();
}

string Episodio::getTitulo(){
    return titulo;
}

