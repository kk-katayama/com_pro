#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  map<int,int> mp;
  rep(i,n) mp[a[i]]++;
  int res = 0;
  for(auto m : mp) {
    if(m.first < m.second) res += m.second - m.first;
    else if(m.first > m.second) res += m.second;
  }
  cout << res << "\n";
  return 0;
}
