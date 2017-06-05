#ifndef HASH_AUTOTESTS_HPP
#define HASH_AUTOTESTS_HPP
#include <iostream>
#include "Hash.hpp"

class AutoTests{
    int countInearation;
    int receivingExistCodes(int x);
    std::string generationstring();
public:
    AutoTests(int countIteration) : countInearation(countIteration){
        srand((unsigned int)time(NULL));
    }
    void GoTestRandom(int lenghtTemp);
};

int AutoTests::receivingExistCodes(int x){
    x += 256;
    while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))){
        if (x < 48){
            x += 24;
        }else{
            x -= 47;
        }
    }
    return x;
}

std::string AutoTests::generationstring(){
    std::string str;
    std::string chars = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    int lenghtString = rand() % 23 + 5;
    for (int i = 0 ; i < lenghtString; i++){
        int index = int(chars[rand() % chars.size() + 0]);
        str += this->receivingExistCodes(index);
    }
    return str;
}

void AutoTests::GoTestRandom(int lenghtTemp){
    int counterCoints = 0;
    std::string stringTemp;
    std::string resultTemp;

    std::string *arrayString = new std::string[this->countInearation];
    std::string *arrayHash = new std::string[this->countInearation];
    for (int i = 0; i < this->countInearation; i++) {
        stringTemp = this->generationstring();
        Hash hash;
        resultTemp = hash.getHash(stringTemp, lenghtTemp);
        arrayString[i] = stringTemp;
        arrayHash[i] = resultTemp;
        std::cout << arrayString[i] << " - " << arrayHash[i] << std::endl;
    }

    //поиск совпадений
    for (int i = 0; i < this->countInearation; i++){
        for (int j = 0; j < this->countInearation; j++){
            if (i == j){
                continue;
            }
            if (arrayHash[i] == arrayString[j]){
                if (arrayString[i] != arrayString[j]){
                    std::cout << "Collision! :" << " (i): " << i << " " << arrayHash[i] << " ("
                              << arrayString[i] << ") " << "(j): " << arrayHash[j] << " (" <<
                              arrayHash[j] << " (" << arrayString[i] << ") " << std::endl;
                    counterCoints++;
                }
            }
        }
    }
    std::cout << "Collisions: " << counterCoints  << " /" << this->countInearation << std::endl;
    arrayString->clear();
    arrayHash->clear();
}


#endif //HASH_AUTOTESTS_HPP
