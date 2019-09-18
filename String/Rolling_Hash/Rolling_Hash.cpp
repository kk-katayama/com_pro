#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll B = 1e+9+7;
bool contain(string a,string b){
  int al = a.size(),bl = b.size();
  if(al>bl) return false;

  ll t = 1;
  rep(i,al) t *= B;

  ll ah = 0,bh = 0;
  rep(i,al) ah = ah*B + a[i];
  rep(i,al) bh = bh*B + b[i];

  for(int i = 0;i+al<=bl;++i){
    if(ah==bh) return true;      
    if(i+al<bl) bh = bh*B+b[i+al]-b[i]*t;
  }
  return false;
}
int main()
{
  string a,b;
  cin >> a >> b;
  
  cout << contain(a,b) << "\n";
  return 0;
}
