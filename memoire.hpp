//
//  memoire.hpp
//  POO
//
//  Created by Léon Deligny on 30/04/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef memoire_hpp
#define memoire_hpp

#include <stdio.h>
#include "Integrateur.hpp"

class Memoire : public Dessinable{
    private:
        std::vector<std::unique_ptr<Toupie>> ensemble;
        Integrateur* integrateur;
    public:
        Memoire(SupportADessin* supp, Integrateur* i1)
        : Dessinable(supp), integrateur(i1) {}

        void ajoute(const Toupie& satourne) {
            ensemble.push_back(satourne.copie());
        }
        Toupie get_toupie(size_t i) {return *ensemble[i]; }
        size_t get_taille() const {return ensemble.size();}
        void evolue();
        void dessine() override { support->dessine(*this); }

};
#endif /* memoire_hpp */
