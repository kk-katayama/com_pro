#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
int n,k;
int a[110];
bool dp[100010];
int main()
{
  cin >> n >> k;
  rep(i,n) cin >> a[i];
  
  dp[0] = false;

  rep1(i,k){
    bool f = false;
    rep(j,n){
      if( i-a[j] < 0) break;
      else if( !dp[i-a[j]] ){
	f = true;
	break;
      }
    }
    dp[i] = f;
  }

  cout << (dp[k] ? "First" : "Second") << "\n";
  
  return 0;
}
