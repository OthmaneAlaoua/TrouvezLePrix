#include "menu.h"

#include <iostream>

using namespace std;

ChoixMenu demanderChoixMenu() {
    char saisieChoix;
    cin >> saisieChoix;
    if(saisieChoix == static_cast<char>(ChoixMenu::JOUER) || saisieChoix == static_cast<char>(ChoixMenu::AFFICHER_SCORES)
       || saisieChoix == static_cast<char>(ChoixMenu::QUITTER)) {
        return static_cast<ChoixMenu>(saisieChoix);
    } else {
        return ChoixMenu::INCORRECT;
    }
}

void afficherMenu() {
    cout << static_cast<char>(ChoixMenu::JOUER) << " : jouer" << endl;
    cout << static_cast<char>(ChoixMenu::AFFICHER_SCORES) << " : afficher les scores" << endl;
    cout << static_cast<char>(ChoixMenu::QUITTER) << " : quitter" << endl;
}
