#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<pair<string,int>> st(n);
  rep(i,n){
    cin >> st[i].first >> st[i].second;
  }
  string x;
  cin >> x;

  int res = 0;
  bool f = false;
  rep(i,n){
    if(f){
      res += st[i].second;
    }
    if(st[i].first==x){
      f=true;
    }
  }
  cout << res << "\n";
  
  return 0;
}
