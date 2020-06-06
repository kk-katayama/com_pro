#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }

vector<int> divisor(int x){
  vector<int> res;
  for(int i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main()
{
  int t;cin >> t;
  vector<int> n(t);
  vector<vector<int>> s(t);
  rep(i,t) {
    cin >> n[i];
    s[i].resize(n[i] + 1);
    rep1(j,n[i]) {
      cin >> s[i][j];
    }
  }

  rep(i,t) {
    vector<int> a(n[i] + 1, 0);
    int res = 0;
    rep1(j,n[i]) {
      vector<int> div = divisor(j);
      int maxi = 0;
      for(auto d:div) {
	if(s[i][d] < s[i][j]) chmax(maxi, a[d]);
      }
      a[j] = maxi + 1;
      chmax(res, a[j]);
    }
    cout << res << "\n";
  }
  
  return 0;
}
