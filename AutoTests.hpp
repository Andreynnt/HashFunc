#ifndef HASH_AUTOTESTS_HPP
#define HASH_AUTOTESTS_HPP
#include <iostream>
#include <vector>
#include "Hash.hpp"

class AutoTests{
    int countInearation;
    int receivingExistCodes(int x);
    std::string generationstring();
    int countCollisions(std::vector<std::string>&, std::vector<std::string>&);
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
    int lengthString = rand() % 23 + 5;
    for (int i = 0 ; i < lengthString; i++){
        int index = int(chars[rand() % chars.size() + 0]);
        str += this->receivingExistCodes(index);
    }
    return str;
}

int AutoTests::countCollisions(std::vector<std::string>& arrayHash, std::vector<std::string>& arrayString){
    int counterCoints = 0;
    for (int i = 0; i < this->countInearation; i++){
        for (int j = 0; j < this->countInearation; j++){
            if (i == j){
                continue;
            }
            if (arrayHash[i] == arrayString[j]){
                if (arrayString[i] != arrayString[j]){
                    std::cout << "Collision! " << " (i): " << i << " " << arrayHash[i] << " ("
                              << arrayString[i] << ") " << "(j): " << arrayHash[j] <<
                              arrayHash[j] << " (" << arrayString[i] << ") " << std::endl;
                    counterCoints++;
                }
            }
        }
    }
    return counterCoints;
}


void AutoTests::GoTestRandom(int lenghtTemp){
    std::string stringTemp;
    std::string resultTemp;

    std::vector<std::string> arrayString(this->countInearation);
    std::vector<std::string> arrayHash(this->countInearation);

    for (int i = 0; i < this->countInearation; i++) {
        stringTemp = this->generationstring();
        Hash hash;
        resultTemp = hash.getHash(stringTemp, lenghtTemp);
        arrayString[i] = stringTemp;
        arrayHash[i] = resultTemp;
    }

    std::cout << "Collisions: " << countCollisions(arrayHash, arrayString) << " / " << this->countInearation << std::endl;
}


#endif //HASH_AUTOTESTS_HPP
