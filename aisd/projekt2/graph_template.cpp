#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FOR(a,c,b) for(int a = c; a < b; ++a)
#define FORD(a,c,b) for(int a = c; a >= b; --a)
#define LL long long
#define debug cerr
using namespace std;
const int INF = 2147483647;
const LL LINF = 9223372036854775807ll;
const int MLN = 1000003;
const int STOTYS = 100003;
const int stala = 0;

class Graph {
   struct Ed {
      int cost, to;//Byc moze to warto zamienic na referencje do Ve??
      Ed(int c, int t):cost(c), to(t) {};
   };
   struct Ve {
      bool visited;
      LL distance;
      vector<Ed> ed;
      Ve(): visited{0}, distance(LINF) {};
   };
   vector<Ve> v;
public:
   Graph(int n) {
      v.assign(n, Ve());
   }
   void addDir(int from, int to, int c = 1) {
      v[from].ed.push_back(Ed(to, c));
   }
   void add(int from, int to, int c = 1) {
      addDir(from, to, c);
      addDir(to, from, c);
   }
   void dijkstra(int start) {
      priority_queue<pair<LL, Ve*>> q;//dzięki wskaźnikowi nie trzeba pisać comparatora
      v[start].distance = 0;
      q.push(make_pair(0, &v[start]));
      while(!q.empty()) {
         Ve& act = *q.top().second; 
         q.pop();
         if(act.visited)
            continue;
         act.visited = 1;
         for(auto& e: act.ed)
            if(act.distance + e.cost < v[e.to].distance) {
               v[e.to].distance = act.distance + e.cost;
               q.push(make_pair(-v[e.to].distance, &v[e.to]));//ważne, priority queue sortuje od największego
            }
      }
   }
   void bfs(int start ) {
      queue<int> q;
      for(q.push(start); !q.empty(); q.pop())
      {
         v[q.front()].visited = 1;
         //do something
         for(auto& e: v[q.front()].ed)
            if(!v[e.to].visited)
               q.push(e.to);
      }
   }
   void dfs(int start) {
      v[start].visited = 1;
      for(auto& e: v[start].ed)
         if(!v[e.to].visited)
            dfs(e.to);
   }
};

int n, m;
int main() {
   ios::sync_with_stdio(0);
   cin>>n>>m;
   Graph g(n);
   REP(i, m) {
      int f,t,c;
      cin>>f>>t>>c;
      g.add(f, t, c);
   }

   return 0;
}
