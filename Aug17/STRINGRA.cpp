//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <climits>
#include <utility>
using namespace std;

#define VI vector <int>
#define PII pair <int, int>
#define LL long long
#define ULL unsigned long long
#define LDB long double
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,a,b) for (auto i = (a); i <= (b); i++)
#define FORD(i,a,b) for (auto i = (a); i >= (b); i--)
#define FORV(CAKE,it) for(auto it =CAKE.begin(); it != CAKE.end(); it++)
#define FIT(it,v) for (auto it = v.begin(); it != v.end(); it++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x < 0)?-(x):x)

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity

int main()
{
  cin.sync_with_stdio(0);
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n,m,flag=1;
    scanf("%d %d", &n, &m);
    VI seq(n+1,-1);
    vector<VI> A(n+1);
    set<PII> ST;
    FOR(i,0,m-1)
    {
      int a,b;
      scanf("%d %d", &a, &b);
      if(a>=b) flag = 0;
      if(ST.find(MP(a,b)) == ST.end())
      ST.insert(MP(a,b));
      else
      flag = 0;
    }
    if(!flag)
    {
      printf("-1\n");
      continue;
    }

    FIT(it, ST) A[it->first].PB(it->second);
    FOR(i,0,n-1)
    {
      if(A[i].size() == 0 || A[i][0] != i+1 || A[i].size() > A[0].size())
      {
        flag = 0;
        break;
      }
    }
    if(!flag)
    {
      printf("-1\n");
      continue;
    }

    vector<int> idx(1+A[0].size(), 0);
    FOR(i,0,A[0].size()-1)
    {
      seq[A[0][i]] = i+1;
      idx[i+1] = A[0][i];
    }
    FOR(i,1,n-1)
    {
      int count=0, index=i+1, num=1;
      FOR(j,0,idx.size()-1)
      {
        if(idx[j] > i)
        {
          count += 1;
          if(j == seq[i]) num = 0;
        }
      }

      FOR(j,i+1,n)
      {
        if(seq[j] == -1)
        {
          index = j;
          break;
        }
      }

      if(find(A[i].begin(), A[i].end(), idx[seq[i]]) == A[i].end() && index < idx[seq[i]]) num = 1;

      int found=0;
      if((num==0 && A[i].size() != count) || (A[i].size() != count && A[i].size() != count+1 && num == 1))
      {
        flag = 0;
        break;
      }
      FOR(j,0,A[i].size()-1)
      {
        if(seq[A[i][j]] == -1)
        {
          if(num)
          {
            seq[A[i][j]] = seq[i];
            idx[seq[i]] = A[i][j];
          }
          else
          {
            flag = 0;
            break;
          }
        }
        else
        {
          if(idx[seq[A[i][j]]] != A[i][j])
          {
            flag = 0;
            break;
          }
          else found++;
        }
      }
      if(!flag || found != count)
      {
        flag = 0;
        break;
      }
    }
    if(!flag)
    {
      printf("-1\n");
      continue;
    }

    FOR(i,1,n)
    {
      if(seq[i] == -1)
      {
        flag=0;
        break;
      }
    }

    if(!flag) printf("-1");
    else
    FOR(i,1,n) printf("%d ", seq[i]);
    printf("\n");
  }

}
