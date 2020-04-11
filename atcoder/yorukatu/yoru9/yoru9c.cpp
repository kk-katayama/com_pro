#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> s(m), c(m);
  rep(i,m){
    cin >> s[i] >> c[i];
    s[i]--;
  }

  vector<int> res(n, -1);
  rep(i,m) {
    if(res[s[i]] >= 0) {
      if(res[s[i]] != c[i] ) {
	cout << -1 << "\n";
	return 0;
      }
    }
    else {
      res[s[i]] = c[i];
    }
  }

  if(n >= 2) {
    if(res[0] == 0) {
      cout << -1 << "\n";
      return 0;
    }
    else if(res[0] == -1) {
      res[0] = 1;
    }
  }

  rep(i,n) if(res[i] == -1) res[i] = 0;

  rep(i,n) cout << res[i];
  cout  << "\n";
  
  return 0;
}
