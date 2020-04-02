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

  vector<int> div = divisor(sum);
  int res = 0;
  for(int x : div) {
    int tmp = 0;
    vector<int> b(n);
    rep(i,n) {
      int xx = a[i] % x;
      tmp += -xx + (x - xx);
      b[i] = a[i] % x;
    }
    sort(b.begin(), b.end());
    int y = tmp / x;
    int kk = (y + n) / 2;
    int summ = 0;
    rep(i,kk) {
      summ += b[i];
    }
    if(summ <= k) res = max(res, x);
  }
  cout << res << "\n";
  return 0;
}
