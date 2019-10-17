#ifndef DOUBLEBIT_H
#define DOUBLEBIT_H

#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>

class DoubleBit{
        

        unsigned long long addr;
        std::string behavior;
        int totalCount;
        int result;

      
    
    public:
        std::unordered_map<unsigned long long,std::pair<std::string, int> >umap;
        DoubleBit ();
        bool parseAndGetResult(unsigned long long,std::string ,int);
        int getRes();
        int getTotalCount();

};
#endif