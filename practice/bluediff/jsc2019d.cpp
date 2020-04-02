#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int res[510][510];
void dfs(int m, int c, int z) {
  if(m == 1) return ;
  int a = m/2;
  int b = m - a;
  rep(i, a) {
    rep(j, b) {
      res[i + z][a + j + z] = c;
    }
  }
  dfs(a, c + 1, z);
  dfs(b, c + 1, z + a);
}
int main()
{
  cin >> n;
  dfs(n, 1, 0);
  rep(i, n-1) {
    rep(j, n){
      if(i >= j) continue;
      cout << res[i][j] << " ";
    }
    cout  << "\n";
  }

  
  return 0;
}
