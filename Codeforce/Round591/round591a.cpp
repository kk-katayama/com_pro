#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int q;
  cin >> q;
  vector<int> n(q);
  rep(i,q) cin >> n[i];

  rep(i,q){
    if(n[i]%2==0){
      if(n[i]==2){
	cout << 2 << "\n";
      }
      else cout << 0 << "\n";
    }
    else cout << 1 << "\n";
  }
  
  return 0;
}
