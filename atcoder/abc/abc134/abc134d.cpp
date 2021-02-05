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
// xの約数を列挙する.返り値はvector.O(sqrt(x))
vector<int> divisor(int x){
  vector<int> res;
  for(int i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}


int main()
{
  int n; cin >> n;
  vvi div(n+1);
  rep1(i,n) {
    div[i] = divisor(i);
  }

  vi a(n+1);
  rep1(i,n) {
    cin >> a[i];
  }
  vi x(n+1, 0);
  vi res;
  for (int i = n; i > 0; --i) {
    if(x[i] % 2 == a[i] % 2) {
      
    }
    else {
      res.push_back(i);
      for(auto tmp: div[i]) {
	x[tmp]++;
      }
    }
  }
  cout << sz(res) << "\n";
  if(sz(res) == 0) return 0;
  for(auto tmp: res) cout << tmp << " ";
  cout << "\n";
  return 0;
}
