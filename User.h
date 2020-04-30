#ifndef LAB5_USER_H
#define LAB5_USER_H

#include <iostream>
#include <vector>
#include "Film.h"
#include "FilmRepo.h"

using namespace std;

class User {
private:
    vector <Film> watchList;
    FilmRepo filmRepo;
public:
    User();

    User(FilmRepo FilmRepo);

    //returneaza watchList-ul
    std::vector <Film> getWatchList();

    //seteaza watchlist-ul
    void setWatchList(vector <Film> list) ;

    //adauga un film in watchList
    void addFilmToWatchList(Film _film);

    //sterge un film din watchlist
    void removeFilmFromWatchList(Film _film);

    //printeaza watchList-ul
    void showWatchList();

    //adauga un like filmului
    void like(Film _film);

    // Searches for the film in the watchlist
    //cauta filmul in watchList
    bool search_film(Film _film) ;

    //returneaza adresa din FilmRepo a atriubutului
    FilmRepo& getFilmRepo();
};

#endif //LAB5_USER_H
