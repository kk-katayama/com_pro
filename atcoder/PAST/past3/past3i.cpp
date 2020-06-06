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
  int n,q; cin >> n >> q;
  vector<int> s(q), a(q), b(q);
  rep(i,q) {
    cin >> s[i];
    if(s[i] != 3) {
      cin >> a[i] >> b[i];
    }
  }

  vector<ll> x(n+1), y(n+1);
  rep(i,n+1) {
    x[i] = i;
    y[i] = i;
  }

  int pari = 1;
  rep(i,q) {
    if(s[i] == 1) {
      if(pari > 0) swap(x[a[i]], x[b[i]]);
      else swap(y[a[i]], y[b[i]]);      
    }
    else if(s[i] == 2) {
      if(pari > 0) swap(y[a[i]], y[b[i]]);
      else swap(x[a[i]], x[b[i]]);      
    }
    else if(s[i] == 3) pari *= -1;
    else {
      if(pari > 0) cout << n*( x[a[i]] - 1) + y[b[i]] - 1 << "\n";
      else  cout << n*( x[b[i]] - 1) + y[a[i]] - 1 << "\n";
    }
  }
  
  return 0;
}
