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
  vi a = {1, 2, 3, 4, 5, 6};
  //  vi b = {1, 2, 3, 4, 5, 6};
  n = n % 30;
  rep(i,n) {
    int x = i%5;
    int y = i%5+1;
    swap(a[x], a[y]);
    // bool f = true;
    // rep(j,6) {
    //   if(a[j] != b[j]) f = false;
    // }
    // if(f) cout << i << "\n";
  }
  rep(i,6) cout << a[i];
  cout  << "\n";
  return 0;
}
