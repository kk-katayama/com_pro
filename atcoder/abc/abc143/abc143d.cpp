#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int l[2100];
int n;
int cntltk(int k,int lef){
  int lb=lef,ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(l[mid]<k) lb=mid;
    else ub=mid;
  }
  return lb;
}
int cntmtk(int k,int lef){
  int lb=lef,ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(l[mid]>k) ub=mid;
    else lb=mid;
  }
  return ub;
}

int main()
{
  cin >> n;
  rep(i,n) cin >> l[i];
  sort(l,l+n);
  ll res = 0;
  rep(i,n) rep(j,n){
    if(i >= j) continue;
    int x = abs(l[i] - l[j]);
    ll tmp = (ll)cntltk(l[i] + l[j],j) - cntmtk(x,j) + 1;
    res += tmp;
  }
  cout << res << "\n";
  return 0;
}
