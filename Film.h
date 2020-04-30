#ifndef LAB5_FILM_H
#define LAB5_FILM_H

#include <iostream>
using namespace std;

class Film{
private:
    string Titel, Genre, URL;
    int ErscheinungsJahr;
    double Likes;
public:
    /*
     * constructor
     */
    Film(string Titel, string Genre, int ErscheinungsJahr, double Likes, string URL);
    string getTitel(){ return Titel;}
    string getGenre(){ return Genre;}
    string getURL(){ return URL;}
    int getErscheinungsJahr(){ return ErscheinungsJahr;}
    double getLikes(){return Likes;}
    void setTitel(string aux){Titel = aux;}
    void setGenre(string aux){Genre = aux;}
    void setURL(string aux){URL = aux;}
    void setErscheinungsJahr(int aux){ErscheinungsJahr = aux;}
    void setLikes(double aux){Likes = aux;}
    void printFilm();
    /*
     * operator pentru a verifica daca doua filme sunt identice
     * (daca au acealasi titlu, an de aparitie si acelasi trailer inseamca ca sunt identice)
     */
    friend bool operator ==(Film f1, Film f2);
};
#endif //LAB5_FILM_H
