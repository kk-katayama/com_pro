#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
//k以下である要素のうち最大のもののインデックスを求める
int m;
vector<ll> vec;
int lower_bound(int k){
  int left=-1,right=m;
  while(right-left>1){
    int mid=(right+left)/2;
    if(vec[mid]<=k) left=mid;
    else right=mid;
  }
  return left;
}

int main()
{
  int n, q;cin >> n >> q;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> x(q);
  rep(i,q) cin >> x[i];

  rep(i, (n - 1) / 2) {
    ll tmp = ( a[n - 2 - i] + a[n - 2 - i - i - 1] ) / 2 + 1;
    vec.push_back(tmp);
  }
  vec.push_back(0);
  // rep(i,vec.size()) cout << vec[i] << " ";
  // cout  << "\n";

  reverse(vec.begin(), vec.end());
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];
  m = (n + 1) / 2;
  vector<ll> jum(m + 1);
  jum[0] = 0;
  if(n % 2 == 0) {
    rep(i,n) {
      if(i % 2 == 1) {
	jum[i/2 + 1] = jum[i/2] + a[i];
      }
    }
  }
  else {
    rep(i,n) {
      if(i % 2 == 0) {
	jum[i/2 + 1] = jum[i/2] + a[i];
      }
    }
  }

  // rep(i, m + 1) cout << jum[i] << " ";
  // cout << "\n";
  
  rep(i,q) {
    ll res = 0;
    int index = lower_bound(x[i]);
    int num = m - index;
    res += sum[n] - sum[n - num];
    int kk = n - 1 - num * 2;
    if(kk < 0) cout << res << "\n";
    else {
      res += jum[ kk/2 + 1 ];
      cout << res << "\n";
    }
  }

  return 0;
}
