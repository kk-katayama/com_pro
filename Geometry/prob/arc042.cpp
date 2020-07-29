#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Vec2
{
  double x;
  double y;
  
  Vec2()
    :x(0.0)
    ,y(0.0){} 
  
  Vec2(double _x,double _y)
    :x(_x)
    ,y(_y){}  
  
  Vec2 operator+(const Vec2& other) const
  {
    return { x + other.x , y + other.y };
  }

  Vec2 operator-(const Vec2& other) const
  {
    return { x - other.x , y - other.y };
  }

  double dot(const Vec2& other) const
  {
    return x * other.x + y * other.y;
  }
  
  double cross(const Vec2& other) const
  {
    return x * other.y - y * other.x;
  }

  double length() const
  {
    return sqrt(x * x + y * y);
  }
};
double dist(Vec2& a,Vec2& b,Vec2& c) //直線abと点cの距離
{
  Vec2 ab = b - a;
  Vec2 ac = c - a;

  double det = ab.cross(ac);
  return fabs(det/ab.length());
}
double xx,yy;
int n;
double x[11],y[11];
int main()
{
  cin >> xx >> yy;
  cin >> n;
  rep(i,n) cin >> x[i] >> y[i];
  x[n] = x[0];
  y[n] = y[0];
  
  Vec2 c(xx,yy);

  double res = 1e+9;
  rep(i,n){
    Vec2 a(x[i],y[i]),b(x[i+1],y[i+1]);
    res = min(res,dist(a,b,c));
  }

  printf("%.7f\n", res);
  return 0;
}
