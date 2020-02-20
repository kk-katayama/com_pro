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
  int sum=0;
  int cnt=0;
  rep(i,n){
    int a;
    cin >> a;
    if(a!=0){
      cnt++;
      sum += a;
    }
  }

  cout << (sum+cnt-1)/cnt << "\n";
  return 0;
}
