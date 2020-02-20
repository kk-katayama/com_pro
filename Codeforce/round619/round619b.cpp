#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int q;
  cin >> q;
  vector<int> n(q);
  vector<vector<int>> a(q);
  rep(i,q){
    cin >> n[i];
    a[i].resize(n[i]);
    rep(j,n[i]){
      cin >> a[i][j];
    }
  }

  rep(i,q){
    int aax = -1,ain = 1e+9+10;
    int res=0;
    rep(j,n[i]){
      if(a[i][j]==-1){
	if(j-1>=0){
	  if(a[i][j-1]!=-1){
	    aax = max(aax,a[i][j-1]);
	    ain = min(ain,a[i][j-1]);
	  }
	}
	if(j+1<n[i]){
	  if(a[i][j+1]!=-1){	  
	    aax = max(aax,a[i][j+1]);
	    ain = min(ain,a[i][j+1]);
	  }
	}
      }
      else if(j+1<n[i]){
	if(a[i][j+1]!=-1){
	  res = max(abs(a[i][j]-a[i][j+1]),res);
	}
      }
    }
    if(aax==-1){
      cout << 0 << " ";
      cout << 0 << "\n";      
    }
    else{
      int tmp = (aax-ain+1)/2;
      res = max(res,tmp);
      cout << res << " ";
      cout << aax-tmp << "\n";
    }
  }
  
  return 0;
}
