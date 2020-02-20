#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  map<string,int> mp;
  rep(i,n){
    mp[s[i]]++;
  }

  int mx=0;
  for(auto it=mp.begin();it!=mp.end();++it){
    mx = max(mx,it->second);
  }

  for(auto it=mp.begin();it!=mp.end();++it){
    if(it->second==mx) cout << it->first << "\n";
  }
  
  return 0;
}
