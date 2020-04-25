#include <iostream>
#include "Vecteur.h"
using std::cout;
using std::endl;

int main(){

    Vecteur v1({1, 2});
    Vecteur v2({1, 2, 3});
    if(v1==v2){cout<<"true"<<endl;}
    else{cout<<"false";}
    v1.augmente(3);
    if(v1==v2){cout<<"true2"<<endl;}
    cout<<v1+v2;
    cout<<"norme : "<<v1.norme()<<endl;
    cout<<"^"<<(v1^v2)<<endl;
    v1.set_coord(6, 5);
    cout<<"v1x3"<<v1*3<<endl;
    Vecteur v3({4, -5, 3, 9, 0, -12, 1});
    cout<<"soustraction"<<v3-v1<<endl;

    return 0;
}

