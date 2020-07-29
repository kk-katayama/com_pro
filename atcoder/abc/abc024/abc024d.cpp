#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll mod = 1e+9+7;
  ll a,b,c; cin >> a >> b >> c;
  ll n = b*c / (a*c + a*b - b*c) - 1;
  ll m = a*(n + 1) / b - 1;
  cout << n - m << " " << m << "\n";
  return 0;
}
