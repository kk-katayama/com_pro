#include <iostream>
#include <algorithm>
using namespace std;
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
  int a,b;
  cin >> a >> b;
  cout << "gcd" << ":" << gcd(a,b) << "\n";
  cout << "lcm" << ":" << lcm(a,b) << "\n";
  return 0;
}





