#include <iostream>
#include <cmath>
using namespace std;
double dst(int x1, int y1, int x2, int y2)
{
   return sqrt((long long)(x1-x2)*(x1-x2) + (long long)(y1-y2)*(y1-y2));
}
int main()
{
   pair<int,int> a,b,c;
   cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
   cout<<(dst(a.first, a.second, b.first, b.second) + dst(b.first, b.second, c.first, c.second) + dst(a.first, a.second, c.first, c.second))<<"\n";
   return 0;
}
