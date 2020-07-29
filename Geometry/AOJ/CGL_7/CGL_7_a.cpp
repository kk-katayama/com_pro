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
struct Point {
  double x;
  double y;

  Point() : x(0.0),y(0.0){} 
  Point(double _x,double _y) :x(_x),y(_y){}  
  
  Point operator+(const Point& other) const { return { x + other.x , y + other.y }; }
  Point operator-(const Point& other) const { return { x - other.x , y - other.y }; }
  bool operator==(const Point& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); }
  
  double dot(const Point& other) const { return x * other.x + y * other.y; }
  double cross(const Point& other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(x * x + y * y); }
};
// A とB のなす角θ cosθ, sinθ を返す
double Cos(const Point A, const Point B) { return A.dot(B) / (A.length()*B.length()); }
double Sin(const Point A, const Point B) { return A.cross(B) / (A.length()*B.length()); }

// 線分AB上に点Cがあるかどうかの判定
bool IsOnLine(const Point A, const Point B, const Point C) {  return abs(Sin(A - C, B - C)) < EPS && Cos(A - C, B - C) < 0; }

// 線分の交差判定
bool CrossCheck(const Point a, const Point b, const Point c, const Point d) {
  if(a == c || a == d || b == c || b == d) return true; // 端点が等しい場合はtrue
  Point AB = b - a, AC = c - a, AD = d - a;
  Point CA = a - c, CB = b - c, CD = d - c;
  double s = AB.cross(AC) * AB.cross(AD);
  double t = CD.cross(CA) * CD.cross(CB);

  if(abs(Sin(AB, CD)) < EPS) { // 平行のとき
    if(abs(Sin(AB, AC)) < EPS) { // 同一直線上にあるか？
      return (CA.dot(CB) - EPS < 0 || (a - d).dot(b - d) - EPS < 0 || AC.dot(AD) - EPS < 0);
    }
    else return false;
  }
  else return s < EPS && t < EPS;
}

double Dist(const Point &a, const Point &b) { return (a - b).length(); }

struct Circle {
  Point p;
  double r;

  Circle() : p({0,0}), r(0) {}
  Circle(Point p, double r) : p(p), r(r) {}
};

int CrossCheckCircle(Circle a, Circle b) {
  double d = Dist(a.p, b.p);
  if(abs(a.r - b.r) > d) return 0;
  else if(abs(abs(a.r - b.r) - d) < EPS) return 1;
  
  if(a.r + b.r < d) return 4;
  else if(abs(a.r + b.r - d) < EPS) return 3;
  else return 2;
}

int main()
{
  Circle c1, c2;
  cin >> c1.p.x >> c1.p.y >> c1.r;
  cin >> c2.p.x >> c2.p.y >> c2.r;
  cout << CrossCheckCircle(c1, c2) << "\n";
  return 0;
}
