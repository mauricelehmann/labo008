/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : affichage.h
 Auteur(s)   : Maurice Lehmann,Mahé Fuentes, Wènes Limem
 Date        : 13.12.2018

 But         : Prototypes des fonctions d'affichage des données du jeu (tablier, score du joueur)

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef AFFICHAGE_H
#define AFFICHAGE_H
    //Librairies utilisé dans affichage.cpp
    #include <iostream>
    #include <string>
    using namespace std;
    //Prototypes
    void afficherTablier(Case tablier[][TAILLE_TABLIER]);
    void initialiserTablier(Case tablier[][TAILLE_TABLIER]);
    void afficherScore(const unsigned int& billesRestantes, Case tablier[][TAILLE_TABLIER]);
    void afficherMouvementsPossibles(const string& mouvementsPossibles);

#endif //AFFICHAGE_H
