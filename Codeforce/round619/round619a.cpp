#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<string> a(n),b(n),c(n);
  rep(i,n){
    cin >> a[i] >> b[i] >> c[i];
  }

  rep(i,n){
    bool f = true;
    rep(j,a[i].size()){
      if(a[i][j]!=c[i][j]&&b[i][j]!=c[i][j]){
	f = false;
	break;
      }
    }
    if(f) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }

  
  return 0;
}
