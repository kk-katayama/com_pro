#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int t;cin >> t;
  vector<ll> n(t),k(t);
  vector<vector<ll>> a(t);
  rep(i,t){
    cin >> n[i] >> k[i];
    a[i].resize(n[i]);
    rep(j,n[i]) cin >> a[i][j];
  }
  rep(i,t){
    bool f = false;
    map<ll,int> mp;
    rep(j,n[i]){
      ll cnt = 0;
      while(a[i][j]!=0){
	while(a[i][j]%k[i]==0){
	  a[i][j] /= k[i];
	  cnt++;
	}
	if(mp[cnt]>0){
	  f = true;
	  break;
	}
	mp[cnt]++;
	a[i][j]--;
      }
      if(f){
	cout << "NO" << "\n";
	break;
      }
    }
    if(!f) cout << "YES" << "\n";
  }
  return 0;
}
