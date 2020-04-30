#include "User.h"
#include "Film.h"

using namespace std;


User::User() {

}


User::User(FilmRepo repo) {
    filmRepo = repo;
}


std::vector<Film> User::getWatchList(){
    return watchList;
}


void User::setWatchList(vector <Film> _list)  {
    watchList = _list;
}


FilmRepo& User::getFilmRepo() {
    return this->filmRepo;
}


void User::addFilmToWatchList(Film _film) {
    bool found = false;

    for (int i = 0; i < watchList.size() && !found; i++)
        //verifica daca filmul exista in watchList
        if (_film.getTitel() == watchList[i].getTitel() && _film.getErscheinungsJahr() == watchList[i].getErscheinungsJahr())
            found = true;

    if (found)
        cout << "\tFilmul " << _film.getTitel() << " exista oricum deja\n";
    else
        //aici filmul va fi adaugat daca nu exista
        watchList.push_back(_film);
}


void User::removeFilmFromWatchList(Film _film) {
    bool found = false;
    for (int i = 0; i < watchList.size() && found == false; i++)
        //verifica daca filmul exista in watchList
        if (_film.getTitel() == watchList[i].getTitel() && _film.getErscheinungsJahr() == watchList[i].getErscheinungsJahr()) {
            found = true;
            watchList.erase(watchList.begin() + i);
            //filmul va fi sters
            return;
        }
    cout << "\tFilmul " << _film.getTitel() << " nu exista oricum\n";
}


void User::showWatchList(){
    //printeaza toate filmele
    for(int i = 0; i < watchList.size(); i++)
        watchList[i].printFilm();
    ;
}


bool User::search_film(Film _film)
{
    //functia returneaza true daca filmul exista in watchList
    for (int i = 0; i < watchList.size(); i++)
        if (_film.getTitel() == watchList[i].getTitel() && _film.getErscheinungsJahr() == watchList[i].getErscheinungsJahr())
            return true;
    return false;
}


void User::like(Film _film){
    filmRepo.updateLikes(_film, _film.getLikes() + 1);
    //adauga un like filmului
}