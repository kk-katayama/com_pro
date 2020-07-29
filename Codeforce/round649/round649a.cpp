#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
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
    int n,x; cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> sum(n+1);
    sum[0] = 0;
    rep(i,n) sum[i+1] = (sum[i] + a[i]) % x;
    map<int,int> mp;
    rep(i,n+1) {
      chmax(mp[sum[i]], i);
    }
    using pi = pair<int,int>;
    pi p1 = {-1, -1}, p2 = {-1, -1};
    for(auto val: mp) {
      int num = val.first;
      int idx = val.second;
      if(p1.first < idx) {
	if(p2.second != p1.second) p2 = p1;
	p1 = {idx, num};
      }
      else if(p2.first < idx) {
	if(p2.second != p1.second) {
	  p2 = {idx, num};
	}
      }
    }
    if(p2.second == -1) {
      res.push_back(-1);
      continue;
    }
    int tmp = 0;
    rep(i,n+1) {
      if(sum[i] != p1.second) {
	chmax(tmp, p1.first - i);
      }
      else {
	chmax(tmp, p2.first - i);	
      }
    }
    res.push_back(tmp);
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
