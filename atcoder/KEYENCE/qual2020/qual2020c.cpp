#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int inf = 1e+9;
int main()
{
  int n,k,s;
  cin >> n >> k >> s;
  if(s==inf){
    rep(i,k){
      cout << s << " ";
    }
    rep(i,n-k){
      cout << 1 << " ";
    }
    cout  << "\n";
  }
  else{
    rep(i,k){
      cout << s << " ";
    }
    rep(i,n-k){
      cout << inf << " ";
    }
    cout  << "\n";
  }
  return 0;
}
