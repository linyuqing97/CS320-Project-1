#include<string>
#include<fstream>
#include<iostream>
#include<sstream>

#ifndef ALWAYSNTAKEN_H
#define ALWAYSNTAKEN_H

class AlwaysNTaken{
        unsigned long long addr;
        unsigned long long target;
        std::string behavior;
        int numberOfNTaken;
        int totalCount;
    public:
        AlwaysNTaken();
        void parseAndGetResult(std::string);
        int getRes();
        int getTotalCount();


};
#endif