#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  if(n%2==0) cout << 0.5 << "\n";
  else{
    int m = (n+1)/2;
    double res = (double)m/n;
    printf("%.6f\n", res);
  }
  return 0;
}
