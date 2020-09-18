// n を素因数分解する.返り値はmap.計算量はO(sqrt(n))
map<int,int> primefactor(int n){
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
