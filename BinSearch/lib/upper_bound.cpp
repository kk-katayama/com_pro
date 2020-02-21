#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
//k以上である要素のうち最小のもののインデックスを求める
int n;
int a[110000];
int upper_bound(int k){
  int left=-1,right=n;
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[mid]>=k) right=mid;
    else left=mid;
  }
  return right;
}

int main()
{
  int k;
  cin >> n >> k;
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  cout << upper_bound(k) << "\n";

  
  return 0;
}
