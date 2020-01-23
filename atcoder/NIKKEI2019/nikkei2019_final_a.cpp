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
    if(i==0) return 0;
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
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n){
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b.begin(), b.end());
  map<int,int> mp;
  int cnt = 1;
  rep(i,n-1){
    if(b[i]!=b[i+1]){
      mp[b[i]] = cnt++;
    }
  }
  mp[b[n-1]] = cnt;
  
  BIT<ll> bit(cnt);
  vector<ll> res(n,1);
  rep(i,n){
    res[i] *= bit.sum(mp[a[i]]-1);
    bit.add(mp[a[i]],1);
  }

  BIT<ll> bitr(cnt);
  rep(i,n){
    res[n-1-i] *= bitr.sum(mp[a[n-1-i]]-1);
    bitr.add(mp[a[n-1-i]],1);
  }
  
  ll ans = 0;
  rep(i,n){
    ans += res[i];
  }
  cout << ans << "\n";
  return 0;
}
