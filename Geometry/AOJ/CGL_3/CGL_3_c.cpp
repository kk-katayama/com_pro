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
const double PI = atan(1)*4;
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

// 線分の交差判定
bool CrossCheck(const Vec2 a, const Vec2 b, const Vec2 c, const Vec2 d) {
  Vec2 AB = b - a, AC = c - a, AD = d - a;
  Vec2 CA = a - c, CB = b - c, CD = d - c;
  double s = AB.cross(AC) * AB.cross(AD);
  double t = CD.cross(CA) * CD.cross(CB);

  if(abs(Sin(CA, CB)) < EPS) return false;
  if(abs(Sin(a - d, b - d)) < EPS) return false;
  
  if(abs(Sin(AB, CD)) < EPS) { // 平行のとき
    return false;
  }
  else return s < EPS && t < EPS;
}


int main()
{
  int n; cin >> n;
  vector<Vec2> v(n);
  rep(i,n) cin >> v[i].x >> v[i].y;
  int q; cin >> q;
  while(q-- > 0) {
    Vec2 w;
    cin >> w.x >> w.y;
    bool f = false;
    rep(i,n) {
      if(abs(Sin(v[i] - w, v[(i+1)%n] - w)) < EPS && Cos(v[i] - w, v[(i+1)%n] - w) < EPS) f = true;
      if(v[i] == w) f = true;
    }
    if(f) {
      cout << 1 << "\n";
      continue;
    }
    Vec2 u(10001, w.y);
    int cnt = 0;
    rep(i,n) {
      if(CrossCheck(w, u, v[i], v[(i+1)%n])) cnt++;
      else if(abs(Sin(w - v[(i+1)%n], u - v[(i+1)%n])) < EPS && Cos(w - v[(i+1)%n], u - v[(i+1)%n]) < EPS) {
	if((v[(i+1)%n].y - v[i].y) * (v[(i+2)%n].y - v[(i+1)%n].y) > EPS ) cnt++;
	else if((v[(i+1)%n].y - v[i].y) > 0 && abs(v[(i+2)%n].y - v[(i+1)%n].y) < EPS) cnt++;
	else if(abs(v[(i+1)%n].y - v[i].y) < EPS && (v[(i+2)%n].y - v[(i+1)%n].y) < 0) cnt++;	
      }
    }
    if(cnt % 2 == 0) cout << 0 << "\n";
    else cout << 2 << "\n";
  }
  return 0;
}
