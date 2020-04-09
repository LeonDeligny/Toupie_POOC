#pragma once
#ifndef SupportADessin_hpp
#define SupportADessin_hpp

class Contenu;
class Toupie;
class Systeme;
class ConeSimple;

class SupportADessin {
public:
    virtual ~SupportADessin() = default;
    // on supposera ici que les supports ne sont ni copiés ni déplacés
    virtual void dessine(Contenu const& a_dessiner) = 0;
    virtual void dessine(Toupie const& a_dessiner) = 0;
    virtual void dessine(Systeme const& a_dessiner) = 0;
    virtual void dessine(ConeSimple const& a_dessiner) = 0;
    // ... autres choses que vous voudriez dessiner...
};

#endif /* SupportADessin_hpp */