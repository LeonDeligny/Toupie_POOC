//
//  Dessinable.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

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
