#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int l,r;
  cin >> l >> r;
  bool ff = true;
  for(int i=l;i<=r;++i){
    map<int,int> mp;
    bool f = true;
    int x = i;
    while(x>0){
      if(mp[x%10]>0){
	f = false;
	break;
      }
      mp[x%10]++;
      x /= 10;
    }
    if(f){
      cout << i << "\n";
      ff = false;
      break;
    }
  }
  if(ff) cout << -1 << "\n";
  return 0;
}
