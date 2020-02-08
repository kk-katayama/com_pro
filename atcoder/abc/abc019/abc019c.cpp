#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  int cnt = 0;
  map<int,int> mp;
  rep(i,n){
    while(!(a[i]&1)){
      a[i] >>= 1;
    }
    if(mp[a[i]]==0){
      cnt++;
    }
    mp[a[i]]++;
  }
  cout << cnt << "\n";
  return 0;
}
