//Sieve of Eratosthenes,
template<typename X>
class Sieve{
private:
  X x;
  vector<bool> prime;
public:
  Sieve(X _x){
    x = _x;
    prime.assign(x+1,true);
  }

  void init(){
    prime[0] = prime[1] = false;
    for(X i=2;i<=n;++i){
      if(prime[i]){
	X b = i*2;
      }
      while(b<=x){
	prime[b] = false;
	b += i;
      }
    }
  }

  int count(){
    int res=0;
    rep(i,x+1){
      if(prime[i]){
	res++;
      }
    }
    return res;
  }

  vector<X> all(){
    vector<X> res;
    rep(i,x+1){
      if(prime[i]){
	res.push_back(i);
      }
    }
    return res;
  }

  bool is_prime(X n){
    return prime[n];
  }
  
  
};
