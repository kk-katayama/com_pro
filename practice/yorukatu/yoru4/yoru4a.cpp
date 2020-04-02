#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];
  map<string,int> mp;
  bool f = true;
  rep(i,n-1) {
    if(s[i][(int)s[i].size()-1] != s[i+1][0] ) {
      f = false;
      break;
    }
    if(mp[s[i]] > 0) {
      f = false;
      break;
    }
    mp[s[i]]++;
  }
  if(mp[s[n-1]] > 0) f =false;
  if(f) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
