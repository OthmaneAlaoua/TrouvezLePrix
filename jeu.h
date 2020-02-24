#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <array>
#include "constantes.h"

using TableauDeScores = std::array<int, NOMBRE_SCORES>;

void demanderProposition(int& proposition);
int jouerPartie(int leJustePrix);
void afficherScores(TableauDeScores& scores);

#endif // JEU_H_INCLUDED
