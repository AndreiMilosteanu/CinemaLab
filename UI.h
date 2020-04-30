#ifndef LAB5_UI_H
#define LAB5_UI_H

#include "User.h"
#include "Admin.h"
#include <vector>

using namespace std;

class Ui {

private:
    vector <User> userList;
    Admin admin;
    User user;
public:
    //Constructorul, unde adminul si userul vor fi treimisi ca parametrii
    Ui(Admin _admin, User _user);

    //Meniul principal de unde se poate alege intre utilizator sau administrator
    void ui_main();

    //Modul Utilizator
    User userActions();

    //Modul admin
    Admin adminActions();

    User filmGenre();

    User deleteAndRate();
};

#endif //LAB5_UI_H
