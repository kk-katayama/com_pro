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
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
const ll MOD=998244353;
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
  int n; cin >> n;
  string s; cin >> s;
  mint res(1);
  vector<mint> buf(7);
  // 0: , 1:R, 2:G, 3:B, 4:RG, 5:GB, 6:BR
  buf[0].x = n;
  rep(i, 3*n) {
    if(s[i] == 'R') {
      if(buf[5].x > 0) {
	res *= buf[5];
	buf[5].x--;
      }
      else if(buf[2].x > 0) {
	res *= buf[2];
	buf[2].x--;
	buf[4].x++;
      }
      else if(buf[3].x > 0) {
	res *= buf[3];
	buf[3].x--;
	buf[6].x++;	
      }
      else {
	res *= buf[0];
	buf[0].x--;
	buf[1].x++;	
      }
    }
    else if(s[i] == 'G') {
      if(buf[6].x > 0) {
	res *= buf[6];
	buf[6].x--;
      }
      else if(buf[1].x > 0) {
	res *= buf[1];
	buf[1].x--;
	buf[4].x++;
      }
      else if(buf[3].x > 0) {
	res *= buf[3];
	buf[3].x--;
	buf[5].x++;	
      }
      else {
	res *= buf[0];
	buf[0].x--;
	buf[2].x++;	
      }
    }
    else {
      if(buf[4].x > 0) {
	res *= buf[4];
	buf[4].x--;
      }
      else if(buf[1].x > 0) {
	res *= buf[1];
	buf[1].x--;
	buf[6].x++;
      }
      else if(buf[2].x > 0) {
	res *= buf[2];
	buf[2].x--;
	buf[5].x++;	
      }
      else {
	res *= buf[0];
	buf[0].x--;
	buf[3].x++;	
      }
    }        
  }
  cout << res.x << "\n";
    
  return 0;
}
