#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
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
const double PI = atan(1)*4;
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

// 線分AB上に点Cがあるかどうかの判定
bool IsOnLine(const Vec2 A, const Vec2 B, const Vec2 C) {  return abs(Sin(A - C, B - C)) < EPS && Cos(A - C, B - C) < 0; }

// 線分の交差判定
bool CrossCheck(const Vec2 a, const Vec2 b, const Vec2 c, const Vec2 d) {
  if(a == c || a == d || b == c || b == d) return true; // 端点が等しい場合はtrue
  Vec2 AB = b - a, AC = c - a, AD = d - a;
  Vec2 CA = a - c, CB = b - c, CD = d - c;
  double s = AB.cross(AC) * AB.cross(AD);
  double t = CD.cross(CA) * CD.cross(CB);

  if(abs(Sin(AB, CD)) < EPS) { // 平行のとき
    if(abs(Sin(AB, AC)) < EPS) { // 同一直線上にあるか？
      return (CA.dot(CB) - EPS < 0 || (a - d).dot(b - d) - EPS < 0 || AC.dot(AD) - EPS < 0);
    }
    else return false;
  }
  else return s < EPS && t < EPS;
}

// 頂点集合を引数にして、凸包を形成する頂点を返す
vector<Vec2> ConvexHull(vector<Vec2> &v) {
  int n = v.size();
  //******** 最も左下の点をスタートにする  ********
  double ymin = 1e+15, xmin = 1e+15;
  int idx;
  rep(i,n) {
    if(abs(v[i].y - ymin) < EPS) {
      if(v[i].x < xmin) {
	xmin = v[i].x;
	idx = i;
      }
    }
    else if(v[i].y < ymin) {
      xmin = v[i].x;
      ymin = v[i].y;
      idx = i;
    }
  }
  Vec2 O = v[idx]; 
  //**********************************
  //************ 偏角ソート **********
  // 偏角が同じものはスタートからの距離が遠いほど先に配置
  sort(v.begin(), v.end(), [&](Vec2 a, Vec2 b) {
			     double adx = a.x - O.x, ady = a.y - O.y;
			     double bdx = b.x - O.x, bdy = b.y - O.y;
			     if(abs(adx) < EPS && abs(ady) < EPS) return true;
			     else if(abs(bdx) < EPS && abs(bdy) < EPS) return false;
                             else if(abs(atan2(ady, adx) - atan2(bdy, bdx)) < EPS ) {
                               return (a - O).length() > (b - O).length();
			     }
			     else {
			       return atan2(ady, adx) < atan2(bdy, bdx);
			     }
			   });
  //**********************************
  //******************* GrahamScan ******************
  vector<Vec2> res;
  int next = 2;
  res.push_back(v[0]);
  res.push_back(v[1]);
  //***************前処理************
  // 偏角が同じものについて、スタート直後のみはスタートからの距離が短い順に並べる。
  while(abs(Sin(v[1] - v[0], v[next] - v[0])) < EPS) {
    res.push_back(v[next]);
    next++;
  }
  sort(res.begin(), res.end(), [&](Vec2 a, Vec2 b) {
				 return (a - O).length() < (b - O).length();
			       });
  //*********************************
  while(next < n) {
    int size = res.size();
    if(abs(Sin(res[size - 1] - res[size - 2], v[next] - res[size - 1])) < EPS
       || Sin(res[size - 1] - res[size - 2], v[next] - res[size - 1]) > 0) {
      res.push_back(v[next]);
      next++;
    }
    else {
      res.pop_back();
    }
  }
  return res;
  //******************************************
}

int main()
{
  int n; cin >> n;
  vector<Vec2> v(n);
  rep(i,n) cin >> v[i].x >> v[i].y;
  vector<Vec2> res = ConvexHull(v);
  cout << (int)res.size() << "\n";
  for(auto val: res) {
    cout << val.x << " " << val.y << "\n";
  }
  return 0;
}
