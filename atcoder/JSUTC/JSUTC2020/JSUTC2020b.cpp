#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> x(n);
  vector<char> c(n);
  rep(i,n) cin >> x[i] >> c[i];

  vector<int> red, blue;
  rep(i,n) {
    if(c[i] == 'R') red.push_back(x[i]);
    else blue.push_back(x[i]);
  }

  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());
  for(auto i : red) cout << i << "\n";
  for(auto i : blue) cout << i << "\n";  

  return 0;
}
