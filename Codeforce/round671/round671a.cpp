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
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    string s; cin >> s;
    if(n % 2 == 0) {
      bool f = true;
      for (int i = 1; i < (int)s.size(); i += 2) {
	int x = s[i] - '0';
	if(x % 2 == 0) f = false;
      }
      cout << (f ? 1 : 2) << "\n";
    }
    else {
      bool f = true;
      for (int i = 0; i < (int)s.size(); i += 2) {
	int x = s[i] - '0';
	if(x % 2 == 1) f = false;
      }
      cout << (f ? 2 : 1) << "\n";      
    }
  }
  return 0;
}
