#include "AlwaysTaken.h"
#include "AlwaysTaken.h"
#include "AlwaysNTaken.h"
#include "AlwaysNTaken.h"
#include "DoubleBit.h"
#include "DoubleBit.h"
#include "Gshare.h"
#include "Gshare.h"
#include"SingleBit.h"
#include"SingleBit.h"
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include<unordered_map>
#include <fstream>
using namespace std;

int main(int argc, char*argv[]){
    ofstream outfile;
    outfile.open(argv[2]);
    ifstream infile(argv[1]);
    string line;
    unsigned long long addr = 0;
    unsigned long long target = 0;
    string behavior;
    unordered_map<int,int> umap;
    int bitTable[] = {16,32,128,256,512,1024,2048};
    int gshareBitTable[] = {3,4,5,6,7,8,9,10,11};
    vector<unsigned long long>addrTable;
    vector<string>behaviorTable;

    AlwaysTaken alwaysTaken;
    AlwaysNTaken alwaysNTaken;
    SingleBit singleBit;
    DoubleBit doubleBit;
    Gshare gshare;



    //Check inputs
    if(argc != 3){
        cerr<<"Input error, correct input: ./predictors <input.txt> <output.txt>"<<endl;
        exit(1);
    }
    



    while(getline(infile,line)){
        stringstream s(line);
        s >> std::hex >> addr >> behavior;
        addrTable.push_back(addr);
        behaviorTable.push_back(behavior);
    }

    //First test -------->Always Taken
    for(int i = 0;i<addrTable.size();i++){
        alwaysTaken.parseAndGetResult(behaviorTable[i]);
    }
    outfile<<" "<<alwaysTaken.getRes()<<","<< alwaysTaken.getTotalCount()<<";"<<endl;
  

    //Second test -------->Always Not Taken
     for(int i = 0;i<addrTable.size();i++){
        alwaysNTaken.parseAndGetResult(behaviorTable[i]);
    }
    outfile<<" "<<alwaysNTaken.getRes()<<","<< alwaysNTaken.getTotalCount()<<";"<<endl;
    
    //Third test----->singleBit prediction
    for(int j = 0;j<sizeof(bitTable)/sizeof(int);j++){
        for(int i = 0;i<addrTable.size();i++){
            singleBit.parseAndGetResult(addrTable[i],behaviorTable[i],bitTable[j])?umap[bitTable[j]]++:NULL;
        }
         singleBit.umap.clear();
    }

    for(int i = 0;i<sizeof(bitTable)/sizeof(int);i++){
        outfile<<" "<<umap[bitTable[i]]<<","<<alwaysNTaken.getTotalCount()<<";";
    }
    cout<<"Test 3\n"<<umap[16]<<endl;
    singleBit.umap.clear();

    //Fourth test
    umap.clear();
     for(int j = 0;j<sizeof(bitTable)/sizeof(int);j++){
        for(int i = 0;i<addrTable.size();i++){
            doubleBit.parseAndGetResult(addrTable[i],behaviorTable[i],bitTable[j])?umap[bitTable[j]]++:NULL;
        }
    
         doubleBit.umap.clear();
    }
    outfile<<endl;
    for(int i = 0;i<sizeof(bitTable)/sizeof(int);i++){
        outfile<<" "<<umap[bitTable[i]]<<","<<alwaysNTaken.getTotalCount()<<";";
    }
    doubleBit.umap.clear();

    cout<<"Test 4\n"<<umap[16]<<endl;
    
    //Fifth test
    
    umap.clear();
    int globalHistory = 0;
 
    
    for(int j = 0;j<sizeof(gshareBitTable)/sizeof(int);j++){
        for(int i = 0;i<addrTable.size();i++){
           gshare.parseAndGetResult(addrTable[i],behaviorTable[i],globalHistory,gshareBitTable[j])?umap[gshareBitTable[j]]++:NULL;
           globalHistory = gshare.getGlobalRes();
        }
        globalHistory = 0;
        gshare.umap.clear();
    }
    outfile<<endl;
    for(int i = 0;i<sizeof(gshareBitTable)/sizeof(int);i++){
        outfile<<" "<<umap[gshareBitTable[i]]<<","<<alwaysNTaken.getTotalCount()<<";";
    }

    

    cout<<"Test 5\n"<<umap[3]<<endl;



   

    return 0;
}
