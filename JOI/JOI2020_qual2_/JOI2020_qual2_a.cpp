#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<vector<char>> rot(vector<vector<char>> c) {
  int n = c.size();
  int m = c[0].size();
  vector<vector<char>> res(m, vector<char>(n));
  rep(i,n) rep(j,m) {
    res[j][n-1-i] = c[i][j];
  }
  return res;
}

int main()
{
  int n;cin >> n;
  vector<vector<char>> s(n, vector<char>(n));
  vector<vector<char>> t(n, vector<char>(n));
  rep(i,n) rep(j,n) cin >> s[i][j];
  rep(i,n) rep(j,n) cin >> t[i][j];

  vector<vector<char>> a = rot(s);
  vector<vector<char>> b = rot(a);
  vector<vector<char>> c = rot(b);  

  int res = 1e+9;

  int tmp = 0;
  rep(i,n) rep(j,n) if(s[i][j] != t[i][j]) tmp++;
  res = min(tmp, res);

  tmp = 0;
  rep(i,n) rep(j,n) if(a[i][j] != t[i][j]) tmp++;
  res = min(tmp+1, res);

  tmp = 0;
  rep(i,n) rep(j,n) if(b[i][j] != t[i][j]) tmp++;
  res = min(tmp+2, res);    

  tmp = 0;
  rep(i,n) rep(j,n) if(c[i][j] != t[i][j]) tmp++;
  res = min(tmp+1, res);

  cout << res << "\n";
  
  return 0;
}
