#ifndef SINGLEBIT_H
#define SINGLEBIT_H

#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>

class SingleBit{
        

        unsigned long long addr;
        std::string behavior;
        int totalCount;
        int result;

      
    
    public:
          std::unordered_map<unsigned long long,std::string>umap;
        SingleBit ();
        bool parseAndGetResult(unsigned long long,std::string ,int);
        int getRes();
        int getTotalCount();

};
#endif