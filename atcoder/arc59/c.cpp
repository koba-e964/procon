#include <bits/stdc++.h>
using namespace std;

#ifdef _WIN32
#define scanfll(x) scanf("%I64d", x)
#define printfll(x) printf("%I64d", x)
#else
#define scanfll(x) scanf("%lld", x)
#define printfll(x) printf("%lld", x)
#endif
#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
#define mp make_pair
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }
#define ldout fixed << setprecision(40) 

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll n, c; cin >> n >> c;
    vll a(n); rep(i, a.size()) cin >> a[i];
    vll b(n); rep(i, b.size()) cin >> b[i];
    rep(i, n) {
        if (a[i] != b[i]) {
            cerr << "Not Partial" << endl;
            return 0;
        }
    }

    // iのj乗
    static ll pow_table[410][410] = {};
    rep(i, 410) {
        pow_table[i][0] = 1;
        repi(j, 1, 410) {
            (pow_table[i][j] = pow_table[i][j-1] * i) %= mo;
        }
    }
    /*
    rep(m, 3) {
        rep(k, 3) {
            cout << m << " " << k << " " << pow_table[m][k] << endl;
        }
    }
    */

    // 最後からm個の和
    static vll one_table(n+1);
    rep(i, n) {
        (one_table[i+1] += a[n-i-1] + one_table[i]) %= mo;
    }
//    cout << one_table << endl;


    static ll dp[410][410] = {};
    rep(i, 410) rep(j, 410) dp[i][j] = -1;

    function<ll(ll, ll)> f = [&](ll m, ll k) {
        if (dp[m][k] >= 0) {
            return dp[m][k];
        }
        if (m == 1) {
            return dp[m][k] = pow_table[a[n-m]][k];
        }
        if (k == 1) {
            return dp[m][k] = one_table[m];
        }
        ll tmp = 0;
        rep(i, m) {
            (tmp += a[n-m+i] * f(m - i, k - 1)) %= mo;
        }
        return (dp[m][k] = tmp) %= mo;
    };

    ll ret = f(n, c);

    /*
    rep(m, 3) {
        rep(k, 3) {
            cout << m << " " << k << " " << dp[m][k] << endl;
        }
    }
    */
    cout << ret << endl;
    return 0;
}
