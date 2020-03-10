#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  string s;cin >> s;
  s[k-1] += 32;
  cout << s << "\n";
  return 0;
}
