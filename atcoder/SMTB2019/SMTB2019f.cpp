#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll t1,t2;
  cin >> t1 >> t2;
  ll a1,a2;
  cin >> a1 >> a2;
  ll b1,b2;
  cin >> b1 >> b2;

  ll d1=(a1-b1)*t1;
  ll d2=d1+(a2-b2)*t2;


  if(d2>0){
    if(d1>0){
      cout << 0 << "\n";
    }
    else{
      if((-d1)%d2==0) cout << ((-d1)/d2)*2 << "\n";
      else cout << ((-d1)/d2)*2+1 << "\n";
    }
  }
  else if(d2<0){
    if(d1<0){
      cout << 0 << "\n";
    }
    else{
      if(d1%(-d2)==0) cout << (d1/(-d2))*2 << "\n";
      else cout << (d1/(-d2))*2+1 << "\n";      
    }    
  }
  else{
    cout << "infinity" << "\n";
  }
  return 0;
}
