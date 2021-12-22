#include <iostream>
#include <vector>
using namespace std;
int minCount(vector<int>& coins) {
        int count=0;
        for(int i=0;i<4;i++){
            if(coins[i]%2==0){
                count+=coins[i]/2;
            }
            else if(coins[i]%2==1){
                count+=coins[i]/2+1;
            }
        }
        return count;
    }