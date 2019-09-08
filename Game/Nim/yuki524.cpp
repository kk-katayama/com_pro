#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll n;
int main()
{
  cin >> n;
  cout << ((n+1)%4?"O":"X") << "\n";
  return 0;
}
