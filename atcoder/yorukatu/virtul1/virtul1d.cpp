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
bool dfs(string s, string t, int cnt, bool f) {
  if(f && s == t) return true;
  int n = s.size();
  bool res = false;
  rep(i,n) {
    rep(j,n) {
      if(i >= j) continue;
      string tmp = s;
      swap(tmp[i], tmp[j]);
      if(f) {
	if(tmp == t) return true;
	else if(cnt == 2) {
	  // 
	}
	else {
	  res |= dfs(tmp, t, cnt+1, f);
	}
      }
      else {
	if(cnt == 2) {
	  if(tmp == t) return true;
	}
	else {
	  res |= dfs(tmp, t, cnt+1, f);
	}
      }
    }
  }
  return res;
}
int main()
{
  string a,b;cin >> a >> b;
  map<char,int> mp;
  string c = "", d = "";
  bool f = false;
  rep(i,a.size()) {
    if(a[i] == b[i]) {
      if(mp[a[i]] == 1) f = true;
      mp[a[i]]++;
    }
    else {
      c.push_back(a[i]);
      d.push_back(b[i]);
    }
  }

  if(c.size() >= 7) cout << "NO" << "\n";
  else {
    if(dfs(c, d, 0, f)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
  return 0;
}
