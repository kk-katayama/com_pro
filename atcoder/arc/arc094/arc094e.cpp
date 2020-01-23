#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];
  
  int cnt = 0;
  ll in = 1e+12;
  ll sum = 0;
  rep(i,n){
    sum += a[i];
    if(a[i]>b[i]){
      in = min(in,b[i]);
    }
    else if(a[i]<b[i]){
      continue;
    }
    else cnt++;
  }
  if(cnt==n){
    cout << 0 << "\n";
    return 0;
  }
  cout << sum - in << "\n";
  return 0;
}
