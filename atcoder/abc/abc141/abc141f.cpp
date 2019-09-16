#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
bool comp(ll& a,ll& b){
  return a>b;
}
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end(),comp);
  
  
  
  return 0;
}
