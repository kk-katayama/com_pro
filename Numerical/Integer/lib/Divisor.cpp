//return x's divisor as vector
vector<int> divisor(int x){
  vector<int> res;
  for(int i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(n/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}
