using ld = long double;
const ld EPS = 1e-10;
struct Vec2 {
  ld x;
  ld y;

  Vec2() : x(0.0),y(0.0){} 
  Vec2(ld _x,ld _y) :x(_x),y(_y){}  
  
  Vec2 operator+(const Vec2& other) const { return { x + other.x , y + other.y }; }
  Vec2 operator-(const Vec2& other) const { return { x - other.x , y - other.y }; }
  bool operator==(const Vec2& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); } 
  bool operator<(const Vec2& other) const { if(abs(x - other.x) < EPS) return y < other.y; else return x < other.x; }
 
  ld dot(const Vec2& other) const { return x * other.x + y * other.y; }
  ld cross(const Vec2& other) const { return x * other.y - y * other.x; }
  ld length() const { return sqrt(x * x + y * y); }
  
  void Show() { printf("%.8Lf %.8Lf\n", x, y); }
};

struct Line {
  Vec2 s; // 始点
  Vec2 t; // 終点
  
  Line() : s({0, 0}), t({0, 0}) {}
  Line(Vec2 s, Vec2 t) : s(s), t(t) {}

  Vec2 V() { return t - s; }
  ld dot(const Line &other) const { return (t - s).dot(other.t - other.s); }
  ld cross(const Line &other) const { return (t - s).cross(other.t - other.s); }
  ld length() const { return (t - s).length(); }

  ld alpha() { // 直線の傾き
    if(abs((t - s).x) < EPS) { cout << "pararell Y axis!!!" << "\n"; return 0; }
    else return (t - s).y / (t - s).x;
  }
  ld beta() { // 直線の切片
    if(abs((t - s).x) < EPS) { cout << "pararell Y axis!!!" << "\n"; return 0; }
    else return s.y - (t - s).y / (t - s).x * s.x;
  }

  void Show() { s.Show(); t.Show();  }  
};

struct Circle {
  Vec2 p; // 中心
  ld r; // 半径

  Circle() : p({0,0}), r(0) {}
  Circle(Vec2 p, ld r) : p(p), r(r) {}
  
  void Show() { printf("%.8Lf %.8Lf %.8Lf\n", p.x, p.y, r); }
};

//******************** 2点間の距離 *******************
ld Dist(Vec2 &A, Vec2 &B) { return (A - B).length(); } 
//*****************ベクトルVをTheta回転******************
Vec2 Rot(Vec2 &V, ld Theta) {
  return Vec2(V.x * cos(Theta) - V.y * sin(Theta), V.x * sin(Theta) + V.y * cos(Theta));
}
//********** ベクトルVを回転**********
Vec2 Rot(Vec2 &V, ld SIN, ld COS) {
  return Vec2(V.x * COS - V.y * SIN, V.x * SIN + V.y * COS);
}
//********** ベクトルA とB のなす角θ cosθ, sin**********
ld Cos(const Vec2 &A, const Vec2 &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.dot(B) / (A.length()*B.length());
}
ld Sin(const Vec2 &A, const Vec2 &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.cross(B) / (A.length()*B.length());
}
//********** 線分A とB のなす角θ cosθ, sin**********
ld Cos(const Line &A, const Line &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.dot(B) / (A.length()*B.length());
}
ld Sin(const Line &A, const Line &B) {
  if(A.length() < EPS || B.length() < EPS) return 0;
  return A.cross(B) / (A.length()*B.length());
}
//**********3点から三角形の面積を求める**********
ld Area(Vec2 &A, Vec2 &B, Vec2 &C) {
  Line AB(A, B), AC(A, C);
  return AB.cross(AC) / 2;
}
//********** 線分ABをB方向に長さlに延長する**********
Line ExpandB(const Line &AB, const ld &l) {
  Line v(Vec2(0,0), Vec2(1,0));
  Vec2 d(l * Cos(v, AB), l * Sin(v, AB));
  return Line(AB.s, AB.s + d);
}
//********** 線分ABを両方向に長さlに延長する**********
Line ExpandAB(Line &AB, ld &l) {
  Line v(Vec2(0,0), Vec2(1,0));
  Vec2 d(l * Cos(v, AB), l * Sin(v, AB));
  return Line(AB.t - d, AB.s + d);
}
//********** 線分ABをx:y に内分する点を返す**********
Vec2 InDiv(Line &AB, ld x, ld y) {
  ld l = AB.length() * x / (x + y);
  return ExpandB(AB, l).t;
}
//********** 直線ABと点Cの距離**********
ld DistLinePoint(const Line &AB, const Vec2 &C) {
  Line AC(AB.s, C);
  return AC.length() * abs(Sin(AB, AC));
}
//********** 直線AB上に点Cを射影した点**********
Vec2 Proj(const Line &AB, const Vec2 &C) {
  Line AC(AB.s, C);
  ld l = AC.length() * Cos(AB, AC);
  Line res = ExpandB(AB, l);
  return res.t;
}
//********** 直線AB上に点Cがあるか**********
bool IsOnLine(const Line &AB, const Vec2 &C) {
  Line CA(C, AB.s), CB(C, AB.t);
  return abs(Sin(CA, CB)) < EPS;
}
//********** 線分AB上に点Cがあるか**********
bool IsInLine(const Line &AB, const Vec2 &C) {
  Line CA(C, AB.s), CB(C, AB.t);
  return abs(Sin(CA, CB)) < EPS && CA.dot(CB) < EPS;
}
//********** 線分の交差判定**********
bool CrossCheck(const Line &AB, const Line &CD) {
  Line AC(AB.s, CD.s), AD(AB.s, CD.t);
  Line BC(AB.t, CD.s), BD(AB.t, CD.t);
  Line CA(CD.s, AB.s), CB(CD.s, AB.t);
  Line DA(CD.t, AB.s), DB(CD.t, AB.t);
  ld s = AB.cross(AC) * AB.cross(AD);
  ld t = CD.cross(CA) * CD.cross(CB);

  if(abs(Sin(AB, CD)) < EPS) { // 平行のとき
    if(abs(Sin(AB, AC)) < EPS) { // 同一直線上にあるか？
      return (CA.dot(CB) < EPS || DA.dot(DB) < EPS || AC.dot(AD) < EPS || BC.dot(BD) < EPS);
    }
    else return false;
  }
  else return s < EPS && t < EPS;
}
//********** 直線の交点**********
Vec2 CrossPoint(Line &AB, Line &CD) {
  if( abs(Sin(AB, CD)) < EPS) {
    cout << "Pararell" << "\n";
    return Vec2(0,0);
  }
  if(abs(AB.V().x) < EPS) { // ABがy軸に平行
    return Vec2(AB.s.x, CD.alpha() * AB.s.x + CD.beta());
  }
  else if( abs(CD.V().x) < EPS) { // CDがy軸に平行
    return Vec2(CD.s.x, AB.alpha() * CD.s.x + AB.beta());
  }
  else {
    ld resX = (CD.beta() - AB.beta()) / (AB.alpha() - CD.alpha());
    ld resY = AB.alpha() * resX + AB.beta();
    return Vec2(resX, resY);
  }
}
//********** 点Cを通りABに平行な直線を返す**********
Line OrthogonalLine(Line &AB, Vec2 &C) {
  Vec2 t(C.x + AB.V().y, C.y - AB.V().x);
  return Line(C, t);
}

//********** 三角形の外接円**********
Circle CircumscribedCircle(Vec2 &A, Vec2 &B, Vec2 &C) {
  Line AB(A, B), BC(B, C);
  Vec2 ABx = InDiv(AB, 1, 1);
  Vec2 BCx = InDiv(BC, 1, 1);  
  Line ABn = OrthogonalLine(AB, ABx);
  Line BCn = OrthogonalLine(BC, BCx);
  Vec2 Cen = CrossPoint(ABn, BCn);
  return Circle(Cen, (Cen - A).length());
}
//********** 直線と円の交点**********
vector<Vec2> CrossPointCircleLine(Circle &C, Line &AB){
  vector<Vec2> res;
  if(IsInLine(AB, C.p)) {
    Line OX(C.p, AB.s);
    Vec2 X = ExpandB(OX, C.r).t;
    Line OY(C.p, AB.t);
    Vec2 Y = ExpandB(OY, C.r).t;
    res.push_back(X);
    res.push_back(Y);
    return res;
  }
  Vec2 P = Proj(AB, C.p);
  Line OP(C.p, P);
  Line OPn = OrthogonalLine(OP, P);
  ld l = sqrt(C.r*C.r - OP.length()*OP.length());

  if(C.r < OP.length()) return res;
  Vec2 X = ExpandB(OPn, l).t;
  Vec2 Y = ExpandB(OPn, -l).t;
  if(X == Y) res.push_back(X);
  else { 
    res.push_back(X);
    res.push_back(Y);    
  }
  return res;
}
//********** 2つの円の交差判定**********
// 0:内包、1:内接、2:交差、3:外接、4:離れている
int CrossCheckCircle(Circle &C, Circle &D) {
  ld d = Dist(C.p, D.p);
  if(abs(C.r - D.r) > d) return 0; 
  else if(abs(abs(C.r - D.r) - d) < EPS) return 1;

  if(C.r + D.r < d) return 4;
  else if(abs(C.r + D.r - d) < EPS) return 3;
  else return 2;
}
//********** 2つの円の交点**********
vector<Vec2> CrossPointCircleCircle(Circle &C, Circle &D) {
  vector<Vec2> res;
  int label = CrossCheckCircle(C, D);
  if(label == 0 || label == 4) return res; // 共有点なし
  else if(label == 1) { // 内接
    if(C.r < D.r) {
      Line DC(D.p, C.p);
      Vec2 X = ExpandB(DC, D.r).t;
      res.push_back(X);
      res.push_back(X);      
    }
    else {
      Line CD(C.p, D.p);
      Vec2 X = ExpandB(CD, C.r).t;
      res.push_back(X);
      res.push_back(X);            
    }
  }
  else if(label == 3) { // 外接
    Line CD(C.p, D.p);
    Vec2 X = ExpandB(CD, C.r).t;
    res.push_back(X);
    res.push_back(X);                
  }
  else if(label == 2) {
    ld ad = 2*(C.p.x - D.p.x);
    ld eb = 2*(D.p.y - C.p.y);
    ld R = - C.p.x*C.p.x + D.p.x*D.p.x - C.p.y*C.p.y + D.p.y*D.p.y + C.r*C.r - D.r*D.r;
    if(abs(eb) < EPS) {
      Vec2 A(- R / ad, 0);
      Vec2 B(- R / ad, 1);
      Line AB(A, B);
      ld inf = 40000;
      Line ABE = ExpandAB(AB, inf);
      res = CrossPointCircleLine(C, ABE);      
    }
    else {
      Vec2 A(0, R / eb);
      Vec2 B(1, (ad + R) / eb);
      Line AB(A, B);
      ld inf = 40000;
      Line ABE = ExpandAB(AB, inf);
      res = CrossPointCircleLine(C, ABE);
    }
  }
  return res;
}
//********** 点Pを通る円Cの接線と円Cとの接点**********
vector<Vec2> TangentCircle(Circle &C, Vec2 &P) {
  vector<Vec2> res;
  Line PC(P, C.p);
  Vec2 OC = PC.V();
  ld l = sqrt(PC.length()*PC.length() - C.r*C.r);
  ld SIN = C.r / PC.length(), COS = l / PC.length();
  Vec2 OX = Rot(OC, SIN, COS), OY = Rot(OC, -SIN, COS);
  Line OXL(Vec2(0,0), OX) , OYL(Vec2(0,0), OY);
  OXL = ExpandB(OXL, l);
  OYL = ExpandB(OYL, l);
  res.push_back(OXL.t + P);
  res.push_back(OYL.t + P);
  return res;
}
//**********多角形の面積を求める**********
ld Area(vector<Vec2> &V) {
  int n = V.size();
  ld res = 0;
  Vec2 O = V[0];
  rep1(i, n-2) {
    res += Area(O, V[i], V[i+1]);
  }
  return res;
}
//*********凸包************
vector<Vec2> ConvexHull(vector<Vec2> &V) {
  int n = V.size();
  //******** 最も左下の点をスタートにする  ********
  sort(V.begin(), V.end());
  Vec2 O = V[0]; 
  //**********************************
  //************ 偏角ソート **********
  // 偏角が同じものはスタートからの距離が遠いほど先に配置
  sort(V.begin(), V.end(), [&](Vec2 a, Vec2 b) {
			     ld adx = a.x - O.x, ady = a.y - O.y;
			     ld bdx = b.x - O.x, bdy = b.y - O.y;
			     if(abs(adx) < EPS && abs(ady) < EPS) return true;
			     else if(abs(bdx) < EPS && abs(bdy) < EPS) return false;
                             else if(abs(atan2(ady, adx) - atan2(bdy, bdx)) < EPS ) {
                               return Dist(O, a) > Dist(O, b);
			     }
			     else {
			       return atan2(ady, adx) < atan2(bdy, bdx);
			     }
			   });
  //**********************************
  //******************* GrahamScan ******************
  vector<Vec2> res;
  int next = 2;
  res.push_back(V[0]);
  res.push_back(V[1]);
  //***************前処理************
  // 偏角が同じものについて、スタート直後のみはスタートからの距離が短い順に並べる。
  while(abs(Sin(V[1] - V[0], V[next] - V[0])) < EPS) {
    res.push_back(V[next]);
    next++;
  }
  sort(res.begin(), res.end(), [&](Vec2 a, Vec2 b) {
				 return Dist(O, a) < Dist(O, b);
			       });
  //*********************************
  while(next < n) {
    int size = res.size();
    if(abs(Sin(res[size - 1] - res[size - 2], V[next] - res[size - 1])) < EPS
       || Sin(res[size - 1] - res[size - 2], V[next] - res[size - 1]) > 0) {
      res.push_back(V[next]);
      next++;
    }
    else {
      res.pop_back();
    }
  }
  return res;
  //******************************************
}
//*************キャリパー法。凸多角形に対して、最遠点対を求める*********
ld Caliper(const vector<Vec2> &V) {
  int n = V.size();
  // x軸方向に最も遠い点対を求める
  int p = 0, q = 0;
  ld xmin = 1e+15, xmax = -1e+15;
  rep(i,n) {
    if(chmin(xmin, V[i].x)) p = i;
    if(chmax(xmax, V[i].x)) q = i;
  }
  ld res = 0;
  int sp = p, sq = q;
  while(p != sq || q != sp) { // 180度回転するまで
    chmax(res, (V[q] - V[p]).length() );
    if( (V[(p+1)%n] - V[p]).cross(V[(q+1)%n] - V[q]) < 0) {
      p = (p + 1) % n;
    }
    else {
      q = (q + 1) % n;
    }
  }
  return res;
}

//*********** 最近点対**********************
// 引数は(点集合、0、点集合のサイズ)
// 予め点集合をソートしておくこと
ld ClosestPair(vector<Vec2> &v, int l, int r) {
  if(r - l <= 1) return 1e+15;
  int mid = (l + r) / 2;
  Vec2 O = v[mid];
  ld d = min(ClosestPair(v, l, mid), ClosestPair(v, mid, r));
  sort(v.begin() + l, v.begin() + r, [](Vec2 a, Vec2 b) {
				       return a.y < b.y;
				     });

  // 境界を跨ぐものをチェック
  vector<Vec2> w;
  for (int i = l; i < r; ++i) {
    if(abs(v[i].x - O.x) >= d) continue;
    for (int j = w.size() - 1; j >= 0; --j) {
      if(abs(v[i].y - w[j].y) >= d) break;
      chmin(d, (v[i] - w[j]).length());
    }
    w.push_back(v[i]);
  }
  return d;
}
