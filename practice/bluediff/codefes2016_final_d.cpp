#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  
  sort(x.begin(), x.end());
  map<int,int> mp1, mp2;
  rep(i,n) mp1[x[i] % m]++;
  rep(i,n-1) {
    if(x[i] == x[i+1]) {
      mp2[x[i] %m] += 2;
      i++;
    }
  }

  // rep(i,m) cout << i << ":" << mp1[i] << "\n";
  // rep(i,m) cout << i << ":" << mp2[i] << "\n";  
  
  if(m % 2 == 0) {
    int res = 0;
    res += mp1[0] / 2;
    res += mp1[m/2] / 2;
    rep1(i,m/2 - 1) {
      if(mp1[i] <= mp1[m - i]) {
	res += mp1[i];
	int tmp = min(mp2[m-i], mp1[m-i] - mp1[i]);
	res += tmp / 2;
      }
      else {
	res += mp1[m-i];
	int tmp = min(mp2[i], mp1[i] - mp1[m - i]);
	res += tmp / 2;
      }
    }
    cout << res << "\n";
  }
  else {
    int res = 0;
    res += mp1[0] / 2;
    rep1(i,m/2) {
      if(mp1[i] <= mp1[m - i]) {
	res += mp1[i];
	int tmp = min(mp2[m-i], mp1[m-i] - mp1[i]);
	res += tmp / 2;
      }
      else {
	res += mp1[m-i];
	int tmp = min(mp2[i], mp1[i] - mp1[m - i]);
	res += tmp / 2;
      }
    }
    cout << res << "\n";
  }
  
  return 0;
}
