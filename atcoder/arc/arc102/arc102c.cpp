#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,k;
  cin >> n >> k;
  ll res = pow((n/k),3);
  if(k%2==0){
    if(n>=k/2){
      res += pow((n-k/2)/k+1,3);
    }
  }
  cout << res << "\n";
  return 0;
}
