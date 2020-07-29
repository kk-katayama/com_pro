#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int t; cin >> t;
  vector<int> res;
  while(t-- > 0) {
    ll a,b; cin >> a >> b;
    if(a > b) swap(a, b);
    bool f = true;
    if(b % a != 0) f = false;
    b /= a;
    int cnt = 0;
    while(b > 1) {
      if(b % 2 != 0) f = false;
      b /= 2;
      cnt++;
    }
    int ans = (cnt + 2) / 3;
    res.push_back((f ? ans : -1));
  }
  for(auto val: res) cout << val << "\n";
  
  return 0;
}
