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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.erase(it, a.end());
    if(a.size() > k) {
      cout << -1 << "\n";
    }
    else {
      if(a.size() < k) {
	while(a.size() < k) a.push_back(1);
      }
      cout << n*k << "\n";
      rep(i,n) rep(j,k) cout << a[j] << " ";
      cout << "\n";
    }
  }
  return 0;
}
