#include "header/constantes.h"
#include "header/affichage.h"

void afficherTablier(Case tablier[][TAILLE_TABLIER], const size_t& taille){

    for(size_t i = 0; i < taille; i++){
        for(size_t j = 0; j < taille; j++){
            switch (tablier[i][j]) {
                case Case::plein:
                    cout << to_string(i+1) + to_string(j+1) + " ";
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
void initialiserTablier(Case tablier[][TAILLE_TABLIER], const size_t& taille){

    for(size_t ligne = 0; ligne < taille; ligne++){
        for(size_t colonne = 0; colonne < taille; colonne++ ){
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
