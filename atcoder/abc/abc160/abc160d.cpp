#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  int x,y;cin >> x >> y;
  x--;y--;
  vector<int> res(n-1,0);
  rep(i,n) rep(j,n){
    if(i >= j) continue;
    if(i < x){
      if(j <= x) res[j - i - 1]++;
      else if(j < y){
	int in = min(y - j + x - i, j - i - 1);
	res[in]++;
      }
      else {
	res[j - y + x - i]++;
      }
    }
    else if(i < y){
      if(j < y){
	int in = min(y - j + i - x, j - i - 1);
	res[in]++;
      }
      else  {
	int in = min(j - y + i - x, j - i - 1);
	res[in]++;	
      }
    }
    else{
      res[j - i - 1]++;
    }
  }

  rep(i,n-1){
    cout << res[i] << "\n";
  }
  return 0;
}
