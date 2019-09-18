#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i,n){
    cin >> d[i];
    if(d[i] == 0){
      cout << 0 << "\n";
      return 0;
    }
  }

  map<int,int> mp;
  rep(i,n) mp[d[i]]++;
  vector<int> des(0),tem(0);
  
  for(auto& itr:mp){
    if(itr.second>=3){
      cout << 0 << "\n";
      return 0;
    }
    else if(itr.second==2){
      des.push_back(itr.first);
      des.push_back(24-itr.first);
    }
    else{
      tem.push_back(itr.first);
    }
  }

  int m = tem.size();
  int maxs = 0;
  rep(S,(1<<m)){
    vector<int> vec = des;
    vec.push_back(0);
    rep(i,m){
      if((S>>i)&1){
	vec.push_back(24-tem[i]);
      }
      else{
	vec.push_back(tem[i]);
      }
    }

    int mins = 50;
    int vs = vec.size();
    rep(i,vs) rep(j,vs){
      if(i==j) continue;
      int a = vec[i],b = vec[j];
      if(a>b) swap(a,b);
      mins = min(mins , min(b-a , 24+a-b));
    }
    maxs = max(maxs,mins);
  }
  
  cout << maxs << "\n";
  return 0;
}
