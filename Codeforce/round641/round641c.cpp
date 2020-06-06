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
//return x's divisor as vector
vector<ll> divisor(ll x){
  vector<ll> res;
  for(ll i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

int main()
{
  ll n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  map<ll,ll> mp;
  rep(i,n) {
    vector<ll> div = divisor(a[i]);
    for(auto d:div) {
      mp[d]++;
    }
  }

  ll res = 1;
  for(auto it = mp.rbegin(); it != mp.rend(); ++it) {
    if(it->second >= n-1) res = lcm(res, it->first);
  }

  cout << res << "\n";
  
  return 0;
}
