#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;cin >> t;
  vector<int> r(t), c(t);
  vector<vector<vector<int>>> s(t);
  rep(i,t) {
    cin >> r[i] >> c[i];
    s[i].resize(r[i], vector<int>(c[i]));
    rep(j,r[i]) rep(k,c[i]) cin >> s[i][j][k];
  }

  rep(i,t) {
    int sum = 0;
    rep(j,r[i]) {
      rep(k,c[i]) {
	rep(l,4) {
	  int nj = j + dx[l];
	  int nk = k + dy[l];
	  if(nj >= 0 && nj < r[i] && nk >= 0 && mk < c[i]) {
	    if(s[i][nj][nk] == 0) {
	      
	    }
	  }
	}
      }
    }
  }
  
  return 0;
}
