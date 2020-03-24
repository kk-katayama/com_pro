#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
//**********************************************************************************
// KMP法、文字列sの中から文字列tと一致する部分があるかを判定。あるならその文字列が始まる位置を返す
vector<int> table;
void kmp_table(string t){
  int ts = t.size();
  table.resize(ts+1);
  table[0] = -1;
  int j = -1;
  rep(i,ts){
    while(j>=0&&t[i]!=t[j]) j = table[j];
    j++;
    table[i+1] = j;
  }
}

vector<int> kmp(string s,string t){
  vector<int> res;
  kmp_table(t);
  int ss = s.size(),ts = t.size();
  bool f = false;
  int i = 0,j = 0;
  while(i<ss){
    while(s[i]==t[j]){
      i++;j++;
      if(j==ts){
	f = true;
	res.push_back(i-j);
	break;
      }
      if(i==ss) break;
    }
    if(j==0) i++;
    else j = table[j];
  }
  return res;
}
//*************************************************************************************
int main()
{
  string s,t;cin >> s >> t;
  vector<int> res = kmp(s,t);
  rep(i,res.size()) cout << res[i] << "\n";
  
  return 0;
}
