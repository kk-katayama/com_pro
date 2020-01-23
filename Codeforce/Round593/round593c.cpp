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

  vector<vector<int>> res(n);

  int cnt = 1;
  rep(i,n){
    if(i%2==0){
      for(int j=0;j<n;++j){
	res[j].push_back(cnt++);
      }
    }
    else{
      for(int j=n-1;j>=0;--j){
	res[j].push_back(cnt++);
      }
    }
  }

  rep(i,n){
    rep(j,n){
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  
  return 0;
}
