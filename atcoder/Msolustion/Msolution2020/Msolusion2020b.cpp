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
  int a,b,c; cin >> a >> b >> c;
  int k; cin >> k;
  while(k-- > 0) {
    if(a >= b) b *= 2;
    else if(b >= c) c *= 2;
    else break;
  }

  if(a < b && b < c) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  
  return 0;
}
