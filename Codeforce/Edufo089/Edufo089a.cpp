#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int t; cin >> t;
  vector<int> res;
  while(t-- > 0) {
    int a,b; cin >> a >> b;
    int tmp = 0;
    if(a > b) swap(a, b);
    int d = b - a;
    if(a > d) {
      tmp += d;
      a -= d;
      tmp += (a / 3) * 2;
      if(a % 3 == 2) tmp++;
      res.push_back(tmp);
    }
    else {
      res.push_back(a);
    }
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
