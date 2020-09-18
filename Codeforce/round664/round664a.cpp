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
  int t; cin >> t;
  while(t-- > 0) {
    int b[4];
    rep(i,4) cin >> b[i];
    bool f = (b[0] == 0 || b[1] == 0 || b[2] == 0);
    int cnt = 0;
    rep(i,4) if(b[i] % 2 == 1) cnt++;
    if(cnt <= 1) cout << "Yes" << "\n";
    else if(cnt >= 3 && (!f)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  }
  return 0;
}
