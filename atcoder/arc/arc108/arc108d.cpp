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
// Modint
// modint<MOD> で宣言
template<long long MOD>
struct modint{
  long long x;
  long long mod = MOD;
  modint(long long x=0):x(x%MOD){}
  modint& operator+=(const modint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator-=(const modint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator*=(const modint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  modint operator+(const modint a) const{
    modint res(*this);
    return res+=a;
  }
  modint operator-(const modint a) const{
    modint res(*this);
    return res-=a;
  }
  modint operator*(const modint a) const{
    modint res(*this);
    return res*=a;
  }
  modint pow(long long t) const{
    if(!t) return 1;
    modint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  modint inv() const{
    return pow(MOD-2);
  }
  modint& operator/=(const modint a){
    return (*this) *= a.inv();
  }
  modint operator/(const modint a) const{
    modint res(*this);
    return res/=a;
  }
};
using mint = modint<1000000007>;

int main()
{
  int n; cin >> n;
  vi c(4);
  rep(i,4) {
    char tmp; cin >> tmp;
    if(tmp == 'A') c[i] = 0;
    else c[i] = 1;
  }

  if(c[1] == 1) {
    rep(i,4) c[i] = !c[i];
    swap(c[0],c[3]);
  }
  
  if(c[0] == 0 || n <= 3) {
    cout << 1 << "\n";
  }
  else if(c[2] == 0) {
    vector<mint> dp1(2);
    dp1[0].x = 1;
    rep(i,n-3) {
      vector<mint> dp2(2);
      dp2[0] += dp1[0] + dp1[1];
      dp2[1] += dp1[0];
      swap(dp1, dp2);         
    }
    cout << (dp1[0]+dp1[1]).x << "\n";
  }
  else {
//    if(c[3] == 0) {
      mint res = mint(2).pow(n-3);
      cout << res.x << "\n"; 
//    }
//    else {
    //   mint res = mint(n-2)*mint(n-3)/mint(2);
    //   res += mint(1);
    //   cout << res.x << "\n";
    // }
  }

  return 0;
}
