#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k,m;
  cin >> n >> k >> m;
  vector<int> a(n-1);
  int sum = 0;
  rep(i,n-1){
    cin >> a[i];
    sum += a[i];
  }

  int res = n*m-sum;
  if(res>k) cout << -1 << "\n";
  else cout << max(0,res) << "\n";
  
  
  return 0;
}
