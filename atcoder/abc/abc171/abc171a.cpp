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
  char c; cin >> c;
  int x = 'A', y = 'Z';
  int z = c;
  if(x <= z && z <= y) cout << 'A' << "\n";
  else cout << 'a' << "\n";
  return 0;
}
