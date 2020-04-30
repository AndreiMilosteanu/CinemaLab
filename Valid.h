#ifndef LAB5_VALID_H
#define LAB5_VALID_H
#include <string>

class Validation {
public:
    //valideaza input-ul principal
    bool validate_inputUI(std::string);

    //valideaza input-ul pentru actiunile userului
    bool validate_inputUI_user(std::string);

    //valideaza input-ul pentru actiunile adminului
    bool validate_inputUI_admin(std::string);

    //valideaza input-ul pentru actiunea 1 a userului
    bool validate_inputUI_3(std::string);

    //valideaza input-ul pentru numere
    bool validate_inputUi_number(const std::string& s);

    bool validate_inputUi_jahr(double jahr);


};

#endif //LAB5_VALID_H
