#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> k(m),p(m);
  vector<vector<int>> s(m);
  rep(i,m) {
    cin >> k[i];
    s[i].resize(k[i]);
    rep(j,k[i]){
      cin >> s[i][j];
      s[i][j]--;
    }
  }
  rep(i,m) cin >> p[i];

  int res = 0;
  rep(mask, (1<<n)) {
    vector<int> cnt(m, 0);
    rep(i,m) {
      rep(j,k[i]) {
	if( (mask >> s[i][j]) & 1) cnt[i]++;
      }
    }
    bool f = true;
    rep(i,m) if(cnt[i] % 2 != p[i]) f = false;
    if(f) res++;
  }
  cout << res << "\n";
  return 0;
}
