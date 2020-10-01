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
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// n を素因数分解する.返り値はmap.計算量はO(sqrt(n))
map<int,int> primefactor(int n){
  int nn = n;
  map<int,int> res;
  for(int i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}

// ユークリッドの互除法で最大公約数を求める
int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
int lcm(int a,int b){
  return a*b/gcd(a,b);
}


int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    map<int,int> pf = primefactor(n);
    vector<pi> a;
    int cnt = 0;
    for(auto val: pf) {
      auto [fi, se] = val;
      a.push_back({fi,se});
    }
    int m = a.size();
    vi res;
    vi v(m);
    auto rec = [&](auto self, int idx) ->void{
		 if(idx == m) {
		   rep1(i,(1 << m)-1) {
		     int g = i ^ (i >> 1);
		     int tmp = 1;
		     rep(j,m) {
		       if(v[j] >= 2) 
		       if(((g >> j) & 1) && v[j] == 1 ) {
			 tmp *= a[j].first;
		       }
		     }
		     res.push_back(tmp);
		   }
		   int rs = res.size();
		   if(rs >= 2) swap(res[rs-1], res[rs-2]);
		   return ;
		 }
		 rep(i,a[idx].second) {
		   v[idx] = i+1;
		   self(self, idx+1);
		 }
	       };

    rec(rec, 0);
    
    for(auto val: res) cout << val << " ";
    cout << "\n";
    rep(i,(int)res.size()) {
      if(gcd(res[i], res[(i+1) % (int)res.size()]) == 1) cnt++;
    }
    cout << cnt << "\n";
  }
  return 0;
}
