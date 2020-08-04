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
  int n; cin >> n;
  string s; cin >> s;
  if(n % 2 == 1) {
    cout << "No" << "\n";
  }
  else {
    int m = n/2;
    rep(i,m) {
      if(s[i] != s[i+m]) {
	cout << "No" << "\n";
	return 0;
      }
    }
    cout << "Yes" << "\n";
  }
  return 0;
}
