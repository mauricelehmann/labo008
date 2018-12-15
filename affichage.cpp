/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : affichage.cpp
 Auteur(s)   : Maurice Lehmann,Mahé Fuentes, Wènes Limem
 Date        : 13.12.2018

 But         : Fonctions d'affichage des données du jeu (tablier, score du joueur)

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/constantes.h"
#include "header/affichage.h"

void afficherTablier(Case tablier[][TAILLE_TABLIER]){

    for(size_t ligne = 0; ligne < TAILLE_TABLIER; ligne++){
        for(size_t colonne = 0; colonne < TAILLE_TABLIER; colonne++){
            switch (tablier[ligne][colonne]) {
                case Case::plein:
                    cout << to_string(ligne+1) + to_string(colonne+1) + " ";
                    break;
                case Case::vide:
                    cout << ".. ";
                    break;
                case Case::nonValide:
                    cout << "   ";
                    break;
            }
        }
        cout << endl ;
    }
}
void initialiserTablier(Case tablier[][TAILLE_TABLIER]){

    for(size_t ligne = 0; ligne < TAILLE_TABLIER; ligne++){
        for(size_t colonne = 0; colonne < TAILLE_TABLIER; colonne++ ){
            //Si il s'agit des case dans les bords, on met des espaces blancs
            if( (ligne < 2 || ligne > 4) and (colonne < 2 || colonne > 4) ){
                tablier[ligne][colonne] = Case::nonValide ;
            }else{
                //Sinon on numérote
                tablier[ligne][colonne] = Case::plein;
            }
        }
    }
    //On retire la case du milieu
    tablier[3][3] = Case::vide;
}

void afficherScore(const unsigned int& billesRestantes, Case tablier[][TAILLE_TABLIER]){

    if(billesRestantes == 1){
        if(tablier[3][3] == Case::plein){
            cout << "Parfait, il ne reste qu'une bille au centre";
        }else{
            cout << "Bravo, vous avez gagne avec une seule bille restante. Au centre ce serait parfait";
        }
    }else if( billesRestantes > 1 && billesRestantes < 6){
        cout << "Pas mal, il ne reste que "<< billesRestantes << " billes";
    }else{
        cout << "Vous pouvez faire mieux, il reste "<< billesRestantes <<" billes";
    }
    cout << endl;
}

void afficherMouvementsPossibles(const string& mouvementsPossibles){
    cout << mouvementsPossibles << endl;
}
