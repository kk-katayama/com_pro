#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  int cnt = 0;
  map<string,int> mp;
  rep(i,n) {
    if(mp[s[i]] == 0) cnt++;
    mp[s[i]]++;
  }
  cout << cnt << "\n";
  return 0;
}
