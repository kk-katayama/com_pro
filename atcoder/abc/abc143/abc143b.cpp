#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];
  int sum = 0;
  rep(i,n) rep(j,n){
    if(i >= j)continue;
    sum += d[i] * d[j];
  }
  cout << sum << "\n";
  return 0;
}
