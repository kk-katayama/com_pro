#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<int> s(3),e(3);
  rep(i,3) cin >> s[i] >> e[i];
  int res = 0;
  rep(i,3){
    res += s[i] * e[i] / 10;
  }
  cout << res << "\n";
  return 0;
}
