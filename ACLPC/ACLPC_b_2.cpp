#include <iostream>
#include <cstdio>
#include <atcoder/fenwicktree>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
using namespace atcoder;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int n,q; scanf("%d %d", &n, &q);

  fenwick_tree<ll> fw(n);
  rep(i,n) {
    ll a; scanf("%lld", &a);
    fw.add(i, a);
  }

  rep(i,q) {
    int t; scanf("%d", &t);
    if(t == 0) {
      ll p, x; scanf("%lld %lld", &p, &x);
      fw.add(p, x);
    }
    else {
      int l, r; scanf("%d %d", &l, &r);
      printf("%lld\n", fw.sum(l, r));
    }
  }
  return 0;
}
