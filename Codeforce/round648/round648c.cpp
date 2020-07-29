#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  vector<int> ap(n+1), bp(n+1);
  rep(i,n) {
    ap[a[i]] = i;
    bp[b[i]] = i;
  }

  vector<int> cnt(n, 0);
  rep1(i,n) {
    int tmp = (ap[i] - bp[i] + n) % n;
    cnt[tmp]++;
  }

  int res = 0;
  rep(i,n) {
    chmax(res, cnt[i]);
  }
  cout << res << "\n";
  
  return 0;
}
