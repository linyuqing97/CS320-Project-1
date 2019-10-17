#include "AlwaysTaken.h"
#include "AlwaysTaken.h"

using namespace std;

AlwaysTaken::AlwaysTaken(){
    addr = 0;
    target = 0;
    numberOfTaken = 0;
    totalCount = 0;
};
void AlwaysTaken::parseAndGetResult(string behavior){
        totalCount++;
        if(behavior == "T") {
          numberOfTaken++;
        }
    
};
int AlwaysTaken::getRes(){
    return numberOfTaken;
}
int AlwaysTaken::getTotalCount(){
    return totalCount;
}


