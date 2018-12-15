/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : reglesDuJeu.cpp
 Auteur(s)   : Maurice Lehmann,Mahé Fuentes, Wènes Limem
 Date        : 13.12.2018

 But         : Fonctions utilisée pour les déplacments de billes, les calcules des coups possibles et les entrées utilisateur

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/constantes.h"
#include "header/reglesDuJeu.h"

void calculerMouvementsPossibles(string& mouvementsPossibles, Case tablier[][TAILLE_TABLIER]){

    //On cherche les cases vide et depuis celles-ci on regarde si les 2 cases autour sont valide pour un mouvement
    //On cast TAILLE_TABLIER en int pour controler les depassements du tablier
    for(int ligne = 0; ligne < (int)TAILLE_TABLIER; ligne++){
        for(int colonne = 0; colonne < (int)TAILLE_TABLIER; colonne++){
            //On cherche d'abord les cases vides
            if(tablier[ligne][colonne] == Case::vide){
                //On cherche les mouvements "Down"
                if( tablier[ligne - 1][colonne] == Case::plein &&
                    tablier[ligne - 2][colonne] == Case::plein &&
                    ligne - 2 >= 0
                ){
                    mouvementsPossibles += to_string(ligne - 1) + to_string(colonne + 1) + "d ";
                }
                //On cherche les mouvements "up"
                if( tablier[ligne + 1][colonne] == Case::plein &&
                    tablier[ligne + 2][colonne] == Case::plein &&
                    ligne + 2 < (int)TAILLE_TABLIER
                ){
                    mouvementsPossibles += to_string(ligne + 3) + to_string(colonne + 1) + "u ";
                }
                //On cherche les mouvements "Left"
                if( tablier[ligne][colonne + 1] == Case::plein &&
                    tablier[ligne][colonne + 2] == Case::plein &&
                    colonne + 2 < (int)TAILLE_TABLIER
                ){
                    mouvementsPossibles += to_string(ligne + 1) + to_string(colonne + 3) + "l ";
                }
                //On cherche les mouvements "Right"
                if( tablier[ligne][colonne - 1] == Case::plein &&
                    tablier[ligne][colonne - 2] == Case::plein &&
                    colonne - 2 >= 0
                ){
                    mouvementsPossibles += to_string(ligne + 1) + to_string(colonne - 1) + "r ";
                }
            }
        }
    }
}

bool entreeMouvement(string& mouvement, const string& mouvementsPossibles){

    const string MSG_ERREUR = "Saisie non-valide!";

    cout << "Entrez un mouvement a effectuer : (numero de la case + 'u','d','r','l') :" << endl;
    cout << "Ou entrez 'h' pour de l aide ou 'q' pour arreter" << endl;

    if(!(cin>>mouvement)){
        cout << MSG_ERREUR <<endl;
        return false;
    }
    //On cherche le mouvements entré par l'utilisateur parmis les mouvements valides
    if (mouvementsPossibles.find(mouvement) != string::npos) {
        return true;
    }
    return false;
}

void deplacerBille(const string& mouvement, Case tablier[][TAILLE_TABLIER]){

    unsigned int positionX,positionY;
    char direction;

    positionX = mouvement[1] - '0' - 1;
    positionY = mouvement[0] - '0' - 1;
    direction = mouvement[2];

    //On eleve la bille de la position
    tablier[positionY][positionX] = Case::vide;

    if(direction == 'u'){
        tablier[positionY - 1][positionX] = Case::vide;
        tablier[positionY - 2][positionX] = Case::plein;
    }
    if(direction == 'd'){
        tablier[positionY + 1][positionX] = Case::vide;
        tablier[positionY + 2][positionX] = Case::plein;
    }
    if(direction == 'l'){
        tablier[positionY][positionX - 1] = Case::vide;
        tablier[positionY][positionX - 2] = Case::plein;
    }
    if(direction == 'r'){
        tablier[positionY ][positionX + 1] = Case::vide;
        tablier[positionY ][positionX + 2] = Case::plein;
    }

}
