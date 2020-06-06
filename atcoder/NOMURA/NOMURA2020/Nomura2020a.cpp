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
  int a,b,c,d,k; cin >> a >>b >> c >> d >> k;
  int x = a*60 + b;
  int y = c*60 + d;
  int z = (1440 + y - x) % 1440;
  cout << z - k << "\n";
  return 0;
}
