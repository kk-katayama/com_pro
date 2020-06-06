#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
// エラストテネスの篩
const int NMAX = 1e+6+1;
int prime[NMAX];
vector<int> Sieve(){
  vector<int> res;
  rep(i,NMAX) prime[i] = true;
  prime[0] = prime[1] = false;
  for(int i=2;i<NMAX;++i){
    if(prime[i]){
      res.push_back(i);
      int j = i;
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
  vector<int> p = Sieve();
  cout << p.size() << "\n";
  cout << p[10000] << "\n";
  return 0;
}
