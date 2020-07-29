#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n; cin >> n;
  string s; cin >> s;
  int buf = 0;
  rep(i,n) {
    if(s[i] == '1') buf++;
  }
  if(buf == 0) {
    rep(i,n) cout << 1 << "\n";
    return 0;
  }
  
  
  ll sum1 = 0, sum2 = 0;
  ll pow2 = 1;
  vector<ll> pow21(n), pow22(n);
  reverse(s.begin(), s.end());
  rep(i,n) {
    if(s[i] == '1') {
      sum1 = (sum1 + pow2 % (buf + 1)) % (buf + 1);
    }
    pow21[i] = pow2;
    pow2 = (pow2 * 2) % (buf + 1);
  }
  pow2 = 1;
  if(buf != 1) {
    rep(i,n) {
      if(s[i] == '1') {
	sum2 = (sum2 + pow2 % (buf - 1)) % (buf - 1);
      }
      pow22[i] = pow2;    
      pow2 = (pow2 * 2) % (buf - 1);
    }
  }
  int M = 4e+5;
  vector<int> f(M+1);
  f[0] = 0;
  rep1(i,M) {
    int x = i;
    int cnt = 1;
    while(x % __builtin_popcount(x) != 0) {
      x = x % __builtin_popcount(x);
      cnt++;
    }
    f[i] = cnt;
  }
  
  
  vector<int> res(n);
  rep(i,n) {
    if(s[i] == '0') {
      int x = (sum1 + pow21[i]) % (buf + 1);
      res[i] = f[x] + 1;
    }
    else if(buf == 1) {
      res[i] = 0;
    }
    else {
      int x = (sum2 - pow22[i] + buf - 1) % (buf - 1);
      res[i] = f[x] + 1;      
    }
  }
  
  reverse(res.begin(), res.end());
  for(auto val: res) cout << val << "\n";

  
  return 0;
}
