#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b;
  cin >> a >> b;
  int c = a%b;
  if(c == 0){
    cout << 0 << "\n";
  }
  else{
    cout << b-c << "\n";
  }
  return 0;
}
