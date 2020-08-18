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
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    vector<int> a(n+1);
    rep(i,n) {
      a[p[i]] = i+1;
    }

    bool f = false;
    int left = 1, right = n;
    for (int i = n; i > 0; --i) {
      if(a[i] == left)	left++;
      else if(a[i] == right) right--;
      else {
	cout << "YES" << "\n";
	cout << left << " ";
	cout << a[i] << " ";
	cout << right << "\n";
	f = true;
	break;
      }
    }
    if(!f) {
      cout << "NO" << "\n";
    }
  }
  return 0;
}
