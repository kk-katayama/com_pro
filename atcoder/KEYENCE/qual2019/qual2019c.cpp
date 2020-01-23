#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
bool comp(ll &a,ll &b){
  return a>b;
}
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  ll suma = 0,sumb = 0;
  rep(i,n){
    cin >> a[i];
    suma += a[i];
  }
  rep(i,n){
    cin >> b[i];
    sumb += b[i];
  }

  if(suma>=sumb){
    ll buf = 0;
    int cnt = 0;
    rep(i,n){
      if(b[i]>a[i]){
	buf += b[i] - a[i];
	cnt++;
      }
    }
    vector<ll> c(n);
    rep(i,n){
      c[i] = a[i] - b[i];
    }
    sort(c.begin(), c.end(),comp);
    int index = 0;
    while(buf>0){
      if(buf<=c[index]){
	buf = 0;
	cnt++;
      }
      else{
	buf -= c[index];
	cnt++;
      }
      index++;
    }
    cout << cnt << "\n";
  }
  else{
    cout << -1 << "\n";
  }

  
  return 0;
}
