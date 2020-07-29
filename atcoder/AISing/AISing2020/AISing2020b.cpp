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
  int n; cin >> n;
  vector<int> a(n+1);
  rep1(i,n) cin >> a[i];

  int res = 0;
  rep1(i,n) {
    if(i % 2 == 1 && a[i] % 2 == 1) res++;
  }
  cout << res << "\n";
  return 0;
}
