#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>
#include<functional>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define debug(output) cout<<#output<<"= "<<output<<endl
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e9+7;
const int MOD=1000000007;
struct Nums{
    long long n;
    vector<long long> kaijo;
    Nums(int N){
        n=N;
        kaijo.push_back(1);
        for(long long i=1;i<=n;i++){
            kaijo.push_back((kaijo[i-1]*i)%MOD);
        }
    }
    lint myPow(lint x, lint n, lint m){
        if(n == 0)
            return 1;
        if(n % 2 == 0)
            return myPow(x * x % m, n / 2, m);
        else
            return x * myPow(x, n - 1, m) % m;
    }
    long long modinv(long long a, long long m) {
        long long b = m, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }
    long long comb(long long N,long long K,long long rest){
        long long res=kaijo[N]*modinv(kaijo[K],rest)%rest;
        res*=modinv(kaijo[N-K],rest);
        res%=rest;
        return res;
    }
};

int main(){
  int n,x;cin>>n>>x;
  x=abs(x);
  string s;cin>>s;
  Nums lib(n+x+1);
  int a=0;
  int b=0;
  rep(i,n){
      if(s[i]=='S')++a;
      else ++b;
  }
  vector<lint> p(b+1,0),sm(b+1,0);
  rep(i,b+1){
      p[i]=lib.comb(b,i,MOD)*lib.myPow(2,b-i,MOD)%MOD;
  }
  sm[b]=p[b];
  for(int i=b-1;i>=0;--i){
      sm[i]=sm[i+1]+p[i];
  }
  lint res=0;
  rep(i,a+1){
      if(i%2!=x%2)continue;
      lint buf=lib.comb(a,i,MOD)*lib.myPow(2,a-i,MOD)%MOD;
      int hoge=(x-3*i+5)/6;
      buf*=sm[hoge];
      buf%=MOD;
      res+=buf;
      res%=MOD;
  }
  cout<<res<<"\n";
  return 0;
}
