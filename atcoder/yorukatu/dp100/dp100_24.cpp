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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
typedef long long ll;
const ll MOD=1e+9+7;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
};


int main()
{
  string s; cin >> s;
  int n = s.size();

  vector<mint> dp(3);
  mint tmp(1);
  rep(i,n) {
    vector<mint> ndp = dp;
    if(s[i] == 'A') {
      ndp[0] += (mint)tmp;
    }
    if(s[i] == 'B') {
      ndp[1] += dp[0];
    }
    if(s[i] == 'C') {
      ndp[2] += dp[1];
    }
    if(s[i] == '?') {
      ndp[0] = dp[0] * (mint)3 + tmp;
      ndp[1] = dp[1] * (mint)3 + dp[0];
      ndp[2] = dp[2] * (mint)3 + dp[1];
      tmp *= (mint)3;
    }
    dp = ndp;
  }
  cout << dp[2].x << "\n";
  return 0;
}
