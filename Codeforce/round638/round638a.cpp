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
    int n; cin >> n;
    int a = pow(2, n);
    rep1(i,n/2 - 1) {
      a += pow(2, i);
    }
    int sum = pow(2, n + 1) - 2;
    cout << abs(2 * a - sum) << "\n";
  }
  return 0;
}
