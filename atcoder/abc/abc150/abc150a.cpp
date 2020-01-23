#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int k;
  cin >> k;
  int x;
  cin >> x;
  if(500*k>=x) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  
  return 0;
}
