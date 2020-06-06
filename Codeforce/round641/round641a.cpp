#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
ll divisor(ll x){
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
  return res[1];
}

int main()
{
  ll t; cin >> t;
  vector<ll> n(t), k(t);
  rep(i,t) cin >> n[i] >> k[i];

  rep(i,t) {
    if(n[i] % 2 == 0) {
      cout << n[i] + k[i]*2 << "\n";
    }
    else {
      ll x = divisor(n[i]);
      cout << x + n[i] + (k[i]-1)*2 << "\n";
    }
  }
  
  return 0;
}
