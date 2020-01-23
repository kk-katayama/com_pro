#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll h,w;
ll k,v;
vector<vector<ll>> a;
vector<vector<ll>> sum;
vector<ll> divisor(ll val){
  vector<ll> res;
  for(ll i=1;i*i<=val;i++){
    if(val%i==0){
      res.push_back(i);
      if(i!=val/i) res.push_back(val/i);
    }
  }
  return res;
}

bool C(ll x){
  vector<ll> div=divisor(x);
  ll miv = 1e+16;
  rep(l,div.size()){
    ll p=div[l],q=x/div[l];
    if(p>h||q>w) continue;
    rep(i,h-p+1){
      rep(j,w-q+1){
	miv = min(miv,sum[i+p][j+q]-sum[i][j+q]-sum[i+p][j]+sum[i][j]);
      }
    }
  }
  return miv+x*k<=v;
}
ll lower(ll l,ll r){
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(C(mid)) lb=mid;
    else ub=mid;
  }
  return lb;
}

int main()
{
  cin >> h >> w;
  cin >> k >> v;
  a.resize(h,vector<ll>(w));
  rep(i,h){
    rep(j,w){
      cin >> a[i][j];
    }
  }

  sum.resize(h+1,vector<ll>(w+1,0));
  rep1(i,h){
    rep1(j,w){
      sum[i][j] = sum[i-1][j]+sum[i][j-1]+a[i-1][j-1]-sum[i-1][j-1];
    }
  }
  
  ll res=0;
  rep1(x,h*w){
    if(C(x)) res=x;
  }
  cout << res << "\n";
  
  return 0;
}
