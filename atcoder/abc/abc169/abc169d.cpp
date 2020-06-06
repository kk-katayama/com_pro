#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
//return x's prime factor as map
map<ll,ll> primefactor(ll x){
  ll nn = x;
  map<ll,ll> res;
  for(ll i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}

int main()
{
  ll n; cin >> n;
  map<ll,ll> mp = primefactor(n);

  ll cnt = 0;
  for(auto m: mp) {
    ll x = m.second;
    ll y = 1;
    while(x > 0) {
      x -= y;
      if(x < 0) break;
      y++;
      cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
