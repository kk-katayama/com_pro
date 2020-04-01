#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  int m = 2025 - n;
  rep1(i,9) rep1(j,9){
    if( i * j == m ) cout << i << " x " << j << "\n";
  }
  return 0;
}
