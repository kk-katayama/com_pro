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
int extgcd(int a, int b, int &p, int &q) {
  if (b == 0) {
    p = 1; q = 0;
    return a;
  }
  int d = extgcd(b, a%b, q, p);
  q -= a/b * p;
  return d;
}

// 中国剰余定理
// x = b1 (mod m1), x = b2 (mod m2), m1とm2は互いに素, を満たすようなxを求める.
// 返り値を (r, m) とすると解は x = r (mod m)
// 解なしの場合は (0, -1) を返すよ
pair<int, int> CRT(int b1, int m1, int b2, int m2) {
  int p, q;
  int d = extgcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return {0, -1};
  int m = m1 * (m2/d); // lcm of (m1, m2)
  int tmp = (b2 - b1) / d * p % (m2/d);
  int r = ((b1 + m1 * tmp) % m + m) % m;
  return {r, m};
}

int main()
{
  int n; cin >> n;
  vi a(n+1), b(n+1);
  int mx = 0;
  rep1(i,n) {
    if(i == 1) continue;
    cout << "? " << i << " " << 1;
    cout.flush();
    cin >> a[i];
    chmax(mx, a[i]);
  }
  vi res(n+1);
  res[1] = mx+1;
  mx = 0;
  rep1(i,n) {
    if(i == 2) continue;
    cout << "? " << i << " " << 2;
    cout.flush();    
    cin >> b[i];
    chmax(mx, b[i]);
  }  
  res[2] = mx+1;

  for (int i = 3; i <= n; ++i) {
    res[i] = CRT(a[i], res[1], b[i], res[2]).first;
  }

  cout << "! ";
  rep1(i,n) {
    cout << res[i] << " ";
  }
  cout.flush();    
  return 0;
}
