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
  bool operator==(const Vec2& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); }
  
  double dot(const Vec2& other) const { return x * other.x + y * other.y; }
  double cross(const Vec2& other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(x * x + y * y); }
};

// A とB のなす角θ cosθ, sinθ を返す
double Cos(const Vec2 A, const Vec2 B) { return A.dot(B) / (A.length()*B.length()); }
double Sin(const Vec2 A, const Vec2 B) { return A.cross(B) / (A.length()*B.length()); }

// 点Cと線分ABの距離
double Dist(const Vec2 A, const Vec2 B, const Vec2 C) { 
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
    return 0;
  }
  if(Cos(A - D, B - D) < 0) {
    return (C - D).length();
  }
  else {
    return 1e+15;
  }
}

// 線分の交差判定
bool CrossCheck(const Vec2 a, const Vec2 b, const Vec2 c, const Vec2 d) {
  if(a == c || a == d || b == c || b == d) return true; // 端点が等しい場合はtrue
  Vec2 AB = b - a, AC = c - a, AD = d - a;
  Vec2 CA = a - c, CB = b - c, CD = d - c;
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


int main()
{
  int q; cin >> q;
  while(q-- > 0) {
    vector<double> x(4),y(4);
    rep(i,4) cin >> x[i] >> y[i];
    double res = 1e+15;
    vector<Vec2> v(4);
    rep(i,4) {
      v[i].x = x[i];
      v[i].y = y[i];
    }
    if(CrossCheck(v[0], v[1], v[2], v[3])) res = 0;
    chmin(res, (v[0] - v[2]).length());
    chmin(res, (v[0] - v[3]).length());    
    chmin(res, Dist(v[2], v[3], v[0]));
    chmin(res, (v[1] - v[2]).length());
    chmin(res, (v[1] - v[3]).length());    
    chmin(res, Dist(v[2], v[3], v[1]));
    chmin(res, (v[2] - v[0]).length());
    chmin(res, (v[2] - v[1]).length());    
    chmin(res, Dist(v[0], v[1], v[2]));
    chmin(res, (v[3] - v[0]).length());
    chmin(res, (v[3] - v[1]).length());    
    chmin(res, Dist(v[0], v[1], v[3]));
    printf("%.9f\n", res);
  }
  
  return 0;
}
