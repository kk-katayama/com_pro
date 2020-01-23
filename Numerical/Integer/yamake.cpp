#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <climits>
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
    prime.assign(n+1,true);
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
  cout << LLONG_MAX/2 << "\n";
  const ll N = 1e+10;
  Number<ll> nb(N);
  vector<ll> pn = nb.sieve();
  cout << "sieve finish!" << "\n";
  cout << pn.size() << "\n";
  //  long double m = 9999999999978083;
  ll m =  4611686018427387903;
  //  ll m =  341606371735362066;
  ll cnt = 0;
  while(1){
    ll mm = (ll)m;
    if(cnt%1000==0) cout << m << "\n";
    cnt++;
    ll k = 0;
    bool f = true;
    bool ff = true;
    bool ffm = true;
    while(pn[k]*pn[k]<=mm){
      if(mm%pn[k]==0){
	ffm = false;
	break;
      }
      k++;
    }


    //    ll n = (ll)m*1.08;
    ll n = m+m*2/25;



    k = 0;
  
  
    while(pn[k]*pn[k]<=n){
      if(n%pn[k]==0){
	f = false;
	break;
      }
      k++;
    }

    //  cout << n << ":" << (f?"YES":"NO") << "\n";
  
    //    ll nn = (ll)m*1.1;
    ll nn = m+m/10;
    k=0;
  
    while(pn[k]*pn[k]<=nn){
      if(nn%pn[k]==0){
	ff = false;
	break;
      }
      k++;
    }
    if(ffm&&f&&ff){
      cout << (ll)m << "\n";
      cout << n << ":" << (f?"YES":"NO") << "\n";  
      cout << nn << ":" << (ff?"YES":"NO") << "\n";
      //      break;
    }
    m--;
  }

  return 0;
}
