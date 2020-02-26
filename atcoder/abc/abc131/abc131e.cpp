#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  if((n-1)*(n-2)/2<k){ cout << -1 << "\n";return 0;}

  vector<int> a,b;
  rep1(i,n-1){
    a.push_back(1);b.push_back(1+i);
  }

  int s=(n-1)*(n-2)/2-k;
  int j=2;
  while(1){
    rep1(i,n-j){
      if(s==0) break;
      a.push_back(j);b.push_back(j+i);
      s--;
    }
    if(s==0) break;
    j++;
  }

  cout << (int)a.size() << "\n";
  rep(i,a.size()) cout << a[i] << " " << b[i] <<"\n" ;
  
  return 0;
}
