// ランレングス圧縮.配列の連続している要素をまとめてしまう圧縮.
vector<pair<ll,int>> rle(vector<ll> a){
  vector<pair<ll,int>> res;
  int n = a.size();
  int cnt = 1;
  pair<ll,int> p;
  p.first = a[0];
  rep(i,n-1){
    if(a[i]==a[i+1]){
      cnt++;
    }
    else{
      p.second = cnt;
      res.push_back(p);
      cnt = 1;
      p.first = a[i+1];
    }
  }
  p.second = cnt;
  res.push_back(p);
  return res;
}