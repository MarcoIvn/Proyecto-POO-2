#include "cPelicula.h"

Pelicula::Pelicula():Video(){  
}

Pelicula::Pelicula(int _id, string _nombre, int _duracion, string _genero , float _rating,int _raters):Video(_id, _nombre, _duracion, _genero , _rating,_raters){
}

string Pelicula::toString(){
    string txt;
    txt = "Nombre: " + nombre + "   ";
    txt += "Duracion: " + to_string(duracion) + "   ";
    txt += "Genero: " + genero + "   ";
    txt += "Rating : " + to_string(rating) + "   ";
    txt += "Raters: " + to_string(raters) + "   ";
    return txt;
}


float Pelicula::getRating(){
    return Video::getRating();
}

int Pelicula::getRaters(){
    return Video::getRaters();
}

string Pelicula::getGenero(){
    return Video::getGenero();
}
