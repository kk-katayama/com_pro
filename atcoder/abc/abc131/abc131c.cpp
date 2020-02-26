#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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
  ll a,b,c,d;cin >> a >> b >> c >> d;
  ll an = (a-1)/c+(a-1)/d-(a-1)/lcm(c,d);
  an = a-1-an;
  ll bn = b/c+b/d-b/lcm(c,d);
  bn = b-bn;
  cout << bn-an << "\n";
  return 0;
}
