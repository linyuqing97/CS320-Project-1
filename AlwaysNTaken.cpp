#include "AlwaysNTaken.h"
#include "AlwaysNTaken.h"

using namespace std;

AlwaysNTaken::AlwaysNTaken(){
    addr = 0;
    target = 0;
    numberOfNTaken = 0;
    totalCount = 0;
};
void AlwaysNTaken::parseAndGetResult(string behavior){
    
        totalCount++;
        if(behavior == "NT") {
          numberOfNTaken++;
        }
   
};
int AlwaysNTaken::getRes(){
    return numberOfNTaken;
}
int AlwaysNTaken::getTotalCount(){
    return totalCount;
}


