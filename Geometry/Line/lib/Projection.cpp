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
const double EPS = 1e-10;
struct Vec2 {
  double x;
  double y;

  Vec2() : x(0.0),y(0.0){} 
  Vec2(double _x,double _y) :x(_x),y(_y){}  
  
  Vec2 operator+(const Vec2& other) const { return { x + other.x , y + other.y }; }
  Vec2 operator-(const Vec2& other) const { return { x - other.x , y - other.y }; }

  double dot(const Vec2& other) const { return x * other.x + y * other.y; }
  double cross(const Vec2& other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(x * x + y * y); }
};

// 点Cから直線ABに下ろした垂線とABの交点(Projection)
Vec2 Proj(const Vec2 A, const Vec2 B, const Vec2 C) { 
  Vec2 D;
  double Z = (A - B).length();
  Z = Z*Z;
  D.y = ( (C.x - B.x)*(A.x - B.x)*(A.y - B.y) + B.y*(A.x - B.x)*(A.x - B.x) + C.y*(A.y - B.y)*(A.y - B.y) ) / Z;
  if(abs(A.x - B.x) > EPS) {
    D.x = C.x - (A.y - B.y)*(D.y - C.y) / (A.x - B.x);
  }
  else if(abs(A.y - B.y) > EPS) {
    D.x = B.x + (A.x - B.x)*(D.y - B.y) / (A.y - B.y);
  }
  else {
    cout << "AB is not a Line !!!" << "\n";
    return Vec2(0, 0);
  }
  return D;
}

int main()
{
  double ax,ay,bx,by;
  cin >> ax >> ay >> bx >> by;
  int q; cin >> q;
  vector<double> cx(q),cy(q);
  rep(i,q) cin >> cx[i] >> cy[i];
  Vec2 A(ax, ay), B(bx, by);
  
  rep(i,q) {
    Vec2 C(cx[i], cy[i]);
    Vec2 D = Proj(A, B, C);
    printf("%.9f %.9f\n", D.x, D.y);
  }
  
  return 0;
}
