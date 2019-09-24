#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct ShakuTori{
  vector<X> array;
  ll n;
  vector<X> sum;
  
  ShakuTori(vector<X> _array)
  {
    array = _array;
    n = (ll)array.size();    
  }

  ll solve()
  {
    ll l = 0;
    ll r = 1;
    ll res = n;
    while(1){
      while(array[r-1] < array[r]){
	res += r - l;
	//	cout << l << " " << r << "\n";
	r++;
	if(r == n+1) break;
      }
      l = r;
      r = l + 1;
      if(r >= n+1) break;
    }
    return res;
  }
  
};

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  ShakuTori<int> arr(a);
  cout << arr.solve() << "\n";
  
  
  return 0;
}
