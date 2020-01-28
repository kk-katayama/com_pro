#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b;
  cin >> a >> b;

  if(0<a){
    cout << "Positive" << "\n";
  }
  else if(a<=0&&0<=b){
    cout << "Zero" << "\n";
  }
  else{
    if((b-a)%2==0){
      cout << "Negative" << "\n";
    }
    else{
      cout << "Positive" << "\n";      
    }
  }
  
  return 0;
}
