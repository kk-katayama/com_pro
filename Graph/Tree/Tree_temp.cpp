class Tree{
private:
  int n;//number of node
  int m;
  vector<vector<int>> edge;// edge does not have cost.
  vector<vector<pair<int,int>>> edge2;// edge has cost.
public:  
  //*****Constructor************
  Tree(int n_){
    n = n_;
    edge.resize(n);
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b){
    n = n_;
    m = m_;
    edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);
    }
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b,vector<int> c){
    n = n_;
    m = m_;
    edge2.resize(n);
    rep(i,m){
      edge2[a[i]].push_back(make_pair(b[i],c[i]));
      edge2[b[i]].push_back(make_pair(a[i],c[i]));
    }
  }  
  //*******************************************
};


