#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll h,w;
  cin >> w >> h;
  vector<pair<ll,int>> p(w+h);
  rep(i,w){
    cin >> p[i].first;
    p[i].second = 0;
  }
  rep(i,h){
    cin >> p[i+w].first;
    p[i+w].second = 1;
  }  

  sort(p.begin(), p.end());
  ll cntw=0,cnth=0;
  ll res = 0;
  rep(i,h+w){
    //    cout << p[i].first << ":" << p[i].second << "\n";
    if(p[i].second==0){
      res += p[i].first*(h+1-cnth);
      cntw++;
    }
    else{
      res += p[i].first*(w+1-cntw);
      cnth++;
    }
  }

  cout << res << "\n";
  
  
  
  return 0;
}
