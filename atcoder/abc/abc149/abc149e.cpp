#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
vector<complex<double>> fft(vector<complex<double>> a,bool inverse = false){
  int n = a.size();
  int h = 0;
  for(int i=0;(1<<i)<n;++i) ++h;

  rep(i,n){
    int j =0;
    rep(k,h) j |= (i>>k&1) << (h-1-k);
    if(i<j) swap(a[i],a[j]);
  }

  for(int b=1;b<n;b*=2){
    rep(j,b){
      complex<double> w = polar(1.0,(inverse?-1:1)*(2*M_PI)/(2*b)*j);
      for(int k=0;k<n;k+=b*2){
	complex<double> s = a[j+k];
	complex<double> t = a[j+k+b]*w;
	a[j+k] = s+t;
	a[j+k+b] = s-t;
      }
    }
  }
  if(inverse) rep(i,n) a[i] /= n;
    
  return a;
}

vector<complex<double>> fft(vector<double> a,bool inverse = false){
  vector<complex<double>> a_complex(a.size());
  rep(i,a.size()) a_complex[i] = complex<double>(a[i],0);
  return fft(a_complex,inverse);
}

vector<double> convolve(vector<double> a,vector<double> b){
  int s = a.size() + b.size() - 1;
  int t = 1;
  while(t<s) t*=2;
  a.resize(t);
  b.resize(t);
  vector<complex<double>> A = fft(a);
  vector<complex<double>> B = fft(b);
  rep(i,t){
    A[i] *= B[i];
  }
  A = fft(A,true);
  a.resize(s);
  rep(i,s) a[i] = A[i].real();
  return a;
}


int main()
{
  int n;
  cin >> n;
  ll m;
  cin >> m;
  vector<ll> a(n);
  ll mm=0;
  rep(i,n){
    cin >> a[i];
    mm = max(mm,a[i]);
  }

  vector<double> x(mm+1,0);
  rep(i,n) x[a[i]]++;

  vector<double> y = convolve(x,x);
  vector<ll> z;
  rep(i,y.size()){
    z.push_back((ll)(y[i]+0.5));
  }


  
  ll sum=0;
  ll res=0;
  for(ll i=(ll)z.size()-1;i>=0;--i){
    sum+=z[i];
    if(sum>=m){
      res+=(z[i]-(sum-m))*i;
      break;
    }
    res+=z[i]*i;
  }

  cout << res << "\n";
    
  


  
  
  return 0;
}
