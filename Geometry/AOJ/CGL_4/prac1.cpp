#include <TApplication.h>
#include <TCanvas.h>
#include <TH1.h>

#include <TArc.h>
#include <TLine.h>

#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
  TApplication app("app", &argc, argv);
  TCanvas *c = new TCanvas("c", "test", 500, 500);
  TH1 *frame = c->DrawFrame(-10001.0, -10001.0, 10000.0, 10000.0);

  int n; cin >> n;
  vector<double> x(n),y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  vector<TLine> line(n);
  for (int i = 0; i < n; ++i) {
    line[i] = TLine(x[i], y[i], x[(i+1)%n], y[(i+1)%n]);
  }
  for (int i = 0; i < n; ++i) {
    line[i].Draw();
  }

  int buf; cin >> buf;
  double xx,yy,zz,ww;
  cin >> xx >> yy >> zz >> ww;
  TLine *line2 = new TLine(xx, yy, zz, ww);
  line2->SetLineColor(2);
  line2->Draw();
  
  // // (x,y)を中心とする半径rの円を描く TArc(x, y, r)
  // TArc *arc = new TArc(50.0, 50.0, 30.0);
  // arc->SetFillColor(2);
  // arc->Draw();
  // TLine *line = new TLine(3, 4, 57, 80);
  // line->Draw();
  app.Run();
  
  return 0;
}
