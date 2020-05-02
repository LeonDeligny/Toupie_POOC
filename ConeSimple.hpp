#ifndef ConeSimple_hpp
#define ConeSimple_hpp
#include "Toupie.hpp"
#include "Dessinable.hpp"
#include "SupportADessin.hpp"
#include <cmath>
#include <cstdio>
class ConeSimple : public Toupie{
private:
    const double masse_volumique_;
    const double rayon_;
    const double moment_dinertie1;
    const double moment_dinertie3;
    const double centre_de_masse;

public:
    ConeSimple(const Vecteur& parametres, const Vecteur& derivees, const double mv,
               const double hauteur, const double rayon, SupportADessin* support)
            :Toupie(parametres, derivees, 0.33 * M_PI * mv * rayon * rayon * hauteur, hauteur, support, 3),
            masse_volumique_(mv), rayon_(rayon),
             moment_dinertie1((3.0 * masse )/20.0 *(rayon*rayon + 0.25 * hauteur*hauteur)),
             moment_dinertie3( ((3.0*masse)/10.0)*rayon*rayon), centre_de_masse(0.75 * hauteur) { }

    void dessine() override { support->dessine(*this); }
    std::ostream& affiche(std::ostream&) const override;

    std::unique_ptr<ConeSimple> clone() const {return std::make_unique<ConeSimple>(*this);}
    std::unique_ptr<Toupie> copie() const override{return clone();}
    Vecteur f_generale() ;
    const double energie_totale() const;


    Vecteur f() override;
};
#endif /* ConeSimple_hpp */
