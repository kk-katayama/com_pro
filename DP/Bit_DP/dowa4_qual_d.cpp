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
  int n;cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  vector<int> a(n-1);
  rep(i,n-1) {
    cin >> a[i]; a[i]--;
  }

  vector<int> rev(n, 0);
  rep(i,n-1) {
    rev[a[i]] += (1 << (i+1));
  }

  auto rec = [&](auto f, int mask, int idx)-> int{
	       if(dp[mask][idx] >= 0) return dp[mask][idx];
	       
	     };
  
  return 0;
}
