#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int M = 42;
int main()
{
  int n,k;cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];
  vector<ll> v;
  rep(i,n){
    for(int j = i+1;j <= n;++j){
      v.push_back(sum[j] - sum[i]);
    }
  }
  ll res = 0;
  vector<ll> pow2(M+1);
  pow2[0] = 1;
  rep(i,M) pow2[i+1] = pow2[i] * 2;
  for(int i = M;i >= 0;--i){
    // rep(j,v.size()) cout << v[j] << " ";
    // cout << "\n";
    int cnt = 0;
    rep(j,v.size()){
      if( ( v[j] >> i ) & 1 ) cnt++;
    }
    if(cnt >= k){
      res += pow2[i];
      vector<ll> tmp;
      rep(j,v.size()){
	if( ( v[j] >> i ) & 1 ) tmp.push_back(v[j]);
      }
      v = tmp;
    }
  }
  cout << res << "\n";
  
  return 0;
}
