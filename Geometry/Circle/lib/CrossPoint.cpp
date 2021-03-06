#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const double eps = 1e-9;
struct Point{
  double x,y;
  Point(double _x,double _y):x(_x),y(_y){}
};
double dist(Point a,Point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
// 内分
Point Indiv(Point a,Point b,double x,double y){
  Point res((b.x-a.x)*x/(x+y)+a.x,(b.y-a.y)*x/(x+y)+a.y);
  return res;
}
// 外分
Point Exdiv(Point a,Point b,double x,double y){
  Point res((b.x-a.x)*x/dist(a,b),(b.y-a.y)*x/dist(a,b));
  return res;
}
struct Circle{
  Point p;
  double r;
  Circle(Point _p,double _r):p(_p),r(_r){}
  double X(){ return p.x;}
  double Y(){ return p.y;}  
};
// 円s,tの交点を返す。2点or 1点 or 0点
vector<Point> crosspoint(Circle s,Circle t){
  vector<Point> res;
  double d = dist(s.p,t.p);
  double ran = d - s.r - t.r;
  // 円同士が接する場合。中心同士の距離=sの半径+tの半径。この場合は中心同士の距離をsの半径:tの半径に内分した点が接する点になる。
  if(fabs(ran)<eps){
    Point ind = Indiv(s.p,t.p,s.r,t.r);
    res.push_back(ind);
    return res;
  }
  // 円同士が交わらない場合。中心同士の距離>sの半径+tの半径。
  else if(ran>eps) return res;
  // 片方の円がもう片方の円の内部にある場合。円同士が接する場合。この場合は中心同士の距離を片方の半径:もう片方の半径に外分した点が接する点になる。
  else if(fabs(d+s.r-t.r)<eps||fabs(d+t.r-s.r)<eps){
    Point exd = Exdiv(s.p,t.p,s.r,t.r);
    res.push_back(exd);
    return res;
  }
  // 片方の円がもう片方の円の内部にある場合。円同士が交わらない場合。
  else if(d+s.r<t.r+eps||d+t.r<s.r+eps) return res;

  // 交点2つの場合
  double a = 2.*(t.X()-s.X());
  double b = 2.*(t.Y()-s.Y());
  double c = s.r*s.r-t.r*t.r-s.X()*s.X()+t.X()*t.X()-s.Y()*s.Y()+t.Y()*t.Y();
  if(fabs(a)<eps){
    double x = s.X() + sqrt(b*b*s.r*s.r-(c-b*s.Y())*(c-b*s.Y()))/b;
    double y = c/b;
    res.push_back(Point(x,y));
    x = s.X() - sqrt(b*b*s.r*s.r-(c-b*s.Y())*(c-b*s.Y()))/b;
    res.push_back(Point(x,y));    
  }
  else if(fabs(b)<eps){
    double x = c/a;
    double y = s.Y() + sqrt(s.r*s.r-(c/a-s.X())*(c/a-s.X())); 
    res.push_back(Point(x,y));
    y = s.Y() - sqrt(s.r*s.r-(c/a-s.X())*(c/a-s.X())); 
    res.push_back(Point(x,y));    
  }
  else{
    double A = a*a + b*b;
    double B = a*b*s.Y() - a*c - b*b*s.X();
    double C = (s.X()*s.X()+s.Y()*s.Y()-s.r*s.r)*b*b + c*c - 2*s.Y()*b*c;

    double x = (-B+sqrt(B*B-A*C))/A;
    double y = (c-a*x)/b;
    res.push_back(Point(x,y));
  
    x = (-B-sqrt(B*B-A*C))/A;
    y = (c-a*x)/b;
    res.push_back(Point(x,y));
  }
  return res;
}

int main()
{
  double x1,y1,r1,x2,y2,r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  vector<Point> cp = crosspoint(Circle(Point(x1,y1),r1),Circle(Point(x2,y2),r2));
  rep(i,cp.size()) printf("%.7f\t%.7f\n", cp[i].x, cp[i].y);
  
  return 0;
}
