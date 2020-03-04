#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

////////////////////////////
// 基本要素 (点, 線分, 円)
////////////////////////////

using DD = long double;
const DD INF = 1LL<<60;      // to be set appropriately
const DD EPS = 1e-7;        // to be set appropriately
const DD PI = acosl(-1.0);
DD torad(int deg) {return (DD)(deg) * PI / 180;}
DD todeg(DD ang) {return ang * 180 / PI;}

/* Point */
struct Point {
    DD x, y;
    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}
};
inline Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
inline Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
inline Point operator * (const Point &p, DD a) {return Point(p.x * a, p.y * a);}
inline Point operator * (DD a, const Point &p) {return Point(a * p.x, a * p.y);}
inline Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
inline Point operator / (const Point &p, DD a) {return Point(p.x / a, p.y / a);}
inline Point conj(const Point &p) {return Point(p.x, -p.y);}
inline Point rot(const Point &p, DD ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
inline Point rot90(const Point &p) {return Point(-p.y, p.x);}
inline DD cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
inline DD dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
inline DD norm(const Point &p) {return dot(p, p);}
inline DD abs(const Point &p) {return sqrt(dot(p, p));}
inline DD amp(const Point &p) {DD res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}
inline bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
inline bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
inline bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
inline Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

/* Line */
struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream& operator << (ostream &s, const Line &l) {return s << '{' << l[0] << ", " << l[1] << '}';}
};

/* Circle */
struct Circle : Point {
    DD r;
    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}
    friend ostream& operator << (ostream &s, const Circle &c) {return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';}
};

// 円の交点
vector<Point> crosspoint(const Circle &e, const Circle &f) {
    vector<Point> res;
    DD d = abs(e - f);
    if (d < EPS) return vector<Point>();
    if (d > e.r + f.r + EPS) return vector<Point>();
    if (d < abs(e.r - f.r) - EPS) return vector<Point>();
    DD rcos = (d * d + e.r * e.r - f.r * f.r) / (2.0 * d), rsin;
    if (e.r - abs(rcos) < EPS) rsin = 0;
    else rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (f - e) / d;
    Point p1 = e + dir * Point(rcos, rsin);
    Point p2 = e + dir * Point(rcos, -rsin);
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}

int N, K;
vector<Point> ps;
vector<DD> c;

DD solve() {
    DD low = 0, high = 1000000;
    for (int _ = 0; _ < 100; ++_) {
        DD x = (low + high) / 2;
        vector<Circle> cs(N);
        for (int i = 0; i < N; ++i) cs[i] = Circle(ps[i], x / c[i]);
        vector<Point> alt;
        for (int i = 0; i < N; ++i) {
            alt.push_back(ps[i]);
            for (int j = i+1; j < N; ++j) {
                auto cp = crosspoint(cs[i], cs[j]);
                for (auto p : cp) alt.push_back(p);
            }
        }
        bool ok = false;
        for (auto p : alt) {
            int tmp = 0;
            for (int i = 0; i < N; ++i) {
                DD dist = abs(cs[i] - p);
                if (dist <= cs[i].r + EPS) ++tmp;
            }
            if (tmp >= K) ok = true;
        }
        if (ok) high = x;
        else low = x;
    }
    return high;
}

int main() {
  double x1,y1,r1,x2,y2,r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  vector<Point> cp = crosspoint(Circle(Point(x1,y1),r1),Circle(Point(x2,y2),r2));
  rep(i,cp.size()) printf("%.7Lf\t%.7Lf\n", cp[i].x, cp[i].y);
  return 0;
}
