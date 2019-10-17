#ifndef GSHARE_H
#define GSHARE_H

#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>

class Gshare{
        

        int addr;
        std::string behavior;
        int totalCount;
        int result;
        int bitSize;
        int updatedGlobalHisotry;

      
    
    public:
        std::unordered_map<int,std::pair<std::string, int> >umap;
       int updateGlobalHistory(std::string,int,int);
        Gshare ();
        bool parseAndGetResult(unsigned long long,std::string ,int,int);
        int getGlobalRes(){
            return updatedGlobalHisotry;
            };
        int getTotalCount();

};
#endif