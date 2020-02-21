#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int a[110000];
// 配列aに含まれる要素kの数を二分探索で求める
int cntk(int k){
  int left=-1,right=n;
  while(right-left>1){
    int mid = (right+left)/2;
    if(a[mid]>=k) right = mid;
    else left = mid;
  }
  int left2=-1,right2=n;
  while(right2-left2>1){
    int mid = (right2+left2)/2;
    if(a[mid]>k) right2 = mid;
    else left2 = mid;
  }
  return right2-right;
}
int main()
{
  cin >> n;
  rep(i,n) cin >> a[i];

  int m;
  cin >> m;
  int res = 0;
  rep(i,m){
    int q;
    cin >> q;
    if(cntk(q)>0) res++;
  }
  cout << res << "\n";
  
  return 0;
}
