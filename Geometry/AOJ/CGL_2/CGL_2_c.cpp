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

Vec2 CrossPoint(const Vec2 a, const Vec2 b, const Vec2 c, const Vec2 d) {
  if( abs(Sin(b - a, d - c)) < EPS) {
    cout << "Pararell" << "\n";
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

int main()
{
  int q; cin >> q;
  while(q-- > 0) {
    vector<double> x(4),y(4);
    rep(i,4) cin >> x[i] >> y[i];
    vector<Vec2> v(4);
    rep(i,4) {
      v[i].x = x[i];
      v[i].y = y[i];
    }
    Vec2 res = CrossPoint(v[0], v[1], v[2], v[3]);
    printf("%.9f %.9f\n", res.x, res.y);
  }
  
  return 0;
}
