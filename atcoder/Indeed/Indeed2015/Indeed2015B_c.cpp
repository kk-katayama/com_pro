#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<int> a(n-1), b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  vector<vector<int>> edge(n);
  rep(i,n-1) {
    edge[a[i]].push_back(b[i]);
    edge[b[i]].push_back(a[i]);
  }

  priority_queue<int> pq;
  pq.push(0);
  vector<bool> f(n, false);
  vector<int> res;
  while( !pq.empty() ) {
    int v = -pq.top(); pq.pop();
    f[v] = true;
    res.push_back(v);
    for(auto w: edge[v]) {
      if(f[w]) continue;
      pq.push(-w);
    }
  }

  rep(i,n) {
    if(i == n-1) cout << res[i]+1 << "\n";
    else cout << res[i]+1 << " ";
  }
  
  return 0;
}
