#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,k;cin >> n >> k;
  vector<int> a(n);
  vector<ll> b(n);
  rep(i,n) cin >> a[i] >> b[i];
  ll res = 0;
  for(int i = 29;i >= 0;--i) {
    if( (k >> i) & 1 ) {
      ll sum = 0;
      rep( j, a.size() ) {
	if( ! ( ( a[j] >> i ) & 1 ) ) {
	  sum += b[j];
	}
      }
      res = max( res, sum );
    }
    else {
      vector<int> atmp;
      vector<ll> btmp;
      rep( j, a.size() ) {
	if( ! ( ( a[j] >> i ) & 1 ) ) {
	  atmp.push_back( a[j] );
	  btmp.push_back( b[j] );	  
	}
      }
      a = atmp;
      b = btmp;
    }
  }
  ll summ = 0;
  rep( j, a.size() ) {
    summ += b[j];
  }
  res = max( res, summ );
  cout << res << "\n";
  return 0;
}
