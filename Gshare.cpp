#include "Gshare.h"
#include "Gshare.h"

using namespace std;

Gshare::Gshare(){
    bitSize = 2048;
    updatedGlobalHisotry = 0;
    
    umap.clear();
}

int Gshare::updateGlobalHistory(string behavior,int globalHistory, int globalHisotryLength){
    int newBit = (behavior == "T") ? 1:0;

    int temp = globalHistory;
    temp = (int)(temp<<1);
    temp = (int)(temp | newBit);
    return updatedGlobalHisotry = (int)(temp & (int)(pow(2,globalHisotryLength)-1));

}

bool Gshare::parseAndGetResult(unsigned long long addr,std::string behavior,int gh, int globalHistoryLength){
    
   int temp = addr % bitSize;

    temp = temp^gh;
    updateGlobalHistory(behavior,gh, globalHistoryLength);

    
    if(umap.find(temp)!=umap.end()){
        if(umap[temp].first == behavior){
                // handle weakly not taken && weakly taken
                if(umap[temp].second== 2 && umap[temp].first == "T"){
                        umap[temp].second++;
                }
                else if(umap[temp].second == 1 && umap[temp].first == "NT"){
                        umap[temp].second--;
                }
                
            return true;
        }
        else{
                if(behavior == "T" && umap[temp].second == 0){
                        umap[temp].second++;
                        return false;
                }
                else if(behavior == "T" && umap[temp].second == 1)
                {
                        umap[temp].second++;
                        umap[temp].first = "T";
                        return false;
                }
                if(behavior == "NT" && umap[temp].second == 3){
                        umap[temp].second--;
                        return false;
                }
                else if(behavior == "NT" && umap[temp].second == 2)
                {
                        umap[temp].second--;
                        umap[temp].first = "NT";
                        return false;
                }
                else{
                        cout<<"error"<<endl;
                }

        }
    }
    
    // 0 == strongly None takein, 1 == weakly NoneTaken, 2 == weakly Taken, 3 == strongly Taken
   else{  
       if (behavior == "T"){
           umap[temp].first = "T";
           umap[temp].second = 3;
           return true;
       }
       else{
             umap[temp].first = "T";
             umap[temp].second = 2;
             return false;

       }
       
      
   }
   return false;

}

