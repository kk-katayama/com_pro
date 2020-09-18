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
#include <complex>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
using namespace atcoder;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();

int main()
{
  int n,m; cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) {
    scanf("%lld", &a[i]);	
  }
  vector<ll> b(m);
  rep(i,m) {
    scanf("%lld", &b[i]);	
  }

  
  vector<ll> res = convolution<998244353>(a, b);
  for(auto val: res) cout << val << " ";
  cout << "\n";
  
  return 0;
}
