// エラストテネスの篩
const int NMAX = 1e+5+1;
int prime[NMAX];
void Sieve(){
  rep(i,NMAX) prime[i] = true;
  prime[0] = prime[1] = false;
  for(int i=2;i<NMAX;++i){
    if(prime[i]){
      int j = i;
      while(j<=NMAX){
	prime[j] = false;
	j += i;
      }
    }
  }
}






