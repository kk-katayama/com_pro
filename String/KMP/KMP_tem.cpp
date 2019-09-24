#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct STR
{
  string s;
  int sl;
  vector<int> table;
  
  STR(string _s)
  {
    s = _s;
    sl = s.size();
  }
  
  void kmp_table(string t)
  {
    int tl = t.size();
    table.resize(tl+1);
    table[0] = -1;
    int i = 1;
    int j = 0;
    int cnt = 0;
    while(1){
      while(t[i]==t[j]){
	cnt++;
	table[i] = ((t[0]==t[i])?-1:0);
	++i;
	if(i == tl){
	  table[i] = cnt;
	  break;
	}
	++j;
      }
      if(i == tl){
	break;
      }
      table[i] = ((t[0]==t[i])?-1:cnt);    
      cnt = 0;
      ++i;
      if(i == tl){
	table[i] = cnt;
	break;
      }
      j = 0;
    }
  }

  int kmp(string t)
  {
    int tl = t.size();
    if(tl > sl) return 0;
    kmp_table(t);

    int cnt = 0;
    int i = 0;
    int j = 0;
    while(1){
      while(s[i] == t[j]){
	++j;
	if(j==tl){
	  ++cnt;
	  j = table[j];
	}
	++i;
	if(i == sl){
	  return cnt;
	}
      }
      if(table[j] == -1){
	++i;
	if(i == sl){
	  return cnt;
	}
	j = 0;
      }
      else{
	j = table[j];
      }
    }
    return cnt;
  }
};
int main()
{
  string s;
  cin >> s;

  int m;
  cin >> m;
  vector<string> t(m);
  rep(i,m) cin >> t[i];
  
  STR st(s);

  int res = 0;
  rep(i,m){
    res += st.kmp(t[i]);
    //    cout << st.kmp(t[i]) << "\n";
  }
  cout << res << "\n";

  
  
  return 0;
}
