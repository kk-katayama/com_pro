#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
//k以下である要素のうち最大のもののインデックスを求める
int n;
int a[110000];
int lower_bound(int k){
  int left=-1,right=n;
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[mid]<=k) left=mid;
    else right=mid;
  }
  return left;
}
//kより小さい要素のうち最大のもののインデックスを求める
int lower_bound(int k){
  int left=-1,right=n;
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[mid]<k) left=mid;
    else right=mid;
  }
  return left;
}

//k以下である要素のうち最大のものを求める
int n;
int a[110000];
int lower_bound(int k){
  int left=-1,right=n;
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[mid]<=k) left=mid;
    else right=mid;
  }
  return a[left];
}
//kより小さい要素のうち最大のものを求める
int lower_bound(int k){
  int left=-1,right=n;
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[mid]<k) left=mid;
    else right=mid;
  }
  return a[left];
}

int main()
{
  int k;
  cin >> n >> k;
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  cout << lower_bound(k) << "\n";

  
  return 0;
}
