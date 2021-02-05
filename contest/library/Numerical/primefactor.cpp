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
