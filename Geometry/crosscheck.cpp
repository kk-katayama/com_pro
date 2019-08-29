#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const double EPS = 1e-10;
struct Vec2
{
  double x;
  double y;
  
  Vec2()
    :x(0.0)
    ,y(0.0){} //デフォルトコンストラクタ
  
  Vec2(double _x,double _y)
    :x(_x)
    ,y(_y){}  //コンストラクタ
  
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
  void print(){
    cout << x << " " << y << "\n";
  }
};
bool crosscheck(Vec2& a,Vec2& b,Vec2& c,Vec2& d) //線分ab線分cdの交差判定
{
  Vec2 ab = b - a;
  Vec2 ac = c - a;
  Vec2 ad = d - a;
  Vec2 cd = d - c;
  Vec2 ca = a - c;
  Vec2 cb = b - c;

  double s = ab.cross(ac) * ab.cross(ad);
  double t = cd.cross(ca) * cd.cross(cb);
  
  return s <= 0 && t <= 0;
}

int main()
{
  Vec2 a(0,4),b(4,1),c(1,0),d(2,1);

  cout << (crosscheck(a,b,c,d)?"YES":"NO") << "\n";
  
  return 0;
}
