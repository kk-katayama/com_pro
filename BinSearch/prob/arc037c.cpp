#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
//x以下である要素の個数を求める
ll n,k;
ll a[31000],b[31000];
ll cntltx(ll x){
  ll lb=-1,ub=n;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(b[mid]<=x) lb=mid;
    else ub=mid;
  }
  return lb+1;
}
bool ok(ll x){
  ll cnt = 0;
  rep(i,n){
    cnt += cntltx(x/a[i]);
  }
  if(cnt>=k) return true;
  else return false;
}
// 条件を満たすものの中で最小
ll bins(){
  ll left=-1,right=1e+18;
  while(right-left>1){
    ll mid = (right+left)/2;
    if(ok(mid)) right = mid;
    else left = mid;
  }
  return right;
}
int main()
{
  cin >> n >> k;
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  sort(b,b+n);
  cout << bins() << "\n";
  
  return 0;
}

