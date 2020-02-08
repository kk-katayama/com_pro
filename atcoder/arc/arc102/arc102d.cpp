#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int l;
  cin >> l;
  int s;
  rep(i,20){
    if((l>>i)&1){
      s = i+1;
    }
  }
  vector<pair<pair<int,int>,int>> res;
  rep1(i,s-1){
    res.push_back({{i,i+1},0});
    res.push_back({{i,i+1},(int)(1<<(i-1))}); 
  }
  int d = (1<<(s-1));
  rep(i,s-1){
    if((l>>i)&1){
      res.push_back({{i+1,s},d});
      d += (1<<i);
    }
  }
  
  cout << s << " " << (int)res.size() << "\n";
  rep(i,res.size()){
    cout << res[i].first.first << " " << res[i].first.second << " " << res[i].second << "\n";
  }
  return 0;
}
