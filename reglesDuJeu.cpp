#include "header/constantes.h"
#include "header/reglesDuJeu.h"

bool entreeMouvement(string& mouvement){

    char direction;
    unsigned int position;
    const string MSG_ERREUR = "Saisie non-valide!";

    cout << "Entrez un mouvement a effectuer : (numero de la case + 'u','d','r','l') :" << endl;
    cout << "Ou entrez 'h' pour de l aide ou 'q' pour arreter" << endl;

    if(!(cin>>mouvement)){
        cout << MSG_ERREUR <<endl;
        return false;
    }
    //On check si il s'agit d'une "commande spéciale" et non un déplacement
    if(mouvement == "h" || mouvement == "q"){
        return false;
    }
    //On check en premier la taille de la commande déplacement
    if(mouvement.size() != 3){
        cout << MSG_ERREUR << endl;
        return false;
    }
    //On récupère la position et la direction du déplacement eg: 13d -> 13 et d
    stringstream(mouvement.substr(0,2)) >> position;
    stringstream(mouvement.substr(2,3)) >> direction;

    //On regarde si la postion n'est pas hors bornes valides
    if(!(
        ((position > 12) && (position < 16)) ||
        ((position > 22) && (position < 26)) ||
        ((position > 30) && (position < 58)) ||
        ((position > 62) && (position < 66)) ||
        ((position > 72) && (position < 76))
    ))
    {
        cout << "Position non-valide!" <<endl;
        return false;
    }
    //On check si la direction est correct
    if(direction != 'u' && direction != 'd' && direction != 'l' && direction != 'r'){
        cout << "Direction non valide!" << endl;
        return false;
    }
    return true;
}
