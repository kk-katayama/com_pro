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
using ld = long double;
const ld EPS = 1e-10;
struct Vec2 {
  ld x;
  ld y;

  Vec2() : x(0.0),y(0.0){} 
  Vec2(ld _x,ld _y) :x(_x),y(_y){}  
  
  Vec2 operator+(const Vec2& other) const { return { x + other.x , y + other.y }; }
  Vec2 operator-(const Vec2& other) const { return { x - other.x , y - other.y }; }
  bool operator==(const Vec2& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); } 
  bool operator<(const Vec2& other) const { if(abs(x - other.x) < EPS) return y < other.y; else return x < other.x; }
 
  ld dot(const Vec2& other) const { return x * other.x + y * other.y; }
  ld cross(const Vec2& other) const { return x * other.y - y * other.x; }
  ld length() const { return sqrt(x * x + y * y); }
  
  void Show() { printf("%.8Lf %.8Lf\n", x, y); }
};

struct Line {
  Vec2 s; // 始点
  Vec2 t; // 終点
  
  Line() : s({0, 0}), t({0, 0}) {}
  Line(Vec2 s, Vec2 t) : s(s), t(t) {}

  Vec2 V() { return t - s; }
  ld dot(const Line &other) const { return (t - s).dot(other.t - other.s); }
  ld cross(const Line &other) const { return (t - s).cross(other.t - other.s); }
  ld length() const { return (t - s).length(); }

  ld alpha() { // 直線の傾き
    if(abs((t - s).x) < EPS) { cout << "pararell Y axis!!!" << "\n"; return 0; }
    else return (t - s).y / (t - s).x;
  }
  ld beta() { // 直線の切片
    if(abs((t - s).x) < EPS) { cout << "pararell Y axis!!!" << "\n"; return 0; }
    else return s.y - (t - s).y / (t - s).x * s.x;
  }
};
// A とB のなす角θ cosθ, sinθ を返す
ld Cos(const Line &A, const Line &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.dot(B) / (A.length()*B.length());
}
ld Sin(const Line &A, const Line &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.cross(B) / (A.length()*B.length());
}
// 線分ABをB方向に長さlに延長する
Line ExpandB(const Line &AB, const ld &l) {
  Line v(Vec2(0,0), Vec2(1,0));
  Vec2 d(l * Cos(v, AB), l * Sin(v, AB));
  return Line(AB.s, AB.s + d);
}
// 線分ABを両方向に長さlに延長する
Line ExpandAB(Line &AB, ld &l) {
  Line v(Vec2(0,0), Vec2(1,0));
  Vec2 d(l * Cos(v, AB), l * Sin(v, AB));
  return Line(AB.t - d, AB.s + d);
}
// 線分ABをx:y に内分する点を返す
Vec2 InDiv(Line &AB, ld x, ld y) {
  ld l = AB.length() * x / (x + y);
  return ExpandB(AB, l).t;
}
// 直線ABと点Cの距離
ld DistLinePoint(const Line &AB, const Vec2 &C) {
  Line AC(AB.s, C);
  return AC.length() * abs(Sin(AB, AC));
}
// 直線AB上に点Cを射影した点
Vec2 Proj(const Line &AB, const Vec2 &C) {
  Line AC(AB.s, C);
  ld l = AC.length() * Cos(AB, AC);
  Line res = ExpandB(AB, l);
  return res.t;
}
// 線分AB上に点Cがあるか
bool IsInLine(const Line &AB, const Vec2 &C) {
  Line CA(C, AB.s), CB(C, AB.t);
  return abs(Sin(CA, CB)) < EPS && CA.dot(CB) < EPS;
}
// 線分の交差判定
bool CrossCheck(const Line &AB, const Line &CD) {
  //  if(a == c || a == d || b == c || b == d) return true; // 端点が等しい場合はtrue
  Line AC(AB.s, CD.s), AD(AB.s, CD.t);
  Line BC(AB.t, CD.s), BD(AB.t, CD.t);
  Line CA(CD.s, AB.s), CB(CD.s, AB.t);
  Line DA(CD.t, AB.s), DB(CD.t, AB.t);
  ld s = AB.cross(AC) * AB.cross(AD);
  ld t = CD.cross(CA) * CD.cross(CB);

  if(abs(Sin(AB, CD)) < EPS) { // 平行のとき
    if(abs(Sin(AB, AC)) < EPS) { // 同一直線上にあるか？
      return (CA.dot(CB) < EPS || DA.dot(DB) < EPS || AC.dot(AD) < EPS || BC.dot(BD) < EPS);
    }
    else return false;
  }
  else return s < EPS && t < EPS;
}
// 直線の交点
Vec2 CrossPoint(Line &AB, Line &CD) {
  if( abs(Sin(AB, CD)) < EPS) {
    cout << "Pararell" << "\n";
    return Vec2(0,0);
  }
  if(abs(AB.V().x) < EPS) { // ABがy軸に平行
    return Vec2(AB.s.x, CD.alpha() * AB.s.x + CD.beta());
  }
  else if( abs(CD.V().x) < EPS) { // CDがy軸に平行
    return Vec2(CD.s.x, AB.alpha() * CD.s.x + AB.beta());
  }
  else {
    ld resX = (CD.beta() - AB.beta()) / (AB.alpha() - CD.alpha());
    ld resY = AB.alpha() * resX + AB.beta();
    return Vec2(resX, resY);
  }
}
// 点Cを通りABに平行な直線を返す
Line OrthogonalLine(Line &AB, Vec2 &C) {
  Vec2 t(C.x + AB.V().y, C.y - AB.V().x);
  return Line(C, t);
}

struct Circle {
  Vec2 p;
  ld r;

  Circle() : p({0,0}), r(0) {}
  Circle(Vec2 p, ld r) : p(p), r(r) {}
  
  void Show() { printf("%.8Lf %.8Lf %.8Lf\n", p.x, p.y, r); }
};

// 三角形の外接円
Circle CircumscribedCircle(Vec2 &A, Vec2 &B, Vec2 &C) {
  Line AB(A, B), BC(B, C);
  Vec2 ABx = InDiv(AB, 1, 1);
  Vec2 BCx = InDiv(BC, 1, 1);  
  Line ABn = OrthogonalLine(AB, ABx);
  Line BCn = OrthogonalLine(BC, BCx);
  Vec2 Cen = CrossPoint(ABn, BCn);
  return Circle(Cen, (Cen - A).length());
}
// 
vector<Vec2> CrossPointCircleLine(Circle &C, Line &AB){
  vector<Vec2> res;
  if(IsInLine(AB, C.p)) {
    Line OX(C.p, AB.s);
    Vec2 X = ExpandB(OX, C.r).t;
    Line OY(C.p, AB.t);
    Vec2 Y = ExpandB(OY, C.r).t;
    res.push_back(X);
    res.push_back(Y);
    return res;
  }
  Vec2 P = Proj(AB, C.p);
  Line OP(C.p, P);
  Line OPn = OrthogonalLine(OP, P);
  ld l = sqrt(C.r*C.r - OP.length()*OP.length());

  if(C.r < OP.length()) return res;
  Vec2 X = ExpandB(OPn, l).t;
  Vec2 Y = ExpandB(OPn, -l).t;
  // if(X == Y) res.push_back(X);
  // else { 
    res.push_back(X);
    res.push_back(Y);    
    //  }
  return res;
}
int main()
{
  Circle C;
  cin >> C.p.x >> C.p.y >> C.r;
  int q; cin >> q;
  while(q-- > 0) {
    Vec2 A,B;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    Line AB(A, B);
    ld inf = 4000;
    Line ABE = ExpandAB(AB, inf);
    vector<Vec2> res = CrossPointCircleLine(C, ABE);
    sort(res.begin(), res.end());
    rep(i,res.size()) printf("%.8Lf %.8Lf ", res[i].x, res[i].y);
    cout << "\n";
  }
  return 0;
}
