#include <iostream>
#include <vector>
using namespace std;

int max(int a,int b){
        return a>b?a:b;
    }
    int gcd(int a,int b){
        return !b?a:gcd(b,a%b);
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int i,j,t,m=0,res=0;
        for(i=0;i<nums.size();i++){
            ans[nums[i]]=1;
            m=max(m,nums[i]);
        }

        for(i=1;i<=m;++i){
            t=0;
            for(j=i;j<=m;j+=i){
                if(ans[j])
                    t=gcd(t,j);
            }

            if(t==i)
                ++res;
        }
        return res;
    }

int main()
{
   
   return 0;
}
