#include <iostream>
using namespace std;

int main()
{
   int p=10;
   int r=20;
   int m=30;
   int *x=&p;
   int *y=&r;
   int *z=&m;
   cout<<x<<" "<<y<<" "<<z;
   return 0;
}
