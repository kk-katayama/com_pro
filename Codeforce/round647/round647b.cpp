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
  vector<int> res;
  while(t-- > 0) {
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    auto bins = [&](int k) {
		  int lb = -1, ub = n;
		  while(ub - lb > 1) {
		    int mid = (ub + lb) / 2;
		    (a[mid] >= k ? ub : lb) = mid;
		  }
		  return ub;
		};
    int ans = 1e+9;
    rep1(k,1023) {
      vector<bool> f(n, false);
      bool flag = true;
      rep(i,n) {
	if(f[i]) continue;
	f[i] = true;
	int tmp = a[i] ^ k;
	int idx = bins(tmp);
	if(idx == n) {
	  flag = false;
	}
	else {
	  if(a[idx] != tmp) {
	    flag = false;
	  }
	  else {
	    f[idx] = true;
	  }
	}
      }
      if(flag) chmin(ans, k);
    }
    res.push_back((ans == 1e+9 ? -1 : ans));
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
