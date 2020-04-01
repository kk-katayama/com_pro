#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w;
  cin >> h >> w;
  int hh = h;
  int ww = w;
  
  vector<vector<int>> res(h,vector<int>(w));
  if(h==1){
    if(w%7==2||w%7==0){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(w>0){
	if(cnt%2==0){
	  w -=2;
	  rep(i,2) res[0][num++] = 2;
	}
	else{
	  w -= 5;
	  rep(i,5) res[0][num++] = 5;	  
	}
	cnt++;
      }
    }
    else if(w%7==5){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(w>0){
	if(cnt%2==1){
	  w -=2;
	  rep(i,2) res[0][num++] = 2;
	}
	else{
	  w -= 5;
	  rep(i,5) res[0][num++] = 5;	  
	}
	cnt++;
      }
    }    
    else{
      cout << "No" << "\n";
      return 0;
    }
  }
  else if(h==2){
    if(w%7==0||w%7==1){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(w>0){
	if(cnt%2==0){
	  w -=1;
	  res[0][num] = 2;
	  res[1][num] = 2;
	  num++;
	}
	else{
	  w -= 6;
	  res[0][num]=5;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=2;
	  res[0][num]=2;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=5;	  
	}
	cnt++;
      }
    }
    else if(w%7==6){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(w>0){
	if(cnt%2==1){
	  w -=1;
	  res[0][num] = 2;
	  res[1][num] = 2;
	  num++;
	}
	else{
	  w -= 6;
	  res[0][num]=5;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=2;
	  res[0][num]=2;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=5;
	  res[0][num]=5;
	  res[1][num++]=5;	  
	}
	cnt++;
      }
    }    
    else{
      cout << "No" << "\n";
      return 0;
    }    
  }
  else if(h==3&&w==3){
    cout << "Yes" << "\n";
    res.assign(3,vector<int>(3,5));
    res[0][0]=2;
    res[0][1]=2;
    res[2][1]=2;
    res[2][2]=2;
  }
  else if(w==1){
    if(h%7==2||h%7==0){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(h>0){
	if(cnt%2==0){
	  h -=2;
	  rep(i,2) res[num++][0] = 2;
	}
	else{
	  h -= 5;
	  rep(i,5) res[num++][0] = 5;	  
	}
	cnt++;
      }
    }
    else if(h%7==5){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(h>0){
	if(cnt%2==1){
	  h -=2;
	  rep(i,2) res[num++][0] = 2;
	}
	else{
	  h -= 5;
	  rep(i,5) res[num++][0] = 5;	  
	}
	cnt++;
      }
    }
    else{
      cout << "No" << "\n";
      return 0;
    }
  }
  else if(w==2){
    if(h%7==0||h%7==1){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(h>0){
	if(cnt%2==0){
	  h -=1;
	  res[num][0] = 2;
	  res[num][1] = 2;
	  num++;
	}
	else{
	  h -= 6;
	  res[num][0]=5;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=2;
	  res[num][0]=2;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=5;	  
	}
	cnt++;
      }
    }
    else if(h%7==6){
      cout << "Yes" << "\n";
      int cnt=0;
      int num=0;
      while(h>0){
	if(cnt%2==1){
	  h -=1;
	  res[num][0] = 2;
	  res[num][1] = 2;
	  num++;
	}
	else{
	  h -= 6;
	  res[num][0]=5;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=2;
	  res[num][0]=2;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=5;
	  res[num][0]=5;
	  res[num++][1]=5;	  
	}
	cnt++;
      }
    }    
    else{
      cout << "No" << "\n";
      return 0;
    }    
  }
  else{
    cout << "No" << "\n";
    return 0;
  }
  rep(i,hh){
    rep(j,ww){
      cout << res[i][j];
    }
    cout  << "\n";
  }      


  
  return 0;
}
