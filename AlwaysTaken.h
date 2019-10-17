#include<string>
#include<fstream>
#include<iostream>
#include<sstream>
#ifndef ALWAYSTAKEN_H
#define ALWAYSTAKEN_H

class AlwaysTaken{
        unsigned long long addr;
        std::string behavior;
        unsigned long long target;
        int numberOfTaken;
        int totalCount;
        std::stringstream s;
    public:
        AlwaysTaken();
        void parseAndGetResult(std::string);
        int getRes();
        int getTotalCount();

      




};
#endif