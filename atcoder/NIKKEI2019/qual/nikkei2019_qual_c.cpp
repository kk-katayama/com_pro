#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<int> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  using pi = pair<int,int>;
  vector<pi> pa(n), pb(n);
  rep(i,n) {
    pa[i] = {a[i], i};
    pb[i] = {b[i], i};
  }
  sort(pa.begin(), pa.end());
  sort(pb.begin(), pb.end());

  vector<int> atos(n), btos(n);
  rep(i,n) atos[pa[i].second] = i;
  rep(i,n) btos[pb[i].second] = i;

  
  vector<int> vec(n-1, 0);
  rep(i,n-1) if(pa[i+1].first > pb[i].first) vec[i]++;

  vector<int> asum(n), bsum(n);
  asum[0] = 0;
  bsum[0] = 0;
  rep(i,n-1) asum[i+1] = asum[i] + (int)(pa[i+1].first > pb[i].first);
  rep(i,n-1) bsum[i+1] = bsum[i] + (int)(pa[i].first > pb[i+1].first);
  
  rep(i,n) {
    if(pa[i].first > pb[i].first) {
      cout << "No" << "\n";
      return 0;
    }
  }

  rep(i,n) {
    int si = atos[i];
    int sj = btos[i];
    if(a[i] <= b[i]) {
      if(si <= sj && asum[sj] - asum[si] == 0) {
	cout << "Yes" << "\n";
	return 0;	  	
      }
      else if(si > sj && bsum[si] - bsum[sj] == 0) {
	cout << "Yes" << "\n";
	return 0;	  		
      }
    }
  }

  rep(i,n) {
    rep(j,n) {
      if(i == j) continue;
      if(a[i] <= b[j] && a[j] <= b[i]) {
	int si = atos[i], sj = btos[j];
	int ti = atos[j], tj = btos[i];

	if(si <= sj && asum[sj] - asum[si] == 0) {
	  if(ti <= tj && asum[tj] == asum[ti]) {
	    cout << "Yes" << "\n";
	    return 0;	  		    
	  }
	  else if(ti > tj && bsum[ti] - bsum[tj] == 0) {
	    cout << "Yes" << "\n";
	    return 0;	  		    	    
	  }
	}
	else if(si > sj && bsum[si] - bsum[sj] == 0) {
	  if(ti <= tj && asum[tj] - asum[ti]) {
	    cout << "Yes" << "\n";
	    return 0;	  		    
	  }
	  else if(ti > tj && bsum[ti] - bsum[tj] == 0) {
	    cout << "Yes" << "\n";
	    return 0;	  		    	    
	  }	  
	}
      }
    }
  }
  
  cout << "No" << "\n";
  
  return 0;
}
