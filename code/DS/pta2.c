#include<stdio.h>
void maxSub(int a[],int k)
{
    int cur=0,sum=-1;
    int isl=0,l=0,r=0;
    for(int i=0;i<k;i++){
        cur+=a[i];      //向后寻找
        if(cur>sum){    
            sum=cur;    //若当前和更大则更新
            l=isl;
            r=i;
        }
        else if(cur<0){
            cur=0;      //若子列和为负数，则不可能使得后面的部分和增大，舍去之
            isl=i+1;    //更新临时下标
        }
    }
    if(sum<0){
        printf("0 %d %d",a[0],a[k-1]);    
    }  
    else{
        printf("%d %d %d",sum,a[l],a[r]);
    }   
}
int main(){
    int N;
    scanf("%d",&N);
    int nums[100000]={0};
    for(int i=0;i<N;i++){
        scanf("%d",&nums[i]);
    }
    maxSub(nums,N);
}
