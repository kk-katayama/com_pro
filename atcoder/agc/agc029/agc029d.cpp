#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int h,w; cin >> h >> w;
  int n; cin >> n;
  vector<set<int>> st(w);
  rep(i,n) {
    int x,y; cin >> x >> y;
    x--; y--;
    st[y].insert(x);
  }

  rep(i,w) {
    st[i].insert(h);
  }

  int j = 0;
  int res = 1e+9;
  rep(i,w) {
    auto it = st[i].lower_bound(j);
    while(*it == j) {
      it++; j++;
      if(j >= h) break;
    }
    if(j >= h) {
      chmin(res, h);
      break;
    }
    chmin(res, *it);
    //    cout << i << ":" << j << "\n";
    j++;
  }

  cout << res << "\n";
  
  return 0;
}
