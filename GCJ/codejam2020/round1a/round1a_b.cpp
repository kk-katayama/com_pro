#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
void walk(int &x, int &y, int size, vector<pair<int,int>> &p, bool f) {
  if(f) {
    bool par = true;
    rep(i, size) {
      p.push_back({x,y});
      rep(j,size - 1 - i) {
	if(par) {
	  x++;
	  p.push_back({x,y});
	}
	else {
	  x--;
	  p.push_back({x,y});
	}
      }
      if(i == size - 1) {
	x++; y++;
      }
      else if(par) {
	y++;
      }
      else {
	x++; y++;
      }
      par = !par;
    }
    while(y <= x) {
      p.push_back({x, y}); y++;
    }
    x++;
  }
  else {
    bool par = true;
    rep(i, size) {
      p.push_back({x,y});
      rep(j,size - 1 - i) {
	if(par) {
	  x++; y++;
	  p.push_back({x,y});
	}
	else {
	  x--; y--;
	  p.push_back({x,y});	
	}
      }
      if(i == size - 1) {
	x++;
      }
      else if(par) {
	y--;
      }
      else {
	x++;
      }
      par = !par;
    }
    while(y >= 1) {
      p.push_back({x, y}); y--;
    }
    x++; y++;
  }
}

int main()
{
  int t;cin >> t;
  vector<int> n(t);
  rep(i,t) cin >> n[i];

  vector<vector<pair<int,int>>> res(t);

  rep(i,t) {
    vector<int> b;
    while(n[i] > 0) {
      b.push_back(n[i] % 2);
      n[i] /= 2;
    }
    // rep(j,b.size()) cout << b[j] << " ";
    // cout  << "\n";
    int cnt = 0;
    vector<int> c;
    rep(j,b.size()) {
      if(b[j] == 1) {
	c.push_back(cnt);
	cnt = 0;
      }
      else {
	cnt++;
      }
    }
    bool f = true;
    int x = 1, y = 1;
    rep(j,c.size() ) {
      if(j % 2 == 0) {
	walk(x, y, c[j], res[i], f);
      }
      else {
	walk(x, y, c[j], res[i], !f);
      }
    }
  }

  rep(i,t) {
    cout << "Case #" << i + 1 << ": " << "\n";
    rep(j,res[i].size()) {
      cout << res[i][j].first << " " << res[i][j].second << "\n";
    }
  }
  
  return 0;
}



