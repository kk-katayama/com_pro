#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b,c;cin >> a >> b >> c;
  int cnt = 0;
  map<int,int> mp;
  mp[a]++;mp[b]++;mp[c]++;
  for(auto w:mp) cnt++;
  cout << cnt << "\n";
  return 0;
}
