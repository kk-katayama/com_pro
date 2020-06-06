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
  int n,k;cin >> n >> k;
  vector<int> cnt(n, 0);
  rep(i,k) {
    int d; cin >> d;
    rep(j,d) {
      int a; cin >> a; a--;
      cnt[a]++;
    }
  }

  int res = 0;
  rep(i,n) if(cnt[i] == 0) res++;
  cout << res << "\n";
  return 0;
}
