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
  
  int res = n;
  rep(i,n) {
    rep1(j,3) {
      int pivot = j;
      int up = i - 1;
      int down = i + 1;
      int cnt = 1;
      int sum = 0;
      while(1) {
	if(up >= 0) {
	  while(a[up] == pivot) {
	    up--;
	    cnt++;
	    if(up < 0) break;
	  }
	}
	if(down < n) {
	  while(a[down] == pivot) {
	    down++;
	    cnt++;
	    if(down >= n) break;
	  }	
	}
	if(cnt < 4) break;
	sum += cnt;
	cnt = 0;
	if(up < 0 || down >= n) break;
	if(a[up] != a[down]) break;
	pivot = a[up];
      }
      chmin(res, n - sum);
    }
  }
  cout << res << "\n";
  
  return 0;
}
