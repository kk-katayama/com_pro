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
map<char,int> mp;
bool comp(string &a, string &b) {
  if(a.size() < b.size()) return true;
  else if(a.size() > b.size()) return false;
  else {
    rep(i,a.size()) {
      if(a[i] != b[i]) return mp[a[i]] < mp[b[i]];
      // if(mp[a[i]] < mp[b[i]]) return true;
      // else if(mp[a[i]] > mp[b[i]]) return false;
    }
    return true;
  }
}

int main()
{
  vector<char> b(10);
  rep(i,10) cin >> b[i];
  int n;cin >> n;
  vector<string> a(n);
  rep(i,n) cin >> a[i];

  rep(i,10) mp[b[i]] = i;
  sort(a.begin(), a.end(), comp);
  rep(i,n) cout << a[i] << "\n";
  
  return 0;
}
