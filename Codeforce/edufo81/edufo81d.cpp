#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// ユークリッドの互除法で最大公約数を求める
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

// n を素因数分解する.返り値はmap.計算量はO(sqrt(n))
map<ll,int> primefactor(ll n){
  ll nn = n;
  map<ll,int> res;
  for(ll i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}

int main()
{
  int q; cin >> q;
  while(q-- > 0) {
    ll a,m; cin >> a >> m;
    map<ll,int> ap = primefactor(a);
    map<ll,int> mp = primefactor(m);
    ll g = gcd(a, m);
    map<ll,int> gp = primefactor(g);
    map<ll,int> lp;
    vl st;
    // for(auto tmp: ap) {
    //   auto [key, val] = tmp;
    //   lp[key] = max(mp[key], val);
    // }
    // for(auto tmp: mp) {
    //   auto [key, val] = tmp;
    //   lp[key] = max(ap[key], val);
    // }    
    for(auto tmp: mp) {
      auto [key, val] = tmp;
      //      cout << key << ":" << val << "\n";
      if(gp[key] < val) {
	//	ll x = pow(key, gp[key]);
	st.push_back(key);
      }
    }
    int n = sz(st);
    //    rep(i,n) cout << st[i] << "\n";
    ll res = (a+m-1)/g - (a-1)/g;
    rep1(S,(1<<n)-1) {
      int cnt = 0;
      ll h = g;
      rep(i,n) {
	if((S >> i) & 1) {
	  h *= st[i];
	  cnt++;
	}
      }
      //      cout << h << ":" << cnt  << "\n";
      if(cnt % 2 == 0) res += (a+m-1)/h - (a-1)/h;
      else res -= (a+m-1)/h - (a-1)/h;
    }
    cout << res << "\n";
  }
  return 0;
}
