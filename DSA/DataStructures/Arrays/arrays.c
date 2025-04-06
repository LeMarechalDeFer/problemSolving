#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void randomArray(int *array, int taille){
    for(int i=0; i<taille; i++){
        array[i] = rand()%100 +1;
        printf("indice i : %d, value : %d\n", i, array[i]);
    }
}

void printArray(int *array, int taille){
    for(int i=0; i<taille; i++){
        printf("indice i : %d, value : %d\n", i, array[i]);
    }
}
int main(){
    srand(time(NULL));
    int taille;
    printf("Entrée la taille du tableau ;\n");
    scanf("%d", &taille);
    
    if(taille<=0){
        printf("Erreur, la taille doit être > 0\n");
        return 1;
    }else{
        // int *array[taille]; 
        int *array = malloc(sizeof(int)*taille);
        if(array == NULL){
            printf("Erreur d'allocation mémoire");
            return 1;
        }
        randomArray(array, taille);
        printArray(array, taille);
        free(array);

    }





    return 0;
}