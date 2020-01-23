#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
  }

  vector<int> cnt(n,0);
  rep(i,n){
    rep(j,n){
      if(i==j) continue;
      if(c[i]%c[j]==0){
	cnt[i]++;
      }
    }
  }

  double res=0;
  rep(i,n){
    int x = cnt[i]/2 + 1;
    int y = cnt[i]+1;
    res += (double)x/y;
  }

  printf("%.7f\n", res);
  
  return 0;
}
