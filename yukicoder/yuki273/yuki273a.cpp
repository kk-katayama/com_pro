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

  int n; cin >> n;
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  vi vec(n);
  rep(i,n) vec[i] = i;
  int mx = -1;
  int cnt = 1;
  do{
    vi c(n);
    rep(i,n) c[i] = a[vec[i]];
    int tmp = 0;
    rep(i,n) {
      tmp += max(0, c[i] - b[i]);
    }
    if(mx == tmp) cnt++;
    else if(mx < tmp){
      mx = tmp;
      cnt = 1;
    }
  } while(next_permutation(vec.begin(), vec.end()));
  cout << cnt << "\n";

  
  return 0;
}
