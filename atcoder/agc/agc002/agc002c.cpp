#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;ll l;
  cin >> n >> l;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n){
    sum[i+1] = sum[i] + a[i];
  }
  
  rep(i,n-1){
    if(sum[i+2]-sum[i]>=l){
      cout << "Possible" << "\n";
      for(int j=1;j<=i;++j){
	cout << j << "\n";
      }
      for(int j=n-1;j>=i+2;--j){
	cout << j << "\n";
      }
      cout << i+1 << "\n";
      return 0;
    }
  }
  cout << "Impossible" << "\n";
  
  return 0;
}
