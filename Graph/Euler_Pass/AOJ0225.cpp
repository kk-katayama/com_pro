#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph{
  int node;
  vector<vector<int>> edge;

  Graph(int _node){
    node = _node;
    edge.resize(node);
    rep(i,node) edge[i].resize(0);
  }

  void add(int from,int to){
    edge[from].push_back(to);
  }

  bool Euler_Check(){
    bool f = true;
    rep(i,node){
      f = f && !(edge[i].size()&1);	
    }
    return f;
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
  while(1){
    int n;
    cin >> n;
    if(n==0) break;
    vector<string> w(n);
    rep(i,n) cin >> w[i];
    Graph gr(26);
    rep(i,n){
      char fr = *w[i].begin();
      char ba = *(w[i].end()-1);
      int ifr = fr - 'a';
      int iba = ba - 'a';
      gr.add(ifr,iba);
      gr.add(iba,ifr);
    }
    res.push_back(gr.Euler_Check());
  }

  rep(i,res.size()){
    cout << (res[i]?"OK":"NG") << "\n";
  }
  return 0;
}
