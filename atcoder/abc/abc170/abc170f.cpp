#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int h,w,k; cin >> h >> w >> k;
  vector<int> s(4);
  rep(i,4) {
    cin >> s[i];
    s[i]--;
  }
  vector<vector<char>> c(h, vector<char>(w));
  rep(i,h) rep(j,w) cin >> c[i][j];

  using pi = pair<int,int>;
  using pii = pair<int,pi>;  
  queue<pi> q;  
  q.push({s[0], s[1]});
  vector<vector<int>> d(h, vector<int>(w, -1));
  d[s[0]][s[1]] = 0;
  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};
  while( !q.empty() ) {
    pi p = q.front(); q.pop();
    int x = p.first, y = p.second;
    rep(i,4) {
      rep1(j,k) {	
	int nx = x + dx[i]*j;
	int ny = y + dy[i]*j;
	if(0 <= nx && nx < h && 0 <= ny && ny < w) {
	  if(c[nx][ny] == '@') break;
	  if(d[nx][ny] == d[x][y] + 1) continue;
	  if(0 <= d[nx][ny]) break;
	  d[nx][ny] = d[x][y] + 1;
	  q.push({nx, ny});
	}
	else break;
      }
    }	  
  }

  // rep(i,h) {
  //   rep(j,w) cout << d[i][j] << " ";
  //   cout << "\n";
  // }
  
  cout << d[s[2]][s[3]] << "\n";
  
  return 0;
}
