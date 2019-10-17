#include "DoubleBit.h"
#include "DoubleBit.h"

using namespace std;

DoubleBit::DoubleBit(){
    addr = 0;
    totalCount = 0;
    umap.clear();
}

bool DoubleBit::parseAndGetResult(unsigned long long addr,std::string behavior,int tableSize){
    totalCount++;
    unsigned long long temp = addr%tableSize;
    
    // string str2 = temp.substr(4,8);
    
    if(umap.find(temp)!=umap.end()){
        /*
            if(behavior == "T"){
                    switch(umap[temp].second){
                            case 0 : umap[temp].second++;return false;
                            case 1 : umap[temp].second++;umap[temp].first = "T";return false;
                            case 2 : umap[temp].second++;return true;
                            default: return true;

                    }
            }
            else{
                        switch(umap[temp].second){
                            case 1 : umap[temp].second--;umap[temp];return true;
                            case 2 : umap[temp].second--;umap[temp].first = "NT";return false;
                            case 3 : umap[temp].second--;return false;
                            default: return false;
                        }
            }




        */
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

