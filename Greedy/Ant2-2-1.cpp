#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<int> c(6);
  rep(i,6) cin >> c[i];
  int a;
  cin >> a;
  vector<int> val={1,5,10,50,100,500};

  
  int res=0;
  for(int i=5;i>=0;--i){
    res+=min(c[i],a/val[i]);
    a-=min(c[i],a/val[i])*val[i];
  }
  
  cout << res << "\n";
  
  return 0;
}
