#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;cin >> n;
  string s;cin >> s;
  int q;cin >> q;
  vector<int> k(q);
  rep( i, q ) cin >> k[i];
  rep( i, q ) {
    ll d = 0, m = 0, dm = 0, dmc = 0;
    rep( j, k[i] ) {
      if( s[j] == 'D' ) d++;
      else if( s[j] == 'M' ) {
	dm += d;
	m++;
      }
      else if( s[j] == 'C' ) dmc += dm;
    }
    rep( j, n - k[i] ) {
      if( s[j] == 'D' ) {
	d--;
	dm -= m;
      }
      else if( s[j] == 'M' ) m--;

      if( s[ j + k[i] ] == 'D' ) d++;
      else if( s[ j + k[i] ] == 'M' ) {
	m++;
	dm += d;
      }
      else if( s[ j + k[i] ] == 'C' ) dmc += dm;
    }
    cout << dmc << "\n";
  }
  return 0;
}
