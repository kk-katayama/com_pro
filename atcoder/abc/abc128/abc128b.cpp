#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<string> s(n);
  vector<int> p(n);
  rep(i,n) cin >> s[i] >> p[i];

  using psii = pair<pair<string,int>,int>;
  vector<psii> vec(n);
  rep(i,n) {
    vec[i] = { {s[i], p[i]}, i+1};
  }

  sort(vec.begin(), vec.end(), [](psii a, psii b) {
				 if(a.first.first == b.first.first) return a.first.second > b.first.second;
				 else return a.first.first < b.first.first;
			       });

  rep(i,n) cout << vec[i].second << "\n";
  
  return 0;
}
