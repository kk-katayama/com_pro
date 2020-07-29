#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,m ; cin >> n >> m;
  vector<int> l(m),r(m);
  rep(i,m) {
    cin >> l[i] >> r[i];
  }

  using pi = pair<int,int>;
  vector<pi> vec;
  rep(i,m) {
    vec.push_back({l[i], 1});
    vec.push_back({r[i] + 1, -1});    
  }
  sort(vec.begin(), vec.end());
  int len = vec.size();
  
  int idx = 0;
  int cnt = 0;
  int res = 0;
  rep1(i,n) {
    while(idx < len && vec[idx].F == i) {
      cnt += vec[idx].S;
      idx++;
    }
    if(cnt == m) res++;
  }
  cout << res << "\n";
  
  return 0;
}
