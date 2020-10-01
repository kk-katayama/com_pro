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
map<int,ll> primefactor(int n){
  int nn = n;
  map<int,ll> res;
  for(int i=2;i*i<=nn;++i){
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
  int n; cin >> n;
  ll res = 0;
  rep1(c,n-1) {
    map<int,ll> mp = primefactor(n-c);
    ll tmp = 1;
    for(auto val: mp) {
      tmp *= (val.second + 1);
    }
    res += tmp;
  }
  cout << res << "\n";
  
  return 0;
}
