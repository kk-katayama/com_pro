#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
typedef long double ld;
int main()
{
  int t; cin >> t;
  vector<ll> n(t), a(t), b(t), c(t), d(t);
  rep(i,t) {
    cin >> n[i] >> a[i] >> b[i] >> c[i] >> d[i];
  }
  ll inf = (1LL << 60);

  rep(i,t) {
    vector<ll> num = {2, 3, 5};
    vector<ll> cost = {a[i], b[i], c[i]};    
    map<ll,ll> dp;
    dp[0] = 0;
    dp[1] = d[i];
    auto rec = [&](auto f, ll nn)-> ll{
		 if(dp.find(nn) != dp.end()) return dp[nn];
		 ll res = inf;
		 if(((ld)nn * (ld)d[i]) < inf) {
		   res = nn * d[i];
		 }
		 rep(j,3) {
		   if(nn % num[j] == 0) chmin(res, f(f, nn/num[j]) + cost[j]);
		   else {
		     chmin(res, f(f, nn/num[j]) + cost[j] + d[i]*(nn % num[j]));
		     chmin(res, f(f, nn/num[j] + 1) + cost[j] + d[i]*(num[j] - nn % num[j]));	   
		   }		   
		 }
		 return dp[nn] = res;
	       };
    cout << rec(rec, n[i]) << "\n";
  }
  
  return 0;
}
