#include "SingleBit.h"
#include "SingleBit.h"

using namespace std;

SingleBit::SingleBit(){
    addr = 0;
    totalCount = 0;
    umap.clear();
}

bool SingleBit::parseAndGetResult(unsigned long long addr,std::string behavior,int tableSize){
    totalCount++;
    unsigned long long temp = addr%tableSize;
    
    // string str2 = temp.substr(4,8);
    if(umap.find(temp)!=umap.end()){
        if(umap[temp] == behavior){
            return true;
        }
        else{
            umap[temp]=behavior;
        }
    }
   else{
     
       if (behavior == "T"){
           umap[temp] = "T";
           return true;
       }
       else{
             umap[temp] = "NT";
       }
       
      
   }
   return false;

}

int SingleBit::getRes(){

    return result;
}
int SingleBit::getTotalCount(){
    return totalCount;
}