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
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());

  vector<bool> f(1000001, true);
  int res = 0;
  rep(i,n) {
    if(i != n-1) {
      if(a[i] != a[i+1] && f[a[i]]) res++;
    }
    else if(f[a[i]]) res++;

    if(f[a[i]]) {
      int x = a[i];
      while(1) {
	f[x] = false;
	if(x + a[i] > 1000000) break;
	x += a[i];
      }
    }    
  }

    
  cout << res << "\n";
  return 0;
}
