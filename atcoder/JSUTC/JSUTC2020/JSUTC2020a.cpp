#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int s,l,r;cin >> s >> l >> r;
  if(s < l) cout << l << "\n";
  else if(s > r) cout << r << "\n";
  else cout << s << "\n";
  return 0;
}
