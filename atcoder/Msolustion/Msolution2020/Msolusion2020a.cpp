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
  int x; cin >> x;
  if(400 <= x && x < 600) cout << 8 << "\n";
  else if(600 <= x && x < 800) cout << 7 << "\n";
  else if(800 <= x && x < 1000) cout << 6 << "\n";
  else if(1000 <= x && x < 1200) cout << 5 << "\n";
  else if(1200 <= x && x < 1400) cout << 4 << "\n";
  else if(1400 <= x && x < 1600) cout << 3 << "\n";
  else if(1600 <= x && x < 1800) cout << 2 << "\n";
  else if(1800 <= x && x < 2000) cout << 1 << "\n";      
  return 0;
}
