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
  char c[3];
  rep(i,3) cin >> c[i];
  if(c[1] == 'R') c[1] = 'B';
  else c[1] = 'R';
  rep(i,3) cout << c[i];
  cout << "\n";
  return 0;
}
