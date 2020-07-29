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
int main()
{
  int n; cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  map<string,int> mp;
  rep(i,n) mp[s[i]]++;

  cout << "AC x " << mp["AC"] << "\n";
  cout << "WA x " << mp["WA"] << "\n";
  cout << "TLE x " << mp["TLE"] << "\n";
  cout << "RE x " << mp["RE"] << "\n";  
  
  return 0;
}
