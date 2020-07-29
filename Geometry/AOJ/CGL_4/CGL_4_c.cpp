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
const double PI = atan(1)*4;
struct Vec2 {
  double x;
  double y;

  Vec2() : x(0.0),y(0.0){} 
  Vec2(double _x,double _y) :x(_x),y(_y){}  
  
  Vec2 operator+(const Vec2& other) const { return { x + other.x , y + other.y }; }
  Vec2 operator-(const Vec2& other) const { return { x - other.x , y - other.y }; }
  bool operator==(const Vec2& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); }
  bool operator!=(const Vec2& other) const { return (abs(x - other.x) > EPS || abs(y - other.y) > EPS ); }  
  
  double dot(const Vec2& other) const { return x * other.x + y * other.y; }
  double cross(const Vec2& other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(x * x + y * y); }
};
// A とB のなす角θ cosθ, sinθ を返す
double Cos(const Vec2 A, const Vec2 B) { return A.dot(B) / (A.length()*B.length()); }
double Sin(const Vec2 A, const Vec2 B) { return A.cross(B) / (A.length()*B.length()); }

// 線分AB上に点Cがあるかどうかの判定
bool IsOnLine(const Vec2 A, const Vec2 B, const Vec2 C) {  return abs(Sin(A - C, B - C)) < EPS && Cos(A - C, B - C) < 0; }

// 線分の交差判定
bool CrossCheck(const Vec2 a, const Vec2 b, const Vec2 c, const Vec2 d) {
  Vec2 AB = b - a, AC = c - a, AD = d - a;
  Vec2 CA = a - c, CB = b - c, CD = d - c;
  if(abs(Sin(AB, CD)) < EPS) { // 平行のとき
    // if(abs(Sin(AB, AC)) < EPS) { // 同一直線上にあるか？
    //   return (CA.dot(CB) - EPS < 0 || (a - d).dot(b - d) - EPS < 0 || AC.dot(AD) - EPS < 0);
    // }
    // else return false;
    return false;
  }
  if(a == c || a == d || b == c || b == d) return true; // 端点が等しい場合はtrue
  if(IsOnLine(a, b, c)) return true;
  if(IsOnLine(a, b, d)) return true;  
  double s = AB.cross(AC) * AB.cross(AD);
  double t = CD.cross(CA) * CD.cross(CB);
  
  return s < EPS && t < EPS;
}

Vec2 CrossPoint(const Vec2 a, const Vec2 b, const Vec2 c, const Vec2 d) {
  if( abs(Sin(b - a, d - c)) < EPS) {
    //    cout << "Pararell" << "\n";
    return Vec2(0,0);
  }
  if(abs(a.x - b.x) < EPS) {
    double alpha2 = (d.y - c.y) / (d.x - c.x);
    double beta2 = c.y - alpha2 * c.x;
    double resX = a.x;
    double resY = alpha2 * resX + beta2;
    return Vec2(resX, resY);
  }
  else if( abs(c.x - d.x) < EPS) {
    double alpha1 = (b.y - a.y) / (b.x - a.x);
    double beta1 = a.y - alpha1 * a.x;
    double resX = c.x;
    double resY = alpha1 * resX + beta1;
    return Vec2(resX, resY);
  }
  else {
    double alpha1 = (b.y - a.y) / (b.x - a.x);
    double beta1 = a.y - alpha1 * a.x;
    double alpha2 = (d.y - c.y) / (d.x - c.x);
    double beta2 = c.y - alpha2 * c.x;
    double resX = (beta2 - beta1) / (alpha1 - alpha2);
    double resY = alpha1 * resX + beta1;
    return Vec2(resX, resY);
  }
}

double Area(const vector<Vec2> &v) {
  int n = v.size();
  if(n <= 2) return 0;
  double res = 0;
  Vec2 O = v[0];
  rep1(i,n-2) {
    res += (v[i] - O).cross(v[i+1] - O) / 2;
  }
  return res;
}

int main()
{
  int n; cin >> n;
  vector<Vec2> v(n);
  rep(i,n) cin >> v[i].x >> v[i].y;
  double M = 20000;  
  int q; cin >> q;
  while(q-- > 0) {
    Vec2 p1,p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    // 線分→直線
    double dx = p2.x - p1.x, dy = p2.y - p1.y;
    double c1x,c2x,c1y,c2y;
    // p2
    if(abs(dx) < EPS) { c2x = 0; }
    else if(dx > 0) { c2x = floor((M - p2.x) / dx); }
    else { c2x = ceil((-M - p2.x) / dx); }
    if(abs(dy) < EPS) { c2y = 0; }
    else if(dy > 0) { c2y = floor((M - p2.y) / dy); }
    else { c2y = ceil((-M - p2.y) / dy); }    
    p2.x = p2.x + dx * max(c2x, c2y);
    p2.y = p2.y + dy * max(c2x, c2y);
    // p1
    dx = -dx; dy = -dy;
    if(abs(dx) < EPS) { c1x = 0; }
    else if(dx > 0) { c1x = floor((M - p1.x) / dx); }
    else { c1x = ceil((-M - p1.x) / dx); }
    if(abs(dy) < EPS) { c1y = 0; }
    else if(dy > 0) { c1y = floor((M - p1.y) / dy); }
    else { c1y = ceil((-M - p1.y) / dy); }    
    p1.x = p1.x + dx * max(c1x, c1y);
    p1.y = p1.y + dy * max(c1x, c1y);
    //
    int start = 0, goal = 0;
    Vec2 q1s(M,M), q1g(M,M), q2s(M,M), q2g(M,M);
    int q1sid, q1gid, q2sid, q2gid;
    bool flag = true; // 交点が二つあるか？
    bool isleft = false; // 左側に点があるか？
    rep(i,n) {
      if(Sin(p2 - p1, v[i] - p1) > 0) isleft = true;
      if(CrossCheck(p1, p2, v[i], v[(i+1)%n])) {
	Vec2 r = CrossPoint(p1, p2, v[i], v[(i+1)%n]);
	if(q1s.x == M || q1s.y == M) {
	  q1s = v[i];
	  q1g = v[(i+1)%n];
	  q1sid = i;
	  q1gid = (i+1) % n;	  
	}
	else if(r != CrossPoint(p1, p2, q1s, q1g)) {
	  flag = false;
	  q2s = v[i];
	  q2g = v[(i+1)%n];
	  q2sid = i;
	  q2gid = (i+1) % n;
	}
      }
    }
    double res = 0;
    if(flag) {
      if(isleft) {
	res = Area(v);
	printf("%.8f\n", res); continue;	
      }
      else {
	printf("%.8f\n", res); continue;
      }
    }
    Vec2 r1 = CrossPoint(q1s, q1g, p1, p2);
    Vec2 r2 = CrossPoint(q2s, q2g, p1, p2);
    // cout << r1.x << ":" << r1.y << "\n";
    // cout << r2.x << ":" << r2.y << "\n";
    // cout << start << ":" << goal << "\n";
    vector<Vec2> h;
    if((p1 - r1).length() < (p1 - r2).length() ) {
      start = q2gid;
      goal = q1sid;
      h.push_back(r2);
      for(int i = start; i % n != (goal + 1) % n; ++i) {
	h.push_back(v[i % n]);
      }
      h.push_back(r1);
    }
    else {
      start = q1gid;
      goal = q2sid;            
      h.push_back(r1);
      for(int i = start; i % n != (goal + 1) % n; ++i) {
	h.push_back(v[i % n]);
      }
      h.push_back(r2);      
    }
    res = Area(h);
    printf("%.8f\n", res);
  }
  return 0;
}
