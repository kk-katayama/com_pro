#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string a,b;cin >> a >> b;
  a += b;
  int res = stoi(a) * 2;
  cout << res << "\n";
  return 0;
}
