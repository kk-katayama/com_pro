#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
// エラストテネスの篩
const int NMAX = 1e+5+1;
int prime[NMAX];
void Sieve(){
  rep(i,NMAX) prime[i] = true;
  prime[0] = prime[1] = false;
  for(int i=2;i<NMAX;++i){
    if(prime[i]){
      int j = i*2;
      while(j<=NMAX){
	prime[j] = false;
	j += i;
      }
    }
  }
}
int main()
{
  int q;cin >> q;
  vector<int> l(q),r(q);
  rep(i,q) cin >> l[i] >> r[i];
  Sieve();
  vector<int> sum(1e+5+2);
  sum[0] = 0;
  rep(i,NMAX){
    if(i%2==1){
      if(prime[i]&&prime[(i+1)/2]){
	sum[i+1] = sum[i] + 1;
	continue;
      }
    }
    sum[i+1] = sum[i];
  }
  rep(i,q) cout << sum[r[i]+1]-sum[l[i]] << "\n";
  
  return 0;
}
