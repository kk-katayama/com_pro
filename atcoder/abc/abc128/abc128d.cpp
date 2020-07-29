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
  int n,k; cin >> n >> k;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  int res = 0;
  rep(i,n+1) {
    rep(j,n+1) {
      if(i + j > n) continue;
      int x = k - (i + j);
      if(x < 0) continue;
      vector<int> vec;
      int sum = 0;
      rep(l,i) {
	vec.push_back(v[l]);
	sum += v[l];
      }
      rep(l,j) {
	vec.push_back(v[n - 1 - l]);
	sum += v[n - 1 - l];
      }
      if(vec.size() == 0) continue;
      sort(vec.begin(), vec.end());
      int idx = 0;
      while(vec[idx] < 0 && 0 < x - idx) {
	sum -= vec[idx];
	idx++;
	if(idx == vec.size()) break;
      }
      chmax(res, sum);
    }
  }
  cout << res << "\n";
  return 0;
}
