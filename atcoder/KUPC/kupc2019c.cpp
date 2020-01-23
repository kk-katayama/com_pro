#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll m,k;
  cin >> m >> k;
  ll z = (m+k-1)/k;
  ll x = 1;
  ll sum = 0;
  int cnt = 0;
  while(sum<z){
    sum += x;
    x *= (k*2+1);
    cnt++;
  }

  cout << cnt << "\n";
  return 0;
}
