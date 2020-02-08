#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  int x=0;
  int ind;
  for(int i=2;i<=n;++i){
    cout << "? " << 1 << " " << i << "\n";
    int d;
    cin >> d;
    if(d>x){
      x = d;
      ind = i;
    }
  }

  x = 0;
  for(int i=1;i<=n;++i){
    if(ind==i) continue;
    cout << "? " << ind << " " << i << "\n";
    int d;
    cin >> d;
    if(d>x){
      x = d;
    }
  }  

  cout << "! " << x << "\n";

  
  return 0;
}
