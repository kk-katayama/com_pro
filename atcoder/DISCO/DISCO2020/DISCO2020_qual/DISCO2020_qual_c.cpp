#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i,h){
    cin >> s[i];
  }

  vector<vector<int>> res(h,vector<int>(w,0));
  int cnt=0;
  int kk=1;
  rep(i,h){
    bool f=true;
    rep(j,w){
      if(s[i][j]=='#'){
	if(f){
	  rep(l,j+1){
	    res[i][l]=kk;
	  }
	  f=false;	  
	}
	else{
	  kk++;
	  res[i][j]=kk;
	}
      }
      else{
	if(!f){
	  res[i][j]=kk;
	}
      }
    }
    if(f){
      cnt++;
    }
    else{
      rep1(l,cnt){
    	rep(j,w){
    	  res[i-l][j]=res[i][j];
    	}
      }
      cnt=0;
      kk++;
    }
  }
  if(cnt!=0){
    rep1(i,cnt){
      rep(j,w){
	res[h-1-cnt+i][j]=res[h-1-cnt][j];
      }
    }

  }

  
  rep(i,h){
    rep(j,w){
      cout <<  res[i][j] << " ";
    }
    cout  << "\n";
  }
  
  
  return 0;
}
