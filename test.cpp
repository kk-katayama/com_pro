#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
double M = 11;
double rec(int x) {
  if(x == 0) return 0;
  double res = 110;
  double y = x;
  res += 2 * y * (11 - y)*rec(x - 1);
  if(x >= 2) {
    res += y * (y - 1) * rec(x - 2);
  }
  res /= (21 - y) * y;
  return res;
}
int main()
{
  cout << rec(11) << "\n";
  return 0;
}
