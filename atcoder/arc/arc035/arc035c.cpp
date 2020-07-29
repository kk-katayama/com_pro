#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  ll n,m; cin >> n >> m;
  const ll inf = (1LL << 60);
  vector<vector<ll>> d(n, vector<ll>(n, inf));
  rep(i,m) {
    ll a,b,c; cin >> a >> b >> c;
    chmin(d[a-1][b-1], c);
    chmin(d[b-1][a-1], c);    
  }
  rep(i,n) d[i][i] = 0;
  ll K; cin >> K;
  vector<ll> x(K),y(K),z(K);
  rep(i,K) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--; y[i]--;
  }
  rep(k,n) rep(i,n) rep(j,n) chmin(d[i][j], d[i][k] + d[k][j]);
  
  rep(k,K) {
    rep(i,n) rep(j,n) {
      chmin(d[i][j], d[i][x[k]] + d[y[k]][j] + z[k]);
      chmin(d[i][j], d[j][x[k]] + d[y[k]][i] + z[k]);      
    }
    ll res = 0;
    rep(i,n) rep(j,n) {
      if(i >= j) continue;
      res += d[i][j];
    }
    cout << res << "\n";

  }
  
  return 0;
}
