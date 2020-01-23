#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
vector<vector<int>> arr(10);
bool C(int x,int y,int i){
  return y<arr[i][x];
}
int upper(int l,int r,int y,int i){//条件を満たす中で最小のものを返す
  int lb=l-1,ub=r;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid,y,i)) ub=mid;
    else lb=mid;
  }
  return ub;
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  rep(i,10){
    arr[i].push_back(-1);
  }
  rep(i,n){
    int num=s[i]-'0';
    arr[num].push_back(i);
  }
  const int inf=1e+9;
  rep(i,10){
    arr[i].push_back(inf);
  }


  int cnt=0;
  rep(i,10){
    rep(j,10){
      rep(k,10){
	if(arr[i].size()==2||arr[j].size()==2||arr[k].size()==2) continue;
	int ii=upper(0,arr[i].size()-1,-1,i);
	if(arr[i][ii]==inf) continue;
	int jj=upper(0,arr[j].size()-1,arr[i][ii],j);
	if(arr[j][jj]==inf) continue;
	int kk=upper(0,arr[k].size()-1,arr[j][jj],k);
	if(arr[k][kk]!=inf){
	  cnt++;
	}
      }
    }
  }

  cout << cnt << "\n";
  
  return 0;
}
