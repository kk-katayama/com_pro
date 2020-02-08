#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<int,int> &a,pair<int,int> &b){
  return a.first > b.first;
}
int main()
{
  vector<pair<int,int>> p(3);
  rep(i,3){
    int a;
    cin >> a;
    p[i] = {a,i};
  }

  sort(p.begin(), p.end(),comp);
  vector<int> res(3);
  rep(i,3){
    res[p[i].second] = i+1;
  }
  rep(i,3){
    cout << res[i] << "\n";
  }
  
  
  
  return 0;
}
