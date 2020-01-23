#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll r=0;
  rep(i,n){
    r += (a[i]+1)/(n+1);
  }


  if(r==0){
    cout << 0 << "\n";
    return 0;
  }

  vector<ll> b(n+1,0);
  rep(i,n){
    ll x = a[i]%(n+1);
    ll y = (x+2)%(n+1);
    b[(n+1-y)%(n+1)]++;
  }


  ll d=0;
  vector<ll> c(n+1);
  rep(i,n+1){
    c[i] = d+1-b[i];
    d = c[i];
  }


  ll mi=0;
  ll mx=c[0];
  rep(i,n+1){
    if(mx<c[i]){
      mx=c[i];
      mi=i;
    }
    if(r<=c[i]){
      cout << i+1 << "\n";
      return 0;
    }
  }

  cout << (r-mx)*(n+1)+mi+1 << "\n";
  
  return 0;
}
