#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }

const int NMAX = 1e+5+1;
bool prime[NMAX];
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
  vector<int> l(q), r(q);
  rep(i,q) cin >> l[i] >> r[i];

  Sieve();
  vector<int> sum(NMAX+1);
  sum[0] = 0;
  rep(i,NMAX) {
    int x = 0;
    if(prime[i] && prime[(i+1)/2]) {
      x = 1;
    }
    sum[i+1] = sum[i] + x;
  }

  rep(i,q) {
    cout << sum[r[i]+1] - sum[l[i]] << "\n";
  }
	    
  
  return 0;
}
