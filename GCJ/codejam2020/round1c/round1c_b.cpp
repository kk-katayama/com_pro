#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int M = 1e+4;
int main()
{
  int t;cin >> t;

  vector<int> u(t);
  vector<vector<string>> q(t, vector<string>(M)), r(t, vector<string>(M));
  rep(i,t) {
    cin >> u[i];
    rep(j,M) cin >> q[i][j] >> r[i][j];
  }

  vector<vector<char>> res(t);
  
  rep(i,t) {
    map<char,int> mp;
    map<char,int> mp2;
    rep(j,M) {
      rep(k, r[i][j].size()) {
	if(mp[r[i][j][k]] == 0) mp[r[i][j][k]] = 0;
      }
      mp2[r[i][j][0]] = 1;
      if(q[i][j].size() == 2) {
	if(q[i][j][1] == '-') continue;
      }
      if(q[i][j].size() == r[i][j].size()) {
	if(q[i][j].size() == 1) {
	  if(mp[r[i][j][0]] == 0) {
	    mp[r[i][j][0]] = q[i][j][0] - '0' + 1;
	  }
	  else {
	    chmin(mp[r[i][j][0]], q[i][j][0] - '0' + 1);
	  }
	}
	else if(q[i][j][0] == '1') {
	  if(mp[r[i][j][0]] == 0) mp[r[i][j][0]] = 2;
	  else {
	    chmin(mp[r[i][j][0]], 2);
	  }
	  int k = 1;
	  while(q[i][j][k] == '0') {
	    mp[r[i][j][k]] = 1;
	    k++;
	    break;
	  }
	}
      }
    }
    vector<pair<pair<int,int>,char>> p;
    vector<char> ans(10, '#');
    
    for(auto &m: mp2) {
      if(m.second == 0) ans[0] = m.first;
    }
    for(auto &m: mp) {
      int id = m.second - 1;
      if(id == -1) id = 9;
      while(ans[id] != '#') id--;
      ans[id] = m.first;
    }
    res[i] = ans;
  }
  
  rep(i,t) {
    cout << "Case #" << i + 1 << ": ";
    rep(j,res[i].size()) cout << res[i][j];
    cout << "\n";
  }





  return 0;
}
