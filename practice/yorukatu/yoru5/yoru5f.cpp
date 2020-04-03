#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
//return x's divisor as vector
vector<int> divisor(int x){
  vector<int> res;
  for(int i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main()
{
  int n,k;cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int sum = 0;
  rep(i,n) sum += a[i];

  int res = 0;
  vector<int> div = divisor(sum);
  rep(i,div.size()) {
    vector<int> mi(n), pl(n);
    rep(j,n) {
      mi[j] = a[j] % div[i];
      pl[j] = div[i] - mi[j];
    }
    sort(mi.begin(), mi.end());
    sort(pl.begin(), pl.end());
    vector<int> msum(n+1), psum(n+1);
    msum[0] = 0;
    psum[0] = 0;
    rep(j,n) {
      msum[j+1] = msum[j] + mi[j];
      psum[j+1] = psum[j] + pl[j];
    }

    rep(j,n+1) {
      if(msum[j] > k) break;
      if(msum[j] == psum[n-j]) res = max(res, div[i]);
    }
  }
  cout << res << "\n";
  return 0;
}
