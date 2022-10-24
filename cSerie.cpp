#include "cSerie.h"

Serie::Serie(){ 
    nombre = "";
    genero = "";
    rating = 0;
    raters = 0;

}

Serie::Serie(string _nombre,vector<Episodio*> _episodios,string _genero, float _rating,int _raters){
    nombre = _nombre;
    episodios = _episodios;
    rating = _rating;
    genero = _genero;
    raters = _raters;
}

string Serie::toString(){
    string txt;
    txt = "Nombre: " + nombre + "   ";
    txt += "Numero de espisodios: " + to_string(episodios.size()) + "   ";
    txt += "Genero: " + genero + "   ";
    txt += "Rating : " + to_string(rating) + "   ";
    txt += "Raters: " + to_string(raters) + "   ";
    return txt;
}

float Serie::calcularRating(){
    vector<Episodio*>::iterator it;
    Episodio* e = new Episodio();
    float promRating = 0;
    for(it = episodios.begin(); it != episodios.end();it++){
        promRating = *e + *(*it);
        e->setRating(promRating);
    }
    return ((e->getRating()) / episodios.size());
}

int Serie::calcularRaters(){
    vector<Episodio*>::iterator it;
    Episodio* e = new Episodio();
    int sumRaters = 0;
    for(it = episodios.begin(); it != episodios.end();it++){
        sumRaters = *e % *(*it);
        e->setRaters(sumRaters);
    }
    return e->getRaters();
}

string Serie::getNombre(){
    return nombre;
}

vector<Episodio*> Serie::getEpisodios(){
    return episodios;
}

void Serie::setRating(float _rating){
    rating = _rating;
}

void Serie::setRaters(int _raters){
    raters = _raters;
}

void Serie::setEpisodios(vector<Episodio*> _episodios){
    episodios = _episodios;
}

string Serie::getGenero(){
    return genero;
}



