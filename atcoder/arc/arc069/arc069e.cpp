#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct BIT
{
  vector<X> dat;
  int n;

  BIT(ll _n){
    n = _n+1;
    dat.assign(n,0);
  }
  
  X sum(ll i)
  {
    X s = 0;
    while(i > 0){
      s += dat[i];
      i -= i&(-i);
    }
    return s;
  }

  void add(ll i,X x)
  {
    while(i<=n){
      dat[i] += x;
      i += i&(-i);
    }
  }
};

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<pair<ll,ll>> p(n);
  rep(i,n){
    p[i]=make_pair(a[i],i);
  }

  sort(p.begin(),p.end());

  BIT<ll> bit(n);

  vector<ll> res(n);
  rep(i,n) res[i] = 0;
  ll pod=0;
  ll level=0;

  rep(i,n){
    bit.add(p[i].second+1,1);
    if(bit.sum(p[i].second+1)==p[i].second+1){
      res[p[i].second] += (n-i)*(p[i].first-level);
      res[p[i].second] += pod;
      pod = 0;
      level = p[i].first;
    }
    else{
      pod += p[i].first-level;
    }
  }

  rep(i,n) cout << res[i] << "\n";
  
  return 0;
}
