#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n,k; cin >> n >> k;
  vector<int> x(n);
  vector<int> v(n+1);
  rep(i,n) {
    cin >> x[i];
    v[x[i]] = i + 1;
  }
  set<int> st;
  rep(i,k) {
    st.insert(x[i]);
  }
  auto it1 = st.end();
  it1--;
  int piv = *it1;
  cout << v[piv] << "\n";
  
  for (int i = k; i < n; ++i) {
    st.insert(x[i]);
    auto it = st.find(piv);
    if(piv > x[i]) {
      it--;
    }
    piv = *it;
    cout << v[piv] << "\n";
  }

  
  return 0;
}
