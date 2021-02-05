class Sieve {
private:
  const int NMAX = 1e+6+1;
  vector<bool> prime;
  
public:
  vector<int> pr;
  vector<int> sum;
  
  Sieve() {}

  void Build() {
    sum.assign(NMAX+1, 0);
    prime.assign(NMAX, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < NMAX; ++i) {
      if(prime[i]) {
	pr.push_back(i);
	sum[i+1] = sum[i] + 1;
	int j = i;
	while(j <= NMAX) {
	  prime[j] = false;
	  j += i;
	}
      }
      else {
	sum[i+1] = sum[i];
      }
    }
  }

  // 区間[l, r) の間にある素数の個数は？
  int Count(int l, int r) {
    return sum[r] - sum[l];
  }
  
  
};
