const double EPS = 1e-10;
struct Vec2 {
  double x;
  double y;

  Vec2() : x(0.0),y(0.0){} 
  Vec2(double _x,double _y) :x(_x),y(_y){}  
  
  Vec2 operator+(const Vec2& other) const { return { x + other.x , y + other.y }; }
  Vec2 operator-(const Vec2& other) const { return { x - other.x , y - other.y }; }
  bool operator==(const Vec2& other) const { return (abs(x - other.x) < EPS && abs(y - other.y) < EPS ); }
  
  double dot(const Vec2& other) const { return x * other.x + y * other.y; }
  double cross(const Vec2& other) const { return x * other.y - y * other.x; }
  double length() const { return sqrt(x * x + y * y); }
};
// A とB のなす角θ cosθ, sinθ を返す
double Cos(const Vec2 A, const Vec2 B) { return A.dot(B) / (A.length()*B.length()); }
double Sin(const Vec2 A, const Vec2 B) { return A.cross(B) / (A.length()*B.length()); }

// 線分AB上に点Cがあるかどうかの判定
bool IsOnLine(const Vec2 A, const Vec2 B, const Vec2 C) {  return abs(Sin(A - C, B - C)) < EPS && Cos(A - C, B - C) < 0; }

// 線分の交差判定
bool CrossCheck(const Vec2 a, const Vec2 b, const Vec2 c, const Vec2 d) {
  if(a == c || a == d || b == c || b == d) return true; // 端点が等しい場合はtrue
  Vec2 AB = b - a, AC = c - a, AD = d - a;
  Vec2 CA = a - c, CB = b - c, CD = d - c;
  double s = AB.cross(AC) * AB.cross(AD);
  double t = CD.cross(CA) * CD.cross(CB);

  if(abs(Sin(AB, CD)) < EPS) { // 平行のとき
    if(abs(Sin(AB, AC)) < EPS) { // 同一直線上にあるか？
      return (CA.dot(CB) - EPS < 0 || (a - d).dot(b - d) - EPS < 0 || AC.dot(AD) - EPS < 0);
    }
    else return false;
  }
  else return s < EPS && t < EPS;
}
