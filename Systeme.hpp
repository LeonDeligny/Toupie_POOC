//
//  Systeme.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Systeme_hpp
#define Systeme_hpp


#include <cstdio>
#include "Integrateur.hpp"

class Systeme : public Dessinable{
private:
    std::vector<std::unique_ptr<Toupie>> ensemble;
    Integrateur* integrateur;
public:
    Systeme(SupportADessin* supp, Integrateur* i1)
    : Dessinable(supp), integrateur(i1) {}

    void ajoute(const Toupie& satourne) {
        ensemble.push_back(satourne.copie());
    }

    void dessine() override { support->dessine(*this); }

    void evolue();

};




#endif /* Systeme_hpp */
