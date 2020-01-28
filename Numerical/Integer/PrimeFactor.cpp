//return x's prime factor as map
map<int,int> primefactor(int x){
  int nn = n;
  map<int,int> res;
  for(int i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}
