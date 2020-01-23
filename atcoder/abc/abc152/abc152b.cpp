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
  if(a>b){
    rep(i,a){
      cout << b;
    }
    cout  << "\n";
  }
  else{
    rep(i,b){
      cout << a;
    }
    cout  << "\n";
  }
  return 0;
}
