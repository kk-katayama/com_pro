#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
ll fact[25];
int main()
{
  string s;cin >> s;
  int n = s.size();

  fact[0] = 1;
  rep1(i,20) {
    fact[i] = (ll)i * fact[i-1];
  }

  string t = s;
  sort(t.begin(), t.end());
  int index = 0;
  map<char,int> mp;
  int cnt = 1;
  vector<int> num;
  rep(i,n-1) {
    if(t[i] == t[i+1]) cnt++;
    else {
      num.push_back(cnt);
      cnt = 1;
      mp[t[i]] = index++;
    }
  }
  num.push_back(cnt);
  mp[t[n-1]] = index;
  vector<int> sum(num.size() + 1);
  sum[0] = 0;
  rep(i,num.size()) {
    sum[i+1] = sum[i] + num[i];
  }
  
  
  ll res = 0;
  rep(i,n) {
    index = mp[s[i]];
    for(int j = index - 1; j >= 0; --j) {
      ll tmp = fact[n - i - 1];
      if(num[j] == 0) continue;
      rep(k, num.size()) {
	if(j == k) tmp /= fact[ num[k] - 1 ];
	else tmp /= fact[ num[k] ];
      }
      res += tmp;      
    }
    num[index]--;
  }
  cout << res+1 << "\n";
  
  return 0;
}
