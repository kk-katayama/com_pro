#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
struct RollingHash{
  string a;
  int al;
  const ll B = 1e+9+7;
  
  RollingHash(string _a){a=_a;al=a.size();}

  int count_contain(string b)
  {
    int bl = b.size();
    if(al<bl) return 0;

    ll t = 1;
    rep(i,bl) t *= B;

    ll ah = 0,bh = 0;
    rep(i,bl) ah = ah*B + a[i];
    rep(i,bl) bh = bh*B + b[i];

    int res = 0;
    for(int i=bl;i<=al;++i){
      if(ah==bh) res++;
      if(i<al) ah = ah*B+a[i]-t*a[i-bl];
    }
    return res;
  }
};


int main()
{
  string s;
  cin >> s;
  int m;
  cin >> m;
  vector<string> c(m);
  rep(i,m) cin >> c[i];

  RollingHash roll(s);

  int res = 0;
  rep(i,m) res += roll.count_contain(c[i]);

  cout << res << "\n";

  
  return 0;
}
