#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int res = -60;
  rep(i,n){
    int tax=-60;
    rep(j,n){
      if(i==j) continue;
      if(i<j){
	int index = 0;
	int T=0,A=0,aax=-60,tmp=0;
	for(int k=i;k<=j;++k){
	  if(index%2==0) T += a[k];
	  else A += a[k];
	  if(aax<A){
	    tmp = T;
	  }
	  index++;
	}
	tax = max(tax,tmp);      
      }
      else{
	int index = 0;
	int T=0,A=0,aax=-60,tmp=0;
	for(int k=j;k<=i;++k){
	  if(index%2==0) T += a[k];
	  else A += a[k];
	  if(aax<A){
	    tmp = T;
	  }
	  index++;
	}
	tax = max(tax,tmp);
      }
    }
    res = max(res,tax);
  }
  cout << res << "\n";
  
  return 0;
}
