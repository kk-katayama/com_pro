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
  int n;cin >> n;
  vector<vector<int>> d(n, vector<int>(n));
  rep(i,n) rep(j,n) cin >> d[i][j];
  int q;cin >> q;
  vector<int> p(q);
  rep(i,q) cin >> p[i];

  vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
  rep(i,n) {
    rep(j,n) {
      sum[i+1][j+1] = d[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
    }
  }
  map<int,int> mp;
  rep1(i,n) {
    rep1(j,n) {
      rep(k,n) {
	rep(l,n) {
	  if(i <= k || j <= l) continue;
	  int val = sum[i][j] - sum[i][l] - sum[k][j] + sum[k][l];
	  int size = (i - k)*(j - l);
	  chmax(mp[size], val);
	}
      }
    }
  }

  vector<pair<int,int>> vec(q);
  rep(i,q) vec[i] = {p[i], i};
  vector<int> res(q);
  sort(vec.begin(), vec.end());
  int maxi = 0;
  auto it = mp.begin();
  rep(i,q) {
    int pp = vec[i].first;
    if(it != mp.end()) {
      while(it->first <= pp) {
	chmax(maxi, it->second);
	it++;
	if(it == mp.end()) break;
      }
    }
    res[vec[i].second] = maxi;
  }

  rep(i,q) {
    cout << res[i] << "\n";
  }

  return 0;
}
