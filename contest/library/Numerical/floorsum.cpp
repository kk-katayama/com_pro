ll floor_sum(ll n, ll m, ll a, ll b) {
  ll res = 0;
  if(a >= m) {
    res += n*(n - 1)*(a/m) / 2;
    a %= m;
  }
  if(b >= m) {
    res += n*(b/m);
    b %= m;
  }

  ll ymax = (a*n + b)/m, xmax = m*ymax - b;
  if(ymax == 0) return res;
  res += ymax*(n - (xmax + a - 1)/a);
  res += floor_sum(ymax, a, m, (a - xmax%a)%a);
  return res;
}