#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  int a,b;cin >> a >> b;
  auto f = [&](int &x)-> void{
	     if(x < a) x = a;
	     else if(b < x) x = b;
	   };

  vector<string> s(n);
  vector<int> d(n);
  rep(i,n) {
    cin >> s[i] >> d[i];
    f(d[i]);
    if(s[i] == "West") d[i] = -d[i];
  }

  int res = 0;
  rep(i,n) res += d[i];
  if(res < 0) cout << "West " << -res << "\n";
  else if(res == 0) cout << 0 << "\n";
  else cout << "East " << res << "\n";
  
  return 0;
}
