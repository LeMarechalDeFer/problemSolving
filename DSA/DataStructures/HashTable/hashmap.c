#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"


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
    
}

HashMap createHashMap(size_t size){

}

void insert(HashMap table, int value){

}

void get_element(HashMap table, const char* key){

}

void delete_element(HashMap table, const char* key){

}

void free_table(HashMap table){

}



int main(){

    printf("Hello world\n");
    return 0;
}