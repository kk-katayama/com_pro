#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct Number{
  X n;
  vector<bool> prime;
  
  Number(X _n)
  {
    n = _n;
    //    prime.assign(n+1,true);
  }
  
  //nの約数を全列挙
  vector<X> divisor()
  {
    vector<X> res(0);
    for(X i=1;i*i<=n;++i){
      if(n%i==0){
	res.push_back(i);
	if(i != n/i) res.push_back(n/i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
  
  //nを素因数分解
  map<X,int> prime_factor()
  {
    int nn = n;
    map<X,int> res;
    for(X i=2;i*i<=nn;++i){
      while(nn%i==0){
	res[i]++;
	nn /= i;
      }
    }
    if(nn!=1) res[nn] = 1;
    return res;
  }

  //n以下の素数を全列挙
  vector<X> sieve()
  {
    vector<X> res(0);
    if(n<=1) return res;
    prime[0] = prime[1] = false;
    for(X i = 2;i<=n;++i){
      if(prime[i]){
	res.push_back(i);
	X b = i*2;
	while(b<=n){
	  prime[b] = false;
	  b += i;
	}
      }
    }
    return res;
  }
  
};
int main()
{
  ll n;
  cin >> n;
  Number<ll> nm(n);

  vector<ll> div = nm.divisor();
  cout << "divisor" << "\n";
  rep(i,div.size()) cout << div[i] << "\n";

  // map<ll,int> pf = nm.prime_factor();
  // cout << "primefactor" << "\n";
  // for(auto& itr:pf) cout << itr.first << " " << itr.second << "\n";

  // vector<ll> pn = nm.sieve();
  // cout << "primenumber" << "\n";
  // rep(i,pn.size()) cout << pn[i] << "\n";
  
  return 0;
}
