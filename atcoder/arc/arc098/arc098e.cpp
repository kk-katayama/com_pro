#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,k,q; cin >> n >> k >> q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  using pi = pair<int,int>;
  vector<pi> b(n);
  rep(i,n) b[i] = {a[i], i};
  sort(b.begin(), b.end());

  set<int> st;
  vector<int> idx;
  st.insert(n);
  int res = 1e+9;
  rep(i,n) {
    int left = 0;
    multiset<int> vec;
    for(auto val: st) {
      multiset<int> part;
      for (int j = left; j < val; ++j) {
	part.insert(a[j]);
      }
      left = val + 1;
      if((int)part.size() - k < 0) continue;
      auto it = part.begin();
      rep(j,part.size() - k + 1) {
	vec.insert(*it);
	if(vec.size() == q + 1) {
	  auto itend = vec.end();
	  itend--;
	  vec.erase(itend);
	}
	++it;
      }
    }
    if(vec.size() < q) break;
    auto itend = vec.end();
    itend--;
    chmin(res, *itend - b[i].first);
    idx.push_back(b[i].second);
    if(i == n-1) continue;
    if(b[i].first != b[i+1].first) {
      for(auto val: idx) {
	st.insert(val);
      }
      idx.clear();
    }
  }

  cout << res << "\n";
  
  return 0;
}
