#include "ConeSimple.hpp"
#include <cmath>
#include "matrice33.hpp"
using namespace std;

std::ostream& ConeSimple::affiche(std::ostream& sortie) const{
    /*Cette fonction sert à surcharger l'opérateur d'affichage << comme demandé*/
    sortie << "Cone Simple " << endl;
    Toupie::affiche(sortie);
     sortie << "masse volumique (kg. m-3) : " << masse_volumique_ << endl
     << "hauteur (m) : " << hauteur_ << endl
     << "rayon (m) : " << rayon_ << endl;
    return sortie;
}

Matrice33 ConeSimple::IA_repereG() const {
    double IA1(masse*((3.0/20.0)*pow(rayon_,2) + (3.0/5.0)*pow(hauteur_,2)));
    double IA3( (3.0/10.0)*masse*pow(rayon_,2));
    Matrice33 IA(IA1, IA1, IA3);
    return IA;  // matrice d'inertie du cone simple au point (A) = (Origine) dans le repere (G, u, b, a)
}

Vecteur ConeSimple::MA_repereG() const {
    Vecteur MA({masse * g.norme() * AG_repereG() * sin(parametres.get_vecteur()[1]), 0.0, 0.0}); // vecteur du moment au point (A) = (Origine) de la force vect(mg) s'exercant au point G
    return MA;
}

Vecteur ConeSimple::omega_point_repereG() const {
    double psi = parametres.get_vecteur()[0];
    double theta = parametres.get_vecteur()[1];
    Vecteur a({sin(theta)*sin(psi), -sin(theta)*cos(psi), cos(theta)});
    Vecteur ez({0,0,1.0});
    Vecteur omega_e_repereG = omega_repereG() - derivees.get_vecteur()[2] * ez;
    Vecteur w_point_repereG = IA_repereG().inv() * (MA_repereG() - (omega_e_repereG^(IA_repereG()*omega_repereG())));
    return w_point_repereG;
}

Vecteur ConeSimple::omega_repereG() const{
    double theta = parametres.get_vecteur()[1];
    double psi_point = derivees.get_vecteur()[0];
    double theta_point = derivees.get_vecteur()[1];
    double phi_point = derivees.get_vecteur()[2];
    Vecteur w({theta_point, psi_point * sin(theta), psi_point*cos(theta)+ phi_point});
    return w; // vecteur de la rotation instantannée du solide (w) = (omega) dans le repere (G, u, b, a)
}

Vecteur ConeSimple::f(const Vecteur& parametre, const Vecteur& vitesse) {
    /*Cette méthode sert à calculer les dérivées secondes des angles de la toupie, qui sont des attributs de cette dernière.
    Nous avons choisi de créer des variables locales afin d'augmenter la lisibilité du code, et avons suivi les formules données par le complément mathématique.*/
    /*double theta = parametre.get_vecteur()[1];
    
    double psi_point = vitesse.get_vecteur()[0];
    double theta_point = vitesse.get_vecteur()[1];
    double phi_point = vitesse.get_vecteur()[2]; // valeurs nécessaires pour la méthode f
    
    Vecteur ez({0,0,1.0});
    Vecteur ey({0,1.0,0});
    Vecteur ex({1.0,0,0}); // vecteurs unitaires permettant de renvoyer les composantes selon (x, y, z)
    
    double IA1(IA_repereG()*ex*ex); // 1ere (resp. 2eme) ligne et 1ere (resp. 2eme) colonne de la matrice d'inertie du cone simple au point (A) = (Origine) dans le repere (G, u, b, a)
    
    double IA3(IA_repereG()*ez*ez); // 3eme ligne et 3eme colonne de la matrice d'inertie du cone simple au point (A) = (Origine) dans le repere (G, u, b, a)
    
    double MA1( MA_repereG()*ex ); // 1ere composante du vecteur du moment au point (A) = (Origine) de la force vect(mg) s'exercant au point G
    
    double MA2( MA_repereG()*ey ); // 2eme composante du vecteur du moment au point (A) = (Origine) de la force vect(mg) s'exercant au point G
    
    double MA3( MA_repereG()*ez ); // 3eme composante du vecteur du moment au point (A) = (Origine) de la force vect(mg) s'exercant au point G

    double theta_point_point( (1/IA1) * (MA1 + psi_point*sin(theta)*(((IA1-IA3)*psi_point*cos(theta) - IA3*phi_point)) ));
    double psi_point_point(0);
    double phi_point_point(0);

    if( std::abs(theta) <= std::pow(10.0, -6)){
        theta_point_point = (omega_point_repereG() * ex);
        phi_point_point = (omega_point_repereG() * ez);
        Vecteur derivees_secondes({psi_point_point,theta_point_point, phi_point_point});
        return derivees_secondes;
    } else {
        psi_point_point = ( 1/(IA1*sin(theta)) * (MA2 + theta_point*((IA3 - IA1)*psi_point*cos(theta)+IA3*phi_point) ) - psi_point*theta_point*(1/(tan(theta))) );
        phi_point_point = (MA3/IA3 + psi_point*theta_point/sin(theta) - (1/(tan(theta)*IA1)) * ( MA2 + theta_point * ((IA3 - IA1)*psi_point*cos(theta) + IA3*phi_point)));
        Vecteur derivees_secondes({psi_point_point, theta_point_point, phi_point_point});
        return derivees_secondes;
    }*/
    double centre_de_masse = AG_repereG();
    double IA1 = masse * (3.0 / 20.0 * rayon_ * rayon_ + 3.0 / 5.0 * hauteur_ * hauteur_);
    double theta = parametre.get_vecteur()[1];
    double psi_point = vitesse.get_vecteur()[0];
    double theta_point = vitesse.get_vecteur()[1];
    double phi_point = vitesse.get_vecteur()[2];
    double theta_derivee_seconde = (1 / IA1) * (masse * g.norme() * centre_de_masse * sin(theta) + psi_point
                                    * sin(theta) * ((IA1 - moment_dinertie3) * psi_point *
                                      cos(theta) - moment_dinertie3 * phi_point));

    Matrice33 IA(masse*(3.0 / 20.0 * rayon_ * rayon_ + 3.0 / 5.0 * hauteur_ * hauteur_), 0, 0 ,
              0, masse * (9.0 / 16.0) * hauteur_ * hauteur_, 0, 0, 0,
              (3.0 / 10.0) * masse * rayon_ * rayon_);
    Vecteur force_poids( { 0 , - masse * g.norme() * sin(theta) , - masse * g.norme() * cos(theta)} );
    Vecteur AG( { 0, 0, centre_de_masse} );
    Vecteur MA(AG ^ force_poids);
    Vecteur w({theta_point, phi_point * sin(theta), psi_point*cos(theta+ phi_point)});
    Vecteur w_point;
    Vecteur biz({0, 0, phi_point});
    w_point = IA.inv() * ( MA - (w - biz)^( IA * w));
    double psi_derivee_seconde(0);
    double phi_derivee_seconde(0);

    if ( std::abs(theta) <= 0.001) {
        psi_derivee_seconde = 0;
        phi_derivee_seconde = w_point.get_vecteur()[2];
        Vecteur v({psi_derivee_seconde, theta_derivee_seconde, phi_derivee_seconde});
        return v;
    } else {
        psi_derivee_seconde = (theta_point / (IA1 * sin(theta))) * ((moment_dinertie3 - 2 * IA1)
                                * psi_point * cos(theta) + moment_dinertie3 * phi_point);
        phi_derivee_seconde = theta_point / (IA1 * sin(theta)) * ((IA1 - (moment_dinertie3 - IA1)
                                * cos(theta) * cos(theta)) * psi_point - moment_dinertie3 * phi_point * cos(theta));
        Vecteur v({psi_derivee_seconde, theta_derivee_seconde, phi_derivee_seconde});
        return v;
    }

}

double ConeSimple::AG_repereG() const {
    return ((3.0/4.0)*hauteur_); // distance entre point de contact (A) = (Origine) et centre de masse (G)
}

Vecteur ConeSimple::invariants_du_mouvement() {
    double psi = parametres.get_vecteur()[0];
    double theta = parametres.get_vecteur()[1];
    
    Vecteur ez({0,0,1.0}); // vecteur unitaire qui renvoie la 3e composante d'un vecteur
    
    Matrice33 repereO_repereG( cos(psi), sin(psi), 0.0, -cos(theta)*sin(psi), cos(psi)*cos(theta), sin(theta), sin(theta)*sin(psi), -sin(theta)*cos(psi), cos(theta) ); // matrice de changement de base entre le repere (O, i, j, k) et repere (G, u, b, a)
    
    Matrice33 I_repereG(moment_dinertie1, moment_dinertie1, moment_dinertie3); // matrice d'inertie au point (G) dans le repere (G, u, b, a)
    
    Matrice33 I_translation_repereG(masse*pow(AG_repereG(),2), masse*pow(AG_repereG(),2), 0.0); // matrice de translation dans le repere (G, u, b, a)
    
    Matrice33 IO_repereG = I_repereG + I_translation_repereG; // matrice d'inertie au point (A) = (Origine) dans le repere (G, u, b, a)
    
    Vecteur a_repereO = repereO_repereG.inv() * ez; // valeur du vecteur unitaire a du repere (G, u, b, a) dans le repere (O, i, j, k)
    
    Vecteur OG_repereO = (AG_repereG() * a_repereO); // vecteur (OG) qui va du point (O) = (Origine) au point (G) = (centre de masse) dans le repere (O, i, j, k)
    
    Vecteur LO_repereG = IO_repereG*omega_repereG(); // vecteur du moment cinétique au point (O) = (Origine) dans le repere (G, u, b, a)
    
    Vecteur LO_repereO = repereO_repereG.transp() * LO_repereG; // vecteur du moment cinétique au point (O) = (Origine) dans le repere (O, i, j, k)
    
    double Energie(0.5 * (omega_repereG() * LO_repereG) + masse * (g * OG_repereO));
    
    double LO_projection_k = ez * LO_repereO; // retour de la 3e composante du vecteur du moment cinétique au point (O) qui correspond donc a la projection du moment cinétique selon la direction a du repere (G, u, b, a)
    
    double LO_projection_a = ez * LO_repereG; // retour de la 3e composante du vecteur du moment cinétique au point (O) qui correspond donc a la projection du moment cinétique selon la direction k du repere (O, i, j, k)
    
    double produit_mixte = (ez * ( omega_repereG()^LO_repereG));

    Vecteur invariants_du_mouvement({Energie, LO_projection_k, LO_projection_a, produit_mixte});
    return invariants_du_mouvement;
}
