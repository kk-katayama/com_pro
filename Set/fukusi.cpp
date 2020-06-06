#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <bitset>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n; cin >> n;
  rep(i,(1 << n)) {
    ll a = 0, b = 0;
    rep(j,n) {
      if((i >> j) & 1) a += pow((j+1), 2);
      else b += pow((j+1), 2);
    }
    if(a == b) {
      cout << i << "\n";
      cout << bitset<20>(i) << "\n";
      break;
    }
  }
  

  return 0;
}
