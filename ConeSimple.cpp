#include "ConeSimple.hpp"
#include <cmath>
#include "matrice33.hpp"
using namespace std;
using std::endl;
using std::cout;

std::ostream& ConeSimple::affiche(std::ostream& sortie) const{
    sortie << "Cone Simple " << endl;
    Toupie::affiche(sortie);
     sortie << "masse volumique (kg. m-3) : " << masse_volumique_ << endl
     << "hauteur (m) : " << hauteur_ << endl
     << "rayon (m) : " << rayon_ << endl;
    return sortie;
}

Vecteur ConeSimple::f() {
    double IA1 = (masse*((3.0/20.0)*rayon_*rayon_+(3.0/5.0)*hauteur_*hauteur_));
    double theta = parametres.get_vecteur()[1];
    double psi_point = derivees.get_vecteur()[0];
    double theta_point = derivees.get_vecteur()[1];
    double phi_point = derivees.get_vecteur()[2];
    double theta_derivee_seconde = ((1/IA1)*(masse* g.norme()*centre_de_masse*sin(theta)+ psi_point * sin(theta) * (( IA1 - moment_dinertie3 ) * psi_point * cos(theta) - moment_dinertie3 * phi_point )));

    Matrice33 IA(masse*((3.0/20.0)*rayon_*rayon_+(3.0/5.0)*hauteur_*hauteur_), 0, 0 ,0, masse * (9.0/16.0) * hauteur_ * hauteur_, 0, 0, 0, (3.0/10.0) * masse * rayon_* rayon_);
    Vecteur force_poids( { 0 , - masse * g.norme() * sin(theta) , - masse * g.norme() * cos(theta)} );
    Vecteur AG( { 0, 0, centre_de_masse} );
    Vecteur MA(AG ^ force_poids);
    Vecteur w({theta_point, phi_point * sin(theta), psi_point*cos(theta+ phi_point)});
    Vecteur w_point;
    Vecteur biz({0, 0, phi_point});
    w_point = IA.inv() * ( MA - (w - biz)^( IA * w));
    
    if ( abs(theta) <= 0.001) {
        double psi_derivee_seconde = 0;
        double phi_derivee_seconde = w_point.get_vecteur()[2];
    Vecteur v({psi_derivee_seconde, theta_derivee_seconde, phi_derivee_seconde});
    return v;
    } else {
       // double psi_derivee_seconde = (w_point.get_vecteur()[1] - psi_point * theta_point * cos(theta) / sin(theta));
        //double phi_derivee_seconde = (w_point.get_vecteur()[2] + (psi_point * theta_point - w_point.get_vecteur()[2]* cos(theta)) / sin(theta));

        double psi_derivee_seconde = ((theta_point / (IA1 * sin(theta))) * ( ( moment_dinertie3 - 2 * IA1) * psi_point * cos(theta) + moment_dinertie3 * phi_point));
        double phi_derivee_seconde = (((theta_point / (IA1 * sin(theta))) * ( ((( ( IA1 - ( moment_dinertie3 - IA1) * cos(theta) * cos(theta) ) ) * psi_point) - moment_dinertie3 * phi_point * cos(theta)))));
        
        Vecteur v({psi_derivee_seconde , theta_derivee_seconde , phi_derivee_seconde});
        

        return v;

    }
}
