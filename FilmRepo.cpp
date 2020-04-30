#include "FilmRepo.h"
using namespace std;

bool FilmRepo::findFilm(Film aux) {
    for(int i=0;i<filme.size();i++)
        if(filme[i] == aux)
            return true;
    return false;
}

void FilmRepo::addFilm(Film aux) {
    if(findFilm(aux))
        cout<<"Filmul exista deja, nu a fost aduagat nimic in lista!"<<endl;
    else
        filme.push_back(aux);
}
void FilmRepo::delFilm(Film aux) {
    if(!findFilm(aux))
        cout<<"Filmul cautat nu exista in lista data!"<<endl;
    else
        for(int i=0;i<filme.size();i++)
            if(filme[i] == aux) {
                filme.erase(filme.begin() + i);
                cout << "Filmul a fost sters cu succes!" << endl;
                break;
            }
}
void FilmRepo::updateTitel(Film aux, string titel_aux) {
    if(!findFilm(aux))
        cout<<"Filmul cautat nu exista in lista data!"<<endl;
    else
    {
        for(int i=0;i<filme.size();i++)
            if(filme[i] == aux) {
                aux.setTitel(titel_aux);
                if (findFilm(aux)){
                    cout << "Filmul nu poate fi actualizat pentru ca mai exista un film identic" << endl;
                } else{
                    cout<<"Filmul a fost actualizat cu succes!";
                    filme[i].setTitel(titel_aux);
                }
                break;
            }
    }
}
void FilmRepo::updateURL(Film aux, string URL_aux) {
    if(!findFilm(aux))
    cout<<"Filmul cautat nu exista in lista data!"<<endl;
    else {
        for (int i = 0; i < filme.size(); i++)
            if (filme[i] == aux) {
                aux.setURL(URL_aux);
                if (findFilm(aux)) {
                    cout << "Filmul nu poate fi actualizat pentru ca mai exista un film identic" << endl;
                } else {
                    cout << "Filmul a fost actualizat cu succes!";
                    filme[i].setURL(URL_aux);
                }
                break;
            }
    }
}
void FilmRepo::updateErscheinungsJahr(Film aux, int ErscheingunsJahr_aux) {
    if(!findFilm(aux))
        cout<<"Filmul cautat nu exista in lista data!"<<endl;
    else {
        for(int i = 0; i < filme.size(); i++)
            if (filme[i] == aux) {
                aux.setErscheinungsJahr(ErscheingunsJahr_aux);
                if (findFilm(aux)) {
                    cout << "Filmul nu poate fi actualizat pentru ca mai exista un film identic" << endl;
                } else {
                    cout << "Filmul a fost actualizat cu succes!";
                    filme[i].setErscheinungsJahr(ErscheingunsJahr_aux);
                }
                break;
            }
    }
}
void FilmRepo::updateGenre(Film aux, string Genre_aux) {
    if(!findFilm(aux))
        cout<<"Filmul nu exista in lista data!"<<endl;
    else{
        for(int i=0;i<filme.size();i++)
            if(filme[i] == aux) {
                filme[i].setGenre(Genre_aux);
                cout << "Filmul a fost actualizat cu succes!" << endl;
                break;
            }
    }
}
void FilmRepo::updateLikes(Film aux, double likes_aux) {
    if(!findFilm(aux))
        cout<<"Filmul nu exista in lista data!"<<endl;
    else{
        for(int i=0;i<filme.size();i++)
            if(filme[i] == aux) {
                filme[i].setLikes(likes_aux);
                cout << "Filmul a fost actualizat cu succes!" << endl;
                break;
            }
    }
}
void FilmRepo::getAll() {
    for(int i=0;i<filme.size();i++)
        filme[i].printFilm();
}
vector<Film> FilmRepo::getGenre(string Genre) {
    vector<Film> aux;
    for(int i=0;i<filme.size();i++)
        if(filme[i].getGenre() == Genre)
            aux.push_back(filme[i]);
    return aux;
}

std::vector<Film> FilmRepo::getFilme() const {
    return filme;
}