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
  int n, m;cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];

  vector<int> c(n, 0);
  rep(i,m) {
    int lb = -1, ub = n;
    while(ub - lb > 1) {
      int mid = (ub + lb)/2;
      (a[i] > c[mid] ? lb : ub) = mid;
    }
    if(lb == -1) {
      cout << -1 << "\n";
    }
    else {
      cout << n - lb << "\n";
      c[lb] = a[i];
    }
  }
  
  return 0;
}
