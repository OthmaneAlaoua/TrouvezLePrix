#include <iostream>
#include <array>
#include <random>
#include "constantes.h"
#include "jeu.h"
#include "menu.h"

using namespace std;

int main() {
    cout << "! Trouvez le bon prix !" << endl;

    auto scores = TableauDeScores{0,0,0};
    auto indiceCourant{0};

    auto generateurAleatoire = std::random_device{};
    auto generateur = mt19937{generateurAleatoire()};
    auto distribution = std::uniform_int_distribution{BORNE_MIN, BORNE_MAX};

    bool continuer{true};
    while(continuer) {
        afficherMenu();
        auto choix = demanderChoixMenu();

        switch(choix) {
        case ChoixMenu::JOUER:
            scores[indiceCourant] = jouerPartie(distribution(generateur));
            indiceCourant = (indiceCourant + 1) % NOMBRE_SCORES;
            break;

        case ChoixMenu::AFFICHER_SCORES:
            afficherScores(scores);
            break;

        case ChoixMenu::QUITTER:
            cout << "Au revoir !" << endl;
            continuer = false;
            break;

        case ChoixMenu::INCORRECT:
        default:
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
