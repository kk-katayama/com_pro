#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
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
double EPS = 1e-10;
int main()
{
  double ax,ay,bx,by;
  cin >> ax >> ay >> bx >> by;
  int q; cin >> q;
  vector<double> cx(q),cy(q);
  rep(i,q) cin >> cx[i] >> cy[i];

  rep(i,q) {
    double Z = (ax - bx)*(ax - bx) + (ay - by)*(ay - by);
    double dy = ( (cx[i] - bx)*(ax - bx)*(ay - by) + by*(ax - bx)*(ax - bx) + cy[i]*(ay - by)*(ay - by) )/Z;
    double dx;
    if(abs(ax - bx) > EPS) {
      dx = cx[i] - (ay - by)*(dy - cy[i]) / (ax - bx);
    }
    else {
      dx = bx + (ax - bx)*(dy - by) / (ay - by);      
    }
    printf("%.9f %.9f\n", dx, dy);
  }
  
  return 0;
}
