#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
//k以上である要素の個数を求める
int n;
int a[110000];
int cntmtk(int l,int r,int k){
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(a[mid]>=k) ub=mid;
    else lb=mid;
  }
  return n-ub;
}

int main()
{
  int k;
  cin >> n >> k;
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  cout << cntmtk(0,n-1,k) << "\n";

  return 0;
}
