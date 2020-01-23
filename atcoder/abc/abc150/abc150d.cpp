#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

int main()
{
  ll n,m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  bool f = true;

  ll c = 0;
  ll d = a[0];
  while(d%2==0){
    d /= 2;
    c++;
  }
  rep1(i,n-1){
    ll cnt = 0;
    ll b = a[i];
    while(b%2==0){
      b /= 2;
      cnt++;
    }
    if(c!=cnt){
      f = false;
      break;
    }
  }
  
  ll g = 1;
  rep(i,n){
    g = lcm(g,a[i]/2);
    
  }

  if(!f){
    cout << 0 << "\n";
  }
  else{
    ll res = m/g;
    res  = (res+1)/2;
    cout << res << "\n";
  }

  return 0;
}
