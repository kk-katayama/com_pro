#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s;cin >> s;
  double d = stod(s);
  printf("%.7f\n", d);
  d *= 2;
  printf("%.7f\n", d);
  
  return 0;
}
