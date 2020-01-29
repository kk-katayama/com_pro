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
  int w=4,h=3;
  while(w<=a){
    if(w==a&&h==b){
      cout << "4:3" << "\n";
      return 0;
    }
    w += 4;
    h += 3;
  }
  w = 16;
  h = 9;
  while(w<=a){
    if(w==a&&h==b){
      cout << "16:9" << "\n";
      return 0;
    }
    w += 16;
    h += 9;
  }  
  return 0;
}
