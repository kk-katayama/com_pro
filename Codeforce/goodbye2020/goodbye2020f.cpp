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
#include <bitset>
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
class xor_base{
public:
  vector<ll> base; // 基底の集合
  vector<ll> tab1,tab2,tab3;

  xor_base(int n) {
    tab1.assign(n, 0);
    tab2.assign(n, -1);
    tab3.assign(n, -1);    
  }
  
  // 要素を追加
  // 要素が線形独立ならtrue, 線形従属ならfalseをreturn
  bool insert(ll a) {
    for(auto val: base) {
      a = min(a, a ^ val);
      if(a == 0) return false;
    }
    base.push_back(a);
    sort(base.begin(), base.end(), [](ll a, ll b){
      return a > b;
    });
    return true;
  }

  bool insert(ll k, vl v) {
    if(k == 1) {
      int val = v[0];
      while(tab2[val] >= 0) {
	val = tab2[val];
      }
      if(tab1[val]) return false;
      tab1[val] = 1;
      return true;
    }
    else {
      int val1 = v[0], val2 = v[1];
      int cnt = 2;
      while(tab2[val1] >= 0) {
	val1 = tab2[val1];
      }
      if(tab1[val1]) {
	cnt--;
	val1 = -1;
      }
      while(tab2[val2] >= 0) {
	val2 = tab2[val2];
      }	
      if(tab1[val2]) {
	cnt--;
	val2 = -1;
      }
      if(val1 == val2) return false;
      if(cnt == 2) {
	if(val1 < val2) swap(val1, val2);
	tab2[val1] = val2;
	tab3[val2] = val1;
	if(tab3[val1] >= 0) val1 = tab3[val1];
	tab2[val1] = val2;
	tab3[val2] = val1;
	return true;
      }
      else if(cnt == 1) {
	if(val1 >= 0) tab1[val1] = 1;
	if(val2 >= 0) tab1[val2] = 1;
	return true;
      }
      else return false;
    }
  }
  
  // 要素が線形独立かチェック
  bool check(ll a) {
    for(auto val: base) {
      a = min(a, a ^ val);
      if(a == 0) return false;
    }
    return true;
  }

  void show() {
    for(auto val: base) {
      cout << bitset<4>(val) << "\n";
    }
  }

};
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
  int n,m; cin >> n >> m;
  xor_base xb(m);
  vi res;
  int cnt = 0;
  rep(i,n) {
    ll k; scanf("%lld", &k);
    vl v(k);
    rep(j,k) {
      scanf("%lld", &v[j]);
      v[j]--;
    }
    if(xb.insert(k, v)) {
      cnt++;
      res.push_back(i+1);
    }
  }
  mint ans = mint(2).pow(cnt);
  cout << ans.x << " " << sz(res) << "\n";
  for(auto tmp: res) cout << tmp << " ";
  cout << "\n";
  
  return 0;
}
