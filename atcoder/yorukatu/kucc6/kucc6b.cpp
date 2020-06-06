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
  vector<int> s(n);
  rep(i,n) cin >> s[i];
  int q;cin >> q;
  vector<int> k(q);
  rep(i,q) cin >> k[i];

  sort(s.begin(), s.end(), [](int a,int b) {
			     return a > b;
			   });
  int idx = n-1;
  while(s[idx] == 0) {
    s.pop_back();
    idx--;
    if(idx == -1) break;
  }

  reverse(s.begin(), s.end());

  int m = s.size();
  
  auto index = [&](int x)-> int{
		 int lb = -1, ub = m;
		 while(ub - lb > 1) {
		  int mid = (ub + lb) / 2;
		  (s[mid] >= x ? ub : lb) = mid;
		 }
		 return ub;
	      };

  auto bins = [&](int kk)-> int{
		 int lb = -1, ub = 1e+9;
		 while(ub - lb > 1) {
		  int mid = (ub + lb) / 2;
		  (m - index(mid) <= kk ? ub : lb) = mid;
		 }
		 return ub;
	      };

  rep(i,q) {
    cout << bins(k[i]) << "\n";
  }

  
  return 0;
}
