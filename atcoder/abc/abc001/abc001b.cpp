#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int m;
  cin >> m;
  if(m<100){
    cout << "00" << "\n";
  }
  else if(100<=m&&m<5000){
    int x = m*10/1000;
    if(x/10==0){
      cout << "0";
      cout << x << "\n";
    }
    else{
      cout << x << "\n";
    }
  }
  else if(6000<=m&&m<=30000){
    cout << m/1000+50 << "\n";
  }
  else if(35000<=m&&m<=70000){
    cout << (m/1000-30)/5+80 << "\n";
  }
  else if(70000<m){
    cout << 89 << "\n";
  }
  return 0;
}
