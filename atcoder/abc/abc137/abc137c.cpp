#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int n;
string s[100010];
map<string,ll> mp;
int main()
{
  cin >> n;
  rep(i,n) cin >> s[i];
  rep(i,n) sort(s[i].begin(), s[i].end());
  
  rep(i,n) mp[s[i]]++;

  ll res = 0;
  for(auto itr=mp.begin();itr!=mp.end();++itr){
    res += (itr->second)*(itr->second - 1)/2;
  }
  cout << res << "\n";
  return 0;
}
