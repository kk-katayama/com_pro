#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}

ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}
ll primefactor(ll x){
  ll nn = x;
  ll res=0;
  for(ll i=2;i*i<=nn;++i){
    if(nn%i==0) res++;
    while(nn%i==0){
      nn /= i;
    }
  }
  if(nn!=1) res++;
  return res;
}

int main()
{
  ll a,b;cin >> a >> b;
  ll g = gcd(a,b);
  ll num = primefactor(g);
  cout << num+1 << "\n";
  
  return 0;
}
