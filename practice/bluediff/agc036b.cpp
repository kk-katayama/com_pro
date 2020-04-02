#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int M = 210000;
int n;
vector<int> a,c;
int ind[M];
ll size;
void dfs(int v, int i) {
  if(v == n) {
    size = i - 1;
    return ;
  }
  int w = c[v];
  if(w <= v) {
    ind[i] = w + 1;
    dfs(w+1, i+1);
  }
  else if(w == n-1) {
    size = (ll)i;
    return ;
  }
  else dfs(w+1, i);
}

void dfs2(int v) {
  if(v == n) return ;
  int w = c[v];
  if(w <= v) {
    cout << a[v] << " ";
    dfs2(v+1);
  }
  else {
    dfs2(w+1);
  }
}
int main()
{
  cin >> n;
  ll k;cin >> k;
  a.resize(n);
  rep(i,n) cin >> a[i];
  vector<vector<int>> b(M);
  rep(i,n) {
    b[a[i]].push_back(i);
  }

  c.resize(n);
  rep(i,M) {
    int s = b[i].size();
    rep(j,s) {
      c[ b[i][j] ] = b[i][ (j+1) % s ];
    }
  }
  
  //  rep(i,n) cout << i << ":" << c[i] << "\n";
  ind[0] = 0;
  dfs(0, 1);
  rep(i,size) {
    cout << i << ":" << ind[i] << "\n";
  }

  ll st = ( k % size - 1 + size ) % size;
  //  cout << st << "\n";

  dfs2(ind[st]);
  cout  << "\n";
  return 0;
}
