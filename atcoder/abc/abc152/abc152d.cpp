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
  int x = stoi(s);
  ll cnt = 0;
  rep1(i,x){
    string ss = to_string(i);
    string tt = ss;
    reverse(ss.begin(), ss.end());
    if(ss[0]=='0') continue;
    int y = stoi(ss);
    //    cout << y << "\n";
    if(i>y){
      // if(ss[0]==ss[ss.size()-1]){
      // 	cnt+=2;
      // }
      if(ss[0]==ss[ss.size()-1]){
	ll z = 1;
	cnt++;
	if(ss.size()>=2){
	  cnt+=2;
	  rep(j,ss.size()-2){
	    cnt +=2* z;
	    z *= 10;
	  }
	}
	if(ss.size()>=3){
	  string sss = tt.substr(1,tt.size()-2);
	  int xx = stoi(sss);
	  cnt +=2*xx;
	}	
      }
      else{
	ll z = 1;
	rep(j,ss.size()-1){
	  cnt += 2*z;
	  z *= 10;
	}
      }
    }
    else if(i==y){
      cnt++;
      ll z = 1;
      if(ss.size()>=2){
	cnt+=2;
	rep(j,ss.size()-2){
	  cnt += 2*z;
	  z *= 10;
	}
      }
      if(ss.size()>=3){
	string sss = tt.substr(1,tt.size()-2);
	int xx = stoi(sss);
	cnt += 2*xx;
      }
    }
    else{
      if(ss[0]==ss[ss.size()-1]){
	cnt++;
	ll z = 1;
	if(ss.size()>=2){
	  cnt+=2;
	  rep(j,ss.size()-2){
	    cnt += 2*z;
	    z *= 10;
	  }
	}
	if(ss.size()>=3){
	  string sss = tt.substr(1,tt.size()-2);
	  int xx = stoi(sss);
	  cnt += 2*xx;
	}	
      }
      else{
	ll z = 1;
	if(ss.size()>=2){
	  rep(j,ss.size()-2){
	    cnt += 2*z;
	    z *= 10;
	  }
	}
      }
    }
    //    cout << i << ":" << cnt << "\n";
  }
  cout << cnt << "\n";
  return 0;
}
