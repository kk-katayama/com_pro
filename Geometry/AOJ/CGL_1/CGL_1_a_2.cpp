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
const double EPS = 1e-10;
struct Vec2 {
  double x;
  double y;

  Vec2() : x(0.0),y(0.0){} 
  Vec2(double _x,double _y) :x(_x),y(_y){}  
  
  Vec2 operator+(const Vec2& other) const { return { x + other.x , y + other.y }; }
  Vec2 operator-(const Vec2& other) const { return { x - other.x , y - other.y }; }
  bool operator==(const Vec2& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); } 
  bool operator<(const Vec2& other) const { if(abs(x - other.x) < EPS) return y < other.y; else return x < other.x; }
 
  double dot(const Vec2& other) const { return x * other.x + y * other.y; }
  double cross(const Vec2& other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(x * x + y * y); }

  void Show() { printf("%.8f %.8f\n", x, y); }
};

struct Line {
  Vec2 s; // 始点
  Vec2 t; // 終点

  Line() : s({0, 0}), t({0, 0}) {}
  Line(Vec2 s, Vec2 t) : s(s), t(t) {}

  Vec2 V() { return t - s; }
  double dot(const Line &other) const { return (t - s).dot(other.t - other.s); }
  double cross(const Line &other) const { return (t - s).cross(other.t - other.s); }
  double length() const { return (t - s).length(); }  
};
// A とB のなす角θ cosθ, sinθ を返す
double Cos(const Line &A, const Line &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.dot(B) / (A.length()*B.length());
}
double Sin(const Line &A, const Line &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.cross(B) / (A.length()*B.length());
}
// 線分ABをB方向に長さlに延長する
Line ExpandB(const Line &AB, const double &l) {
  Line v(Vec2(0,0), Vec2(1,0));
  Vec2 d(l * Cos(v, AB), l * Sin(v, AB));
  return Line(AB.s, AB.s + d);
}

// 直線ABと点Cの距離
double DistLinePoint(const Line &AB, const Vec2 &C) {
  Line AC(AB.s, C);
  return AC.length() * abs(Sin(AB, AC));
}
// 直線AB上に点Cを射影した点
Vec2 Proj(const Line &AB, const Vec2 &C) {
  Line AC(AB.s, C);
  double l = AC.length() * Cos(AB, AC);
  Line res = ExpandB(AB, l);
  return res.t;
}

int main()
{
  Vec2 p1, p2;
  cin >> p1.x >> p1.y >> p2.x >> p2.y;
  Line AB(p1, p2);
  int q; cin >> q;
  while(q-- > 0) {
    Vec2 p;
    cin >> p.x >> p.y;
    Vec2 res = Proj(AB, p);
    res.Show();
  }
  return 0;
}
