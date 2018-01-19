#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

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

using ll = long long; using vll = vector<ll>; using vvll = vector<vll>; using P = pair<ll, ll>;
using ld = long double;  using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>; vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }

inline void input(int &v){ v=0;char c=0;int p=1; while(c<'0' || c>'9'){if(c=='-')p=-1;c=getchar();} while(c>='0' && c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();} v*=p; } // これを使うならば、tieとかを消して！！
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; o << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T> ostream &operator<<(ostream &o, const deque<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const unordered_set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U, typename V>  ostream &operator<<(ostream &o, const unordered_map<T, U, V> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }
vector<int> range(const int x, const int y) { vector<int> v(y - x + 1); iota(v.begin(), v.end(), x); return v; }
template <typename T> istream& operator>>(istream& i, vector<T>& o) { rep(j, o.size()) i >> o[j]; return i;}
template <typename T, typename S, typename U> ostream &operator<<(ostream &o, const priority_queue<T, S, U> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const queue<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.front(); tmp.pop(); o << x << " ";} return o; }
template <typename T> ostream &operator<<(ostream &o, const stack<T> &v) { auto tmp = v; while (tmp.size()) { auto x = tmp.top(); tmp.pop(); o << x << " ";} return o; }
template <typename T> unordered_map<T, ll> counter(vector<T> vec){unordered_map<T, ll> ret; for (auto&& x : vec) ret[x]++; return ret;};
string substr(string s, P x) {return s.substr(x.fi, x.se - x.fi); }
void vizGraph(vvll& g, int mode = 0, string filename = "out.png") { ofstream ofs("./out.dot"); ofs << "digraph graph_name {" << endl; set<P> memo; rep(i, g.size())  rep(j, g[i].size()) { if (mode && (memo.count(P(i, g[i][j])) || memo.count(P(g[i][j], i)))) continue; memo.insert(P(i, g[i][j])); ofs << "    " << i << " -> " << g[i][j] << (mode ? " [arrowhead = none]" : "")<< endl;  } ofs << "}" << endl; ofs.close(); system(((string)"dot -T png out.dot >" + filename).c_str()); }
size_t random_seed; namespace std { using argument_type = P; template<> struct hash<argument_type> { size_t operator()(argument_type const& x) const { size_t seed = random_seed; seed ^= hash<ll>{}(x.fi); seed ^= (hash<ll>{}(x.se) << 1); return seed; } }; }; // hash for various class
struct timeval start; double sec() { struct timeval tv; gettimeofday(&tv, NULL); return (tv.tv_sec - start.tv_sec) + (tv.tv_usec - start.tv_usec) * 1e-6; }
struct init_{init_(){ ios::sync_with_stdio(false); cin.tie(0); gettimeofday(&start, NULL); struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec); random_seed = RAND_MAX / 2 + rand() / 2; }} init__;
#define ldout fixed << setprecision(40) 

#define EPS (double)1e-14
#define INF (ll)1e18
#define mo  (ll)(1e9+7)
ll n, T;
vll a, t;
ll retret;
bool f(ll num, bool res_mode = 0) {
    vll ta, tb;
    rep(i, n) {
        if (a[i] <= num)
            ta.pb(t[i]);
        else 
            tb.pb(t[i]);
    }
    sort(all(ta));
    sort(all(tb));

    vll tas(ta.size()+1), tbs(tb.size()+1);
    rep(i, ta.size()) tas[i+1] = tas[i] + ta[i];
    rep(i, tb.size()) tbs[i+1] = tbs[i] + tb[i];

    ll mi = -1;
    repi(i, 0, ta.size()+1) if (num-i < tbs.size()) {
        // taからi個取って、tbからnum-i個取れるか？
        if (tas[i] + tbs[num-i] <= T) {
            mi = i;
        }
    }
    cout << "######"<<endl;
    cout << num << endl;
    cout << ta << endl;
    cout << tb << endl;
    cout << mi << endl;
    retret=mi;
    if (res_mode) {
        if (mi != -1 && ta.size() != 0) {
            vector<P> ta, tb;
            rep(i, n) {
                if (a[i] <= num)
                    ta.pb(P(t[i], i));
                else 
                    tb.pb(P(t[i], i));
            }
            sort(all(ta));
            sort(all(tb));

            cout << mi << endl;
            cout << num << endl;
            rep(i, mi) {
                cout << ta[i].se + 1 << " ";
            }
            rep(i, num - mi) {
                cout << tb[i].se + 1 << " ";
            }
            cout << endl;
        } else {
            cout << 0 << endl;
            cout << 0 << endl;
            cout << endl;
        }

        if (mi == -1 || ta.size() == 0) {
            return 1;
        } else {
            return 0;
        }

    } else {
        if (mi == -1) {
            return 1;
        } else {
            return 0;
        }
    }
}

ll solve(void) {
    cout << f(1) << endl;
    /*
    rep(_, 100) {
        cout << f(_);
    }
    cout << endl;
    */
    ll ng = 0, ok = n + 10;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
//    f(ng, 1);
    f(1);
    cout << retret<<"jfoie"<< endl;
    f(2);
    cout << retret<<"jfoie"<<endl;
    f(ng);
    return retret;
}

ll brutal(void) {
    assert(n <= 10);
    ll ans = 0;
    rep(mask, 1<<n) {
        vector<P> ta;
        rep(i, n) if (mask & (1ll << i)) {
            ta.pb(P(a[i], t[i]));
        }
        ll tsum = 0;
        rep(i, ta.size()) {
            tsum += ta[i].se;
        }
        if (tsum > T) continue;
        ll ret = 0;
        rep(i, ta.size()) {
            ret += ta[i].fi <= ta.size();
        }
        chmax(ans, ret);
    }
    return ans;
}

int main(void) {
    cin >> n >> T;
    a.resize(n);
    t.resize(n);
    rep(i, n) {
        cin >> a[i] >> t[i];
    }

    ll x = solve();
    ll y = brutal();
    if (x != y) {
        cout << "#######"<<endl;
        cout << x << endl;
        cout << y << endl;
        cout << endl;

        cout << n << " " << T << endl;
        cout << a << endl;
        cout << t << endl;
    }

    return 0;
}