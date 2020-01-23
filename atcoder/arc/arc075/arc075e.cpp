#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct BIT
{
  vector<X> dat;
  int n;

  BIT(int _n){
    n = _n+1;
    dat.assign(n,0);
  }
  
  X sum(int i)
  {
    X s = 0;
    while(i > 0){
      s += dat[i];
      i -= i&(-i);
    }
    return s;
  }

  void add(int i,X x)
  {
    while(i<=n){
      dat[i] += x;
      i += i&(-i);
    }
  }
};

int main()
{
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> sum(n+1);
  sum[0] = 0;

  rep(i,n){
    sum[i+1] = sum[i]+(a[i]-k);
  }

  map<ll,int> mp;
  rep(i,n+1){
    mp[sum[i]]=1;
  }

  int j=1;
  for(auto& it:mp){
    it.second=j++;
  }

  BIT<ll> bt(n+1);
  ll res=0;
  rep(i,n+1){
    int index=mp[sum[i]];
    res += bt.sum(index);
    bt.add(index,1);
  }

  cout << res << "\n";
  return 0;
}
