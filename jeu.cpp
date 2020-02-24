#include "jeu.h"

#include <iostream>
#include <chrono>
#include "constantes.h"

using namespace std;

void demanderProposition(int& proposition) {
    cin >> proposition;
}

int jouerPartie(int leJustePrix) {
    auto proposition{0};
    auto nombreTentatives{0};

    using Duree = std::chrono::duration<double>;

    auto debutPartie = std::chrono::system_clock::now();

    do {
        cout << "Proposition ? ";
        demanderProposition(proposition);
        if(proposition >= BORNE_MIN && proposition < BORNE_MAX) {
            nombreTentatives++;
            if(proposition == leJustePrix) {
                cout << "Bravo !" << endl;
            } else if(proposition > leJustePrix) {
                cout << "C'est moins !" << endl;
            } else {
                cout << "C'est plus !" << endl;
            }
        }
    } while(proposition != leJustePrix && proposition >= BORNE_MIN);

    auto finPartie = std::chrono::system_clock::now();
    auto duree = std::chrono::duration_cast<Duree>(finPartie - debutPartie);

    if(proposition == leJustePrix) {
        cout << "Partie terminée !" << " en " << nombreTentatives << " tentatives" << endl;
        cout << "Durée de la partie : " << duree.count() << "s" << endl;
        if(duree < 30s) {
            cout << "Vous avez gagné !!!" << endl;
        }
    } else {
        cout << "Partie abandonnée..." << endl;
    }

    cout << endl;

    return nombreTentatives;
}

void afficherScores(TableauDeScores& scores) {
    cout << "Dernières parties : " << endl;
    for(auto score : scores) {
        if(score == 0) {
            cout << "-" << endl;
        } else {
            cout << score << " tentatives" << endl;
        }
    }
}
