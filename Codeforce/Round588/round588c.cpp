#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

struct Graph{
  int node;
  vector<vector<int>> edge;
  vector<vector<int>> emat;

  Graph(int n){
    node = n;
    edge.resize(node);
  }

  void add(int from,int to){
    edge[from].push_back(to);
  }

  void make_mat(){
    emat.assign(node,vector<int>(node,0));
    rep(i,node){
      for(auto& v:edge[i]){
	emat[i][v]=1;
      }
    }
  }

  void show_mat(){
    rep(i,node){
      rep(j,node){
	cout << emat[i][j] << " ";
      }
      cout  << "\n";
    }
  }
  
};
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m) cin >> a[i] >> b[i];
  rep(i,m){ a[i]--;b[i]--; }

  
  Graph gp(7);
  rep(i,m){
    gp.add(a[i],b[i]);
    gp.add(b[i],a[i]);    
  }

  
  gp.make_mat();

  vector<vector<int>> mat = gp.emat;

  rep(i,7){
    bool f=true;
    rep(j,7){
      if(mat[i][j]==1){
	f=false;
	break;
      }
    }
    if(f){
      cout << m << "\n";
      return 0;
    }
  }


  int res=0;
  rep(i,7){
    rep(j,7){
      if(mat[i][j]==1){
	int cnt=0;
	rep(k,7){
	  if(i==k||j==k) continue;
	  if(mat[i][k]==1&&mat[j][k]==1) cnt++;
	}
	res=max(res,m-cnt);
      }
    }
  }
  
  cout << res << "\n";
  
  return 0;
}
