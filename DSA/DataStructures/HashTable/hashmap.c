#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"


/*
Structure clef - valeur
    Comment retrouver rapidement une information données à partir d'une informatation associée (clé) ?

Proposition 1 : 
    Direct Acces Table (un tableau de taille)
    - on initialise un tableau statiquement.
    - on délimite la plage de clef à partir des indices de notre tableau.
    => la plus grande clef est proportionnelle à la taille du tableau
    => la mémoire utilisé est propotionnnelle à la plus grande clef utilisé.
    - les limites : les clés/indices doivent être bornées, denses (sinon gaspillage de mémoire), limiter un ou quelque bit d'indice donc char ou int sinon gaspillage mémoire voir impossible car pas assez de ram.
    
    en bref : 
    Un tableau devient une table d'accès direct si l'indice a du sens en lui-même : c’est une clé qui te permet d’accéder directement à la valeur associée.

    autres remarques:
    - quand on dit statique c'est qu'il n'y a pas de redimension automatique, il faut d'une part le faire manuellement, ce n'est pas scallable
        et si ce n'est pas fait à l'avance => segfault

Proposition 2 :
    Hash Map (table de hachage)
    Objectif : résoudre les limites des DAT.
    Avantages :
    - Accepte des clés dynamiques : string, struct, float, etc.
    - Taille mémoire contrôlée : le tableau sous-jacent est de taille fixe au départ (ex: 1024 cases) et peut être redimensionné.
    - Accès en O(1) en moyenne grâce à une fonction de hachage : `index = hash(clé) % taille_table`.

    Fonctionnement :
    - Clé → fonction de hachage → index dans le tableau
    - En cas de collision (deux clés ont le même index), on utilise une technique de résolution :
        - Chaînage (listes dans chaque case)
        - Probing linéaire/quadratique (déplacement dans le tableau)

    Remarques :
    - La redimension dynamique (rehashing) est possible : quand le taux de remplissage est trop élevé, on agrandit le tableau et on re-hashe toutes les clés.
    - Complexité :
        - Insertion, recherche, suppression : O(1) en moyenne, O(n) en pire cas si mauvaise fonction de hachage.
    
    Exemple de fonction de hachage :
        - Pour string : djb2, djb2a, FNV-1a, MurmurHash, etc.
        - Pour int : `return (unsigned int)key;` ou algo mixant les bits (multiplication + xor)

    En résumé :
    - DAT = très rapide mais très rigide (index = clé)
    - HashMap = plus flexible et adaptée à des clés variées, mais nécessite une bonne fonction de hachage et une gestion des collisions

*/

/*
djb2 (Daniel J. Bernstein)
- fast 
- uniformly distribued (minimize collizions)
- deterministic
*/


unsigned long hash(const char* str){
    
    unsigned long hash = 5381 ; //nombre premier choisi empiriquement par Bernstein
    int c ;
    //on stock puis lit le caractère suivant tant que c != 0, cad tant que pas /n
    while ((c = *str++))
    {
        // pourquoi 33
        // opérateur de décalage binaire letft shift multiplie par 2^n (>> right shift, divise par 2^n)
        hash = ((hash << 5) + hash) + c ; // équivaut à hash * 33 + c

    /*   
        Parce que c’est un petit nombre impair (évite certaines régularités), pas trop petit, et multiplier par 33 est rapide (bitwise shift + add). 
        Il donne de bonnes distributions dans la pratique.
    */
    }

    return hash ; 
    
}

// HashMap createHashMap(size_t size){

// }

// void insert(HashMap table, int value){

// }

// void get_element(HashMap table, const char* key){

// }

// void delete_element(HashMap table, const char* key){

// }

// void free_table(HashMap table){

// }

#include <stdio.h>

int main(){

    printf("Hello world\n");

    const char* clef = "Romain";

    printf("Le hash de la clef %s est : %lu ", clef, hash(clef));

    return 0;
}