#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,l;cin >> n >> l;
  vector<int> a(n);
  rep(i,n) a[i] = i+l;
  vector<int> sum(n+1);sum[0]=0;
  rep(i,n) sum[i+1] = sum[i]+a[i];

  int in=1e+9;
  int res;
  rep(i,n){
    int tmp = abs(sum[i+1]-sum[i]);
    if(in>tmp){
      res=sum[n]-sum[i+1]+sum[i];
      in = tmp;
    }
  }
  cout << res << "\n";
  return 0;
}
