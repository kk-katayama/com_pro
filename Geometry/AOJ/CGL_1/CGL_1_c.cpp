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

// cosθを返す。A とB のなす角θ
double Cos(const Vec2 A, const Vec2 B) {
  return A.dot(B) / (A.length()*B.length());
}

double Sin(const Vec2 A, const Vec2 B) {
  return A.cross(B) / (A.length()*B.length());
}

int main()
{
  double p0x,p0y,p1x,p1y; cin >> p0x >> p0y >> p1x >> p1y;
  int q; cin >> q;
  vector<double> p2x(q),p2y(q);
  rep(i,q) cin >> p2x[i] >> p2y[i];
  Vec2 A(p1x - p0x, p1y - p0y);
  
  rep(i,q) {
    Vec2 B(p2x[i] - p0x, p2y[i] - p0y);
    if(abs(B.length()) < EPS) {
      cout << "ON_SEGMENT" << "\n";
      continue;
    }
    double sine = Sin(A, B);
    if(abs(sine) < EPS) {
      double cosi = Cos(A, B);
      if(cosi < 0) {
	cout << "ONLINE_BACK" << "\n";
      }
      else {
	if(A.length() + EPS < B.length()) cout << "ONLINE_FRONT" << "\n";
	else cout << "ON_SEGMENT" << "\n";
      }
    }
    else if(sine > 0) {
      cout << "COUNTER_CLOCKWISE" << "\n";
    }
    else if(sine < 0) {
      cout << "CLOCKWISE" << "\n";
    }
  }
  
  return 0;
}
