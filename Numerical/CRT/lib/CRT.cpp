// 拡張ユークリッドの互除法
// ap + bq = gcd(a, b) となる (p, q) を求める.
// 返り値はgcd(a, b)
ll ExtGcd(ll a, ll b, ll &p, ll &q) {  
  if (b == 0) {
    p = 1; q = 0;
    return a;
  }  
  ll d = ExtGcd(b, a%b, q, p);  
  q -= a/b * p;  
  return d;  
}

// 中国剰余定理
// x = b1 (mod m1), x = b2 (mod m2), m1とm2は互いに素, を満たすようなxを求める. 
// 返り値を (r, m) とすると解は x = r (mod m)
// 解なしの場合は (0, -1) を返すよ
pair<ll, ll> CRT(ll b1, ll m1, ll b2, ll m2) {
  ll p, q;
  ll d = ExtGcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if ((b2 - b1) % d != 0) return {0, -1};
  ll m = m1 * (m2/d); // lcm of (m1, m2)
  ll tmp = (b2 - b1) / d * p % (m2/d);
  ll r = ((b1 + m1 * tmp) % m + m) % m;
  return {r, m};
}
