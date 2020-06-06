#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,a,b,c; cin >> n >> a >> b >> c;
  vector<string> s(n);
  rep(i,n) {
    cin >> s[i];
  }

  vector<char> res(n);
  if(a+b+c <= 1) {
    rep(i,n) {
      if(s[i] == "AB") {
	if(a == 0 && b == 0) {
	  cout << "No" << "\n";
	  return 0;
	}
	else if(a == 0) {
	  a++; b--;
	  res[i] = 'A';
	}
	else {
	  a--; b++;
	  res[i] = 'B';
	}
      }
      else if(s[i] == "AC") {
	if(a == 0 && c == 0) {
	  cout << "No" << "\n";
	  return 0;
	}
	else if(a == 0) {
	  a++; c--;
	  res[i] = 'A';
	}
	else {
	  a--; c++;
	  res[i] = 'C';
	}
      }
      if(s[i] == "BC") {
	if(c == 0 && b == 0) {
	  cout << "No" << "\n";
	  return 0;
	}
	else if(c == 0) {
	  c++; b--;
	  res[i] = 'C';
	}
	else {
	  c--; b++;
	  res[i] = 'B';
	}
      }      
    }
    cout << "Yes" << "\n";
    rep(i,n) {
      cout << res[i] << "\n";
    }
  }
  else if(a+b+c <= 2){
    rep(i,n) {
      if(s[i] == "AB") {
	if(a > b) {
	  a--; b++; res[i] = 'B';
	}
	else if(a < b) {
	  a++; b--; res[i] = 'A';	
	}
	else if(a == 1 && b == 1) {
	  if(i == n-1) {
	    a++; b--; res[i] = 'A';		  
	  }
	  else {
	    if(s[i+1] == "AC") {
	      a++; b--; res[i] = 'A';
	    }
	    else if(s[i+1] == "BC") {
	      a--; b++; res[i] = 'B';	    
	    }
	    else {
	      a++; b--; res[i] = 'A';
	    }
	  }
	}
	else {
	  cout << "No" << "\n";
	  return 0;
	}
      }
      else if(s[i] == "AC") {
	if(a > c) {
	  a--; c++; res[i] = 'C';
	}
	else if(a < c) {
	  a++; c--; res[i] = 'A';	
	}
	else if(a == 1 && c == 1) {
	  if(i == n-1) {
	    a++; c--; res[i] = 'A';		  
	  }
	  else {
	    if(s[i+1] == "AB") {
	      a++; c--; res[i] = 'A';
	    }
	    else if(s[i+1] == "BC") {
	      a--; c++; res[i] = 'C';	    
	    }
	    else {
	      a++; c--; res[i] = 'A';
	    }
	  }
	}
	else {
	  cout << "No" << "\n";
	  return 0;
	}
      }
      else if(s[i] == "BC") {
	if(c > b) {
	  c--; b++; res[i] = 'B';
	}
	else if(c < b) {
	  c++; b--; res[i] = 'C';	
	}
	else if(c == 1 && b == 1) {
	  if(i == n-1) {
	    c++; b--; res[i] = 'C';		  
	  }
	  else {
	    if(s[i+1] == "AC") {
	      c++; b--; res[i] = 'C';
	    }
	    else if(s[i+1] == "AB") {
	      c--; b++; res[i] = 'B';	    
	    }
	    else {
	      c++; b--; res[i] = 'C';
	    }
	  }
	}
	else {
	  cout << "No" << "\n";
	  return 0;
	}
      }
    }
    cout << "Yes" << "\n";
    rep(i,n) cout << res[i] << "\n";
  }
  else {
    rep(i,n) {
      if(s[i] == "AB") {
	if(a == 0 && b == 0) {
	  cout << "No" << "\n";
	  return 0;
	}
	else {
	  if(a > b) {
	    a--; b++; res[i] = 'B';
	  }
	  else {
	    a++; b--; res[i] = 'A';
	  }
	}
      }
      else if(s[i] == "AC") {
	if(a == 0 && c == 0) {
	  cout << "No" << "\n";
	  return 0;
	}
	else {
	  if(a > c) {
	    a--; c++; res[i] = 'C';
	  }
	  else {
	    a++; c--; res[i] = 'A';
	  }
	}
      }
      else if(s[i] == "BC") {
	if(c == 0 && b == 0) {
	  cout << "No" << "\n";
	  return 0;
	}
	else {
	  if(c > b) {
	    c--; b++; res[i] = 'B';
	  }
	  else {
	    c++; b--; res[i] = 'C';
	  }
	}
      }      
    }
    cout << "Yes" << "\n";
    rep(i,n) {
      cout << res[i] << "\n";
    }
  }

  return 0;
}
