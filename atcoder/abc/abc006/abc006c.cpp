#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  if(m<2*n||4*n<m){
    cout << -1 << " " << -1 << " " << -1 << "\n";
  }
  else{
    int d = m - 3*n;
    if(d>=0){
      cout << 0 << " " << n-d << " " << d << "\n";
    }
    else{
      cout << -d << " " << n+d << " " << 0 << "\n";
    }
  }
  return 0;
}
