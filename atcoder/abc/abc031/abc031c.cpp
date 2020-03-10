#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int res = -1e+9;
  rep(i,n){
    int aax = -1e+9;
    int tax = -1e+9;
    rep(j,n){
      if(i==j) continue;
      if(i<j){
	int ta = 0,ao = 0;
	for(int k=0;k<=j-i;++k){
	  if(k%2==0) ta += a[i+k];
	  else ao += a[i+k];
	}
	if(ao>aax){
	  aax = ao;
	  tax = ta;
	}
      }
      else{
	int ta = 0,ao = 0;
	for(int k=0;k<=i-j;++k){
	  if(k%2==0) ta += a[j+k];
	  else ao += a[j+k];
	}
	if(ao>aax){
	  aax = ao;
	  tax = ta;
	}	
      }
    }
    res = max(res,tax);
  }
  cout << res << "\n";
  return 0;
}
