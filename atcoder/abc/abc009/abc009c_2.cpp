#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  const int inf = 1e+9;
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  string t = s;
  vector<bool> f(n,false);
  string ss = s;  
  sort(t.begin(), t.end());
  int c = 0;
  rep(i,n){
    if(s[i]==t[i]){
      continue;
    }
    else{
      if(k-c>=2){
	for(int j=n-1;j>i;--j){
	  if(t[i]==s[j]){
	    if(!f[i]&&!f[j]){
	      c += 2;
	      char tmp = s[i];
	      s[i] = s[j];
	      s[j] = tmp;
	      f[i] = true;
	      f[j] = true;
	    }
	    else if(!f[i]){
	      c += 1;
	      char tmp = s[i];
	      s[i] = s[j];
	      s[j] = tmp;	      
	      f[i] = true;
	    }
	    else if(!f[j]){
	      c += 1;
	      char tmp = s[i];
	      s[i] = s[j];
	      s[j] = tmp;	      
	      f[j] = true;	      
	    }
	    else{
	      char tmp = s[i];
	      s[i] = s[j];
	      s[j] = tmp;	      
	    }
	    break;
	  }
	}
      }
      else if(k-c==1){
	if(f[i]){
	  int in = inf;
	  for(int j=n-1;j>i;--j){
	    if(t[i]==s[j]){
	      if(f[j]){
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		in = inf;
		break;
	      }
	      else{
		in = j;
	      }
	    }
	  }
	  if(in!=inf){
	    f[in] = true;
	    c++;
	    char tmp = s[i];
	    s[i] = s[in];
	    s[in] = tmp;	    
	  }
	}
	else{
	  int in = inf;
	  char cc = 'z' + 1;
	  for(int j=n-1;j>i;--j){
	    if(s[i]>s[j]&&f[j]){
	      if(cc>s[j]){
		in = j;
		cc = s[j];
	      }
	    }
	  }
	  if(in==inf){
	    continue;
	  }
	  char tmp = s[i];
	  s[i] = s[in];
	  s[in] = tmp;	      
	  c++;
	  f[i] = true;
	}
      }
      else if(k==c){
	if(f[i]){
	  int in = inf;
	  char cc = 'z' + 1;
	  for(int j=n-1;j>i;--j){
	    if(s[i]>s[j]&&f[j]){
	      if(cc>s[j]){
		in = j;
		cc = s[j];
	      }
	    }
	  }
	  if(in==inf){
	    continue;
	  }
	  char tmp = s[i];
	  s[i] = s[in];
	  s[in] = tmp;	      
	}
      }
    }
    // cout << s << "\n";
    // cout << c << "\n";
    // rep(i,n){
    //   cout << f[i] << " ";
    // }
    // cout  << "\n";    
  }

  cout << s << "\n";

  // char xx = 'z' + 1;
  // cout << xx << "\n";

  // rep(i,n){
  //   cout << f[i] << " ";
  // }
  // cout  << "\n";
  int cnt=0;
  rep(i,n){
    if(s[i]!=ss[i]){
      cnt++;
    }
  }
  //  cout << cnt << "\n";
  
  return 0;
}
