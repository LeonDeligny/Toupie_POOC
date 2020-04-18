#pragma once
#ifndef Systeme_hpp
#define Systeme_hpp

#include <cstdio>
#include "Integrateur.h"

class Systeme : public Dessinable{
private:
    std::vector<std::unique_ptr<Toupie>> ensemble;
    Integrateur* integrateur;
public:
    Systeme(SupportADessin* supp, Integrateur* i1)
    : Dessinable(supp), integrateur(i1) {}

    void ajoute(const Toupie& satourne) {
        ensemble.push_back(satourne.copie());
        //La méthode copie() retourne un unique_ptr entre autre pour cette méthode.
    }

    const std::unique_ptr<Toupie>& get_spinning_top(size_t k) const {return ensemble[k];}
    size_t get_taille() const {return ensemble.size();}
    //Ces deux méthodes sont nécessaires au fonctionnement de textviewer.

    void dessine() override { support->dessine(*this); }

    void evolue();

};

std::ostream& operator<<(std::ostream& sortie, const std::vector<std::unique_ptr<Toupie>>& systeme);

#endif /* Systeme_hpp */
