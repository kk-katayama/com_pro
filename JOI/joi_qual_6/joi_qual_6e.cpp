#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<pair<int,int>,pair<int,int>> &a,pair<pair<int,int>,pair<int,int>> &b){
  return a.second.second>b.second.second;
}
int main()
{
  int s=0,n;
  rep(i,3){
    int x;
    cin >> x;
    s += x;
  }
  cin >> n;
  vector<pair<pair<int,int>,pair<int,int>>> p(n);
  rep(i,n){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--;b--;c--;
    p[i] = {{a,b},{c,d}};
  }

  sort(p.begin(), p.end(),comp);
  vector<int> res(s,2);
  rep(i,n){
    int a=p[i].first.first;
    int b=p[i].first.second;
    int c=p[i].second.first;
    int d=p[i].second.second;        
    if(d==1){
      res[a]=1;res[b]=1;res[c]=1;      
    }
    else{
      if(res[a]==1&&res[b]==1) res[c]=0;
      else if(res[a]==1&&res[c]==1) res[b]=0;
      else if(res[c]==1&&res[b]==1) res[a]=0;      
    }
  }

  rep(i,s){
    cout << res[i] << "\n";
  }
  
  
  return 0;
}
