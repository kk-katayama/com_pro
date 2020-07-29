#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int k,s; cin >> k >> s;
  int res = 0;
  rep(i,k+1) {
    rep(j,k+1) {
      if(0 <= s - i - j && s - i - j <= k) res++;
    }
  }
  cout << res << "\n";
  return 0;
}
