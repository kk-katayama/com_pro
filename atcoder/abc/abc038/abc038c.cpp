#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  ll s=0,t=0;
  ll res = 0;
  while(t<n){
    if(s==t){
      res++;
      t++;
    }
    else{
      if(a[t-1]<a[t]){
	res += t-s+1;
	t++;
      }
      else{
	s = t;
      }
    }
  }

  cout << res << "\n";
  
  return 0;
}
