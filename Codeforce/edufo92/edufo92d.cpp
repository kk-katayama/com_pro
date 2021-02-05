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
  int q; cin >> q;
  while(q-- > 0) {
    ll n,k; cin >> n >> k;
    ll a,b,c,d; cin >> a >> b >> c >> d;

    if(a > c) {
      swap(a, c);
      swap(b, d);
    }
    if(c <= b) {
      if(b < d) 
	k -= (b - c)*n;
      else
	k -= (d - c)*n;
      if(k <= 0) {
	cout << 0 << "\n";
	continue;
      }
      ll A = abs(b - d) + c - a;
      if(k <= n*A) {
	cout << k << "\n";
	continue;
      }
      k -= n*A;
      cout << n*A + k*2 << "\n";
    }
    else {
      ll A = c - b;
      ll B = (d - c) + (c - a);
      if(k <= B) {
	cout << A + k << "\n";
	continue;
      }
      if(B <= A) {
	cout << A + B + 2*(k - B) << "\n";
	continue;
      }
      if(n <= k/B) {
	cout << (A + B)*n + (k - n*B)*2 << "\n";
	continue;
      }
      //      k -= k/B * B;
      if(A < (k - k/B*B)) {
	cout << k/B * (A + B) + A + (k - k/B * B) << "\n";
      }
      else {
	cout << k/B * (A + B) + (k - k/B * B) * 2 << "\n";	
      }
    }
    
  }
  return 0;
}
