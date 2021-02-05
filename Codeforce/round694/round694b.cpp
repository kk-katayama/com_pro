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
class Sieve {
private:
  const int NMAX = 1010;
  vector<bool> prime;
  
public:
  vector<int> pr;
  vector<int> sum;
  
  Sieve() {}

  void Build() {
    sum.assign(NMAX+1, 0);
    prime.assign(NMAX, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < NMAX; ++i) {
      if(prime[i]) {
	pr.push_back(i);
	sum[i+1] = sum[i] + 1;
	int j = i;
	while(j <= NMAX) {
	  prime[j] = false;
	  j += i;
	}
      }
      else {
	sum[i+1] = sum[i];
      }
    }
  }

  // 区間[l, r) の間にある素数の個数は？
  int Count(int l, int r) {
    return sum[r] - sum[l];
  }
  
  
};

int main()
{
  Sieve sie;
  sie.Build();
  auto fanc = [&](ll x)->ll {
    ll res = x;
    for(auto tmp: sie.pr) {

      while(res % (tmp*tmp) == 0) res /= (tmp*tmp);
    }
    return res;
  };
  int q; cin >> q;
  while(q-- > 0) {
    int n; scanf("%d", &n);
    vl a(n);
    rep(i,n) scanf("%lld", &a[i]);
    map<ll,ll> mp;
    ll res1 = 0;
    rep(i,n) {
      ll tmp = fanc(a[i]);
      //      cout << a[i] <<"*"<< tmp << "\n";
      mp[tmp]++;
      chmax(res1, mp[tmp]);
    }
    ll res2 = res1;
    for(auto tmp: mp) {
      auto [key, val] = tmp;
      if(key == 1) continue;
      if(val % 2 == 0) {
	mp[1] += val;
	chmax(res2, mp[1]);
      }
    }
    int qq; cin >> qq;
    while(qq-- > 0) {
      int w; scanf("%d", &w);
      if(w == 0) cout << res1 << "\n";
      else cout << res2 << "\n";
    }
  }
  return 0;
}
