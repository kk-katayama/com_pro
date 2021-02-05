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
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  string s; cin >> s;
  int n = sz(s);
  if(n % 2 == 0) {
    char c = s[n/2];
    int i = 0;
    while(i < n/2 && s[n/2+i] == c && s[n/2-1-i] == c) i++;
    cout << n/2+i << "\n";
  }
  else {
    char c = s[n/2];
    int i = 0;
    while(i < n/2+1 && s[n/2+i] == c && s[n/2-i] == c) i++;
    cout << n/2+i << "\n";    
  }
  
  return 0;
}
