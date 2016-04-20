#include <bits/stdc++.h>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FOR(a,c,b) for(int a = c; a < b; ++a)
#define FORD(a,c,b) for(int a = c; a >= b; --a)
#define LL long long
using namespace std;
const LL INF = 2ll<<38;
const double EPS = 1e-6;
//const int stala = 5e5 + 3;
const int stala = 1e6 + 3;
pair<int, int> byX[stala];//(x, y)
int res[3]; //wynik
int n;
inline double dst(const pair<int, int>& a, const pair<int,int>& b)
{
   return sqrtl((LL)(a.first - b.first)*(a.first - b.first) + (LL)(a.second - b.second)*(a.second - b.second));
}
ostream& print(pair<int, int>& p)
{
   return cerr<<"("<<p.first<<","<<p.second<<")";
}
double best = INF;
void solve(int p, int k, const vector<int>& byY)//y, id
{
   if(k - p < 3) 
      return ;
   int s = (p+k)>>1;
   vector<int> left, right;
   left.reserve(s - p + 2);
   right.reserve(s - p + 1);
   for(auto x: byY)
      if(x < s + 1)
         left.push_back(x);
      else
         right.push_back(x);
   solve(p, s, left);
   solve(s+1, k, right);
   vector<int>  v;
   v.reserve(k - p + 1);
   double s2 = (byX[s].first + byX[s + 1].first)/2.0;
   for(auto x: byY) 
      if(abs(byX[x].first - s2) <= best)
         v.push_back(x);
   //zbieram punkty w odleglosci best/2 
   double b1;
   for(size_t i = 0, j, l; i < v.size(); ++i) 
   {
      for(j = i + 1; j < v.size(); ++j) {
         if(2*abs(byX[v[j]].second - byX[v[i]].second) > best)
            break;
         b1 = dst(byX[v[j]], byX[v[i]]);
         for(l = j + 1; l < v.size() && 
               b1 + abs(byX[v[l]].second - byX[v[i]].second) 
                  + abs(byX[v[l]].second - byX[v[j]].second) < best; ++l) 
         {
            double tmp = b1 + dst(byX[v[i]], byX[v[l]]) + 
                              dst(byX[v[j]], byX[v[l]]);
            if(tmp < best) 
            {
               best =  tmp;
               res[0] = v[i]; res[1] = v[j]; res[2] = v[l];
            }
         }
      }
   }
}

int main() {
   best = INF;
   scanf("%d", &n);
   vector<int> tmp;
   vector<pair<int, int> > byY;
   byY.reserve(n);
   tmp.reserve(n);
   REP(i, n){
      scanf("%d %d", &byX[i].first, &byX[i].second);
   }
   sort(byX, byX + n);
   REP(i, n)
      byY.push_back(make_pair(byX[i].second, i));
   sort(byY.begin(), byY.end());
   for(auto x: byY)
      tmp.push_back(x.second);
   byY.clear();
   solve(0, n, tmp);
   REP(i,3)
      printf("%d %d\n", byX[res[i]].first, byX[res[i]].second);
   return 0;
}

