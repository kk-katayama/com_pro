#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
// ユークリッドの互除法で最大公約数を求める
int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
int lcm(int a,int b){
  return a*b/gcd(a,b);
}
int main()
{
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> rsum(n+1), lsum(n+1);
  lsum[0] = rsum[0] = 0;
  rep(i,n) {
    lsum[i+1] = gcd(lsum[i], a[i]);
  }
  for(int i = n; i > 0; --i) {
    rsum[i-1] = gcd(rsum[i], a[i-1]);
  }

  int res = 0;
  rep(i,n) {
    chmax(res, gcd(lsum[i], rsum[i+1]));
  }
  cout << res << "\n";
  
  return 0;
}
