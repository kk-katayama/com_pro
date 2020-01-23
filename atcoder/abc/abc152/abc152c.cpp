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
  vector<int> p(n);
  rep(i,n){
    cin >> p[i];
  }

  int pv = 1e+9;
  int cnt = 0;
  rep(i,n){
    if(pv>=p[i]){
      cnt++;
      pv = p[i];
    }
  }

  cout << cnt << "\n";
  return 0;
}
