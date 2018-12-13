//TODO COM GLOBAL

#ifndef AFFICHAGE_H
#define AFFICHAGE_H
    //Librairies utilisé dans affichage.cpp
    #include <iostream>
    #include <string>
    using namespace std;
    //Prototypes
    void afficherTablier(Case tablier[][TAILLE_TABLIER], const size_t& taille);
    void initialiserTablier(Case tablier[][TAILLE_TABLIER], const size_t& taille);

#endif //AFFICHAGE_H
