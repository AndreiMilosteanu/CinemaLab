#include "Admin.h"

Admin::Admin() {

}
Admin::Admin(FilmRepo repo) {
    this->repo = repo;
}
void Admin::addFilm(Film aux) {
    repo.addFilm(aux);
}
void Admin::delFilm(Film aux) {
    repo.delFilm(aux);
}
void Admin::updateErscheinungsJahr(Film aux, int erscheinungsJahr_aux) {
    repo.updateErscheinungsJahr(aux,erscheinungsJahr_aux);
}
void Admin::updateTitel(Film aux, string film_aux) {
    repo.updateTitel(aux, film_aux);
}
void Admin::updateLikes(Film aux, double likes_aux) {
    repo.updateLikes(aux,likes_aux);
}
void Admin::updateGenre(Film aux, string genre_aux) {
    repo.updateGenre(aux,genre_aux);
}
void Admin::updateURL(Film aux, string URL_aux) {
    repo.updateURL(aux,URL_aux);
}
void Admin::printALL() {
    repo.getAll();
}
FilmRepo Admin::getAll() {
    return repo;
}
