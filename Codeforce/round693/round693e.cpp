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
struct info {
  int a,b,id;
};
int main()
{
  int q; cin >> q;

  while(q-- > 0) {
    int n; cin >> n;
    vector<info> p(n);
    rep(i,n) {
      cin >> p[i].a >> p[i].b;
      p[i].id = i;
      if(p[i].a > p[i].b) swap(p[i].a, p[i].b);
    }
    
    sort(p.begin(), p.end(), [](info x, info y){
      return x.a < y.a;
    });

    int mn = inf, idx = -1;
    int mn2 = inf, idx2 = -1;
    vi res(n, -1);
    rep(i,n) {
      if(i != 0 && p[i-1].a != p[i].a) {
	mn = mn2;
	idx = idx2;
      }
      if(mn < p[i].b) {
	res[p[i].id] = idx+1;
      }
      if(chmin(mn2, p[i].b)) {
	idx2 = p[i].id;
      }
    }
    for(auto tmp: res) cout << tmp << " ";
    cout << "\n";
  }
  return 0;
}
