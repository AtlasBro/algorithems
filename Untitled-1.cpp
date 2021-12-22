#include<stdlib.h>
#include<iostream>
using namespace std;
int search(int num[]){
    int max,min;
    max=min=num[0];
    int count=0;
    for(int i=0;i<10;i++){
        count++;
        if(num[i]>max)
        max=num[i];
        else if(num[i]<min)
        min=num[i];
    }
    cout<<count<<endl;
    return 0;
}
int main(){
    int num[10];
    for(int i=0;i<10;i++){
        num[i]=rand()%20+1;
        cout<<num[i]<<endl;
    }
    search(num);
}