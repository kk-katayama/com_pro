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
using ld = long double;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  vector<ld> x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];

  vector<int> vec(n);
  rep(i,n) vec[i] = i;
  // vectorの全並び替えを全探索
  ld res = 0;
  do{
    rep(i,n-1) {
      int a = vec[i], b = vec[i+1];
      res += sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
    }
  } while(next_permutation(vec.begin(), vec.end()));
  rep1(i,n) {
    res /= i;
  }
  printf("%.8Lf\n", res);
  
  return 0;
}
