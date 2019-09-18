#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct Array
{
  vector<X> array;
  int n;

  Array(vector<X> _array)
  {
    array = _array;
    n = array.size();
  }

  ll solve(ll k)
  {
    ll res = 0;
    ll r = 1;
    ll sum = array[0];
    rep(l,n){
      while(sum<=k){
	res += r - l;
	cout << l << " " << r << "\n";
	r++;
	if(r == n+1) break;
	sum += array[r-1];	
      }
      if(r == n+1) break;
      sum -= array[l];
    }
    return res;
  }
};
int main()
{
  int n,q;
  cin >> n >> q;
  vector<ll> a(n);
  vector<ll> z(q);
  rep(i,n) cin >> a[i];
  rep(i,q) cin >> z[i];

  Array<ll> arr(a);

  rep(i,q) cout << arr.solve(z[i]) << "\n";
  
  return 0;
}

