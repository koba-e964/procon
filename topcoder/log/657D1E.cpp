#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
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

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

// 整数二分探索
// O(log(range))
// f: 単調増加関数. 000111, 111111, 000000を許容する（11110000で探索したい場合は、自分でfを反転すること）
// 閉区間[rl, rr]から単調関数fを満たす最小の数を返す。
// 全て0ならrr+1を返す！
ll BinarySearch(ll rl, ll rr, function<bool(ll)> f) { 
    ll lo = rl-1, ro = rr+1;
    while (ro - lo != 1) {
        ll m = (lo + ro) / 2; 
        ((m!=rl-1&&f(m))?ro:lo)=m; 
    }
    return ro;
}
void BinarySearchInteractive(ll rl, ll rr, function<bool(ll)> f) { 
    while (1) {
        cout << "####" << endl;
        ll tmp; cin >> tmp;
        if (rl > tmp) {cout << "Out of range: too small" << endl; continue; }
        if (rr < tmp) {cout << "Out of range: too large" << endl; continue; }
        ll ret = f(tmp); cout << tmp << " : " << ret << endl;
    }
}

class ProblemSets {
    public:
        ll maxSets(ll e_, ll em_, ll m_, ll mh_, ll h_) {
            auto f = [&](ll x) { 
                ll e = e_; e-=x;
                ll m = m_; m-=x;
                ll h = h_; h-=x;
                ll em = em_; em+=min(e, 0ll); if (em < 0) return 1;
                ll mh = mh_; mh+=min(h, 0ll); if (mh < 0) return 1;
                if (em + mh < -m) return 1;
                return 0;
            };
//            BinarySearchInteractive(0, (ll)2e18, f);
            return BinarySearch(0, (ll)2e18, f) - 1;
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, long long p0, long long p1, long long p2, long long p3, long long p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	ProblemSets *obj;
	long long answer;
	obj = new ProblemSets();
	clock_t startTime = clock();
	answer = obj->maxSets(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	long long p0;
	long long p1;
	long long p2;
	long long p3;
	long long p4;
	long long p5;
	
#if 0
	// ----- test 0 -----
	disabled = false;
	p0 = 2ll;
	p1 = 2ll;
	p2 = 1ll;
	p3 = 2ll;
	p4 = 2ll;
	p5 = 3ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 100ll;
	p1 = 100ll;
	p2 = 100ll;
	p3 = 0ll;
	p4 = 0ll;
	p5 = 0ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 657ll;
	p1 = 657ll;
	p2 = 657ll;
	p3 = 657ll;
	p4 = 657ll;
	p5 = 1095ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 1ll;
	p1 = 2ll;
	p2 = 3ll;
	p3 = 4ll;
	p4 = 5ll;
	p5 = 3ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 1000000000000000000ll;
	p1 = 1000000000000000000ll;
	p2 = 1000000000000000000ll;
	p3 = 1000000000000000000ll;
	p4 = 1000000000000000000ll;
	p5 = 1666666666666666666ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
#endif
   	// ----- test 5 -----
	disabled = false;
	p0 = 563411256982316815ll;
	p1 = 396646749275446584ll;
	p2 = 10830259274061248ll;
	p3 = 369314785529224450ll;
	p4 = 706727134601021100ll;
	p5 = 670101525530524548ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
 
    // ----- test 5 -----
	disabled = false;
	p0 = 200000000000000ll;
	p1 = 200000000000000ll;
	p2 = 100000000000000ll;
	p3 = 200000000000000ll;
	p4 = 200000000000000ll;
	p5 = 300000000000000ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Cat Snuke came up with some problems. He wants to construct as many problem sets as possible using those problems.
// 
// Each problem set must contain exactly three problems: one for the Easy slot, one for the Medium slot, and one for the Hard slot. Each problem can only be assigned to a single slot in a single problem set. He came up with E + EM + M + MH + H problems in total. The distribution of the problems is as follows:
// 
// 
// E problems can only be used in the Easy slot.
// EM problems can be used either in the Easy slot or the Medium slot.
// M problems can only be used in the Medium slot.
// MH problems can be used either in the Medium slot or the Hard slot.
// H problems can only be used in the Hard slot.
// 
// 
// Return the maximal number of problem sets he can construct.
// 
// DEFINITION
// Class:ProblemSets
// Method:maxSets
// Parameters:long long, long long, long long, long long, long long
// Returns:long long
// Method signature:long long maxSets(long long E, long long EM, long long M, long long MH, long long H)
// 
// 
// CONSTRAINTS
// -E, EM, M, MH, H will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// 2
// 1
// 2
// 2
// 
// Returns: 3
// 
// One of EM problems should be used for the Easy slot, and the other should be used for the Medium slot.
// One of MH problems should be used for the Medium slot, and the other should be used for the Hard slot.
// 
// 1)
// 100
// 100
// 100
// 0
// 0
// 
// Returns: 0
// 
// Unfortunately, no problem can be used for the Hard slot.
// 
// 2)
// 657
// 657
// 657
// 657
// 657
// 
// Returns: 1095
// 
// 
// 
// 3)
// 1
// 2
// 3
// 4
// 5
// 
// Returns: 3
// 
// 
// 
// 4)
// 1000000000000000000
// 1000000000000000000
// 1000000000000000000
// 1000000000000000000
// 1000000000000000000
// 
// Returns: 1666666666666666666
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!