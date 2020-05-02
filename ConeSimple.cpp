#include "ConeSimple.hpp"
#include <cmath>
#include "matrice33.hpp"
using std::endl;

std::ostream& ConeSimple::affiche(std::ostream& sortie) const{
    /*Cette fonction sert à surcharger l'opérateur d'affichage << comme demandé*/
    sortie << "Cone Simple " << endl;
    Toupie::affiche(sortie);
     sortie << "masse volumique (kg. m-3) : " << masse_volumique_ << endl
     << "hauteur (m) : " << hauteur_ << endl
     << "rayon (m) : " << rayon_ << endl;
    return sortie;
}

Vecteur ConeSimple::f() {
    /*Cette méthode sert à calculer les dérivées secondes des angles de la toupie, qui sont des attributs de cette dernière.
    Nous avons choisi de créer des variables locales afin d'augmenter la lisibilité du code, et avons suivi les formules données
    par le complément mathématique.*/
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
    
    if ( std::abs(theta) <= 0.001) {
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

const double ConeSimple::energie_totale() const{
    double IA1 = moment_dinertie1 + masse * centre_de_masse * centre_de_masse;
    double theta = parametres.get_vecteur()[1];
    double psi_point = derivees.get_vecteur()[0];
    double theta_point = derivees.get_vecteur()[1];
    double phi_point = derivees.get_vecteur()[2];
    double theta_derivee_seconde = ((1/IA1)*(masse* g.norme()*centre_de_masse*sin(theta)+ psi_point * sin(theta) * (( IA1 - moment_dinertie3 ) * psi_point * cos(theta) - moment_dinertie3 * phi_point )));
    Vecteur w({theta_point, phi_point * sin(theta), psi_point*cos(theta+ phi_point)});
    Vecteur LA({0.0, 0.0, 0.0});

    double Energie = 0.5 * w * LA - masse * g.norme() * centre_de_masse;
    return Energie;
}

Vecteur ConeSimple::f_generale(){
    double d = centre_de_masse;
    double IA1 = moment_dinertie1 + masse * d * d;
    double IA3 = moment_dinertie3;
    double MA1 = 0; // non
    double MA2 = 0; //non
    double MA3 = 0; //non

  
    double psi_point = derivees.get_vecteur()[0];
    double psi = parametres.get_vecteur()[0];
    double theta = parametres.get_vecteur()[1];
    double theta_point = derivees.get_vecteur()[1];
    double phi_point = derivees.get_vecteur()[2];
    double phi = parametres.get_vecteur()[2];


    Vecteur omega({theta_point*cos(psi_point) + phi_point*sin(psi)*sin(theta), theta_point*sin(psi) - phi_point*cos(psi)*sin(theta), psi_point + phi_point*cos(theta)}); // vecteur omega :: w
    double a = (3.0/4.0)*hauteur_;
    Vecteur OG({sin(theta)*sin(psi)*a, -sin(theta)*cos(psi)*a, cos(theta)*a});

    Matrice33 IO(moment_dinertie1+ masse*(9.0/16.0)*hauteur_*hauteur_, moment_dinertie1+ masse*(9.0/16.0)*hauteur_*hauteur_, moment_dinertie3);
    
    Vecteur LO = IO*omega;
    Vecteur ez({0,0,1.0});
    Vecteur ey({0,1.0,0});
    Vecteur ex({1.0,0,0});

    
    double LO_projection_k = ez * LO;
    double LO_projection_a(ex*LO*sin(theta)*sin(psi) -sin(theta)*cos(psi)*ey*LO + cos(theta)*ez*LO);
    Vecteur MA(OG^(masse*g));

    double theta_point_point = (1.0/IA1) * MA1 + psi_point*sin(theta) * ((IA1 - IA3) * psi_point * cos(theta - IA3 * phi_point));
    double psi_point_point = (1.0/IA1*sin(theta)) * (MA2 + theta_point *((IA3 - IA1) * psi_point*cos(theta) +IA3*phi_point))- psi_point*theta_point*(1/tan(theta));
    double phi_point_point = (MA3/IA3) + (psi_point*theta_point)/sin(theta) - ((MA2 + theta_point*((IA3-IA1)*psi_point*cos(theta) + IA3 * phi_point))/IA1) * (1/tan(theta));

    Vecteur derivees_secondes({theta_point_point, psi_point_point, phi_point_point});
    return derivees_secondes;

}

