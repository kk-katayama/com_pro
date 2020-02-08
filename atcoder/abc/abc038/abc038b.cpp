#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a==c||a==d||b==c||b==d){
    cout << "YES" << "\n";
  }
  else{
    cout << "NO" << "\n";
  }
  return 0;
}
