#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a=0,b=0;
  rep(i,4){
    int x;
    cin >> x;
    a+=x;
  }
  rep(i,4){
    int x;
    cin >> x;
    b+=x;
  }

  cout << (int)max(a,b) << "\n";
  
  return 0;
}
