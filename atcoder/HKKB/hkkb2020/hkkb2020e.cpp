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
template<ll MOD>
struct modint{
  ll x;
  ll mod = MOD;
  modint(ll x=0):x(x%MOD){}
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
  modint pow(ll t) const{
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
  int h,w; cin >> h >> w;
  vector<string> s(h);
  rep(i,h) {
    cin >> s[i];
  }

  vector<mint> pow2(4000010);
  pow2[0].x = 1;
  rep(i,4000000) pow2[i+1] = pow2[i] * (mint)2;
  
  int k = 0;
  //  vector<set<int>> tate(w), yoko(h);
  vector<vector<int>> tate(w), yoko(h);
  rep(i,h) {
    yoko[i].push_back(-1);
    yoko[i].push_back(w);    
  }
  rep(i,w) {
    tate[i].push_back(-1);
    tate[i].push_back(h);    
  }  
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '.') {
	k++;
      }
      else {
	tate[j].push_back(i);
	yoko[i].push_back(j);
      }
    }
  }

  rep(i,h) {
    sort(yoko[i].begin(), yoko[i].end());
  }
  rep(i,w) {
    sort(tate[i].begin(), tate[i].end());
  }  
  
  mint res;
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '.') {
	int lb = -1, ub = sz(yoko[i]) + 1;
	while(ub - lb > 1) {
	  int mid = (ub + lb) / 2;
	  if(yoko[i][mid] > j) ub = mid;
	  else lb = mid;
	}
	int y = ub;
	lb = -1; ub = sz(tate[j]) + 1;
	while(ub - lb > 1) {
	  int mid = (ub + lb) / 2;
	  if(tate[j][mid] > i) ub = mid;
	  else lb = mid;
	}	
	// auto it = yoko[i].upper_bound(j);
	// auto it2 = it; it2--;
	// auto it3 = tate[j].upper_bound(i);
	// auto it4 = it3; it4--;
	//	int x = *it - *it2 - 1 + *it3 - *it4 - 1 - 1;
	int x = yoko[i][y] - yoko[i][y-1] - 1 + tate[j][ub] - tate[j][ub-1] - 1 - 1;
	res += pow2[k] - pow2[k - x];
      }
    }
  }
  cout << res.x << "\n";
  
  return 0;
}
