//Bartłomiej Najdecki
//273975
//KLO
#include <iostream>
using namespace std;


int main()
{  
   ios::sync_with_stdio(2);
   int a,b;
   cin>>a>>b;
   a+= !(a&1);
   for(; a<=b; a+=2)
      cout<<a<<" ";
   cout<<"\n";
   return 0;
}
