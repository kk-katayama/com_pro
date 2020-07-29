#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int t; cin >> t;
  vector<vector<vector<int>>> res;
  vector<int> ans;
  while(t-- > 0) {
    int n,k; cin >> n >> k;
    if(k % n == 0) ans.push_back(0);
    else ans.push_back(2);
    vector<vector<int>> tmp(n, vector<int>(n, 0));
    int x = 0, i = 0, j = 0;
    while(k-- > 0) {
      tmp[i % n][(j + x) % n] = 1;
      i++;
      j++;
      if(i % n == 0) x++;
    }
    res.push_back(tmp);
  }
  int idx = 0;
  for(auto val: res) {
    cout << ans[idx++] << "\n";
    rep(i,val.size()) {
      rep(j,val.size()) cout << val[i][j];
      cout  << "\n";
    }
  }

  
  return 0;
}
