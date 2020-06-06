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
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());  
  
  if(n % 2 == 0) {
    cout << b[n/2-1] + b[n/2] - a[n/2-1] - a[n/2] + 1 << "\n";
  }
  else {
    cout << b[n/2] - a[n/2] + 1 << "\n";
  }
  
  return 0;
}
