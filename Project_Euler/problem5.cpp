#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
// ユークリッドの互除法で最大公約数を求める
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}
int main()
{
  ll g = 1;
  rep1(i,20) g = lcm(g, i);
  cout << g << "\n";

  rep1(i,20) cout << g%i << "\n";
  
  return 0;
}
