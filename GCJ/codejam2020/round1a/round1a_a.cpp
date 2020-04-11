#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
string check_back(string s, string t) {
  int ss = s.size();
  int ts = t.size();
  if(ss < ts) {
    if(t.substr(ts-ss, ss) == s) return t;
    else return "bad";
  }
  else if(ss > ts) {
    if(s.substr(ss-ts, ts) == t) return s;
    else return "bad";
  }
  else {
    if(s == t) return s;
    else return "bad";
  }
}

string check_front(string s, string t) {
  int ss = s.size();
  int ts = t.size();
  if(ss < ts) {
    if(t.substr(0, ss) == s) return t;
    else return "bad";
  }
  else if(ss > ts) {
    if(s.substr(0, ts) == t) return s;
    else return "bad";
  }
  else {
    if(s == t) return s;
    else return "bad";
  }
}

string merge_str(string s,string t) {
  int ss = s.size();
  int ts = t.size();
  string res;
  if(ss <= ts) {
    rep(i,ss+1) {
      bool f = true;
      rep(j,ss-i) {
	if(s[i+j] != t[j]) {
	  f = false; break;
	}
      }
      if(f) {
	res = s.substr(0,i) + t;
	break;
      }
    }
  }
  else {
    for(int i = ts;i >= 0;--i) {
      bool f = true;
      rep(j, i) {
	if(s[ss - i + j] != t[j]) {
	  f = false; break;
	}
      }
      if(f) {
	res = s.substr(0, ss - i) + t;
	break;
      }
    }
  }
  return res;
}

int main()
{
  int t;cin >> t;
  vector<int> n(t);
  vector<vector<string>> p(t);
  rep(i,t) {
    cin >> n[i];
    p[i].resize(n[i]);
    rep(j,n[i]) cin >> p[i][j];
  }

  // string x = "";
  // string y = "rnb";
  // cout << check_back(y,x) << "\n";

  vector<string> res(t);
  rep(i,t) {
    string left = "", right = "";
    rep(j,n[i]) {
      if(p[i][j][0] == '*') {
	right = check_back(p[i][j].substr(1, p[i][j].size()-1), right);
      }
      else if(p[i][j][ p[i][j].size()-1 ] == '*') {
	left = check_front(p[i][j].substr(0, p[i][j].size()-1), left);
      }
      else {
	int index;
	rep(k,p[i][j].size() ) {
	  if(p[i][j][k] == '*' ) {
	    index = k; break;
	  }
	}
	left = check_front(left, p[i][j].substr(0, index));
	right = check_back(right, p[i][j].substr(index+1, p[i][j].size() - 1 - index));
      }
      //      cout << left << ":" << right << "\n";
      if(left == "bad" || right == "bad") {
	res[i] = "*";
	break;
      }
    }
    //    cout << left << ":" << right << "\n";
    if(left == "bad" || right == "bad") {
      res[i] = "*";
    }
    else if(left.size() + right.size() <= 104) {
      res[i] = left + right;
    }
    // else {
    //   res[i] = merge_str(left, right);
    //   if(res[i].size() > 104) res[i] = "*";
    // }
  }

  rep(i,t) {
    cout <<  "Case #" << i+1 << ": " << res[i] << "\n";
  }
  
  return 0;
}
