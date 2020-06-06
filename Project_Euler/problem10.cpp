#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
// エラストテネスの篩
const ll NMAX = 2000001;
ll prime[NMAX];
ll Sieve(){
  ll res = 0;
  rep(i,NMAX) prime[i] = true;
  prime[0] = prime[1] = false;
  for(ll i=2;i<NMAX;++i){
    if(prime[i]){
      res += i;
      ll j = i;
      while(j<=NMAX){
	prime[j] = false;
	j += i;
      }
    }
  }
  return res;
}

int main()
{
  cout << Sieve() << "\n";
  
  return 0;
}
