#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  if(n<=59) cout << "Bad" << "\n";
  else if(60<=n&&n<=89) cout << "Good" << "\n";
  else if(90<=n&&n<=99) cout << "Great" << "\n";
  else cout << "Perfect" << "\n";
  return 0;
}
