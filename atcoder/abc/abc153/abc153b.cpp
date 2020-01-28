#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h;
  cin >> h;
  int n;
  cin >> n;
  int sum = 0;
  rep(i,n){
    int a;
    cin >> a;
    sum += a;
  }
  if(sum>=h){
    cout << "Yes" << "\n";
  }
  else{
    cout << "No" << "\n";
  }
  
  return 0;
}
