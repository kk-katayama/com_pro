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
using pl = pair<ll,ll>;
int main()
{
  ll n,m; cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(m),c(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i] >> c[i];

  vector<pl> v;
  rep(i,n) {
    v.push_back({a[i], 1});
  }
  rep(i,m) {
    v.push_back({c[i], b[i]});    
  }

  sort(v.begin(), v.end(), [](pl x, pl y){
			     return x.F > y.F;
			   });
  int idx = 0;
  ll res = 0;
  while(n-- > 0) {
    if(v[idx].S > 0) {
      res += v[idx].F;
      v[idx].S--;
    }
    else {
      idx++;
      res += v[idx].F;
      v[idx].S--;      
    }
  }
  cout << res << "\n";
  
  return 0;
}
