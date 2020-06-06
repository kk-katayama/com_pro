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
  string a,b,c;
  cin >> a >> b >> c;

  vector<int> anum(26, 0), bnum(26, 0), cnum(26, 0);
  int n = a.size();
  rep(i,n) {
    int xa = a[i] - 'A';
    int xb = b[i] - 'A';
    int xc = c[i] - 'A';
    anum[xa]++;
    bnum[xb]++;
    cnum[xc]++;
  }

  int acnt = 0, bcnt = 0;
  rep(i,26) {
    if(anum[i] + bnum[i] < cnum[i]) {
      cout << "NO" << "\n";
      return 0;
    }
    else {
      acnt += max(0, cnum[i] - bnum[i]);
      bcnt += max(0, cnum[i] - anum[i]);
    }
  }

  if(acnt > n/2 || bcnt > n/2) {
    cout << "NO" << "\n";
  }
  else cout << "YES" << "\n";
  
  return 0;
}
