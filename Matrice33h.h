#pragma once
#ifndef TOUPIE_MATRICE33H_H
#define TOUPIE_MATRICE33H_H
#include <vector>
#include "Vecteurh.h"

class Matrice33 {
private:
    std::vector<Vecteur_dim3> matrice;
public:
    explicit Matrice33(std::vector<Vecteur_dim3> R) : matrice(std::move(R)) {}
    Matrice33 transp();
    double det() const;
    Matrice33 inv() const;
    std::ostream& affiche_matrice33(std::ostream& sortie) const;
};
std::ostream& operator<<(std::ostream& sortie, Matrice33 const& v);

#endif //TOUPIE_MATRICE33H_H
