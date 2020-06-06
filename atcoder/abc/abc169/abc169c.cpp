#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll a; cin >> a;
  string b; cin >> b;

  ll c = (b[0] - '0')*100 + (b[2] - '0')*10 + (b[3] - '0');
  cout << a*c/100 << "\n";
  
  return 0;
}
