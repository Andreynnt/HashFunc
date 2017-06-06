#include "Hash.hpp"

int Hash::receivingExistCodes(int x){
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

unsigned int Hash::getControlSum(std::string str){
    unsigned int sault = 0, strlen = 0;
    for (; strlen < str.size(); strlen++){
        sault += int(str[strlen]);
    }
    return sault;
}

std::string Hash::getHash(std::string userString, unsigned int lengthHash){
    if (lengthHash > 3){
        //Минимальная длина строки хеша, кратная двум
        unsigned int minlen = 2;
        //Длина строки, ближайшая к нужной длине хэша
        unsigned int realMinLen = 0;

        //получаем соль оригинальной строки
        unsigned int originalSault = this->getControlSum(userString);
        unsigned int originalLengthStr = userString.size();

        //Получаение длины строки, кратной степени двух, ближайшей к заданной длине хеша
        while (minlen < lengthHash){
            realMinLen = (minlen *= 2);
        }

        //получаем ближайшее к длине исходной строки число типа 2^n
        while (minlen < originalLengthStr){
            minlen *= 2;
        }

        //Делаем длину строки хэша, как минимум, в 2 раза длинней оригинальной строки
        if ((minlen - originalLengthStr) < minlen){
            minlen *= 2;
        }

        //получаем кол-во символов, которое необходимо добавить к строке
        int addCount = minlen - originalLengthStr;
        //Добавление
        for (int i = 0; i < addCount; i++){
            userString += this->receivingExistCodes(userString[i] + userString[i+1]);
        }

        //получаем максимальную ссоль
        int maxSault = this->getControlSum(userString);
        int maxLenghtStr = userString.size();

        //определение степени сжатия
        while (userString.size() != realMinLen){
            for (int i = 0, center = userString.size() / 2; i < center; i++){
                this->hash += this->receivingExistCodes(userString[center - i] + userString[center + 1]);
            }
            userString = this->hash;
            this->hash.clear();
        }

        //Приведение к нужной длине, а не к n^2
        unsigned int rem = realMinLen - lengthHash;
        if (rem != 0) {
            for (int i = 0, countCompress = realMinLen / rem; this->hash.size() < (lengthHash - 4); i++) {
                if (i % countCompress == 0) {
                    this->hash += this->receivingExistCodes(userString[i] + userString[++i]);
                } else {
                    this->hash += userString[i];
                }
            }
        }else{
            int userLength = userString.length();
            for (int i = userLength / 2 , j = userLength / 2  + 1; i != 2; i--, j++){
                this->hash += userString[i];
                this->hash += userString[j];
            }
        }

        //добавление оригинальных солей
        this->hash += this->receivingExistCodes(originalSault);
        this->hash += this->receivingExistCodes(originalLengthStr);
        //добавление максимальных солей
        this->hash += this->receivingExistCodes(maxSault);
        this->hash += this->receivingExistCodes(maxLenghtStr);
        return this->hash;
    }
    return "";
}