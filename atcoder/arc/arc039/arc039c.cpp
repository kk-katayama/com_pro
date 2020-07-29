#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  string s; cin >> s;

  using pi = pair<int,int>;
  using vi = vector<int>;
  map<pi,vi> mp;
  map<char,int> idx;
  idx['R'] = 0;
  idx['U'] = 1;
  idx['L'] = 2;
  idx['D'] = 3;
  pi now = {0, 0};
  rep(i,n) {
    
  }
  
  return 0;
}
