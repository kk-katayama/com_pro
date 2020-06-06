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
  int n,m;cin >> n >> m;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  vector<bool> f(n, true);
  rep(i,m) {
    if(h[a[i]] < h[b[i]]) f[a[i]] = false;
    else if(h[a[i]] > h[b[i]]) f[b[i]] = false;
    else {
      f[a[i]] = false;
      f[b[i]] = false;
    }
  }

  int res = 0;
  rep(i,n) {
    if(f[i]) res++;
  }
  cout << res << "\n";
  
  return 0;
}
