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
