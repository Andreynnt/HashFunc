#ifndef HASH_HASH_HPP
#define HASH_HASH_HPP
#include <iostream>



class Hash{
    std::string hash;
    int receivingExistCodes(int x);
    unsigned int getControlSum(std::string str);
public:
    std::string getHash(std::string userString, unsigned int lengthHash);
};



#endif //HASH_HASH_HPP
