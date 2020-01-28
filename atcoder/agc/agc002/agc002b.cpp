#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
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
  vector<pair<bool,int>> p(n,{false,1});
  p[0].first = true;
  rep(i,m){
    if(p[a[i]].first){
      p[b[i]].first = true;
    }
    p[a[i]].second--;
    p[b[i]].second++;
    if(p[a[i]].second==0){
      p[a[i]].first=false;
    }
  }

  int cnt = 0;
  rep(i,n){
    if(p[i].first){
      cnt++;
    }
  }

  cout << cnt << "\n";
  return 0;
}
