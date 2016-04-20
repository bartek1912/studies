#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int stala = 5e3+7;
const long long INF = 1e14;
long long tab[2][3][stala];//ostatni ruch w gore = 0, dol = 1
long long v[3][stala];
int pow[10];
int main()
{
   int w, k;
   ios::sync_with_stdio(0);
   cin>>w>>k;
   int i;
   for(int j = 0; j < 2; j++)
      for(i = 0; i < 3; i++)
         for(int l = 0; l < k + 4; l++)
            tab[j][i][l] = -INF;
//            fill_n(&tab[j][i][0], -INF, k+7);
   pow[0] = 1;
   for(int i = 1; i < 10; ++i)
      pow[i] = pow[i-1] * 7;
   char c;
   for(i = 1; i <= w; ++i)
   {
      int act = i % 3;
      int nast = (act + 1)%3;
      for(int j = 2; j < k + 2; ++j) 
      {
         cin>>c;
         v[act][j] = pow[c - '0'];
            tab[1][act][j] = v[act][j] + max(max(tab[0][nast][j - 1], tab[0][nast][j + 1]),
                                         max(tab[1][nast][j - 1], tab[1][nast][j + 1]));
         if(i == 1)
            tab[0][act][j] = v[act][j];
      }
      nast = (act + 2) % 3;
      if(i != 2)//bo na planszy szerokosci 3 nie da sie skoczyc wszedzie
         for(int j = 2; j < k + 2; ++j) 
            tab[0][nast][j] = v[nast][j] + max(tab[1][act][j-2], tab[1][act][j+2]);  
   }
   long long wyn = 0;
   i--;
   i = (i+3)%3;
   for(int j = 2; j < k+2; j++)
      wyn = max(wyn, max(tab[0][i][j], tab[1][i][j]));
   cout<<wyn<<"\n";
   return 0;
}
