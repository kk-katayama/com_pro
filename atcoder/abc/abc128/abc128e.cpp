#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,q;cin >> n >> q;
  vector<int> s(n),t(n),x(n);
  rep(i,n) cin >> s[i] >> t[i] >> x[i];
  map<int,int> mp;
  vector<int> d(q);
  rep(i,q){ cin >> d[i];mp[d[i]]=i; }

  vector<pair<int,pair<int,int>>> imos;
  rep(i,n){
    imos.push_back({s[i]-x[i],{1,x[i]}});
    imos.push_back({t[i]-x[i],{0,x[i]}});
    //    cout << st << ":" << go << ":" << x[i] << "\n";
  }
  rep(i,q) imos.push_back({d[i],{2,1e+9+10}});

  sort(imos.begin(), imos.end());
  set<int> se;
  vector<int> res(q);
  rep(i,imos.size()){
    //    cout << imos[i].first << ":" << imos[i].second.first << ":" << imos[i].second.second << "\n";
    if(imos[i].second.first==1){
      se.insert(imos[i].second.second);
    }
    else if(imos[i].second.first==0){
      se.erase(imos[i].second.second);
    }
    else{
      if(se.empty()) res[mp[imos[i].first]] = -1;
      else res[mp[imos[i].first]] = *se.begin();
    }
  }

  rep(i,q) cout << res[i] << "\n";
  
  return 0;
}
