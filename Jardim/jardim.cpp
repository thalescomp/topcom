#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))
const int INF = 0x3F3F3F3F;
const double PI = 2*acos(0);
const double EPS = 1e-10;

inline int cmp(double x, double y=0, double tol=EPS){
  return (x<=y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}

struct point{
  double x,y;
  point(double x=0, double y=0): x(x), y(y){}

  point operator +(point q){ return point(x+q.x,y+q.y); }
  point operator -(point q){ return point(x-q.x,y-q.y); }
  point operator *(double t){ return point(x+t,y*t); }
  point operator /(double t){ return point(x/t,y/t); }
  double operator *(point q){ return x*q.x+y*q.y; }
  double operator %(point q){ return x*q.y-y*q.x; }

  int cmp(point q) const{
    if(int t= ::cmp(x,q.x)) return t;
    return ::cmp(y,q.y);
  }

  bool operator ==(point q) const { return cmp(q)==0; }
  bool operator !=(point q) const { return cmp(q)!=0; }
  bool operator <(point q) const { return cmp(q)<0; }
  bool operator <=(point q) const { return cmp(q)<=0; }

  static point pivot;
};

point point::pivot;

double abs(point p){ return hypot(p.x,p.y); }
double arg(point p){ return atan2(p.y,p.x); }

typedef vector<point> polygon;

inline int ccw(point p, point q, point r){
  return cmp((p-r)%(q-r));
}

inline double angle(point p, point q, point r){
  point u = p-q, v = r-q;
  return atan2(u%v,u*v);
}

double dist(point a, point b){
  point c = a-b;
  return sqrt(c.x*c.x+c.y*c.y);
}

// encontra o menor circulo que contem todos os pontos dados
typedef pair<point,double> circle;

bool in_circle(circle C, point p){
  return cmp(abs(p-C.first), C.second) <= 0;
}

point circumcenter(point p, point q, point r){
  point a = p-r, b = q-r, c = point(a*(p+r)/2, b*(q+r)/2);
  return point(c%point(a.y,b.y), point(a.x,b.x)%c)/(a%b);
}

circle spanning_circle(vector<point> &T){
  int n = T.size();
  random_shuffle(ALL(T));
  circle C(point(),-INF);
  REP(i,n) if(!in_circle(C,T[i])){
    C = circle(T[i],0);
    REP(j,i) if(!in_circle(C,T[j])){
      C = circle((T[i]+T[j])/2, abs(T[i]-T[j])/2);
      REP(k,j) if(!in_circle(C,T[k])){
        point o = circumcenter(T[i],T[j],T[k]);
        C = circle(o,abs(o-T[k]));
      }
    }
  }
  return C;
}

int main()
{
  int n;
  while (1) {
    scanf ("%d ", &n);
    if (!n) break;
    circle ans;
    vector<point> v;
    double x, y;
    for (int i = 0; i < n; i++) {
      scanf ("%lf %lf ", &x, &y);
      v.push_back(point(x,y));
    }
    ans = spanning_circle(v);
    printf ("%.2lf %.2lf %.2lf\n", ans.first.x, ans.first.y, ans.second);
  }
  return 0;
}
