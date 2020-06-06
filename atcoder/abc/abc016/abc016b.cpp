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
  int a,b,c; cin >> a >> b >> c;
  
  auto plus = [&]()-> bool { return a + b == c; };
  auto minus = [&]()-> bool { return a - b == c; };  
  if(plus() && minus() ) cout << '?' << "\n";
  else if(plus() && ! minus() ) cout << '+' << "\n";
  else if(!plus() && minus() ) cout << '-' << "\n";
  else cout << '!' << "\n";
  return 0;
}
