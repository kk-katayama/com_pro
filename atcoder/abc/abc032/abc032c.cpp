#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  ll k;
  cin >> k;
  vector<ll> a(n);
  bool f = false;
  rep(i,n){
    cin >> a[i];
    if(a[i]==0){
      f = true;
    }
  }
  if(f){
    cout << n << "\n";
    return 0;
  }
  int s=0,t=0,res=0;
  ll pr=a[0];
  while(1){
    if(pr<=k){
      res = max(res,t-s+1);
      t++;
      if(t==n) break;
      pr *= a[t];
    }
    else{
      pr /= a[s];
      s++;
      if(s>t){
	t++;
	if(t==n) break;
	pr *= a[t];
      }
    }
  }
  cout << res << "\n";
  return 0;
}
