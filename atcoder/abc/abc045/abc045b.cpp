#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<string> s(3);
  rep(i,3){
    cin >> s[i];
  }
  vector<int> cnt(3,0);
  vector<int> n(3);
  rep(i,3){
    n[i] = s[i].size();
  }
  int num=0;
  int nextnum;
  while(1){
    if(cnt[num]==n[num]){
      if(num==0){
	cout << "A" << "\n";
      }
      else if(num==1){
	cout << "B" << "\n";
      }
      else{
	cout << "C" << "\n";
      }
      break;
    }
    //    cout << num << "\n";
    if(s[num][cnt[num]]=='a'){
      nextnum = 0;
    }
    else if(s[num][cnt[num]]=='b'){
      nextnum = 1;
    }
    else{
      nextnum = 2;
    }
    cnt[num]++;
    num = nextnum;
  }
  return 0;
}
