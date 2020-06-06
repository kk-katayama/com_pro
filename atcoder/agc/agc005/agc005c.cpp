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
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> cnt(n, 0);
  int maxi = 0;
  rep(i,n) {
    chmax(maxi, a[i]);
    cnt[a[i]]++;
  }
  
  if(maxi % 2 == 0) {
    bool f = true;
    rep(i,maxi/2) {
      if(cnt[maxi-i] < 2) {
	f = false;
      }
    }
    if(cnt[maxi/2] != 1) f = false;
    rep(i,maxi/2) {
      if(cnt[i] > 0) f = false;
    }
    cout << (f ? "Possible" : "Impossible") << "\n";
  }
  else {
    bool f = true;
    rep(i,maxi/2) {
      if(cnt[maxi-i] < 2) {
	f = false;
      }
    }
    if(cnt[(maxi+1)/2] != 2) f = false;
    rep(i,maxi/2) {
      if(cnt[i] > 0) f = false;
    }
    cout << (f ? "Possible" : "Impossible") << "\n";    
  }
  
  return 0;
}
