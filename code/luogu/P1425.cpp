#include<iostream>
int main(){
    int h1,m1,h2,m2,hour,min;
    std::cin>>h1>>m1>>h2>>m2;
    if(m2-m1<0){
        hour=h2-h1-1;
        min=60-m1+m2;
    }
    else{
        hour=h2-h1;
        min=m2-m1;
    }
    std::cout<<hour<<" "<<min;
}