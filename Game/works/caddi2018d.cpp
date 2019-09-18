#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  bool f = false;
  rep(i,n){
    if(a[i]%2==1){
      f = true;
      break;
    }
  }
  cout << (f?"first":"second") << "\n";
  
  return 0;
}
