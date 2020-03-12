#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];
  vector<vector<bool>> f(5001,vector<bool>(5001,false));
  rep(i,n) f[x[i]][y[i]] = true;
  int res = 0;
  rep(i,n) rep(j,n){
    if(i==j) continue;
    if(x[i]<x[j]) continue;
    if(0<=x[i]+y[i]-y[j]&&x[i]+y[i]-y[j]<=5000&&0<=x[j]+y[i]-y[j]&&x[j]+y[i]-y[j]<=5000&&0<=y[i]+x[j]-x[i]&&y[i]+x[j]-x[i]<=5000&&0<=y[j]+x[j]-x[i]&&y[j]+x[j]-x[i]<=5000){
      if(f[x[i]+y[i]-y[j]][y[i]+x[j]-x[i]]&&f[x[j]+y[i]-y[j]][y[j]+x[j]-x[i]]){
	res = max(res,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      }
    }
    if(0<=x[i]-y[i]+y[j]&&x[i]-y[i]+y[j]<=5000&&0<=x[j]-y[i]+y[j]&&x[j]-y[i]+y[j]<=5000&&0<=y[i]-x[j]+x[i]&&y[i]-x[j]+x[i]<=5000&&0<=y[j]-x[j]+x[i]&&y[j]-x[j]+x[i]<=5000){
      if(f[x[i]-y[i]+y[j]][y[i]-x[j]+x[i]]&&f[x[j]-y[i]+y[j]][y[j]-x[j]+x[i]]){
	res = max(res,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      }
    }
  }
  cout << res << "\n";
  return 0;
}
