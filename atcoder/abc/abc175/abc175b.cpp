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
  ll n; cin >> n;
  vector<ll> l(n);
  rep(i,n) cin >> l[i];

  ll res = 0;
  rep(i,n) rep(j,n) rep(k,n) {
    if(l[i] == l[j] || l[i] == l[k] || l[j] == l[k]) continue;
    if(i < j && j < k) {
      if(2 * max({l[i], l[j], l[k]}) < l[i] + l[j] + l[k]) {
	res++;
      }
    }
  }
  cout << res << "\n";


  
  return 0;
}
