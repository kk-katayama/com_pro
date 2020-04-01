#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  string s;cin >> s;
  vector<int> a;
  int cnt = 1;
  rep(i,n-1){
    if(s[i] == s[i+1]) cnt++;
    else{
      a.push_back(cnt);
      cnt = 1;
    }
  }
  a.push_back(cnt);
  int res = 0;
  int as = a.size();
  rep(i,as) res += a[i] - 1;
  int x = ( as - 1 ) / 2;
  if(as % 2 == 0){
    if( x + 1 <= k ) res += 2 * x + 1;
    else if( x <= k ) res += 2 * x;
    else res += 2 * k;
  }
  else {
    if( x <= k ) res += 2 * x;
    else res += 2 * k;    
  }
  cout << res << "\n";
  return 0;
}
