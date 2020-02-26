#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<int,int> &a,pair<int,int> &b){
  return a>b;
}
int main()
{
  int n;cin >> n;
  vector<pair<int,int>> p(n);
  rep(i,n){
    int a,b;cin >> a >> b;
    p[i] = {b,a};
  }

  sort(p.begin(), p.end(),comp);
  int t = 2e+9;
  rep(i,n){
    t=min(t,p[i].first);
    t -= p[i].second;
  }
  if(t<0) cout << "No" << "\n";  
  else cout << "Yes" << "\n";
  
  return 0;
}
