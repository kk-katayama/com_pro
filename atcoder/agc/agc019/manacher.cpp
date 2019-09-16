#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  string s;
  cin >> s;
  int n = s.size();
  string p(2*n+1,'A');
  rep(i,n) p[2*i+1] = s[i];
  cout << p << "\n";

  vector<int> r(2*n+1,0);
  int cent = 0;
  while(cent<2*n+1){//palindrome
    cout << cent << "\n";
    int i=cent+1,j=cent-1,cnt=0;
    if(i==2*n+1||j==-1){
      cent++;
      continue;
    }
    while(p[i]==p[j]){
      cnt++;
      ++i;--j;
      if(i==2*n+1||j==-1) break;
    }
    if(cnt>=2){
      r[cent] = cnt;
      bool f = true;
      int k=1;
      while(k<=cnt){
	if(r[cent-k]==0){
	  k++;
	  continue;
	}
	if(r[cent-k]<cnt-k){
	  r[cent+k] = r[cent-k];
	  k++;
	}
	else if(r[cent-k]>cnt-k){
	  r[cent+k] = cnt-k;
	  k++;
	}
	else{
	  cent += k;
	  break;
	}
      }
      if(k>cnt) cent++;
    }
    else cent++;
  }

  rep(i,2*n+1){
    cout << i << " " << r[i] << "\n";

  }
  return 0;
}
