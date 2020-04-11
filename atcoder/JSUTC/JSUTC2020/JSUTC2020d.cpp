#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
// int gcd(int a,int b){
//   if(b==0) return a;
//   return gcd(b,a%b);
// }
int main()
{
  int n,q;cin >> n >> q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> s(q);
  rep(i,q) cin >> s[i];

  int x = a[0];
  vector<pair<int,int>> p;
  p.push_back( {x, 1} );
  rep(i,n) {
    int g = gcd(x, a[i]);
    if(g != x) p.push_back( {g, i+1} );
    x = g;
  }

  rep(i,q) {
    int g = s[i];
    bool f = true;
    for(auto j : p) {
      g = gcd(g, j.first);
      if(g == 1) {
	cout << j.second << "\n";
	f = false;
	break;
      }
    }
    if(f) cout << g << "\n";
  }
  return 0;
}
