#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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

int main()
{
  ll n;cin >> n;
  vector<ll> v = divisor(n);
  ll res = (1LL << 60);
  rep(i,v.size()) {
    ll x = n / v[i];
    res = min(res, x + v[i] - 2);
  }
  cout << res << "\n";
  return 0;
}
