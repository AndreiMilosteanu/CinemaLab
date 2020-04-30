#include "UI.h"
#include "Admin.h"
#include <iostream>
#include <algorithm>
#include "Valid.h"

using namespace std;


Ui::Ui(Admin _admin, User _user)
{
    admin = _admin;
    user = _user;
}


void Ui::ui_main()
{
    User utilizator;
    Admin administrator;
    string mode = "Selectati actiunea\n"
                  "0. Iesire"
                  "\n1. Utilizator\n"
                  "2. Admin";

    string input;
    cout << mode;
    cout << "\nInput: "; cin >> input;


    //verifica daca datele introduse sunt credibile
    Validation valid;
    while (!valid.validate_inputUI(input))
    {
        cout << "\nInput-ul este gresit, alegeti intre 0, 1 sau 2\n" << mode << "\nInput: "; cin >> input;
    }

    while(true)
    {
        if (input == "1")
        {
            utilizator = userActions();
            cout << mode;
            cout << "\nInput: "; cin >> input;
        }
        if (input == "2")
        {
            administrator = adminActions();
            cout << mode;
            cout << "\nInput: "; cin >> input;
        }
        if (input == "0")
            break;
    }
}

User Ui::userActions()
{
    User utilizator = user;
    string userActions = "1. Arata si adauga un film dupa gen\n"
                         "2. Evalueaza un film si dupa sterge filmul\n"
                         "3. Arata watchList-ul\n"
                         "4. Inchide\n";
    string input;
    while (true)
    {
        cout << "Modul Utilizator\n";
        cout << "\n" << userActions;
        cout << "\nInput: ";
        cin >> input;

        //verifica daca datele introduse sunt credibile
        Validation valid;
        while (!valid.validate_inputUI_user(input))
        {
            cout << "\nInput-ul este gresit, alegeti intre 1, 2, 3 sau 4\n" << userActions << "\nInput: "; cin >> input;
        }

        if (input == "1"){
            utilizator = filmGenre();
        }
        else if (input == "2"){
            utilizator = deleteAndRate();
        }
        else if (input == "3"){
            utilizator.showWatchList();
        }
        else if(input == "4"){
            break;
        }
    }

    return utilizator;
}

User Ui::filmGenre()
{
    //3 Possible operations for searching by genre
    string next = "1.adauga la watchList\n"
                  "2.mai departe\n"
                  "3.inchide\n";

    string genre = "";
    int index = 0;
    cout << "Introduceti genul:";
    cin >> genre;
    //afiseaza toate filmele care apartin aceluiasi gen
    vector <Film> filmeByGenre = user.getFilmRepo().getGenre(genre);
    if(!filmeByGenre.empty())
    {
        filmeByGenre[index].printFilm();
        //deschide browser-ul cu trailer-ul
        system(std::string("start " + filmeByGenre[index].getURL()).c_str());
        while (true)
        {
            string input;
            cout << next;
            cin >> input;

            //verifica daca datele introduse sunt credibile
            Validation valid;
            while (!valid.validate_inputUI_3(input))
            {
                cout << "\nInput-ul este gresit, alegeti intre 1, 2, sau 3\n" << next << "\nInput: "; cin >> input;
            }

            if (input == "1")
            {
                std::vector<Film> v = user.getWatchList();
                Film key = filmeByGenre[index];

                if (std::find(v.begin(), v.end(), key) != v.end())
                {
                    cout<< "Este deja in watchList\n";
                    break;
                }
                user.addFilmToWatchList(filmeByGenre[index]);
                index++;
                cout << "cantitate: " << user.getWatchList().size() << "\n";
            }
            else if (input == "2") {
                if (index == filmeByGenre.size()-1)
                {
                    cout << "\nNu mai sunt filme care sa apartina acestui gen\n";
                    break;
                }
                index++;
                   filmeByGenre[index].printFilm();
                //deschide browser-ul cu trailer-ul
                system(std::string("start " + filmeByGenre[index].getURL()).c_str());

            }
            else if (input == "3")
            {
                break;
            }
        }
    }
    else
        {
        cout << "\nNu exista filme care sa apartina acestui gen, va aparea o lista cu toate filmele disponibile\n";
        user.getFilmRepo().getAll();
    }

    return user;
}

User Ui::deleteAndRate()
{
    string title;
    cout << "Titlul: ";
    cin.ignore();
    getline(cin, title);
    std::vector<Film> v = user.getWatchList();
    Film key = Film("", "", 0, 0, "");
    for (int i = 0; i < user.getFilmRepo().getFilme().size(); i++) {
        if (title == user.getFilmRepo().getFilme()[i].getTitel()) {
            key = user.getFilmRepo().getFilme()[i];
            break;
        }
    }
    if (!(std::find(v.begin(), v.end(), key) != v.end()))
    {
        cout << "Nu este in watchList\n";
    } else{
        // 3 Possible operations, with 3 if statements
        while(true)
        {
            cout<<"Vreti sa-i lasati un like filmului?\n";
            string input;
            string instructions = "1. Da\n"
                                  "2. Doar sterge\n"
                                  "3. Inchide\n"
                                  "Input: ";
            cout << instructions;
            cin >> input;

            //verifica daca datele introduse sunt credibile
            Validation valid;
            while (!valid.validate_inputUI_3(input))
            {
                cout << "\nInput-ul este gresit, alegeti intre 1, 2, sau 3\n" << instructions  << "\nInput: "; cin >> input;
            }

            if(input == "1")
            {
                user.like(key);
                admin.updateLikes(key, key.getLikes() + 1);
                user.removeFilmFromWatchList(key);
                break;
            }
            else if (input == "2"){
                user.removeFilmFromWatchList(key);
                break;
            }
            else if(input == "3"){
                break;
            }
        }
    }
    return user;
}

Admin Ui::adminActions()
{
    // infos about the 5 admin operations
    string adminActions = "1. Adauga un film\n"
                          "2. Sterge un film\n"
                          "3. Modifica un film\n"
                          "4. Arata filmele\n"
                          "5. Inchide\n";
    while (true)
    {
        string input;
        cout << "Modul Admin\n";
        cout << "\n" << adminActions;
        cout << "\nInput: ";
        cin >> input;

        //verifica daca datele introduse sunt credibile
        Validation valid;
        while (!valid.validate_inputUI_admin(input))
        {
            cout << "\nInput-ul este gresit, alegeti intre 1, 2, 3, 4 sau 5\n" << adminActions << "\nInput: "; cin >> input;
        }
        if (input == "1"){
            string title;
            string genre;
            double jahr;
            double likes;
            string trailer;
            cout<<"Introduceti titlul: "; cin >> title;
            //verifica daca datele introduse sunt credibile
            Validation valid;
            while (valid.validate_inputUi_number(title))
            {
                cout << "\nInput-ul este gresit, alegeti un nume nenumeric\n" << "\nIntroduceti titlul: "; cin >> title;
            }
            cout<<"Introduceti genul: "; cin >> genre;
            //verifica daca datele introduse sunt credibile
            while (valid.validate_inputUi_number(genre))
            {
                cout << "\nInput-ul este gresit, alegeti un nume nenumeric\n" <<"\nIntroduceti genul: "; cin >> genre;
            }
            cout<<"Introduceti anul: "; cin >> jahr;
            //verifica daca datele introduse sunt credibile
            while(!cin || !valid.validate_inputUi_jahr(jahr))
                {
                if(!cin)
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout<<"Input invalid\n";
                    cout<<"Introduceti anul: "; cin >> jahr;

                } else if (!valid.validate_inputUi_jahr(jahr))
                {
                    cout << "\nInput-ul este gresit, alegeti un numar corect\n" << "\nIntroduceti anul: "; cin >> jahr;
                }
            }
            cout<<"Introduceti numaru de like-uri: "; cin >> likes;
            while(!cin)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout<<"Input invalid\n";
                cout<<"Introduceti numaru de like-uri: "; cin >> likes;
            }
            cout<<"Introduceti trailer-ul : "; cin >> trailer;
            //verifica daca datele introduse sunt credibile
            while (valid.validate_inputUi_number(title))
            {
                cout << "\nInput-ul este gresit, alegeti un URL corect\n" << "\nIntroduceti trailer-ul: "; cin >> trailer;
            }
            Film film = Film(title, genre, jahr, likes, trailer);
            admin.addFilm(film);
        }
            //verifica daca filmul este in repo si il sterge daca exista
        else if (input == "2")
        {
            string title;
            Film film = Film("", "", 0, 0, "");
            cout << "Titlul: ";
            cin.ignore();
            getline(cin, title);
            for (int i = 0; i < admin.getAll().getFilme().size(); i++)
            {
                //verifica daca filmul exista
                if (title == admin.getAll().getFilme()[i].getTitel())
                {
                    film = admin.getAll().getFilme()[i];
                    break;
                }
            }
            if (film.getTitel() == "")
            {
                cout << "Filmul nu a fost gasit\n";
            }
            else
                {
                admin.delFilm(film);
                user.removeFilmFromWatchList(film);
                }

        }
        //verifica daca filmul exista si in caz ca exista, il modifica
        else if (input == "3")
        {
            string title;
            Film film = Film("","",0,0,"");
            cout<<"Titlul: ";cin.ignore(); getline(cin, title);
            for (int i = 0; i < admin.getAll().getFilme().size(); i++)
            {
                //verifica daca filmul exista
                if (title == admin.getAll().getFilme()[i].getTitel())
                {
                    film = admin.getAll().getFilme()[i];
                    break;
                }
            }
            if (film.getTitel() == "")
            {
                cout << "Filmul nu a fost gasit\n";

            }
            while (true)
            {
                string input2;
                //infos for editing a film
                string instrunctions = "Ce vreti sa moddificati?\n"
                                       "1. Titlul\n"
                                       "2. Genul\n"
                                       "3. Anul\n"
                                       "4. Like-urile\n"
                                       "5. Trailer-ul\n"
                                       "Input: ";
                cout << instrunctions;
                cin >> input2;

                // Validating the input
                while (!valid.validate_inputUI_admin(input2))
                {
                    cout << "\nInput-ul este gresit, alegeti intre 1, 2, 3, 4 sau  5\n" << instrunctions << "\nInput: "; cin >> input;
                }

                if (input2 == "1")
                {
                    string title2;
                    cout << "Titlul nou: ";
                    cin.ignore();
                    getline(cin, title2);

                    admin.updateTitel(film, title2);
                    //schimbarea va fi vizibila si daca userul a adaucat filmul in watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setTitel(title2);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "2")
                {
                    string genre;
                    cout << "Genul nou: ";
                    cin.ignore();
                    getline(cin, genre);

                    admin.updateGenre(film, genre);
                    //schimbarea va fi vizibila si daca userul a adaucat filmul in watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setGenre(genre);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "3")
                {
                    double jahr;
                    cout << "An nou: ";
                    cin >> jahr;
                    while(!cin)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout<<"Input invalid\n";
                        cout<<"An nou: "; cin >> jahr;
                    }

                    admin.updateErscheinungsJahr(film, jahr);
                    //schimbarea va fi vizibila si daca userul a adaucat filmul in watchlist
                    if (user.search_film(film)) {
                        user.removeFilmFromWatchList(film);
                        film.setErscheinungsJahr(jahr);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "4")
                {
                    double likes;
                    cout << "Like-uri: ";
                    cin >> likes;
                    while(!cin)
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout<<"Input invalid\n";
                        cout<<"Like-uri: "; cin >> likes;
                    }

                    admin.updateLikes(film, likes);
                    //schimbarea va fi vizibila si daca userul a adaucat filmul in watchlist
                    if (user.search_film(film))
                    {
                        user.removeFilmFromWatchList(film);
                        film.setLikes(likes);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
                else if (input2 == "5")
                {
                    string trailer;
                    cout << "Trailer nou: ";
                    cin.ignore();
                    getline(cin, trailer);

                    admin.updateURL(film, trailer);

                    //schimbarea va fi vizibila si daca userul a adaucat filmul in watchlist

                    if (user.search_film(film))
                    {
                        user.removeFilmFromWatchList(film);
                        film.setURL(trailer);
                        user.addFilmToWatchList(film);
                    }
                    break;
                }
            }
        }
        // printeaza toate filmele
        else if (input == "4")
        {
            admin.printALL();
        }
        else if(input == "5")
        {
            break;
        }
    }
    return admin;
}