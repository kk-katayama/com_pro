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
  int res = n;
  int cnt = 0;
  for(auto m : mp) {
    if(m.second % 2 == 1) {
      res -= m.second - 1;
    }
    else {
      res -= m.second - 2;
      cnt++;
    }
  }
  res -= (cnt + 1)/2 * 2;
  cout << res << "\n";
  return 0;
}
