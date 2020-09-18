// xの約数を列挙する.返り値はvector.O(sqrt(x))
vector<int> divisor(int x){
  vector<int> res;
  for(int i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}
