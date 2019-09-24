#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph{
  int node;
  vector<vector<int>> edge;

  Graph(int _node){
    node = _node;
    edge.resize(node);
  }

  void add(int from,int to){
    edge[from].push_back(to);
  }

  bool Euler_Check(int s,int g){
    bool f = true;
    rep(i,node){
      if(node == s || node == g){
	f = f && (edge[i].size()&1);
      }
      else{
	f = f && !(edge[i].size()&1);	
      }
    }
    return f;
  }

  void reset(int _node){
    edge.resize(0);
    node = _node;
    edge.resize(node);
  }
};
int main()
{
  vector<bool> res(0);
  int a,b;
  Graph gp(100);  
  while(scanf("%d%d",&a,&b)!=EOF){
    if(a==0&&b==0){
      res.push_back(gp.Euler_Check(0,1));
      gp.reset(100);
    }
    else{
      a--;
      b--;
      gp.add(a,b);
      gp.add(b,a);
    }
  }

  rep(i,res.size()) cout << (res[i]?"OK":"NG") << "\n";
  
  return 0;
}
