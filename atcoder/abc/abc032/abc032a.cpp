#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b,n;
  cin >> a >> b >> n;
  while(1){
    if(n%a==0&&n%b==0){
      cout << n << "\n";
      break;
    }
    n++;
  }
  return 0;
}
