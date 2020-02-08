#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Vec2{
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

Vec2 pointa[100010],pointb[100010];
int n;
Vec2 ny;
const double eof = 1e-9;

double cos(Vec2 a,Vec2 b)
{
  double d = a.dot(b);
  double al = a.length(),bl = b.length();
  if(al==0.||bl==0.) return 1.;
  return d/al/bl;
}

  
bool comp1(Vec2& a,Vec2& b){
  if(a.x==b.x) return a.y<b.y;
  else return a.x>b.x;
}

bool comp2(Vec2& a,Vec2& b){
  return cos(ny,Vec2(a-pointa[0]))>cos(ny,Vec2(b-pointa[0]));
}

bool comp3(Vec2& a,Vec2& b){
  return cos(ny,Vec2(a-pointb[0]))>cos(ny,Vec2(b-pointb[0]));
}
  

int main()
{
  cin >> n;
  rep(i,n){
    cin >> pointa[i].x >> pointa[i].y;
  }
  rep(i,n){
    cin >> pointb[i].x >> pointb[i].y;
  }
  
  ny = {0.,1.};
  sort(pointa,pointa+n,comp1);
  sort(pointa,pointa+n,comp2);
  pointa[n] = pointa[0];

  Vec2 A = pointa[1]-pointa[0];
  int xx = 1;
  double len = 0;
  for(int i=2;i<=n;++i){
    Vec2 B = pointa[i] - pointa[xx];
    if(A.cross(B)<eof){
      A = A + B;
      xx = i;
    }
    else{
      len += A.length();
      A = B;
      xx = i;
    }
  }

  sort(pointb,pointb+n,comp1);
  sort(pointb,pointb+n,comp3);
  pointb[n] = pointb[0];

  A = pointb[1]-pointb[0];
  xx = 1;
  double len2 = 0;
  for(int i=2;i<=n;++i){
    Vec2 B = pointb[i] - pointb[xx];
    if(A.cross(B)<eof){
      A = A + B;
      xx = i;
    }
    else{
      len2 += A.length();
      A = B;
      xx = i;
    }
  }

  double res = len2/len;
  printf("%.7f\n", res);
  
  
  return 0;
}
