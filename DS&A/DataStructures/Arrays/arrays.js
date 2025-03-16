//nodejs prerequisites

const crypto = require("crypto")

// console.log("Hello Word !")

function getRandomInt(min, max){
    const range = max - min +1;
    const array = new Uint32Array(1)
    crypto.getRandomValues(array);
    return min +(array[0]% range); 
}


function randomArray(taille){
    if(taille <= 0){
        console.log("Erreur de taille");
        return [];
    }

    let array = [] ;//tab
    // let array = {} //object
    for(let i =0; i<taille; i++){
        array.push(getRandomInt(1, 100)) ; 
    }

    return array; 

}


console.log(randomArray(10));



