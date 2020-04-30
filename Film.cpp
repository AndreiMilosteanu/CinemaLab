#include "Film.h"

Film::Film(string Titel, string Genre, int ErscheinungsJahr, double Likes, string URL){
    this->Titel = Titel;
    this->Genre = Genre;
    this->ErscheinungsJahr = ErscheinungsJahr;
    this->Likes = Likes;
    this->URL = URL;
}
bool operator==(Film f1, Film f2) {
    return (f1.getTitel() == f2.getTitel() && f1.getErscheinungsJahr() == f2.getErscheinungsJahr() && f1.getURL() == f2.getURL());
}
void Film::printFilm() {
    cout<<this->Titel<<" "<<this->Genre<<" "<<this->ErscheinungsJahr<<" "<<to_string(this->Likes)<<endl;
}