#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  map<int,int> mp;
  rep(i,n) mp[i] = 0;
  rep(i,m){
    mp[a[i]]++;
    mp[b[i]]++;
  }

  bool f = true;
  for(auto& itr:mp){
    int val = itr.second;
    if(val&1){
      f = false;
      break;
    }
  }

  cout << (f?"YES":"NO") << "\n";
  return 0;
}
