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
  int a,b; cin >> a >> b;
  vi p1(a),p2(b);
  rep(i,a) cin >> p1[i];
  rep(i,b) cin >> p2[i];

  vector<char> res(10, 'x');
  rep(i,a) res[p1[i]] = '.';
  rep(i,b) res[p2[i]] = 'o';

  for (int i = 7; i <= 9; ++i) {
    cout << res[i] << " ";
  }
  cout << res[0] << "\n";
  cout << " ";
  for (int i = 4; i <= 6; ++i) {
    cout << res[i] << " ";    
  }
  cout << "\n";
  cout << " ";
  cout << " ";  
  for (int i = 2; i <= 3; ++i) {
    cout << res[i] << " ";    
  }
  cout << "\n";
  cout << " ";
  cout << " ";
  cout << " ";  
  cout << res[1] << "\n";
  return 0;
}
