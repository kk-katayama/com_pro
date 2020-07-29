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
  int x,n; cin >> x >> n;
  set<int> st;
  rep(i,n) {
    int p; cin >> p;
    st.insert(p);
  }

  int i = 0;
  while(1) {
    if(st.find(x-i) == st.end()) {
      cout << x-i << "\n";
      break;
    }
    if(st.find(x+i) == st.end()) {
      cout << x+i << "\n";
      break;
    }
    i++;
  }
  
  return 0;
}
