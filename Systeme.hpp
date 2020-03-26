//
//  Systeme.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Systeme_hpp
#define Systeme_hpp

#include <stdio.h>
#include <memory>
#include <iostream>
#include "Toupie.hpp"
#include "Dessinable.hpp"
#include "Integrateur.hpp"
std::ostream& operator<<(std::ostream& cout, std::vector<std::unique_ptr<Toupie>> systeme);

class Systeme : public Dessinable {
private:
    std::vector<std::unique_ptr<Toupie>> systeme;
    Integrateur* i;
public:
    Systeme(SupportADessin* s, std::vector<std::unique_ptr<ConeSimple>> systeme1, Integrateur* i1) : Dessinable(s), systeme(std::move(systeme1)), i(i1) {}
    void ajoute(std::unique_ptr<Toupie> t) {
        systeme.push_back(std::move(t));
    }
    virtual void dessine() {
        std::cout << "OK" << std::endl;
    }

};


#endif /* Systeme_hpp */
