// 繰り返し二乗法(mod m)
ll pow(ll x, ll n, ll m) {
  ll res = 1;
  while(n > 0) {
    if(n & 1) res = res*x % m;
    x = x*x % m;
    n >>= 1;
  }
  return res;
}
