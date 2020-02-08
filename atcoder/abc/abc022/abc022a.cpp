#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,s,t,w;
  cin >> n >> s >> t >> w;
  vector<int> a(n-1);
  rep(i,n-1){
    cin >> a[i];
  }

  int cnt = 0;
  if(s<=w&&w<=t) cnt++;
  rep(i,n-1){
    w += a[i];
    if(s<=w&&w<=t) cnt++;
  }
  cout << cnt << "\n";
  
  return 0;
}
