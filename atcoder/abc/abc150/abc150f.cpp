#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct STR
{
  vector<int> s;
  int sl;
  vector<int> table;
  
  STR(vector<int> _s)
  {
    s = _s;
    sl = s.size();
  }
  
  void kmp_table(vector<int> t)
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

  vector<int> kmp(vector<int> t)
  {
    vector<int> res;
    int tl = t.size();
    if(tl > sl) return res;
    if(tl==1){
      rep(i,sl){
	if(s[i]==t[0]){
	  res.push_back(i);
	}
      }
      return res;
    }
    kmp_table(t);

    int cnt = 0;
    int i = 0;
    int j = 0;
    while(1){
      while(s[i] == t[j]){
	++j;
	if(j==tl){
	  ++cnt;
	  res.push_back(i-tl+1);
	  j = table[j];
	}
	++i;
	if(i == sl){
	  return res;
	}
      }
      if(table[j] == -1){
	++i;
	if(i == sl){
	  return res;
	}
	j = 0;
      }
      else{
	j = table[j];
      }
    }
    return res;
  }
};


int main()
{
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
  }
  if(n==1){
    cout << 0 << ":" << (a[0]^b[0]) << "\n";
  }
  vector<int> c,d;
  rep(i,2*n-2){
    c.push_back(a[i%n]^a[(i+1)%n]);
    //    cout << a[i%n] << ":" << a[(i+1)%n] << "\n";
  }
  rep(i,n-1){
    d.push_back(b[i]^b[(i+1)%n]);
  }

  // rep(i,c.size()){
  //   cout << c[i] << " ";
  // }
  // cout  << "\n";
  // rep(i,d.size()){
  //   cout << d[i] << " ";
  // }
  // cout  << "\n";  
  
  STR st(c);
  vector<int> res = st.kmp(d);
  //  if(res.size()==0) return 0;
  rep(i,res.size()){
    cout << res[i] << " " << (a[res[i]]^b[0]) << "\n";
  }
  
  return 0;
}
