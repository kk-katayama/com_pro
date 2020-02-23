#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  vector<int> d(m);
  vector<int> c(m,0);  
  int cnt=1;
  rep(i,n-1){
    if(a[i]==a[i+1]) cnt++;
    else{
      d[a[i]%m] += cnt/2;
      cnt = 1;
    }
  }

  rep(i,n) c[a[i]%m]++;
  rep(i,m/2+1){
    
  }
  
  return 0;
}
