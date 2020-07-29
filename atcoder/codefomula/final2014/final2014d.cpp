#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<int> m(n), s(n), e(n);
  rep(i,n) {
    cin >> m[i] >> s[i] >> e[i];
    m[i]--;
  }
  using pi = pair<int,int>;
  using pii = pair<pi,int>;
  vector<pii> a(n);
  rep(i,n) a[i] = {{e[i], s[i]}, m[i]};
  sort(a.begin(), a.end());
  
  vector<vector<int>> dp(n, vector<int>(n, 0));
  
  auto rec = [&](auto f, int i, int j) {
	       for(int k = j+1; k < n; ++k) {
		 
	       }
	     };

  rep(i,n) {
    
  }
  
  return 0;
}
