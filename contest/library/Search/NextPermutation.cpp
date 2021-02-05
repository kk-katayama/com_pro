
vector<int> vec(n);
sort(vec.begin(), vec.end());

// vectorの全並び替えを全探索
do{
  // rep(i,n) cout << vec[i] << " ";
  // cout  << "\n";
} while(next_permutation(vec.begin(), vec.end()));
	      
