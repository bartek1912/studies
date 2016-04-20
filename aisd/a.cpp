#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef unsigned long long ll;
int n;
multiset<ll> q;//10^6 * 240 bajtów
int main()
{
   ios::sync_with_stdio(0);
   cin>>n;
   for(int i = 0; i < n; i++)
   {
      ll a, il;
      cin>>a>>il;
      for(int j = 0; (1llu<<j) <= il; j++)
         if( ((1llu<<j) & il) != 0)
            q.insert(a<<j);
   }
   int wyn = 0;
   while(!q.empty())
   {
      ll act = *q.begin(), il = 1;
      q.erase(q.begin());
      for(;q.size() > 0; q.erase(q.begin()), il++)
         if(act != *q.begin())
            break;
      for(int j = 1; (1llu<<j) <= il; j++)
         if( ((1llu<<j) & il) != 0)
            q.insert(act<<j);
//      if(il&1) cerr<<act<<" ";
      wyn += il&1;
   }
   cout<<wyn<<"\n";
   return 0;
}
