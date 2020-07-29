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
  ll n; cin >> n;
  ll x = n % 24;
  if(0 <= x && x <= 7) {
    if(x % 2 == 0) cout << "Lose" << "\n";
    else cout << "Win" << "\n";
  }
  else if(8 <= x && x <= 15) {
    if(x % 2 == 0) cout << "Win" << "\n";
    else cout << "Lose" << "\n";
  }
  else {
    cout << "Win" << "\n";
  }  
  return 0;
}
