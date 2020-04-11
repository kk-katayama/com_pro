#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;

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

  vector<ll> div = divisor(n);
  vector<ll> div2 = divisor(n-1);
  ll res = div2.size() - 1;

  rep(i,div.size()) {
    ll k = div[i];
    if(k == 1) continue;
    ll nn = n;
    while(nn % k == 0) nn /= k;
    if( (nn - 1) % k == 0) res++;
  }
  cout << res << "\n";
  
  return 0;
}
