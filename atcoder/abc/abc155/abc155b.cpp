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

  bool f = true;
  rep(i,n){
    if(a[i]%2==0){
      if(a[i]%3!=0&&a[i]%5!=0){
	f = false;
	break;
      }
    }
  }
  if(f) cout << "APPROVED" << "\n";
  else cout << "DENIED" << "\n";
  return 0;
}
