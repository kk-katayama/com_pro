#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int a[21],b[21],c[21];
int main()
{
  cin >> n;
  rep(i,n){
    cin >> a[i];
    a[i]--;
  }
  rep(i,n) cin >> b[i];
  rep(i,n-1) cin >> c[i];
  vector<int> x;

  int res = 0;
  rep(i,n) res += b[i];

  rep(i,n-1){
    if(a[i]+1==a[i+1]) x.push_back(a[i]);
  }
  rep(i,x.size()){
    res += c[x[i]];
  }

  cout << res << "\n";
  
  return 0;
}
