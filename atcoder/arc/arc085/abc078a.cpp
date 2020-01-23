#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  char x,y;
  cin >> x >> y;
  int xi = x - 'A';
  int yi = y - 'A';  

  if(xi<yi){
    cout << "<" << "\n";
  }
  else if(xi>yi){
    cout << ">" << "\n";
  }
  else{
    cout << "=" << "\n";
  }
  
  return 0;
}
