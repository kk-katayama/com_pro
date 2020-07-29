#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int a,b,c,d; cin >> a >> b >> c >> d;
  int x = c - a;
  int y = d - b;
  rep(i,x) cout << 'R';
  rep(i,y) cout << 'U';
  rep(i,x) cout << 'L';
  rep(i,y) cout << 'D';
  cout << 'D';
  rep(i,x+1) cout << 'R';
  rep(i,y+1) cout << 'U';
  cout << 'L';
  cout << 'U';    
  rep(i,x+1) cout << 'L';
  rep(i,y+1) cout << 'D';
  cout << "R\n";
  return 0;
}
