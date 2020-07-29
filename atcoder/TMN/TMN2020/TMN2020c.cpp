#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  int k; cin >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  using pi = pair<int,int>;

  rep(i,k) {
    vector<int> b(n, 1);
    vector<pi> p;
    rep(j,n){
      p.push_back({j,2});
    }
    rep(j,n) {
      p.push_back({max(0, j-a[j]), 1});
      p.push_back({min(n, j+a[j]+1), -1});      
    }
    sort(p.begin(), p.end());
    int now = 0;
    rep(j,p.size()) {
      int id = p[j].second;
      if(id == 2) {
	b[p[j].first] = now;
      }
      else {
	now += id;
      }
    }
    bool f = true;
    a = b;
    for(auto val: a) if(val != n) f = false;
    if(f) break;
    
  }

  for(auto val: a) cout << val << " ";
  cout  << "\n";    


  return 0;
}
