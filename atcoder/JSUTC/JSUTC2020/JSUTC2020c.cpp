#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int a,b,c;
int res;
void dfs(int x, int y, int z) {
  if(x == a && y == b && z == c) {
    res++;
    return ;
  }
  if(x < a) dfs(x+1, y, z);
  if(y < b && y < x) dfs(x, y+1, z);
  if(z < c && z < y) dfs(x, y, z+1);
}
int main()
{
  cin >> a >> b >> c;
  res = 0;
  dfs(0,0,0);
  cout << res << "\n";
  return 0;
}
