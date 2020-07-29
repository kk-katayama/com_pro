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
  int q; cin >> q;
  while(q-- > 0) {
    vector<double> x(4),y(4);
    rep(i,4) cin >> x[i] >> y[i];
    Vec2 A(x[1] - x[0], y[1] - y[0]);
    Vec2 B(x[3] - x[2], y[3] - y[2]);
    double sine = Sin(A, B);
    double cosi = Cos(A, B);
    if(abs(sine) < EPS) cout << 2 << "\n"; // 平行
    else if(abs(cosi) < EPS) cout << 1 << "\n"; //直行
    else cout << 0 << "\n";
  }
  
  return 0;
}
