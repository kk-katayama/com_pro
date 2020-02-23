#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  int res=0;
  while(n>0){
    n /= k;
    res++;
  }
  cout << res << "\n";
  return 0;
}
