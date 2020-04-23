#pragma once
#ifndef Dessinable_hpp
#define Dessinable_hpp

class SupportADessin; 
//Cette portion de code est nécessaire pour les attributs de dessinable, et pour éviter
//les include qui ne fonctionnaient pas

class Dessinable {
protected:
    SupportADessin* support; //Un pointeur sur un support à dessin, comme demandé
public:
    virtual void dessine() = 0; //La méthode est redéfinie dans les classes qui héritent de dessinable : toupie, conesimple, etc
    virtual ~Dessinable() = default; //Assure le polymorphisme dans les sous-classes
    Dessinable(SupportADessin* support)
    : support(support) { }
};
#endif /* Dessinable_hpp */
