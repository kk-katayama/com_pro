#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int t; cin >> t;
  vector<string> res;
  while(t-- > 0) {
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if(a + b < n + m) {
      res.push_back("No");
      continue;
    }
    if(min(a, b) < m) res.push_back("No");
    else res.push_back("Yes");
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
