#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int a,b;
int main()
{
  cin >> a >> b;
  int c = 1;
  int res = 0;
  while(c<b){
    c += a-1;
    res++;
  }
  cout << res << "\n";
  return 0;
}
