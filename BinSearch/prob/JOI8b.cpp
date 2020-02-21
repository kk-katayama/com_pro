#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
//k以上である要素のうち最小のインデックスを返す
int n;
int a[110000];
int bins(int k){
  int lb=-1,ub=n+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(a[mid]>=k) ub=mid;
    else lb=mid;
  }
  return ub;
}

int main()
{
  int d;cin >> d;
  cin >> n;
  int m;cin >> m;
  a[0] = 0;
  rep1(i,n-1) cin >> a[i];
  a[n] = d;
  vector<int> k(m);
  rep(i,m) cin >> k[i];
  sort(a,a+n);

  int sum = 0;
  rep(i,m){
    int kk = bins(k[i]);
    if(a[kk]-k[i]==0) continue;
    else{
      int x = min(a[kk]-k[i],k[i]-a[kk-1]);
      sum += x;
    }
  }

  cout << sum << "\n";
  
  return 0;
}
