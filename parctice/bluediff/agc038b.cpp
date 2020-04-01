#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  set<int> st;
  rep(i,k) st.insert(p[i]);
  int left = 0;
  int right = k;
  int res = 1;
  while(right < n) {
    bool f = true;
    auto lit = st.find(p[left]);
    if(lit != st.begin() ) f = false;
    st.erase(p[left]);
    st.insert(p[right]);
    auto rit = st.find(p[right]);
    rit++;
    if(rit != st.end()) f = false;
    if(!f) res++;
    left++;
    right++;
  }

  int cnt = 1;
  int kk = 0;
  rep(i,n-1) {
    if(p[i] < p[i+1]) cnt++;
    else {
      if(cnt >= k) kk++;
      cnt = 1;
    }
  }
  if(cnt >= k) kk++;
  res -= max(kk - 1, 0);
  cout << res << "\n";
  return 0;
}
