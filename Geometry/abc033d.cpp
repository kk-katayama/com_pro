#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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

  double length() const
  {
    return sqrt(x * x + y * y);
  }
};

int main()
{
  
  return 0;
}
