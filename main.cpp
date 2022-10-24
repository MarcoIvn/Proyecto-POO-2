
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include "cCatalogo.h"
using namespace std;


int main(){
    Catalogo c("Catalogo.csv");
    int ans;
    float r;
    string s,se;
    while(true){
        cout<<"1. Show the videos (movie or episode) with a specific rating."<<endl;
        cout<<"2. Show the videos (movie or episode) with a specific genre."<<endl;
        cout<<"3. Show the episodes of a specific series with a specific rating."<<endl;
        cout<<"4. Show the movies with a specific rating."<<endl;
        cout<<"5. Rate a video."<<endl;
        cout<<"6. Exit."<<endl;
        cin>>ans;
        switch(ans){
        case 1:
            while(true){
                cout<<"CHOOSE: "<<endl;
                cout<<"1. Movies."<<endl;
                cout<<"2. Episodes."<<endl;
                cout<<"3. Exit."<<endl;
                cin>>ans;
                switch(ans){
                    case 1:
                        cout<<"MOVIE CHOICES"<<endl;
                        c.choicePeliculas();
                        cout<<"Type rating: "<<endl;
                        cin>>r;
                        try{
                            if(r < 0 ) throw "r < 0";
                            else if(r > 5) throw "r > 5";
                            c.mostrarPeliculas(0,r,"");
                        }
                        catch(...){
                            cout<<"Dont type a value for r,lower than 0 or bigger than 5"<<endl;
                        }
                        break;
                    case 2:
                        cout<<"SERIES CHOICES"<<endl;
                        c.choiceSeries();
                        cout<<"Type rating: "<<endl;
                        cin>>r;
                        try{
                            if(r < 0 ) throw "r < 0";
                            else if(r > 5) throw "r > 5";
                            c.mostrarEpisodios(0,r,"");
                        }
                        catch(...){
                            cout<<"Dont type a value for r,lower than 0 or bigger than 5"<<endl;
                        }
                        break;
                    default:
                        break;
                }
                if(ans == 3){
                    break;
                }
            }   
            break;
        case 2:
            while(true){
                cout<<"CHOOSE: "<<endl;
                cout<<"1. Movies."<<endl;
                cout<<"2. Episodes."<<endl;
                cout<<"3. Exit."<<endl;
                cin>>ans;
                switch(ans){
                    case 1:
                        cout<<"GENRE CHOICES: "<<endl;
                        c.choiceGeneros(0);
                        cout<<"Type genre: "<<endl;
                        cin.ignore();
                        getline(cin,s);
                        c.mostrarPeliculas(1,0,s);
                        break;
                    case 2:
                        cout<<"GENRE CHOICES: "<<endl;
                        c.choiceGeneros(1);
                        cout<<"Type genre: "<<endl;
                        cin.ignore();
                        getline(cin,s);
                        c.mostrarEpisodios(1,0,s);
                        break;
                    default:
                        break;
                }
                if(ans == 3){
                    break;
                }
            }   
            break;
        case 3:
            cout<<"SERIES CHOICES"<<endl;
            c.choiceSeries();
            cout<<"Type the name of the serie: "<<endl;
            cin.ignore();
            getline(cin,s);
            cout<<"Type the specific rating: "<<endl;
            cin>>r;
            try{
                if(r < 0 ) throw "r < 0";
                else if(r > 5) throw "r > 5";
                c.mostrarSeries(s,r);
            }
            catch(...){
                cout<<"Dont type a value for r,lower than 0 or bigger than 5"<<endl;
            }
            break;
        case 4:
            cout<<"MOVIE CHOICES"<<endl;
            c.choicePeliculas();
            cout<<"Type the specific rating: "<<endl;
            cin>>r;
            try{
                if(r < 0 ) throw "r < 0";
                else if(r > 5) throw "r > 5";
                c.mostrarPeliculas(0,r,"");
            }
            catch(...){
                cout<<"Dont type a value for r,lower than 0 or bigger than 5"<<endl;
            }
            break;
        case 5:
            while(true){
                cout<<"RATE: "<<endl;
                cout<<"1. Movies."<<endl;
                cout<<"2. Episodes."<<endl;
                cout<<"3. Exit."<<endl;
                cin>>ans;
                switch(ans){
                    case 1:
                        cout<<"MOVIE CHOICES"<<endl;
                        c.choicePeliculas();
                        cout<<"Type the name of the movie"<<endl;
                        cin.ignore();
                        getline(cin,s);
                        cout<<"Type the rating"<<endl;
                        cin>>r;
                        try{
                            if(r < 0 ) throw "r < 0";
                            else if(r > 5) throw "r > 5";
                            c.ratePelicula(s,r);
                        }
                        catch(...){
                            cout<<"Dont type a value for r,lower than 0 or bigger than 5"<<endl;
                        }
                        break;
                    case 2:
                        cout<<"SERIES CHOICES"<<endl;
                        c.choiceSeries();
                        cout<<"Type the name of the Serie"<<endl;
                        cin.ignore();
                        getline(cin,s);
                        c.choiceEpisodios(s);
                        cout<<"Type the title of the episode"<<endl;
                        getline(cin,se);
                        cout<<"Type the rating"<<endl;
                        cin>>r;
                        try{
                            if(r < 0 ) throw "r < 0";
                            else if(r > 5) throw "r > 5";
                            c.rateEpisodio(s,se,r);
                        }
                        catch(...){
                            cout<<"Dont type a value for r,lower than 0 or bigger than 5"<<endl;
                        }
                        break;
                    default:
                        break;
                }
                if(ans == 3){
                    break;
                }
            }
            break;   
        default:
            break;
        }
        if(ans == 6){
            cout<<"GOODBYE"<<endl;
            break;
        }
    }
    return 0;
}
