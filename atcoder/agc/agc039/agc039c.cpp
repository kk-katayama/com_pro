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
// ランレングス圧縮.配列の連続している要素をまとめてしまう圧縮.
vector<pair<ll,int>> rle(vector<ll> a){
  vector<pair<ll,int>> res;
  int n = a.size();
  int cnt = 1;
  pair<ll,int> p;
  p.first = a[0];
  rep(i,n-1){
    if(a[i]==a[i+1]){
      cnt++;
    }
    else{
      p.second = cnt;
      res.push_back(p);
      cnt = 1;
      p.first = a[i+1];
    }
  }
  p.second = cnt;
  res.push_back(p);
  return res;
}
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
using mint = modint<998244353>;

int main()
{
  // int n = 511;
  // rep1(i,n) {
  //   int j = i;
  //   if(j % 2 == 0) j = j/2 + 256;
  //   else j /= 2;
  //   int cnt = 1;
  //   while(j != i) {
  //     if(j % 2 == 0) j = j/2 + 256;
  //     else j /= 2;
  //     cnt++;
  //   }
  //   cout << bitset<9>(i) << ":" << cnt << "\n";
  // }

  ll n; cin >> n;
  string s; cin >> s;

  map<ll,ll> mp;
  ll x = 0;
  rep(i,n) {
    if(s[i] == '1') x += pow(2, n-1-i);
  }
  ll res2 = 0;
  rep(i,x+1) {
    ll j = i;
    if(j % 2 == 0) j = j/2 + pow(2, n-1);
    else j /= 2;
    ll cnt = 1;
    while(j != i) {
      if(j % 2 == 0) j = j/2 + pow(2, n-1);
      else j /= 2;
      cnt++;
    }
    res2 += cnt;
    mp[cnt]++;
  }

  for(auto val: mp) {
    auto [num, cnt] = val;
    cout << num << ":" << cnt << "\n";
  }

  cout << res2 << "\n";
  vl a(n);
  rep(i,n) a[i] = ll(s[i] - '0');
  vector<pair<ll,int>> p = rle(a);

  mint res;
  mint cnt;
  ll k = 3;
  while(k <= n) {
    if(n % k != 0) {
      k += 2;
      continue;
    }
    ll m = n / k;
    if(p[0].first == 1) {
      if(p[0].second > m) {
	res += mint(2*m * 2*m);
	cnt += mint(2*m);
      }
      else {
	ll j = p[0].second;
	int id = 1;
	bool par = false;
	while(1) {
	  if(id == k) {
	    res += mint(2*m * (m+j));
	    cnt += mint(m+j);
	    break;
	  }
	  else {
	    ll l = p[id].second;
	    if(par) { // 1
	      if(l > m) {
		res += mint(2*m * (m+j));
		cnt += mint(m+j);
		break;
	      }
	      else if(l < m) {
		res += mint(2*m * (m+j-1));
		cnt += mint(m+j-1);
		break;
	      }
	    }
	    else { // 0
	      if(l < m) {
		res += mint(2*m * (m+j));
		cnt += mint(m+j);
		break;
	      }
	      else if(l > m) {
		res += mint(2*m * (m+j-1));
		cnt += mint(m+j-1);
		break;
	      }
	    }
	  }
	  id++;
	}
      }
    }
    else { // p0 = 0
      if(p[0].second > m) {
	//
      }
      else {
	ll j = p[0].second;
	int id = 1;
	bool par = true;
	while(1) {
	  if(id == k) {
	    if(j == m) {
	      res += mint(2*m * (m+1-j));
	      cnt += mint(m+1-j);
	    }
	    else {
	      ll l = p[id].second;
	      if(l == m-j) {
		res += mint(2*m * (m+1-j));
		cnt += mint(m+1-j);		
	      }
	      else {
		res += mint(2*m * (m-j));
		cnt += mint(m-j);				
	      }
	    }
	    break;
	  }
	  else {
	    ll l = p[id].second;
	    if(par) { // 1
	      if(l > m) {
		res += mint(2*m * (m+1-j));
		cnt += mint(m+1-j);
		break;
	      }
	      else if(l < m) {
		res += mint(2*m * (m-j));
		cnt += mint(m-j);
		break;
	      }
	    }
	    else { // 0
	      if(l < m) {
		res += mint(2*m * (m+1-j));
		cnt += mint(m+1-j);
		break;
	      }
	      else if(l > m) {
		res += mint(2*m * (m-j));
		cnt += mint(m-j);
		break;
	      }
	    }
	  }
	  id++;
	}
      }
    }
    cout << 2*m << ":" << cnt.x << "\n";
    k += 2;
  }

  vector<mint> pow2(n);
  pow2[0].x = 1;
  rep(i,n-1) {
    pow2[i+1] = pow2[i] * mint(2);
  }

  mint cnt2(1);
  rep(i,n) {
    if(a[i] == 1) {
      cnt2 += pow2[n-1-i];
    }
  }

  cnt2 -= cnt;
  res += cnt2 * mint(2*n);
  cout << res.x << "\n";
  return 0;
}
