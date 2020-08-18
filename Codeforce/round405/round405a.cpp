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
  int n,k; cin >> n >> k;
  vector<string> res(n);
  vector<string> name(52);
  rep(i,52) name[i] = 'A' + (i % 26);
  rep(i,26) name[i+26].push_back((char)'a' + i);
  rep(i,k-1) {
    res[i] = name[i];
  }
  int idx = k - 1;
  rep(i,n-k+1) {
    string s; cin >> s;
    if(s == "YES") {
      res[i + k - 1] = name[idx];
      idx++;
    }
    else {
      res[i + k - 1] = res[i];
    }
  }
  for(auto val: res) cout << val << " ";
  cout << "\n";
  
  return 0;
}
