#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct KMP{
  string s;
  int n;
  vector<int> table;
  
  KMP(string _s)
  {
    s = _s;
    n = s.size();
  }
  //kmpテーブルの作成
  void make_kmp_table(string p)
  {
    int ps = p.size();
    table.resize(ps+1);
    table[0] = -1;
    int j = -1;
    rep(i,ps){
      while(j>=0&&p[i]!=p[j]) j = table[j];
      j++;
      table[i+1] = j;
    }
  }
  //kmp法
  int kmp_search(string p)
  {
    int res;
    make_kmp_table(p);
    int ps = p.size();
    bool f = false;
    int i = 0,j = 0;
    while(i<n){
      while(s[i]==p[j]){
	i++;j++;
	if(j==ps){
	  f = true;
	  res = i-j;
	  break;
	}
	if(i==n) break;      
      }
      if(j==0) i++;
      else j = table[j];
    }
    return f?res:-1;
  }

  int kmp_count(string p)
  {
    int res = 0;
    make_kmp_table(p);
    int ps = p.size();
    int i = 0,j = 0;
    while(i<n){
      while(s[i]==p[j]){
	i++;j++;
	if(j==ps){
	  res++;
	}
	if(i==n) break;      
      }
      if(j==0)	i++;
      else j = table[j];
    }
    return res;
  }

};
int main()
{
  string s;
  cin >> s;
  KMP kmp(s);

  int m;
  cin >> m;

  vector<string> c(m);
  rep(i,m) cin >> c[i];

  int res = 0;
  rep(i,m){
    res += kmp.kmp_count(c[i]);
  }

  cout << res << "\n";
  
  return 0;
}
