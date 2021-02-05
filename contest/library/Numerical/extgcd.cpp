
// 拡張ユークリッドの互除法
// ap + bq = gcd(a, b) となる (p, q) を求める.
// 返り値はgcd(a, b)
long long ExtGcd(long long a, long long b, long long &p, long long &q) {
  if (b == 0) {
    p = 1; q = 0;
    return a;
  }
  long long d = ExtGcd(b, a%b, q, p);
  q -= a/b * p;
  return d;
}