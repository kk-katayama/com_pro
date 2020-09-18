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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
// エラストテネスの篩
const int NMAX = 1e+3+1;
int prime[NMAX];
vector<int> pri;
void Sieve(){
  rep(i,NMAX) prime[i] = true;
  prime[0] = prime[1] = false;
  for(int i=2;i<NMAX;++i){
    if(prime[i]){
      pri.push_back(i);
      int j = i;
      while(j<=NMAX){
	prime[j] = false;
	j += i;
      }
    }
  }
}

// ユークリッドの互除法で最大公約数を求める
int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
int lcm(int a,int b){
  return a*b/gcd(a,b);
}

int main()
{
  int n; cin >> n;
  vector<int> b(n);
  rep(i,n) cin >> b[i];

  vector<int> a;
  rep(i,n) {
    if(b[i] != 1) a.push_back(b[i]);
  }
  n = a.size();
  
  Sieve();
  
  vector<bool> f(1e+6+1, false);
  rep(i,n) {
    vector<int> tmp;
    if(f[a[i]]) goto AAA;
    tmp.push_back(a[i]);
    rep(j,pri.size()) {
      if(a[i] % pri[j] == 0) {
	if(f[pri[j]]) goto AAA;
	tmp.push_back(pri[j]);
	if(a[i] / pri[j] == 1) continue;
	if(f[a[i] / pri[j]]) goto AAA;
	tmp.push_back(a[i] / pri[j]);
      }
    }
    for(auto val: tmp) {
      f[val] = true;
    }
  }
  

  cout << "pairwise coprime" << "\n";  
  return 0;
  
 AAA:
  int g = a[0];
  rep(i,b.size()) {
    g = gcd(g, b[i]);
  }
  if(g == 1) cout << "setwise coprime" << "\n";
  else cout << "not coprime" << "\n";
  return 0;
}
