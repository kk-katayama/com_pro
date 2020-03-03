#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  int k;cin >> k;
  vector<int> a(k);
  rep(i,k) cin >> a[i];
  sort(a.begin(),a.end());
  vector<int> b;
  int cnt=0;
  rep(i,k-1){
    if(a[i]+1==a[i+1]) cnt++;
    else if(a[i]+2==a[i+1]&&a[0]==0){
      b.push_back(cnt);
      b.push_back(0);
      cnt = 1;
    }      
    else{
      b.push_back(cnt);
      cnt = 1;
    }
  }
  b.push_back(cnt);
  
  int res = 0;
  if(n==k){
    cout << n << "\n";
    return 0;
  }
  rep(i,b.size()){
    res = max(res,b[i]);
    if(b[i]==0) res = max(res,b[i-1]+b[i+1]+1);
  }
  cout << res << "\n";
  
  return 0;
}
