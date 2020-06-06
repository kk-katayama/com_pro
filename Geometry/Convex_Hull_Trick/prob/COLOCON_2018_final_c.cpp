#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
template <typename X>
struct Line{
  X a;
  X b;

  Line(X a, X b) : a(a), b(b) {}
  
  X f(X x) { return a*x + b; };
};

template <typename X>
class ConvexHullTrick{
private:
  vector<Line<X>> line;
  
public:
  ConvexHullTrick() = default;

  bool Check_Low(int idx, Line<X> newl) {
    if(idx <= 0) return false; // not reject
    return (line[idx].b - line[idx-1].b)*(line[idx].a - newl.a) >= (newl.b - line[idx].b)*(line[idx-1].a - line[idx].a);
  };

  void Add(X x, X y) {
    while( Check_Low( line.size()-1, Line<X>(x, y) ) ) {
      line.pop_back();
    }
    line.emplace_back(x, y);
  }
  
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
  int n;cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ConvexHullTrick<ll> cht;
  rep(j,n) {
    cht.Add(-2*j, a[j] + j*j);
  }
  
  rep(i,n) {
    ll res = i*i + cht.Get(i);
    cout << res << "\n";
  }
  
  return 0;
}
