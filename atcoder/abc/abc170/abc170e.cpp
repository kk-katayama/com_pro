#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using pi = pair<int,int>;
int main()
{
  int n,q; cin >> n >> q;
  vector<int> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];
  vector<int> c(q),d(q);
  rep(i,q) cin >> c[i] >> d[i];

  vector<pi> p(n+1);
  int M = 200000;
  vector<multiset<int>> idx(M+1);
  vector<multiset<int>> rate(M+1);  
  rep(i,n) {
    p[i+1] = {a[i], b[i]};
    idx[b[i]].insert(i+1);
    rate[b[i]].insert(a[i]);
  }
  multiset<int> st;
  rep(i,M+1) {
    if(rate[i].size() != 0) {
      auto it = rate[i].end();
      it--;
      st.insert(*it);
      // for(auto val: idx[i]) cout << val << " ";
      // cout << "\n";
    }
  }
  // for(auto val: st) cout << val << " ";
  // cout << "\n";

  rep(i,q) {
    int rat = p[c[i]].first;
    int now = p[c[i]].second;
    p[c[i]].second = d[i];
    //    idx[now].erase(c[i]);
    auto it = rate[now].lower_bound(rat);
    auto it2 = rate[now].end(); it2--;
    if(*it == *it2) {
      auto it3 = st.lower_bound(rat);
      st.erase(it3);
      if(rate[now].size() >= 2) {
	it2--;
	st.insert(*it2);
      }
    }
    rate[now].erase(it);
    
    //    idx[d[i]].insert(c[i]);

    if(rate[d[i]].size() == 0) st.insert(rat);
    else {
      auto it4 = rate[d[i]].end(); it4--;
      if(*it4 < rat) {
	auto it5 = st.lower_bound(*it4);
	st.erase(it5);
	st.insert(rat);
      }
    }
    rate[d[i]].insert(rat);

    //
    // for(auto val: st) cout << val << " ";
    // cout << "\n";    
    auto it6 = st.begin();
    cout << *it6 << "\n";
  }
  
  
  return 0;
}
