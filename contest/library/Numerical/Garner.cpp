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

// modが合成数の場合のmodの逆元
// modが合成数のときはFermatの小定理を用いた逆元計算ができない
// aの法modにおける逆元は、aとmodが互いに素であれば
// 拡張ユークリッドの互除法を用いることで行うことができる
ll ModInv(ll a, ll mod) {
  ll x,y;
  ll d = ExtGcd(a, mod, x, y);
  if(d != 1) {
    return -1;
  }
  x = ( (x%mod) + mod ) % mod;
  return x;
}

// Garnerのアルゴリズム
// x = r[i] (mod m[i]) を満たすx を見つけ、x % mod を返す
ll Garner(vector<ll> r, vector<ll> m, ll mod = 100000000000000003) {
  r.push_back(0);
  m.push_back(mod); // 答えを% mod する
  int n = r.size();
  vector<ll> mprod(n, 1); // mprodにはm[i]の積を入れていく
  vector<ll> x(n, 0); // xは答え
  rep(i,n-1) {
    // x[i] + t*mprod[i] = r[i] (mod m[i]) からt を計算する
    ll t = ((r[i] - x[i]) * ModInv(mprod[i], m[i])) % m[i];
    if(t < 0) t += m[i];
    // x, mprodを更新
    for (int j = i + 1; j < n; j++) {
      (x[j] += mprod[j] * t) %= m[j];
      (mprod[j] *= m[i]) %= m[j];
    }
  }
  return x[n-1];
}

