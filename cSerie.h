#pragma once
#include <iostream>
#include "cVideo.h"
#include "cEpisodio.h"
#include <vector>
using namespace std;


class Serie{
    private:
        string nombre;
        vector<Episodio*> episodios;
        string genero;
        float rating;
        int raters;
    public:
        Serie();
        Serie(string,vector<Episodio*>,string, float,int);
        string toString();
        float calcularRating();
        int calcularRaters();
        vector<Episodio*> getEpisodios();
        void setEpisodios(vector<Episodio*>);
        string getNombre();
        void setRating(float);
        void setRaters(int);
        string getGenero();
};