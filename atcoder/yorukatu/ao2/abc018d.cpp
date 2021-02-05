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
#include <bitset>
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
int main()
{
  int n,m,p,q,r; cin >> n >> m >> p >> q >> r;
  vi x(r),y(r),z(r);
  rep(i,r) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--; y[i]--;
  }
  
  vector<vector<pi>> e(n);
  rep(i,r) {
    e[x[i]].push_back({y[i], z[i]});
  }

  vvi otoko((1 << n), vi(m, 0));
  int comb=(1<<p)-1;//辞書順最小
  while(comb<(1<<n)){//n個の要素から選ぶのでcomb>=(1<<n)となってはいけない
    rep(i,n){
      if((comb >> i) & 1) {
	for(auto val: e[i]) {
	  auto [to, cost] = val;
	  otoko[comb][to] += cost;
	}
      }
    }
    // cout << bitset<4>(comb) << "\n";
    // for(auto val: otoko[comb]) cout << val << " ";
    // cout << "\n";
    int x=comb&-comb;//最下位の1bitを独立させたもの
    int y=comb+x;//combの最下位の1の連続した部分を0に変え、その部分より1つ上の位を1に変える
    comb=((comb&~y)/x>>1)|y;
  }

  int res = 0;
  comb=(1<<p)-1;//辞書順最小
  while(comb<(1<<n)){//n個の要素から選ぶのでcomb>=(1<<n)となってはいけない
    sort(otoko[comb].begin(), otoko[comb].end(), [](int a, int b) {
						   return a > b;
						 });
    int tmp = 0;
    rep(i,q) {
      tmp += otoko[comb][i];
    }
    chmax(res, tmp);
    int x=comb&-comb;//最下位の1bitを独立させたもの
    int y=comb+x;//combの最下位の1の連続した部分を0に変え、その部分より1つ上の位を1に変える
    comb=((comb&~y)/x>>1)|y;
  }  
  cout << res << "\n";
  
  return 0;
}
