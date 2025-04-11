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
    - les limites : les clés/indices doivent être bornées, denses (sinon gaspillage de mémoire), limiter un ou quelque octets d'indice donc char ou int sinon gaspillage mémoire voir impossible car pas assez de ram.
    
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
    //on stock (avec casting du char en int cf ascii table pour connaitre la valeur) puis lit le caractère suivant tant que c != 0, cad tant que pas /n
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

HashMap createHashMap(size_t size){
    HashMap newHashMap = malloc(sizeof(struct HashMap)); 
    if(!newHashMap){
        perror("Malloc failled");
        exit(EXIT_FAILURE);
    }

    newHashMap->entries = calloc(size, sizeof(HashEntry*));
    if(!newHashMap->entries){
        perror("Malloc Failled");
        exit(EXIT_FAILURE);
    }

    newHashMap->size = size ; 

    return newHashMap ; 
}

// Insertion (chaînage en cas de collision)
void insert(HashMap table, const char* key, int value) {
    unsigned long index = hash(key) % table->size;
    HashEntry* entry = table->entries[index];

    // Si la clé existe déjà, on remplace la valeur
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }

    // Sinon, on insère en tête
    HashEntry* new_entry = malloc(sizeof(HashEntry));
    new_entry->key = strdup(key); // copie de la clé
    new_entry->value = value;
    new_entry->next = table->entries[index];
    table->entries[index] = new_entry;
}

// Récupération d'un élément
void get_element(HashMap table, const char* key) {
    unsigned long index = hash(key) % table->size;
    HashEntry* entry = table->entries[index];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            printf("Valeur associée à la clé \"%s\" : %d\n", key, entry->value);
            return;
        }
        entry = entry->next;
    }

    printf("Clé \"%s\" non trouvée.\n", key);
}

// Suppression d'un élément
void delete_element(HashMap table, const char* key) {
    unsigned long index = hash(key) % table->size;
    HashEntry* entry = table->entries[index];
    HashEntry* prev = NULL;

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            if (prev) prev->next = entry->next;
            else table->entries[index] = entry->next;

            free(entry->key);
            free(entry);
            printf("Clé \"%s\" supprimée.\n", key);
            return;
        }
        prev = entry;
        entry = entry->next;
    }

    printf("Clé \"%s\" non trouvée pour suppression.\n", key);
}

// Libération de la table
void free_table(HashMap table) {
    for (size_t i = 0; i < table->size; i++) {
        HashEntry* entry = table->entries[i];
        while (entry) {
            HashEntry* temp = entry;
            entry = entry->next;
            free(temp->key);
            free(temp);
        }
    }
    free(table->entries);
    free(table);
}


int main(){

    printf("Hello world\n");

    const char* clef = "FR";
    printf("Le hash de la clef %s est : %lu\n", clef, hash(clef));
    HashMap table = createHashMap(10);

    insert(table, "Alice", 25);
    insert(table, "Bob", 30);
    insert(table, "Charlie", 40);

    get_element(table, "Bob");
    get_element(table, "David");

    delete_element(table, "Bob");
    get_element(table, "Bob");

    free_table(table);
    
    return 0;
}