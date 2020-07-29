#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int t; cin >> t;
  vector<string> res;
  vector<int> di = {1, 0, -1, 0};
  vector<int> dj = {0, 1, 0, -1};
  using pi = pair<int,int>;
  while(t-- > 0) {
    int n,m; cin >> n >> m;
    vector<vector<char>> c(n, vector<char>(m));
    rep(i,n) rep(j,m) cin >> c[i][j];
    bool f = true;
    rep(i,n) rep(j,m) {
      if(c[i][j] == 'B') {
	rep(k,4) {
	  int ni = i + di[k];
	  int nj = j + dj[k];
	  if(0 <= ni && ni < n && 0 <= nj && nj < m) {
	    if(c[ni][nj] == '.') c[ni][nj] = '#';
	    else if(c[ni][nj] == 'G') f = false;
	  }
	}
      }
    }
    if( !f ) {
      res.push_back("No");
      continue;
    }
    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pi> q;
    q.push({n-1, m-1});
    d[n-1][m-1] = 0;
    if(c[n-1][m-1] == '#') q.pop();
    while( !q.empty() ) {
      pi p = q.front(); q.pop();
      int i = p.first, j = p.second;
      rep(k,4) {
	int ni = i + di[k];
	int nj = j + dj[k];
	if(0 <= ni && ni < n && 0 <= nj && nj < m) {
	  if(d[ni][nj] == -1 && (c[ni][nj] == 'G' || c[ni][nj] == '.')) {
	    d[ni][nj] = d[i][j] + 1;
	    q.push({ni, nj});
	  }
	}
      }
    }
    rep(i,n) {
      rep(j,m) {
	if(c[i][j] == 'G' && d[i][j] == -1) f = false;
      }
    }
    res.push_back((f ? "Yes" : "No" ));
  }
  for(auto val: res) cout << val << "\n";
  
  return 0;
}
