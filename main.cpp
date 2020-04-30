#include "FilmRepo.h"
#include "Ui.h"
#include <iostream>

using std::cout;

int main() {
    // Lista cu cele 10 filme este deja adaugata

    Film f1("The Expendables 3", "Action", 2014, 76432, "https://www.youtube.com/watch?v=4xD0junWlFc");
    Film f2("Interstellar", "SF", 2014, 54, "https://www.youtube.com/watch?v=zSWdZVtXT7E");
    Film f3("Rush Hour", "Crime", 1998, 424385, "https://www.youtube.com/watch?v=JMiFsFQcFLE");
    Film f4("Shutter Island", "Mystery", 2010, 1065137, "https://www.youtube.com/watch?v=5iaYLCiq5RM");
    Film f5("Se7en", "Crime", 1995, 1364614, "https://www.youtube.com/watch?v=znmZoVkCjpI");
    Film f6("The Pianist", "Drama", 2002, 2324, "https://www.youtube.com/watch?v=BFwGqLa_oAo");
    Film f7("Joker", "Drama", 2019, 9, "https://www.youtube.com/watch?v=rgXplohCw5o");
    Film f8("Avengers: Endgame", "Action", 2019, 15, "https://www.youtube.com/watch?v=TcMBFSGVi1c");
    Film f9("Suicide Squad", "Action", 2016, 9, "https://www.youtube.com/watch?v=CmRih_VtVAs");
    Film f10("The Wolf of Wall Street", "Biography", 2013, 7, "https://www.youtube.com/watch?v=iszwuX1AK6A");




    FilmRepo filmRepo;
    filmRepo.addFilm(f1);
    filmRepo.addFilm(f2);
    filmRepo.addFilm(f3);
    filmRepo.addFilm(f4);
    filmRepo.addFilm(f5);
    filmRepo.addFilm(f6);
    filmRepo.addFilm(f7);
    filmRepo.addFilm(f8);
    filmRepo.addFilm(f9);
    filmRepo.addFilm(f10);

    User user = User(filmRepo);
    Admin admin = Admin(filmRepo);

    // Utilizatorul incepe cu 2 filme in lista
    user.addFilmToWatchList(f1);
    user.addFilmToWatchList(f2);


    Ui a(admin, user);
    a.ui_main();
}