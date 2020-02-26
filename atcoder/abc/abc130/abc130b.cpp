#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,x;cin >> n >> x;
  vector<int> l(n);rep(i,n) cin >> l[i];
  int res=1;
  int d=0;
  rep(i,n){
    d += l[i];
    if(d<=x) res++;
    else break;
  }
  cout << res << "\n";
  return 0;
}
