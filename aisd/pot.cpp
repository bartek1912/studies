#include <iostream>
using namespace std;

int main()
{

   int t;
   cin>>t;
   while(t--)
   {
      long long a, b, m, wyn = 1, tmp = a;
      cout<<"ch1\n";
      cin>>a>>b>>m;
      for(long long i = 1; i < (1ll<<33); i<<=1)
      {
         if(b&i)
            wyn = wyn * tmp % m;
         tmp = tmp*tmp%m;
      }
      cout<<"ch2\n";
      cout<<wyn<<"\n";
   }
   return 0;
}
