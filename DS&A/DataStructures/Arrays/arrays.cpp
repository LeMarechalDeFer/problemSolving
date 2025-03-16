#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

// cstd : C standrard Librairy #include <cstdlib>

//principe de référence

void randomArray(std::vector<int> &array, int taille){
    array.resize(taille);

    std::random_device random; //seed material based
    std::mt19937 gen(random()) ; //mersenne twister generator
    std::uniform_int_distribution<int> distrib(1,100); //avoid statistical bias (0, 1, 2, 3 +96)

    for(size_t i = 0; i < array.size(); i++){
        array[i] = distrib(gen);
    }
}

void printArray(std::vector<int> &array){
    for(size_t i = 0; i < array.size(); i++){
        std::cout << "indice " << i << " : valeur " << array[i] << std::endl;
    }
}

int main(){

    int taille ;
    std::cout << "Entrez une valeur dans le tableau :" ;
    std::cin >>taille ;
    if(taille<=0){
        std::cout << "Valeur non autorisée" << std::endl ;
        return 1;
    }

  
    int test = 121 ;

    // std::string string_number = std::to_string(test);

    // sort(string_number.begin(), string_number.end() )

    std::vector<int> array ;

    randomArray(array, taille);
    printArray(array);

    return 0;

}