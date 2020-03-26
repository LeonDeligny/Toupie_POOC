//
//  Systeme.cpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#include "Systeme.hpp"
#include <memory>
#include <vector>
#include "Toupie.hpp"
std::ostream& operator<<(std::ostream& sortie, std::vector<std::unique_ptr<Toupie>> systeme) {
    for( auto const& element : systeme ) {
        element->affiche(sortie);
    }
    return sortie;
}
