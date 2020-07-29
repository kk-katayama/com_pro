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
  //  bool operator<(const Vec2& other) const { if(abs(x - other.x) < EPS) return y < other.y; else return x < other.x; }
  bool operator<(const Vec2& other) const { return x < other.x; }
  
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

pair<Vec2,Vec2> pd;
// 最近点対
double ClosestPair(vector<Vec2> &v, int l, int r) {
  if(r - l <= 1) return 1e+15;
  int mid = (l + r) / 2;
  Vec2 O = v[mid];
  double d = min(ClosestPair(v, l, mid), ClosestPair(v, mid, r));
  sort(v.begin() + l, v.begin() + r, [](Vec2 a, Vec2 b) {
					return a.y < b.y;
				      });

  // 境界を跨ぐものをチェック
  vector<Vec2> w;
  for (int i = l; i < r; ++i) {
    if(abs(v[i].x - O.x) >= d) continue;
    for (int j = w.size() - 1; j >= 0; --j) {
      if(abs(v[i].y - w[j].y) >= d) break;
      chmin(d, (v[i] - w[j]).length());
    }
    w.push_back(v[i]);
  }
  return d;
}

int main()
{
  int n; cin >> n;
  vector<Vec2> v(n);
  rep(i,n) cin >> v[i].x >> v[i].y;

  sort(v.begin(), v.end());
  
  double res = ClosestPair(v, 0, n);
  printf("%.10f\n", res);
  return 0;
}
