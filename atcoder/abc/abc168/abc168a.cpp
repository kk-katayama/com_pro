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
  int n;cin >> n;
  int x = n % 10;
  if(x == 0 || x == 1 || x == 6 || x == 8) cout << "pon" << "\n";
  else if(x == 3) cout << "bon" << "\n";
  else cout << "hon" << "\n";
  return 0;
}
