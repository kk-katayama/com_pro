#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
int a,b,c;
int main()
{
  cin >> a >> b >> c;
  cout << max(c-(a-b) , 0) << "\n";
  return 0;
}
