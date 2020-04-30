#ifndef LAB5_FILMREPO_H
#define LAB5_FILMREPO_H

#include "Film.h"
#include <vector>
class FilmRepo{
private:
    vector<Film> filme;
public:
    /*
     * se parcurge vecorul de filme si se returneaza true daca sa gaseste o aparitie, daca nu ,false
     */
    bool findFilm(Film aux);
    /*
     * se cauta filmul in vector
     * daca exista, se afiseaza eroare pe ecran
     * daca nu, se adauga in vector
     */
    void addFilm(Film aux);
    /*
     * se cauta filmul in vector
     * daca se gaseste, se sterge aparitia
     * daca nu, se returneaza eroare
     */
    void delFilm(Film aux);
    /*
     * se cauta filmul care doreste a fi updatat(aux)
     * daca nu se gaseste, se afiseaza eroare
     * daca se gaseste, se verfica daca ar exista doua filme identice in cazul updatarii
     * daca totul este ok, se updateaza si se afiseaza un mesaj
     * daca nu, se afiseaza eroare
     */
    void updateTitel(Film aux, string titel_aux);
    void updateErscheinungsJahr(Film aux, int ErscheingunsJahr_aux);
    void updateLikes(Film aux, double likes_aux);
    void updateURL(Film aux, string URL_aux);
    void updateGenre(Film aux, string Genre_aux);
    /*
     * se printeaza fiecare film din vector
     */
    void getAll();
    /*
     * se returneaza vectorul de filme care apartin genului dorit
     */
    vector<Film> getGenre(string Genre);

    vector<Film> getFilme() const;
};
#endif //LAB5_FILMREPO_H
