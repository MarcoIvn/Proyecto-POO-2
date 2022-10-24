#pragma once
#include <iostream>

using namespace std;

class Video{
    protected:
        int id;
        string nombre;
        int duracion;
        string genero;
        float rating;
        int raters;
    public:
        Video();
        Video(int,string,int,string,float,int);
        virtual string toString() = 0;
        void setRating(int);
        string getNombre();
        virtual float getRating();
        virtual int getRaters();
        void setRating(float);
        void setRaters(int);
        string getGenero();

};