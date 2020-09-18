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
// ユークリッドの互除法で最大公約数を求める
int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
int lcm(int a,int b){
  return a*b/gcd(a,b);
}
int main()
{
  int n; scanf("%d", &n);
  vector<int> a(n);
  rep(i,n) {
    scanf("%d", &a[i]);	
  }
  if(n % 2 == 0) {
    vi b(n);
    for (int i = 0; i < n; i += 2) {
      int l = lcm(a[i], a[i+1]);
      b[i] = l / a[i];
      b[i+1] = - l / a[i+1];
    }
    rep(i,n) {
      if(i < n - 1) cout << b[i] << " ";
      else cout << b[i] << "\n";
    }
  }
  else {
    vi b(n);
    int na = lcm(a[0], a[1]);
    int nl = lcm(na, a[2]);
    b[0] = nl / a[0];
    b[1] = nl / a[1];
    b[2] = - 2 * nl / a[2];
    for (int i = 3; i < n; i += 2) {
      int l = lcm(a[i], a[i+1]);
      b[i] = l / a[i];
      b[i+1] = - l / a[i+1];
    }
    rep(i,n) {
      if(i < n - 1) cout << b[i] << " ";
      else cout << b[i] << "\n";
    }    
  }

  
  return 0;
}
