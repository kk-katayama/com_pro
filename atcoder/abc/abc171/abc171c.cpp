#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n; cin >> n;
  ll x = 26;
  vector<char> res;
  while(n > 0) {
    ll y = n % 26;
    char c = 'a' + y - 1;
    if(y == 0) c = 'z';
    res.push_back(c);
    n /= 26;
    if(y == 0) n--;
  }

  
  reverse(res.begin(), res.end());
  for(auto val: res) cout << val;
  cout  << "\n";


  
  return 0;
}
