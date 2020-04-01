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
  int s = n % 60;
  n /= 60;
  int m = n % 60;
  n /= 60;

  printf("%02d:%02d:%02d\n", n , m , s);
  return 0;
}
