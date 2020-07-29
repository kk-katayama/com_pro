#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  vector<int> h(n);
  rep(i,n) {
    cin >> h[i];
  }

  vector<int> v;
  rep(i,n) {
    int m = v.size();
    cout << m << "\n";
    while(m - 1 >= 0 && v[m-1] < h[i]) {
      v.pop_back();
      m--;
    }
    v.push_back(h[i]);
  }
  
  
  return 0;
}
