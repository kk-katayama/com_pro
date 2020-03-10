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
Point Indiv(Point a,Point b,double x,double y){
  Point res((b.x-a.x)*x/(x+y)+a.x,(b.y-a.y)*x/(x+y)+a.y);
  return res;
}
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

vector<Point> crosspoint(Circle s,Circle t){
  vector<Point> res;
  double d = dist(s.p,t.p);
  double ran = d - s.r - t.r;
  if(fabs(ran)<eps){
    Point ind = Indiv(s.p,t.p,s.r,t.r);
    res.push_back(ind);
    return res;
  }
  else if(ran>eps) return res;
  else if(fabs(d+s.r-t.r)<eps||fabs(d+t.r-s.r)<eps){
    Point exd = Exdiv(s.p,t.p,s.r,t.r);
    res.push_back(exd);
    return res;
  }
  else if(d+s.r<t.r+eps||d+t.r<s.r+eps) return res;
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
  // double x1,y1,r1,x2,y2,r2;
  // cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  // vector<Point> cp = crosspoint(Circle(Point(x1,y1),r1),Circle(Point(x2,y2),r2));
  // rep(i,cp.size()) printf("%.7f\t%.7f\n", cp[i].x, cp[i].y);
  int n,k;cin >> n >> k;
  vector<double> x(n),y(n),c(n);
  rep(i,n) cin >> x[i] >> y[i] >> c[i];
  if(k==1) {
    printf("%.10f\n", 0.);
    return 0;
  }
  double left = 0,right = 1e+6;
  rep(num,100){
    double mid = (left+right)/2.;
    int cnt = 0;
    rep(i,n) rep(j,n){
      if(i==j) continue;
      vector<Point> cp = crosspoint(Circle(Point(x[i],y[i]),mid/c[i]),Circle(Point(x[j],y[j]),mid/c[j]));
      rep(cpi,cp.size()){
  	int tmp = 0;
  	rep(l,n) if(dist(cp[cpi],Point(x[l],y[l]))<=mid/c[l]+eps) tmp++;
  	cnt = max(cnt,tmp);
      }
      {
  	int tmp = 0;	
  	rep(l,n) if(dist(Point(x[i],y[i]),Point(x[l],y[l]))<=mid/c[l]+eps) tmp++;
  	cnt = max(cnt,tmp);
      }
    }
    //    cout << cnt << "\n";
    if(cnt>=k) right = mid;
    else left = mid;
    
  }
  printf("%.10f\n", right);
  
  return 0;
}
