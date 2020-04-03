#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
//k以上である要素のうち最小のもののインデックスを求める
int n;
vector<int> a;
int upper_bound(int k){
  int left=-1,right=a.size();
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[mid]>=k) right=mid;
    else left=mid;
  }
  return a[right];
}

int main()
{
  int m;cin >> n >> m;
  string s;cin >> s;
  rep(i,n+1) {
    if(s[i] == '0') a.push_back(i);
  }
  int index = n;
  vector<int> res;
  while(index > 0) {
    int next = upper_bound(index - m);
    if(next >= index) {
      cout << -1 << "\n";
      return 0;
    }
    else {
      res.push_back(index - next);
    }
    index = next;
  }
  reverse(res.begin(), res.end());
  rep(i,res.size()) cout << res[i] << " ";
  cout << "\n";
  return 0;
}
