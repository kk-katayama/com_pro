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
int main()
{
  int n,d; cin >> n >> d;
  int x,y; cin >> x >> y;

  x = abs(x);
  y = abs(y);
  if(x % d != 0 || y % d != 0) {
    cout << 0 << "\n";
    return 0;
  }

  int a = x/d, b = y/d;
  if( (n - a - b) % 2 != 0) {
    cout << 0 << "\n";
    return 0;    
  }

  int r = (n - a - b) / 2;
  ld res = 0;
  const ld eps = 1e-10;
  rep(i, r+1) {
    ld tmp = 1;
    vector<ld> v;
    rep(j,n) v.push_back(4);
    int j = r - i;
    rep1(k,a+i) v.push_back(k);
    rep1(k,i) v.push_back(k);
    rep1(k,b+j) v.push_back(k);
    rep1(k,j) v.push_back(k);
    ld m = n;
    int cnt = 0;
    while(m > 0 || cnt < sz(v)) {
      if(m == 0) {
	tmp /= v[cnt];
	cnt++;		
      }
      else if(tmp > 1 + eps && cnt < sz(v)) {
	tmp /= v[cnt];
	cnt++;	
      }
      else if(m > 0){
	tmp *= m;
	m--;	
      }
    }
    res += tmp;
  }
  printf("%.10Lf\n", res);
  return 0;
}
