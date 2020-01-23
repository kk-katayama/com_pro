#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<pair<int,int>> date(n);
  rep(i,n){
    char c;
    cin >> date[i].first;
    cin >> c;
    cin >> date[i].second;
  }
  sort(date.begin(), date.end());

  vector<int> mond={31,29,31,30,31,30,31,31,30,31,30,31};
  vector<int> cum(13);
  cum[0]=0;
  rep(i,12){
    cum[i+1]=cum[i]+mond[i];
  }
  vector<bool> day(366,false);
  rep(i,366){
    if(i%7==0||i%7==6){
      day[i] = true;
    }
  }

  rep(i,n){
    int d=cum[date[i].first-1]+date[i].second-1;
    int k=0;
    while(day[d+k]) k++;
    if(d+k==366) continue;
    day[d+k] = true;
  }

  int res=0;
  int cnt=0;
  rep(i,366){
    if(day[i]){
      res = max(res,++cnt);
    }
    else{
      cnt=0;
    }
  }

  cout << res << "\n";
  
  return 0;
}
