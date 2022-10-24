#include "cVideo.h"


Video::Video(){
    id = 0;
    nombre = "";
    duracion = 0;
    genero = "";
    rating = 0;  
    raters = 0;
}

Video::Video(int _id, string _nombre, int _duracion, string _genero , float _rating, int _raters){
    id = _id;
    nombre = _nombre;
    duracion = _duracion;
    genero = _genero;
    rating = _rating;
    raters = _raters;
}

void Video::setRating(int _rating){
    rating = _rating;
}

float Video::getRating(){
    return rating;
}

int Video::getRaters(){
    return raters;
}

void Video::setRating(float _rating){
    rating = _rating;
}

void Video::setRaters(int _raters){
    raters = _raters;
}

string Video::getGenero(){
    return genero;
}

string Video::getNombre(){
    return nombre;
}





