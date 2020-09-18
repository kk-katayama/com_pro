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
    string s; cin >> s;
    vector<int> one;
    int cnt = 0;
    rep(i,(int)s.size()) {
      if(s[i] == '1') {
	cnt++;
      }
      else {
	one.push_back(cnt);
	cnt = 0;
      }
    }
    one.push_back(cnt);
    sort(one.begin(), one.end(), [](int a, int b){
				   return a > b;
				 });
    int res = 0;
    rep(i,(int)one.size()) {
      if(i % 2 == 0) res += one[i];
    }
    cout << res << "\n";
  }
  return 0;
}
