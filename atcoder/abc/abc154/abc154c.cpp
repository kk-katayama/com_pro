#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  map<int,int> mp;
  int n;
  bool f = true;
  cin >> n;
  rep(i,n){
    int a;
    cin >> a;
    if(mp[a]>0) f = false;
    mp[a]++;
  }
  if(f) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
