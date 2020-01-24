#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int count(vector<int> s,vector<int> t){
  int cnt = 0;
  rep(i,s.size()){
    cnt += abs(s[i]-t[i]);
  }
  return cnt/2;
}
int main()
{
  const int inf = 1e+9;
  int n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  string t = s;
  sort(t.begin(), t.end());

  vector<vector<int>> vec(n,vector<int>(26,0));
  rep(i,n){
    int l = s[i] - 'a';
    for(int j=i;j<n;++j){
      vec[j][l]++;
    }
  }

  vector<char> res(n);
  vector<int> lis = vec[n-1];
  vector<int> ss(26,0);
  int sum=0;
  rep(i,n){
    vector<int> vv(26);
    rep(l,26){
      vv[l] = vec[n-1][l]-vec[i][l];
    }
    rep(j,26){
      if(lis[j]>0){
	lis[j]--;
	ss[j]++;
	char cj = 'a'+j;
	int tmp;
	if(s[i]!=cj){
	  tmp = sum + 1;
	}
	else{
	  tmp = sum;
	}
	int cnt = tmp + count(lis,vv);
	// cout << "count" << ":" << count(lis,vv) << "\n";
	// cout << "tmp" << ":" << tmp << "\n";
	// cout << cnt << "\n";	  
	if(cnt<=k){
	  //	  cout << cnt << "\n";
	  char cc = 'a' + j;
	  res[i] = cc;
	  sum = tmp;
	  break;
	}
	else{
	  lis[j]++;
	  ss[j]--;
	}
      }
    }
  }

  rep(i,n){
    cout << res[i];
  }
  cout << "\n";
  
  // rep(i,n){
  //   cout << i << ":";
  //   rep(j,26){
  //     cout << vec[i][j] << " ";
  //   }
  //   cout  << "\n";
  // }
  
  return 0;
}
