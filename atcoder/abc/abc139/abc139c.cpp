#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
vector<int> h;
int main()
{
  cin >> n;
  h.resize(n);
  rep(i,n) cin >> h[i];

  int cnt = 0,res = 0;
  rep(i,n-1){
    if(h[i]>=h[i+1]) cnt++;
    else{
      res = max(res,cnt);
      cnt = 0;
    }
  }
  res = max(res,cnt);
  
  cout << res << "\n";
  
  
  return 0;
}
