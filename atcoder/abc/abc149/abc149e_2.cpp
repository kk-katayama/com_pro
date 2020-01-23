#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
bool comp(ll &a,ll &b){
  return a>b;
}
int main()
{
  int n;
  cin >> n;
  ll m;
  cin >> m;
  vector<ll> a(n);
  ll mm = 0;
  for(int i=0;i<n;++i){
    cin >> a[i];
    mm = max(mm,a[i]);
  }
  mm *= 2;
  
  sort(a.begin(), a.end(),comp);

  ll lb=0,ub=mm+1;
  while(ub-lb>1){
    ll mid = (ub+lb)/2;
    ll cnt=0;
    for(int i=0;i<n;++i){
      ll thr = mid-a[i];
      ll lbb = -1,ubb = n;
      while(ubb-lbb>1){
	ll midd=(ubb+lbb)/2;
	if(a[midd]>=thr){
	  lbb = midd;
	}
	else{
	  ubb = midd;
	}
      }
      //cout << i << ":" << lbb << "\n";
      cnt+=lbb+1;
    }
    //    cout << mid << ":" << cnt << "*************\n";
    if(cnt>=m){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }
  
  ll x = lb;
  //  cout << x << "\n";
  vector<ll> sum(n+1);
  sum[0] = 0;
  for(int i=0;i<n;++i){
    sum[i+1] = sum[i]+a[i];
  }

  // for(int i=0;i<n+1;++i){
  //   cout << sum[i] << "\n";
  // }
  
  ll res = 0;
  ll ct = 0;
  for(int i=0;i<n;++i){
    ll thr = x - a[i];
    ll lbb = -1,ubb = n;
    while(ubb-lbb>1){
      ll midd = (ubb+lbb)/2;
      if(a[midd]>=thr){
	lbb = midd;
      }
      else{
	ubb = midd;
      }
    }
    //    cout << i << ":" << lbb << "\n";
    ct += lbb+1;
    res += a[i]*(lbb+1)+sum[lbb+1];
  }

  res -= (ct-m)*x;
  cout << res << "\n";
  
  return 0;
}
