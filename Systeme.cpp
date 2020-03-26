#include "Systeme.hpp"
#include <memory>
#include <vector>
#include "Toupieh.h"
std::ostream& operator<<(std::ostream& sortie, const std::vector<std::unique_ptr<Toupie>>& systeme) {
    for( auto const& element : systeme ) {
        element->affiche(sortie);
    }
    return sortie;
}