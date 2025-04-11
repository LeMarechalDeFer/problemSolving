
#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

void printState(const vector<int>& piles, int depth, const string& role, int alpha, int beta, string prefix = "") {
    string indent(depth * 2, ' ');
    cout << indent << prefix << role << " | Piles: ";
    for (int pile : piles) cout << pile << " ";
    cout << "| α: " << alpha << " β: " << beta << endl;
}

bool isGameOver(const vector<int>& piles) {
    for (int pile : piles) {
        if (pile > 0) return false;
    }
    return true;
}

int minimax(vector<int>& piles, bool isMaximizing, int alpha, int beta, int depth = 0) {
    string role = isMaximizing ? "MAX" : "MIN";

    if (isGameOver(piles)) {
        int result = isMaximizing ? -1 : 1;
        printState(piles, depth, role, alpha, beta, "FIN DE PARTIE: ");
        return result;
    }

    int bestScore = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();

    for (size_t i = 0; i < piles.size(); ++i) {
        for (int remove = 1; remove <= piles[i]; ++remove) {
            piles[i] -= remove;

            string indent(depth * 2, ' ');
            cout << indent << role << " essaie: retirer " << remove << " de la pile " << i << endl;

            int score = minimax(piles, !isMaximizing, alpha, beta, depth + 1);
            piles[i] += remove;

            if (isMaximizing) {
                bestScore = max(bestScore, score);
                alpha = max(alpha, score);
            } else {
                bestScore = min(bestScore, score);
                beta = min(beta, score);
            }

            printState(piles, depth, role, alpha, beta, "Retour de branche: ");

            if (beta <= alpha) {
                string indent(depth * 2, ' ');
                cout << indent << "⛔ Pruning: β ≤ α" << endl;
                return bestScore;
            }
        }
    }

    return bestScore;
}

int main() {
    vector<int> piles = {2, 2}; // ou {1, 3, 5, 7} pour le Nim classique

    cout << "DÉMARRAGE DE MINIMAX AVEC ALPHA-BETA" << endl << endl;
    minimax(piles, true, numeric_limits<int>::min(), numeric_limits<int>::max());
    return 0;
}



// #include <iostream>
// #include <vector>
// #include <limits>
// #include <iterator>


// bool isGameOver(const std::vector<int> &piles);
// std::pair<int, int> findBestMove(std::vector<int>&pile);
// int minimax(std::vector<int> &piles, bool isMaximizing, int alpha, int beta);

// bool isGameOver(const std::vector<int> &piles){
//     std::vector<int>::const_iterator it;
//     for(it = piles.begin(); it != piles.end(); it++){
//         if(*it != 0){
//             return false;
//         }
//     }
//     return true;
// }

// int minimax(std::vector<int> &piles, bool isMaximizing, int alpha, int beta){
//     // 1 if max win, and -1 if he lose
//     if(isGameOver(piles)){
//         return isMaximizing ? -1 : 1;
//     }

//     if(isMaximizing){
//         int maxEval = std::numeric_limits<int>::min() ;

//         for(size_t i = 0; i< piles.size(); i++ ){
//             for(int remove =1; remove<= std::min(2, piles[i]); ++remove){
                
//             }
//         }

//     }
//     else{
//         int minEval = std::numeric_limits<int>::max();


//     }


// }

// std::pair<int, int> findBestMove(std::vector<int> &piles){

// }


// int main(){
//     std::vector<int> piles = {2, 2, 1};

    
// }
