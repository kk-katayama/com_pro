#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  string s,t;
  cin >> s >> t;
  int a,b;
  cin >> a >> b;
  string u;
  cin >> u;
  if(s==u) a--;
  else if(t==u) b--;
  cout << a << " " << b << "\n";
  return 0;
}
