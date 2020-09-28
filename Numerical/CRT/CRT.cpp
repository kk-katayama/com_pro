#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// 拡張ユークリッドの互除法
// ap + bq = gcd(a, b) となる (p, q) を求める.
// 返り値はgcd(a, b)
ll extgcd(ll a, ll b, ll &p, ll &q) {  
  if (b == 0) {
    p = 1; q = 0;
    return a;
  }  
  ll d = extgcd(b, a%b, q, p);  
  q -= a/b * p;  
  return d;  
}

// 中国剰余定理
// x = b1 (mod m1), x = b2 (mod m2), m1とm2は互いに素, を満たすようなxを求める. 
// 返り値を (r, m) とすると解は x = r (mod m)
// 解なしの場合は (0, -1) を返すよ
pair<ll, ll> CRT(ll b1, ll m1, ll b2, ll m2) {
  ll p, q;
  ll d = extgcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return {0, -1};
  ll m = m1 * (m2/d); // lcm of (m1, m2)
  ll tmp = (b2 - b1) / d * p % (m2/d);
  ll r = ((b1 + m1 * tmp) % m + m) % m;
  return {r, m};
}

// n を素因数分解する.返り値はmap.計算量はO(sqrt(n))
map<ll,int> primefactor(ll n){
  ll nn = n;
  map<ll,int> res;
  for(ll i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}

int main()
{
  int a,b; cin >> a >> b;
  int c,d; cin >> c >> d;
  cout << CRT(a,b,c,d).first << "\n";
  return 0;
}
