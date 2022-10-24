#pragma once
#include <iostream>
#include "cVideo.h"
using namespace std;


class Episodio:public Video{
    private:
        string titulo;
        int temporada;
        //int calificacion
        //int duracion
        
    public:
        Episodio();
        Episodio(string, int,int,string,int,string,float,int);
        float operator + (Episodio& e){
            float result = rating + e.getRating();
            return result;
        }
        
        int operator % (Episodio& e){
            int result = raters + e.getRaters();
            return result;
        }
        string getTitulo();
        string getGenero();
        float getRating();
        int getRaters();
        void setRating(float _rating);
        void setRaters(int _raters);
        string toString();
        //
};
