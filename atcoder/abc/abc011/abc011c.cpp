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
  vector<int> ng(3);
  rep(i,3){
    cin >> ng[i];
    if(n==ng[i]){
      cout << "NO" << "\n";
      return 0;
    }
  }

  

  bool f = true;
  int cnt = 0;
  while(n>0){
    if(cnt>=100){
      cout << "NO" << "\n";
      return 0;
    }
    cnt++;
    //    cout << n << "\n";
    bool fff = false;
    for(int j=3;j>0;--j){
      bool ff = true;
      rep(i,3){
	if(n-j==ng[i]){
	  ff = false;
	  break;
	}
      }
      if(ff){
	fff = true;
	n -= j;
	break;
      }
    }
    if(!fff){
      f = false;
      break;
    }
    else{
      if(n==0){
	break;
      }
    }
  }
  if(f) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
