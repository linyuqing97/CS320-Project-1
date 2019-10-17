#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include"Gshare.h"
#include "DoubleBit.h"
#include"Gshare.h"
#include "DoubleBit.h"


class Tournament{
    int addr;
    std::string behavior;
    int totalCount;
    int result;
    int bitSize;
    int updatedGlobalHisotry;

      
    
    public:
        std::unordered_map<int,std::pair<std::string, int> >umap;
        int updateGlobalHistory(std::string,int,int);
        Tournament();
        bool parseAndGetResult(unsigned long long,std::string ,int,int);
        int getGlobalRes(){
            return updatedGlobalHisotry;
        };
        int getTotalCount();
};








#endif

