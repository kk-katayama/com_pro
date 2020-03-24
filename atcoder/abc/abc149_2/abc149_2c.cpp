#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
// エラストテネスの篩
const int NMAX = 1e+6+1;
int prime[NMAX];
void Sieve(){
  rep(i,NMAX) prime[i] = true;
  prime[0] = prime[1] = false;
  for(int i=2;i<NMAX;++i){
    if(prime[i]){
      int j = i*2;;
      while(j<=NMAX){
	prime[j] = false;
	j += i;
      }
    }
  }
}

int main()
{
 
  int n;cin >> n;
  Sieve();
  while(1){
    if(prime[n]){
      cout << n << "\n";
      break;
    }
    n++;
  }
  return 0;
}
