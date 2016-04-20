#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const int stala = 1e6+3;
int n;
inline bool cmp(const pair<int, ll>& a, const pair<int, ll>& b) 
{
   return a.first < b.first;
}
pair<int, ll> v[stala];//10^6 * 240 bajtów
int main()
{
   ios::sync_with_stdio(0);
   cin>>n;
   for(int i = 0; i < n; i++)
   {
      int a;
      ll il;
      cin>>a>>il;
      for(;!(a&1); a>>=1,il<<=1);
      v[i] = make_pair(a, il);
   }
   //sort(v, v+n, cmp);
   sort(v, v+n);
   ll wyn = 0;
   for(int i = 1; i < n; i++) 
      if(v[i-1].first == v[i].first)
         v[i].second += v[i-1].second;
      else 
         wyn+=__builtin_popcountll(v[i-1].second);
   wyn+=__builtin_popcountll(v[n-1].second);
   cout<<wyn<<"\n";
   return 0;
}
