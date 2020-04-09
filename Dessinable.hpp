#pragma once
#ifndef Dessinable_hpp
#define Dessinable_hpp

class SupportADessin;

class Dessinable {
protected:
    SupportADessin* support;
public:
    virtual void dessine() = 0;
    virtual ~Dessinable() = default;
    Dessinable(SupportADessin* support)
    : support(support) { }
};
#endif /* Dessinable_hpp */