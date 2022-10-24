#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "cmath"
#include "cVideo.h"
#include "cSerie.h"
#include "cPelicula.h"
using namespace std;

class Catalogo{
    private:
        vector<Video*> videos;
        vector<Serie*> series;
        vector<string> split(string original, string delimiter);
    public:
        Catalogo(string filename);
        void mostrarEpisodios(int,float,string);
        void mostrarPeliculas(int,float, string);
        void mostrarSeries(string, float);
        void setRatingSeries();
        void setRatersSeries();
        bool findSerie(string);
        void ratePelicula(string, float);
        void rateEpisodio(string,string, float);
        void choicePeliculas();
        void choiceSeries();
        void choiceGeneros(int);
        void choiceEpisodios(string);
        string toString();
};