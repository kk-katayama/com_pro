#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> s(n),t(n);
  rep(i,n) cin >> s[i]>>t[i];

  vector<pair<int,int>> sch(n);
  rep(i,n) {
    sch[i]=make_pair(t[i],s[i]);
  }
  sort(sch.begin(), sch.end());
  
  int ans=0;
  int time=0;
  rep(i,n){
    if(sch[i].second>time){
      ans++;
      time=sch[i].first;
    }
  }
  cout << ans << "\n";
  return 0;
}
