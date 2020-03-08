#include "Vecteur.hpp"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

    void probleme_dimension(string nom_methode) {
        cout << "Problème de dimension avec méthode : " << nom_methode << " : dans fichier : Vecteur.cpp " << endl;
    }
    void probleme_vide(string nom_methode) {
        cout << "Utilisation d'un vecteur vide avec méthode : " << nom_methode << " : dans fichier : Vecteur.cpp " << endl;
    }
    bool Vecteur::compare(Vecteur const &v)const  {
        if ( v.vecteur.size() == vecteur.size() ) {
            for ( size_t i(0); i < vecteur.size(); ++i ) {
                if ( v.vecteur[i] != vecteur[i] ) {
                    return false;
                }
            }
        } else {
            return false;
        }
        return true;
    }
    void Vecteur::augmente(double const& valeur) { vecteur.push_back(valeur); }
    void Vecteur::set_coord(size_t const& position, double const& valeur) {
        if ( vecteur.size() > position ) {
            vecteur[position] = valeur;
        } else {
            size_t m(position - vecteur.size() + 1);
            for (size_t i(0); i < m ; ++i) {
                vecteur.push_back(0);
            }
            vecteur[position] = valeur;
        }
    }
    void Vecteur::affiche() const {
        for (size_t i(0); i < vecteur.size() ; ++i ) {
            cout << vecteur[i] << " ";
        }
    }    

    Vecteur Vecteur::addition(Vecteur const& autre) const {
        Vecteur v_;
        if( vecteur.size() != autre.vecteur.size()) {
            probleme_dimension("addition");
        } else if( vecteur.size() == 0 or autre.vecteur.size() == 0) {
            probleme_vide("soustration");
        } else {
            for ( size_t i(0); i < vecteur.size(); ++i) {
                v_.set_coord(i, autre.vecteur[i] + vecteur[i]);
            }
        }
        return v_;
    }
    Vecteur Vecteur::oppose() const {
       Vecteur v_;
        if ( vecteur.size() == 0 ) {
            probleme_vide("oppose");
        }
        for( size_t i(0); i < vecteur.size(); ++i ) {
                v_.set_coord(i, -vecteur[i]);
        }
        return v_;
    }
    Vecteur Vecteur::soustraction(Vecteur const& autre) const {
        Vecteur v_;
        if( vecteur.size() != autre.vecteur.size() and vecteur.size() != 0) {
            probleme_dimension("soustration");
        } else if ( vecteur.size() == 0 or autre.vecteur.size() == 0) {
            probleme_vide("soustration");
        } else {
            for ( size_t i(0); i < vecteur.size(); ++i) {
                v_.set_coord(i, vecteur[i] - autre.vecteur[i]);
            }
        }
        return v_;
    }
    Vecteur Vecteur::mult(double const& autre) {
        if ( vecteur.size() == 0 ) {
            probleme_vide("mult");
        } else {
            for( size_t i(0); i < vecteur.size(); ++i ) {
                vecteur[i] = autre * vecteur[i];
            }
        }
        return *this;
    }
    double Vecteur::prod_scal(Vecteur const& autre) const {
        double a(0);
        if ( vecteur.size() == 0 or autre.vecteur.size() == 0) {
            probleme_vide("prod_scal");
            return 0;
        } else if (vecteur.size() != autre.vecteur.size()) {
            probleme_dimension("prod_scal");
            return 0;
        } else {
            for(size_t i(0); i < vecteur.size(); ++i ) {
                a += vecteur[i] * autre.vecteur[i];
            }
        }
        return a;
    }
    double Vecteur::norme() const {
        double a(0);
        if ( vecteur.size() == 0) {
            probleme_vide("norme");
            return 0;
        } else {
            for( size_t i(0); i < vecteur.size(); ++i) {
                a += vecteur[i] * vecteur[i];
            }
        }
        return sqrt(a);
    }
    double Vecteur::norme2() const {
        double a(0);
        if ( vecteur.size() == 0) {
            probleme_vide("norme2");
            return 0;
        } else {
            for( size_t i(0); i < vecteur.size(); ++i) {
                a += vecteur[i] * vecteur[i];
            }
        }
        return a;
    }
    Vecteur Vecteur::unitaire() {
        const double n(Vecteur::norme());
        if ( n != 0) {
            for ( int i(0); i < vecteur.size() ; ++i) {
                vecteur[i] = vecteur[i] / n;
            }
        }
        return *this;
    }
    Vecteur Vecteur::prod_vectoriel(Vecteur const& autre )const {
        Vecteur v_;
        if ( autre.vecteur.size() == 3 and vecteur.size() == 3 ) {
            v_.vecteur[0] = vecteur[1] * autre.vecteur[2] - vecteur[2] * autre.vecteur[1];
            v_.vecteur[1] = vecteur[2] * autre.vecteur[0] - vecteur[0] * autre.vecteur[2];
            v_.vecteur[2] = vecteur[0] * autre.vecteur[1] - vecteur[1] * autre.vecteur[0];
        }
        return v_;
    }

