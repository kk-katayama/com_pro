#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;
  cin >> t;
  vector<int> x(t),y(t);
  rep(i,t) cin >> x[i] >> y[i];

  rep(i,t){
    if(x[i]>=4) cout << "YES" << "\n";
    else if(x[i]>=2){
      if(y[i]<=3) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
    else{
      if(y[i]==1) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
    
  }
  
  return 0;
}
