#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,p;
  cin >> n >> p;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll odd = 0,even = 0;
  rep(i,n){
    if(a[i]&1) odd++;
    else even++;
  }
  ll comb[60][60];
  {
    rep(i,odd+1){
      comb[i][0] = comb[i][i] = 1;
    }
    for(int i=2;i<=odd;++i){
      for(int j=1;j<i;++j){
	comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
      }
    }
  }

  ll res = 0;
  ll ex = 1LL<<even;
  for(int i=p;i<=odd;i+=2){
    res += comb[odd][i] * ex;
  }

  cout << res << "\n";
  
  return 0;
}
