#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,m,v,p;
  cin >> n;
  cin >> m;
  cin >> v;
  cin >> p;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll vv = v-(p-1);
  sort(a.begin(), a.end());
  vector<ll> b;
  rep(i,n-p+1){
    b.push_back(a[i]);
  }
  reverse(b.begin(), b.end());
  int nn = b.size();
  vector<ll> sum(nn);
  sum[0] = 0;
  rep1(i,nn-1){
    sum[i] = sum[i-1] + b[i-1];
  }
  // rep(i,nn){
  //   cout << b[i] << " ";
  // }
  //  cout << "\n";
  int res = (int)p;
  rep1(i,nn-1){
    if(b[0]-b[i]>m) continue;
    ll d = sum[i] - i*b[i];
    ll vvv = max(0LL,vv-(nn-i));
    // cout << i << " ";
    // cout << vvv << " ";
    // cout << d << " ";
    // cout << m << "\n";
    if(m*vvv<=m*i-d) res++;
  }

  cout << res << "\n";
  return 0;
}
