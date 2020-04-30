#ifndef LAB5_ADMIN_H
#define LAB5_ADMIN_H

#include "FilmRepo.h"
class Admin{
private:
    FilmRepo repo;
public:
    //Un fel de Controller pentru clasa FilmRepo, utilizeaza fuctile implementate in clasa respectiva
    Admin();
    Admin(FilmRepo aux);
    void addFilm(Film aux);
    void delFilm(Film aux);
    void updateTitel(Film aux, string film_aux);
    void updateErscheinungsJahr(Film aux, int erscheinungsJahr_aux);
    void updateLikes(Film aux, double likes_aux);
    void updateGenre(Film aux, string genre_aux);
    void updateURL(Film aux, string URL_aux);
    FilmRepo getAll();
    void printALL();

};
#endif //LAB5_ADMIN_H
