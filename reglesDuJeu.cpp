#include "header/constantes.h"
#include "header/reglesDuJeu.h"
#include <stdexcept>

bool entreeMouvement(string& mouvement){

    cout << "Entrez un mouvement a effectuer : (numero de la case + 'u','d','r','l') :";
    cin >> mouvement ;
    //On check d'abord la longueur de l'input, il doit être égal a 3 (eg: 13d)
    if(mouvement.size() == 3){
        //On récupère la position de la case choisie
        unsigned int position ;
        try{
            position = stoi(mouvement.substr(0,2));
        }catch(invalid_argument& e){
            return false;
        }
        //On récupère la direction
        char direction = mouvement[3];
        //On controle que la direction sois bien u,d,l ou r
        if(direction == 'u' or direction == 'd' or direction == 'l' or direction == 'r'){
            //On controle si la position est valide
            
        }
        return true;
    }
    return false;

}
