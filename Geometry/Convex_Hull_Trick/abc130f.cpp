#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
struct Line{
  double a;
  double b;

  Line(double a, double b) : a(a), b(b) {}
  
  double f(double x) { return a*x + b; };

};

class ConvexHullTrick{
private:
  vector<Line> line;
  bool ismax; // true = 最大値をとるクエリ
  
public:
  ConvexHullTrick() = default;

  ConvexHullTrick(bool ismax) : ismax(ismax) {} 

  bool Check_Low(int idx, Line newl) {
    if(idx <= 0) return false; // not reject
    bool f = (line[idx].b - line[idx-1].b)*(line[idx].a - newl.a) <= (newl.b - line[idx].b)*(line[idx-1].a - line[idx].a);
    return ismax ? f : !f;
  };

  // 追加クエリ、追加は傾き(x)の降順にお願いします
  void Add(Line newl) {
    while( Check_Low( line.size()-1, newl ) ) {
      line.pop_back();
    }
    line.push_back(newl);
  }
  
  double Get(double x) {
    auto isok = [&](int idx)-> bool{
		  bool f = line[idx].f(x) > line[idx+1].f(x);
		  return ismax ? f : !f;
		};
    int lb = -1, ub = line.size() - 1;
    while(ub - lb > 1) {
      int mid = (lb + ub) / 2;
      ( isok(mid) ? ub : lb ) = mid;
    }
    return line[ub].f(x);
  }

  vector<double> CrossPoint() {
    vector<double> res;
    rep(i,line.size()-1) {
      double x = (line[i+1].b - line[i].b) / (line[i].a - line[i+1].a);
      res.push_back(x);
    }
    return res;
  }

  void Show() {
    rep(i,line.size()) {
      cout << line[i].a << ":" << line[i].b << "\n";
    }
  }
  
};

int main()
{
  int n;cin >> n;
  vector<double> x(n), y(n);
  vector<char> d(n);
  rep(i,n) cin >> x[i] >> y[i] >> d[i];

  double rmax = -1e+10, lmax = -1e+10, rlmax = -1e+10;
  double rmin = 1e+10, lmin = 1e+10, rlmin = 1e+10;  
  double umax = -1e+10, dmax = -1e+10, udmax = -1e+10;
  double umin = 1e+10, dmin = 1e+10, udmin = 1e+10;
  
  rep(i,n) {
    if(d[i] == 'R') {
      chmax(rmax, x[i]);
      chmin(rmin, x[i]);      
      chmax(udmax, y[i]);
      chmin(udmin, y[i]);      
    }
    else if(d[i] == 'L') {
      chmax(lmax, x[i]);
      chmin(lmin, x[i]);
      chmax(udmax, y[i]);
      chmin(udmin, y[i]);            
    }
    else if(d[i] == 'U') {
      chmax(rlmax, x[i]);
      chmin(rlmin, x[i]);            
      chmax(umax, y[i]);
      chmin(umin, y[i]);            
    }
    else if(d[i] == 'D') {
      chmax(rlmax, x[i]);
      chmin(rlmin, x[i]);                  
      chmax(dmax, y[i]);
      chmin(dmin, y[i]);            
    }    
   
  }

  ConvexHullTrick chtR(true);
  ConvexHullTrick chtL(false);
  ConvexHullTrick chtU(true);
  ConvexHullTrick chtD(false);

  chtR.Add(Line(1, rmax));
  chtR.Add(Line(0, rlmax));
  chtR.Add(Line(-1, lmax));
  chtL.Add(Line(1, rmin));
  chtL.Add(Line(0, rlmin));
  chtL.Add(Line(-1, lmin));
  chtU.Add(Line(1, umax));
  chtU.Add(Line(0, udmax));
  chtU.Add(Line(-1, dmax));
  chtD.Add(Line(1, umin));
  chtD.Add(Line(0, udmin));
  chtD.Add(Line(-1, dmin));      

  // chtR.Show();
  // cout << "**" << "\n";
  // chtL.Show();
  // cout << "**" << "\n";  
  // chtU.Show();
  // cout << "**" << "\n";  
  // chtD.Show();
  // cout << "**" << "\n";  
  
  double res = 1e+15;
  vector<double> R = chtR.CrossPoint();
  rep(i,R.size()) {
    double ans = (chtR.Get(R[i]) - chtL.Get(R[i])) * (chtU.Get(R[i]) - chtD.Get(R[i]));
    chmin(res, ans);
  }

  vector<double> L = chtL.CrossPoint();
  rep(i,L.size()) {
    double ans = (chtR.Get(L[i]) - chtL.Get(L[i])) * (chtU.Get(L[i]) - chtD.Get(L[i]));
    chmin(res, ans);
  }  
  
  vector<double> U = chtU.CrossPoint();
  rep(i,U.size()) {
    double ans = (chtR.Get(U[i]) - chtL.Get(U[i])) * (chtU.Get(U[i]) - chtD.Get(U[i]));
    chmin(res, ans);
  }

  vector<double> D = chtD.CrossPoint();
  rep(i,D.size()) {
    double ans = (chtR.Get(D[i]) - chtL.Get(D[i])) * (chtU.Get(D[i]) - chtD.Get(D[i]));
    chmin(res, ans);
  }

  printf("%.9lf\n", res);
  
  return 0;
}
