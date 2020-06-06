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
  int n;cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  int res = 0;
  int cnt = 1;
  bool f = true;
  rep(i,n-1) {
    if(h[i] < h[i+1]) {
      if(f) {
	cnt++;
      }
      else {
	chmax(res,cnt);
	cnt = 2;
	f = true;
      }
    }
    else {
      if(f) {
	cnt++;
	f = false;
      }
      else {
	cnt++;
      }
    }
    //    cout << "**" << cnt << "\n";
  }
  chmax(res, cnt);
  cout << res << "\n";
  return 0;
}
