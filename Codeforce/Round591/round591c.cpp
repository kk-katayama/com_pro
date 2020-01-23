#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
  if(b==0) return a;
  else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}
bool comp(ll& a,ll& b){
  return a>b;
}
bool C(ll z,vector<ll> p,ll x,ll y,ll a,ll b,ll k){
  ll sum=0;
  int i=0;
  ll s=z/lcm(a,b);
  while(i<s){
    sum+=(x+y)*(p[i]/100);
    ++i;
  }
  ll t=z/b-z/lcm(a,b);
  while(i<s+t){
    sum+=y*(p[i]/100);
    ++i;
  }
  ll u=z/a-z/lcm(a,b);
  while(i<s+t+u){
    sum+=x*(p[i]/100);
    ++i;
  }
  return k<=sum;
}
ll upper(ll l,ll r,vector<ll> p,ll x,ll y,ll a,ll b,ll k){
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(C(mid,p,x,y,a,b,k)) ub=mid;
    else lb=mid;
  }
  return ub;
}

int main()
{
  int q;
  cin >> q;
  vector<int> n(q);
  vector<vector<ll>> p(q);
  vector<ll> x(q),y(q);
  vector<ll> a(q),b(q);
  vector<ll> k(q);
  rep(i,q){
    cin >> n[i];
    p[i].resize(n[i]);
    rep(j,n[i]) cin >> p[i][j];
    cin >> x[i] >> a[i];
    cin >> y[i] >> b[i];
    cin >> k[i];
  }

  rep(i,q){
    sort(p[i].begin(), p[i].end(),comp);
    if(x[i]>y[i]){
      swap(a[i],b[i]);
      swap(x[i],y[i]);
    }
    ll res=upper(0,n[i],p[i],x[i],y[i],a[i],b[i],k[i]);

    if(res==n[i]+1) cout << -1 << "\n";
    else cout << res << "\n";
  }

  
  return 0;
}
