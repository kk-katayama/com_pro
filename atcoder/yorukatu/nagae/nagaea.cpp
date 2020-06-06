#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;

  int dx = x2 - x1, dy = y2 - y1;
  int x3 = x2 - dy, y3 = y2 + dx;
  int x4 = x1 - dy, y4 = y1 + dx;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
  
  return 0;
}
