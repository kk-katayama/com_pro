template<typename T>
class CumSum2D{
public:
    vector<vector<T>> a;
    vector<vector<T>> sum;
    int n,m;
    CumSum2D() {};

    // vectorを追加
    void add(vector<T> &v) {
        a.push_back(v);
    }   

    void build() {
        n = sz(a);
        m = sz(a[0]);
        sum.resize(n+1, vector<T>(m+1, 0));
        rep(i,n) {
            rep(j,m) {
            sum[i+1][j+1] = a[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
            }   
        }
    }

    // [(l, d), (r, u)) の範囲の累積和を返す. [l, r), [d, u)
    T range(int l, int r, int d, int u) {
        return sum[r][u] - sum[r][d] - sum[l][u] + sum[l][d];
    }
};

