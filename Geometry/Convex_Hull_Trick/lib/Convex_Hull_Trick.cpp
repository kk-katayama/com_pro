#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
// 一次関数。y = ax + b
template <typename X>
struct Line{
  X a; 
  X b;

  Line(X a, X b) : a(a), b(b) {}
  
  X f(X x) { return a*x + b; };
};
// Convex-Hull Trick
template <typename X>
class ConvexHullTrick{
private:
  // 直線集合。
  vector<Line> line;
  
public:
  ConvexHullTrick() = default;

  // line[idx]が不必要かチェック。trueで不必要
  bool Check_Low(int idx, Line newl) {
    if(idx <= 0) return false; // not reject
    return (line[idx].b - line[idx-1].b)*(line[idx].a - newl.a) >= (newl.b - line[idx].b)*(line[idx-1].a - line[idx].a);
  };

  // 直線追加クエリ。*******傾き(a)の降順に追加してください!!!!!!!!!*********
  void Add(X a, X b) {
    while( Check_Low( line.size()-1, Line(a, b) ) ) {
      line.pop_back();
    }
    line.emplace_back(a, b);
  }

  // 最小値取得クエリ。xを入れると、a*x+b が最小となるような直線を見つけてその a*x+bを返す。O(log(N))
  X Get(X x) {
    auto isok = [&](int idx)-> bool{
		  return line[idx].f(x) < line[idx+1].f(x);
		};
    int lb = -1, ub = line.size() - 1;
    while(ub - lb > 1) {
      int mid = (lb + ub) / 2;
      ( isok(mid) ? ub : lb ) = mid;
    }
    return line[ub].f(x);
  }
};

int main()
{
  ConvexHullTrick<double> cht;
  cht.Add(2, 0);
  cht.Add(-1, 1);
  cht.Add(-2, 3);
  cht.Add(-3, -3);
  
  double x; cin >> x;
  cout << cht.Get(x) << "\n";
  
  return 0;
}
