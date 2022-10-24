#pragma once
#include <iostream>
#include "cVideo.h"
using namespace std;


class Pelicula:public Video{
    public:
        Pelicula();
        Pelicula(int,string,int,string,float,int);
        string toString();
        string getGenero();
        float getRating();
        int getRaters();
};