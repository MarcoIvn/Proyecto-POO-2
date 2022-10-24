#include "cCatalogo.h"

Catalogo::Catalogo(string filename){
    vector<string> lines;
	fstream theFile;
    theFile.open(filename, ios::in);
    if(theFile.is_open()){
        string line;
        while(getline(theFile, line)){
            lines.push_back(line);
        }
    }
    lines.erase(lines.begin());
    theFile.close();
    vector<string>::iterator it;
    string videoseparetor = ",";
    for(it = lines.begin(); it != lines.end(); it++){
        vector<string> strvids = split((*it),  videoseparetor); //Vector de strings de una pelicula o serie del csv
        if(strvids[2] == "Pelicula"){
            Pelicula* vid = new Pelicula(stoi(strvids[0]),strvids[1],stoi(strvids[3]), strvids[4],stof(strvids[7]),stoi(strvids[8]));
            videos.push_back(vid);
        }else if(strvids[2] == "Serie"){
            if(findSerie(strvids[1]) == true){
                vector<Serie*>::iterator it;
                for(it = series.begin(); it != series.end();it++){
                    if((*it)->getNombre() == strvids[1]){
                        Episodio* ep = new Episodio(strvids[5],stoi(strvids[6]),stoi(strvids[0]),strvids[1],stoi(strvids[3]),strvids[4],stof(strvids[7]),stoi(strvids[8]));
                        vector<Episodio*> epps = (*it)->getEpisodios();
                        epps.push_back(ep);
                        (*it)->setEpisodios(epps);
                        break;
                    }
                }
            }else{
                vector<Episodio*> epis;
                Episodio* ep = new Episodio(strvids[5],stoi(strvids[6]),stoi(strvids[0]),strvids[1],stoi(strvids[3]),strvids[4],stof(strvids[7]),stoi(strvids[8]));
                epis.push_back(ep);
                Serie* ser = new Serie(strvids[1],epis,strvids[4],0.0,0); 
                series.push_back(ser);
            }
        }
    }
    setRatingSeries();
    setRatersSeries();
}

vector<string> Catalogo::split(string original, string delimiter){
    vector<string> splitted;
    size_t pos = 0;
    while ((pos = original.find(delimiter)) != string::npos){
        string token = original.substr(0, original.find(delimiter));
        original.erase(0, original.find(delimiter) + delimiter.length());
        splitted.push_back(token);
    }
    splitted.push_back(original);
    return splitted;
}

bool Catalogo::findSerie(string _nombre){
    vector<Serie*>::iterator it;
    for(it = series.begin(); it != series.end();it++){
        if((*it)->getNombre() == _nombre){
            return true;
        }
    }
    return false;
}

void Catalogo::setRatingSeries(){
    vector<Serie*>::iterator it;
    for(it = series.begin(); it != series.end();it++){
        (*it)->setRating((*it)->calcularRating());
    }
}

void Catalogo::setRatersSeries(){
    vector<Serie*>::iterator it;
    for(it = series.begin(); it != series.end();it++){
        (*it)->setRaters((*it)->calcularRaters());
    }
}


void Catalogo::mostrarPeliculas(int c, float _rating, string _genero){
    vector<Video*>::iterator it;
    int _drating = round(_rating);
    if(c == 0){
        for(it = videos.begin();it != videos.end();it++){
            if(round((*it)->getRating()) == _drating){
                cout<<(*it)->toString()<<endl;
            }
        }
    }else{
        for(it = videos.begin();it != videos.end();it++){
            if((*it)->getGenero() == _genero){
               cout<<(*it)->toString()<<endl; 
            }
        }
    }  
}


void Catalogo::mostrarEpisodios(int c,float _rating, string _genero){
    vector<Serie*>::iterator it;
    vector<Episodio*>::iterator ite;
    int _drating = round(_rating);
    for(it = series.begin();it != series.end();it++){
        vector<Episodio*> eps = (*it)->getEpisodios(); 
        if(c == 0){
            for(ite = eps.begin();ite != eps.end();ite++){
                if(round((*ite)->getRating()) == _drating){
                    cout<<(*ite)->toString()<<endl;
                }
            }
        }else{
            for(ite = eps.begin();ite != eps.end();ite++){
                if((*ite)->getGenero() == _genero){
                    cout<<(*ite)->toString()<<endl; 
                }
            }
        }  
    }
}

void Catalogo::mostrarSeries(string _nombre, float _rating){
    vector<Serie*>::iterator it;
    vector<Episodio*>::iterator ite;
    int _drating = round(_rating);
    for(it = series.begin();it != series.end();it++){
        if((*it)->getNombre() == _nombre){
            vector<Episodio*> eps = (*it)->getEpisodios(); 
            for(ite = eps.begin();ite != eps.end();ite++){
                if(round((*ite)->getRating()) == _drating){
                    cout<<(*ite)->toString()<<endl; 
                }
            }
        }
    }
}

void Catalogo::ratePelicula(string _nombre,float _rating){
    vector<Video*>::iterator it;
    for(it = videos.begin();it != videos.end();it++){
        if((*it)->getNombre() == _nombre){
            (*it)->setRating(_rating);
            (*it)->setRaters((*it)->getRaters()+1);
        }
    }
}

void Catalogo::rateEpisodio(string _nombre,string _titulo,float _rating){
    vector<Serie*>::iterator it;
    vector<Episodio*>::iterator ite;
    for(it = series.begin();it != series.end();it++){
        if((*it)->getNombre() == _nombre){
            vector<Episodio*> eps = (*it)->getEpisodios();
            for(ite = eps.begin();ite != eps.end();ite++){
                if((*ite)->getTitulo() == _titulo){
                    (*ite)->setRating(_rating);
                    (*ite)->setRaters((*ite)->getRaters()+1);
                }
            }
            (*it)->setEpisodios(eps);
        }
    }
    setRatingSeries();
    setRatersSeries();
}


void Catalogo::choicePeliculas(){
    vector<string> nombrePeliculas;
    vector<Video*>::iterator it;
    vector<string>::iterator its;
    int i = 1;
    for(it = videos.begin(); it != videos.end();it++){
        if(find(nombrePeliculas.begin(), nombrePeliculas.end(),(*it)->getNombre()) != nombrePeliculas.end()){
            //Element found
        }else{
            nombrePeliculas.push_back((*it)->getNombre());
        }
    }
    for(its = nombrePeliculas.begin(); its != nombrePeliculas.end();its++){
        cout<<to_string(i)+ "- " + (*its)<<endl;
        i++;
    }
}



void Catalogo::choiceSeries(){
    vector<string> nombreSeries;
    vector<Serie*>::iterator it;
    vector<string>::iterator its;
    int i = 1;
    for(it = series.begin(); it != series.end();it++){
        if(find(nombreSeries.begin(), nombreSeries.end(),(*it)->getNombre()) != nombreSeries.end()){
            //Element found
        }else{
            nombreSeries.push_back((*it)->getNombre());
        }
    }
    for(its = nombreSeries.begin(); its != nombreSeries.end();its++){
        cout<<to_string(i)+ "- " + (*its)<<endl;
        i++;
    }
}

void Catalogo::choiceEpisodios(string _nombre){
    vector<string> nombreEpisodios;
    vector<Serie*>::iterator it;  
    vector<Episodio*>::iterator ite; 
    vector<string>::iterator its; 
    int i = 1;
    for(it = series.begin(); it != series.end();it++){
        if((*it)->getNombre() == _nombre){
            vector<Episodio*> eps = (*it)->getEpisodios();
            for(ite = eps.begin();ite != eps.end();ite++){
                if(find(nombreEpisodios.begin(), nombreEpisodios.end(),(*ite)->getTitulo()) != nombreEpisodios.end()){
                    //Element found
                }else{
                    nombreEpisodios.push_back((*ite)->getTitulo());
                }
            }  
        }
    }
    for(its = nombreEpisodios.begin(); its != nombreEpisodios.end();its++){
        cout<<to_string(i)+ "- " + (*its)<<endl;
        i++;
    }
}


void Catalogo::choiceGeneros(int _type){
    vector<string> generos;
    vector<Video*>::iterator itp;
    vector<Serie*>::iterator its;
    vector<string>::iterator itg;
    int i = 1;
    // 0 for movies, 1 for series
    if(_type == 0){
        for(itp = videos.begin();itp != videos.end(); itp++){
            if(find(generos.begin(), generos.end(),(*itp)->getGenero()) != generos.end()){
            //Element found
            }else{
                generos.push_back((*itp)->getGenero());
            }
        }
    }else{
        for(its = series.begin();its != series.end(); its++){
            if(find(generos.begin(), generos.end(),(*its)->getGenero()) != generos.end()){
            //Element found
            }else{
                generos.push_back((*its)->getGenero());
            }   
        }
    }
    for(itg = generos.begin(); itg != generos.end();itg++){
        cout<<to_string(i)+ "- " + (*itg)<<endl;
        i++;
    }
}




