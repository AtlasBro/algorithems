#include <iostream>

using namespace std;

char c;

struct MyStake{
    int top,a[100000];
    void init(){top=0;}
    void push(char x){a[++top]=x;}
    void pop(){if(top) top--;}
    int empty(){if(top>0) return 0;else return 1;}
}stack;


int main()
{
   stack.init();
   while(cin>>c&&c!='@'){
       if(stack.empty()){
           if(c==')');
           cout<<"NO";
           return 0;
       }
       if(c=='(') stack.push(c);
       if(c==')') stack.pop();
   }
   if(stack.empty()) cout<<"YES";
   else cout<<"NO";
   return 0;
}
