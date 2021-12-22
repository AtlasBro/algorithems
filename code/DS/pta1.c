#include<stdio.h>
int maxSub(int a[],int k)
{
    int cur=0,sum=0;
    for(int i=0;i<k;i++){
        cur+=a[i];  //向后寻找
        if(cur>sum){    
            sum=cur;    //若当前和更大则更新
        }
        else if(cur<0){
            cur=0;      //若子列和为负数，则不可能使得后面的部分和增大，舍去之
        }
    }
    return sum;
}
int main(){
    int N;
    scanf("%d",&N);
    int nums[100000]={0};
    for(int i=0;i<N;i++){
        scanf("%d",&nums[i]);
    }
    int ans=maxSub(nums,N);
    printf("%d",ans);
}
