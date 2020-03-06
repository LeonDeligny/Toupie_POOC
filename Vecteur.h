#pragma once
#include <vector>
class Vecteur {
private:
    std::vector<double> vecteur;
public:
    void augmente(double const& valeur);
    void set_coord(size_t const& position, double const& valeur);
    void affiche();
    std::vector<double> get_vecteur() const;
    bool compare(Vecteur const &v) ;
    Vecteur addition(const Vecteur& autre) const;
    Vecteur oppose() const;
    Vecteur soustraction(const Vecteur& autre) const;
    Vecteur mult(const double& autre) const;
    double prod_scal(const Vecteur& autre) const;
    double normeuclide() const;
    double norme2() const;

};

