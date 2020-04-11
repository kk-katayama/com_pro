#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  set<int> st;
  st.insert(-1);
  st.insert(n);
  map<int,vector<int>> mp;
  rep(i,n) {
    if(mp[-h[i]].size() == 0) mp[-h[i]].push_back(-1);
    mp[-h[i]].push_back(i);
  }

  vector<int> res(n);
  for(auto m : mp) {
    m.second.push_back(n);
    rep1(i, m.second.size()-2){
      int index = m.second[i];
      auto it = st.lower_bound(index);
      int right = *it--;
      int left = *it;
      res[index] = (right - index - 1) + (index - left - 1);
    }
    rep1(i, m.second.size()-2){
      int index = m.second[i];
      st.insert(index);
    }
  }

  rep(i,n) cout << res[i] << "\n";
  
  return 0;
}
