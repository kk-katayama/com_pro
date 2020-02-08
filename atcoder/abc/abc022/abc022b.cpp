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
  map<int,int> mp;
  int cnt = 0;
  rep(i,n){
    int a;
    cin >> a;
    if(mp[a]>0) cnt++;
    mp[a]++;
  }
  cout << cnt << "\n";
  return 0;
}
