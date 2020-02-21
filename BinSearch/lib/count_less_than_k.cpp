#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
//k以下である要素の個数を求める
int n;
int a[110000];
int cntltk(int k){
  int lb=-1,ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(a[mid]<=k) lb=mid;
    else ub=mid;
  }
  return lb+1;
}

int main()
{
  int k;
  cin >> n >> k;
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  cout << cntltk(k) << "\n";
  return 0;
}
