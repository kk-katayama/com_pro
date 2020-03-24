#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
//return x's prime factor as map
int primefactor(int x){
  int nn = x;
  int res = 0;
  for(int i=2;i*i<=nn;++i){
    while(nn%i==0){
      res++;
      nn /= i;
    }
  }
  if(nn!=1) res++;
  return res;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  int x = 0;
  rep(i,n){
    x ^= primefactor(a[i]);
  }
  if(x==0){
    cout << "No" << "\n";
  }
  else{
    cout << "Yes" << "\n";
  }
  
  return 0;
}
