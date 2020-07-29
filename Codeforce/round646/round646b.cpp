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
  int t; cin >> t;
  vector<int> res;
  while(t-- > 0) {
    string s; cin >> s;
    vector<int> a,b;
    int n = s.size();
    int cnt = 1;
    rep(i,n-1) {
      if(s[i] != s[i+1]) {
	a.push_back((int)s[i] - '0');
	b.push_back(cnt);
	cnt = 1;
      }
      else cnt++;
    }
    a.push_back((int)s[n-1] - '0');
    b.push_back(cnt);
    int m = a.size();
    vector<int> zsum(m+1), osum(m+1);
    zsum[0] = 0;
    osum[0] = 0;
    rep(i,m) {
      if(a[i] == 0) {
	zsum[i+1] = zsum[i] + b[i];
	osum[i+1] = osum[i];
      }
      else {
	zsum[i+1] = zsum[i];
	osum[i+1] = osum[i] + b[i];
      }
    }
    int ans = 1e+9;
    rep(i,m+1) {
      int tmp = osum[i] + zsum[m] - zsum[i];
      chmin(ans, tmp);
      tmp = zsum[i] + osum[m] - osum[i];
      chmin(ans, tmp);
    }
    res.push_back(ans);
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
