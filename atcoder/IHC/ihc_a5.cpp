#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <random>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll D; cin >> D;
  vector<ll> c(26);
  rep(i,26) cin >> c[i];
  vector<vector<ll>> s(D, vector<ll>(26));
  rep(i,D) {
    rep(j,26) {
      cin >> s[i][j];
    }
  }

  vector<ll> t(D);  
  vector<ll> last(26, -1);
  rep(i,D) {
    ll score = -1000000000;
    rep(j,26) {
      ll tmp = 0;
      rep(k,26) {
	if(j == k) {
	  tmp += s[i][j];
	}
	else {
	  tmp -= c[k] * (i - last[k]);
	}
      }
      if( chmax(score, tmp) ) {
	t[i] = j;
      }
    }
    last[t[i]] = i;
  }
  
  ll m = 26*365*30;
  vector<ll> d(m), q(m);
  rep(k,30) {
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

  random_device rnd;
  mt19937 mt(rnd());
  uniform_real_distribution<> rand365(0, 364);
  uniform_real_distribution<> rand1(0, 1);
  
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

  double par = 1.00;
  double prob = 0.0;
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
    else if((double)oldres < (double)res * par) {
      if(rand1(mt) < prob) {
    	t[d[i]] = neww;
    	par = max(1., par * 0.99);
    	prob *= 0.99;
      }
    }    
    else {
      t[d[i]] = old;
      st[old] = oldst1;
      st[neww] = oldst2;
      pen[old] = oldpen1;
      pen[neww] = oldpen2;      
    }
  }  

  par = 1.5;
  prob = 0.2;
  int N = 1e+7;
  ll cnt = 0;
  double T = 2e+3;
  rep(i,N) {
    if(cnt >= 5e+5) break;
    // rep(l,2) {
    // rep(i,365){
    //   rep1(k,365) {
    ll d1 = (i) % 365;      
    //    ll d1 = rand365(mt);
    //      ll d2 = (i + k) % 365;
    ll d2 = rand365(mt);
    ll oldres = res;
    ll old = t[d1];
    ll neww = t[d2];
    if(old == neww) continue;
    cnt++;
    set<ll> oldst1 = st[old];
    set<ll> oldst2 = st[neww];    
    ll oldpen1 = pen[old];
    ll oldpen2 = pen[neww];

    res += s[d1][neww] - s[d1][old];
    st[old].erase(d1);
    st[neww].insert(d1);    
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
    
    res += s[d2][old] - s[d2][neww];
    st[neww].erase(d2);
    st[old].insert(d2);    
    // old
    res += pen[old];
    pen[old] = 0;
    it = st[old].begin();
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
    double delta = res - oldres;
    
    if(oldres < res) {
      t[d1] = neww;
      t[d2] = old;
    }
    // else if((double)oldres < (double)res * par) {
    //   if(rand1(mt) < prob) {
    // 	t[d1] = neww;
    // 	t[d2] = old;
    // 	par = max(1., par * 0.99);
    // 	prob *= 0.99;	
    //   }
    // }
    else if(rand1(mt) < exp(delta/T)) {
    	t[d1] = neww;
    	t[d2] = old;
	T = max(T*0.99, 1.);
    }    
    else {
      t[d1] = old;
      t[d2] = neww;      
      st[old] = oldst1;
      st[neww] = oldst2;
      pen[old] = oldpen1;
      pen[neww] = oldpen2;      
    }
    //   }
    // }
  }
  /*
  int M = 1e+5;
  rep(i,M) {
    ll d1 = (i) % 365;      
    ll d2 = (i + 1) % 365;      
    ll oldres = res;
    ll old = t[d1];
    ll neww = t[d2];
    if(old == neww) continue;
    set<ll> oldst1 = st[old];
    set<ll> oldst2 = st[neww];    
    ll oldpen1 = pen[old];
    ll oldpen2 = pen[neww];

    res += s[d1][neww] - s[d1][old];
    st[old].erase(d1);
    st[neww].insert(d1);    
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
    
    res += s[d2][old] - s[d2][neww];
    st[neww].erase(d2);
    st[old].insert(d2);    
    // old
    res += pen[old];
    pen[old] = 0;
    it = st[old].begin();
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
      t[d1] = neww;
      t[d2] = old;
    }
    else {
      t[d1] = old;
      t[d2] = neww;      
      st[old] = oldst1;
      st[neww] = oldst2;
      pen[old] = oldpen1;
      pen[neww] = oldpen2;      
    }
  }  
  */
  rep(i,D) cout << t[i]+1 << "\n";
  
  return 0;
}
