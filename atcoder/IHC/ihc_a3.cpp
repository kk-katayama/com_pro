#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <random>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
ll rand26() {
  random_device rnd;
  mt19937 mt(rnd());
  uniform_real_distribution<> rand(0, 25);
  return (ll)rand(mt);
}
ll rand365() {
  random_device rnd;
  mt19937 mt(rnd());
  uniform_real_distribution<> rand(0, 364);
  return (ll)rand(mt);
}
int main()
{
  ll D; cin >> D;
  vector<ll> c(26);
  rep(i,26) cin >> c[i];
  vector<vector<ll>> s(D, vector<ll>(26));
  vector<ll> t(D);  
  rep(i,D) {
    ll smax = -1;
    rep(j,26) {
      cin >> s[i][j];
      if(smax <= s[i][j]) {
	smax = s[i][j];
	t[i] = j;
      }
    }
  }
  
  ll m = 26*365*140;
  vector<ll> d(m), q(m);
  rep(k,140) {
    rep(i,26) {
      rep(j,365) {
	d[k*26*365 + i*365 + j] = (j + k) % 365;
	q[k*26*365 + i*365 + j] = (i + k) % 26;
      }
    }
  }
  
  vector<set<ll>> st(26);
  rep(i,26) {
    st[i].insert(-1);
    st[i].insert(D);    
  }
  rep(i,D) {
    st[t[i]].insert(i);
  }

  ll res = 0;
  // ペナルティ
  vector<ll> pen(26, 0);
  rep(i,26) {
    auto it = st[i].begin();
    it++;
    while(it != st[i].end()) {
      auto it2 = it;
      it2--;
      ll x = *it - *it2 - 1;
      res -= x * (x + 1) / 2 * c[i];
      pen[i] += x * (x + 1) / 2 * c[i];
      it++;
    }
  }
  rep(i,D) {
    res += s[i][t[i]];
  }

  rep(i,m){
    ll oldres = res;
    ll old = t[d[i]];
    ll neww = q[i];
    if(old == neww) continue;
    set<ll> oldst1 = st[old];
    set<ll> oldst2 = st[neww];    
    ll oldpen1 = pen[old];
    ll oldpen2 = pen[neww];
    
    res += s[d[i]][neww] - s[d[i]][old];
    st[old].erase(d[i]);
    st[neww].insert(d[i]);    
    // old
    res += pen[old];
    pen[old] = 0;
    auto it = st[old].begin();
    it++;
    while(it != st[old].end()) {
      auto it2 = it;
      it2--;
      ll x = *it - *it2 - 1;
      res -= x * (x + 1) / 2 * c[old];
      pen[old] += x * (x + 1) / 2 * c[old];
      it++;
    }
    // new
    res += pen[neww];
    pen[neww] = 0;
    it = st[neww].begin();
    it++;
    while(it != st[neww].end()) {
      auto it2 = it;
      it2--;
      ll x = *it - *it2 - 1;
      res -= x * (x + 1) / 2 * c[neww];
      pen[neww] += x * (x + 1) / 2 * c[neww];
      it++;
    }

    if(oldres < res) {
      t[d[i]] = neww;
    }
    else {
      t[d[i]] = old;
      st[old] = oldst1;
      st[neww] = oldst2;
      pen[old] = oldpen1;
      pen[neww] = oldpen2;      
    }
  }

  rep(i,D) cout << t[i]+1 << "\n";
  
  return 0;
}
