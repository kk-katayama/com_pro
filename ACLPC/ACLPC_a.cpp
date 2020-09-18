#include <iostream>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main(int argc, char *argv[])
{
  int n,q; cin >> n >> q;
  dsu d(n);
  while(q-- > 0) {
    int t,u,v; cin >> t >> u >> v;
    if(t == 0) {
      d.merge(u, v);
    }
    else {
      cout << (d.same(u, v) ? 1 : 0) << "\n";
    }
  }
  return 0;
}
